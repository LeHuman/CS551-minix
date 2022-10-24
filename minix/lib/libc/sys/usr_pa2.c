#include <lib.h>

#include <sys/cdefs.h>
#include <sys/featuretest.h>
#include <sys/pa2.h>
#include <sys/param.h>
#include <sys/ptrace.h>
#include <sys/signal.h>
#include <sys/types.h>

#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int get_trap_count() {
    message m;
    memset(&m, 0, sizeof(m));
    int ret = _syscall(PM_PROC_NR, PM_GETTRAPCOUNT, &m);
    return ret;
}

int reset_trap_count() {
    message m;
    memset(&m, 0, sizeof(m));
    return (_syscall(PM_PROC_NR, PM_RESETTRAPCOUNT, &m));
}

int get_msg_count() {
    message m;
    int ret = _syscall(PM_PROC_NR, PM_GETMSGCOUNT, &m);
    return ret;
}

int reset_msg_count() {
    message m;
    return (_syscall(PM_PROC_NR, PM_RESETMSGCOUNT, &m));
}