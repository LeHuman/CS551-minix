/*	$NetBSD: domainname.c,v 1.15 2011/08/29 14:51:18 joerg Exp $	*/

/*
 * Copyright (c) 1988, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
#include <sys/pa2.h>
#include <sys/pa3.h>
#ifndef lint
__COPYRIGHT("@(#) Copyright (c) 1988, 1993\
 The Regents of the University of California.  All rights reserved.");
#endif /* not lint */

#ifndef lint
#if 0
static char sccsid[] = "@(#)hostname.c	8.1 (Berkeley) 5/31/93";
#else
__RCSID("$NetBSD: domainname.c,v 1.15 2011/08/29 14:51:18 joerg Exp $");
#endif
#endif /* not lint */

#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <minix/mthread.h>

#define CLIENTS 100
#define BYTES 64

int Run = 0;
unsigned short seed[] = {164, 486, 345};
unsigned int count;

void *test(void *c);

void *test(void *c) {
    char id[128];
    sprintf(id, "test_file_%d.txt", (int)c);
    int i;
    size_t cnt = 0;
    char data[BYTES];

    for (i = 0; i < BYTES; i++) {
        data[i] = (char)nrand48(seed);
    }
    while (!Run) {
        mthread_yield();
    }

    printf("Start\n");

    while (Run) {
        int fd = open(id, O_CREAT | O_WRONLY);
        write(fd, data, BYTES);
        close(fd);
        fd = open(id, O_RDONLY);
        read(fd, data, BYTES);
        close(fd);
        remove(id);
        cnt++;
        mthread_yield();
    }

    printf("Done\n");

    count += cnt;

    return (void *)0;
}

int main(int argc, char *argv[]) {

    int fd = open("times.csv", O_CREAT | O_WRONLY);
    char buf[512];
    int off = 0;
    int priority = 11;
    int cache = 0;
    int zone = 0;
    off += sprintf(buf + off, "Cache, Zone, Priority, W/R in 10s,\n");

    while (priority - 1) {
        printf("Starting test\n");
        int i;
        mthread_thread_t threads[CLIENTS];

        for (i = 0; i < CLIENTS; i++) {
            mthread_create(threads + i, NULL, test, (void *)i);
        }

        time_t t = time(NULL);

        Run = 1;

        printf("Waiting\n");
        while (time(NULL) - t < 10)
            ;

        Run = 0;

        printf("Kill\n");
        for (i = 0; i < CLIENTS; i++) {
            mthread_join(threads[i], NULL);
        }
        printf("\nFinish! %u, %u, %u, %u,\n", cache, zone, priority, count);

        off += sprintf(buf + off, "%u, %u, %u, %u,\n", cache, zone, priority, count);

        write(fd, buf, off);
        cache += 4096;
        increase_cache(4096);
        zone += 4096;
        increase_zone(4096);
        increase_user_priority(priority--);
        count = 0;
        printf("Cached!\n");
    }

    close(fd);
    truncate("times.csv", off - 2);
}