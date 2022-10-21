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

#include <lib.h>

#include <sys/cdefs.h>
#include <sys/featuretest.h>
#include <sys/param.h>
#include <sys/types.h>

#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int get_trap_count();
static int reset_trap_count();
static int get_msg_count();
static int reset_msg_count();
static void test();

static int get_trap_count() {
    message m;
    memset(&m, 0, sizeof(m));
    int ret = _syscall(PM_PROC_NR, PM_GETTRAPCOUNT, &m);
    return ret;
}

static int reset_trap_count() {
    message m;
    memset(&m, 0, sizeof(m));
    return (_syscall(PM_PROC_NR, PM_RESETTRAPCOUNT, &m));
}

static int get_msg_count() {
    message m;
    int ret = _syscall(PM_PROC_NR, PM_GETMSGCOUNT, &m);
    return ret;
}

static int reset_msg_count() {
    message m;
    return (_syscall(PM_PROC_NR, PM_RESETMSGCOUNT, &m));
}

#define BYTES 64

unsigned short seed[] = {164, 486, 345};

static void test() {
    int fd = open("test_file.txt", O_CREAT | O_WRONLY);
    int i;
    char data[BYTES];

    for (i = 0; i < BYTES; i++) {
        data[i] = (char)nrand48(seed);
    }

    write(fd, data, BYTES);
    close(fd);
    fd = open("test_file.txt", O_RDONLY);

    read(fd, data, BYTES);

    close(fd);
    remove("test_file.txt");
}

int main(int argc, char *argv[]) {

    test();

    int tc = get_trap_count();
    int mc = get_msg_count();
    printf("Traps: %i\n", tc);
    printf("Msgs:  %i\n", mc);

    reset_msg_count();
    reset_trap_count();

    test();

    tc = get_trap_count();
    mc = get_msg_count();

    printf("Traps: %i\n", tc);
    printf("Msgs:  %i\n", mc);
}