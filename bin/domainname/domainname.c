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

static void test();

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

// #define FATAL(...)                               \
//     do {                                         \
//         fprintf(stderr, "strace: " __VA_ARGS__); \
//         fputc('\n', stderr);                     \
//         exit(EXIT_FAILURE);                      \
//     } while (0)

// int trace(char **argv) {

//     pid_t pid = fork();
//     switch (pid) {
//     case -1: /* error */
//         FATAL("%s", strerror(errno));
//     case 0: /* child */
//         ptrace(PTRACE_TRACEME, 0, 0, 0);
//         /* Because we're now a tracee, execvp will block until the parent
//          * attaches and allows us to continue. */
//         execvp(argv[1], argv + 1);
//         FATAL("%s", strerror(errno));
//     }

//     /* parent */
//     waitpid(pid, 0, 0); // sync with execvp
//     ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_EXITKILL);

//     for (;;) {
//         /* Enter next system call */
//         if (ptrace(PTRACE_SYSCALL, pid, 0, 0) == -1)
//             FATAL("%s", strerror(errno));
//         if (waitpid(pid, 0, 0) == -1)
//             FATAL("%s", strerror(errno));

//         /* Gather system call arguments */
//         struct user_regs_struct regs;
//         if (ptrace(PTRACE_GETREGS, pid, 0, &regs) == -1)
//             FATAL("%s", strerror(errno));
//         long syscall = regs.orig_rax;

//         /* Print a representation of the system call */
//         fprintf(stderr, "%ld(%ld, %ld, %ld, %ld, %ld, %ld)",
//                 syscall,
//                 (long)regs.rdi, (long)regs.rsi, (long)regs.rdx,
//                 (long)regs.r10, (long)regs.r8, (long)regs.r9);

//         /* Run system call and stop on exit */
//         if (ptrace(PTRACE_SYSCALL, pid, 0, 0) == -1)
//             FATAL("%s", strerror(errno));
//         if (waitpid(pid, 0, 0) == -1)
//             FATAL("%s", strerror(errno));

//         /* Get system call result */
//         if (ptrace(PTRACE_GETREGS, pid, 0, &regs) == -1) {
//             fputs(" = ?\n", stderr);
//             if (errno == ESRCH)
//                 exit(regs.rdi); // system call was _exit(2) or similar
//             FATAL("%s", strerror(errno));
//         }

//         /* Print system call result */
//         fprintf(stderr, " = %ld\n", (long)regs.rax);
//     }
// }

// domainname trace ls

int main(int argc, char *argv[]) {

    // if (argc >= 2) {
    //     if (!strcmp(argv[1], "trace")) {
    //         trace(argv + 1);
    //     }
    //     if (!strcmp(argv[1], "count")) {
    //         reset_msg_count();
    //         reset_trap_count();

    //         test();

    //         int tc = get_trap_count();
    //         int mc = get_msg_count();

    //         printf("Traps: %i\n", tc);
    //         printf("Msgs:  %i\n", mc);
    //     }
    // }
    if (argc >= 3) {
        test();
    } else if (argc >= 2) {
        reset_msg_count();
        reset_trap_count();
    } else {
        int tc = get_trap_count();
        int mc = get_msg_count();
        printf("Traps: %i\n", tc);
        printf("Msgs:  %i\n", mc);
    }
}