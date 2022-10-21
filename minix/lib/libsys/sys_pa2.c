#include "syslib.h"

int sys_initmsgcount(void) {
    message m;
    return (_kernel_call(SYS_INITMSGCOUNT, &m));
}

int sys_inittrapcount(void) {
    message m;
    return (_kernel_call(SYS_INITTRAPCOUNT, &m));
}

int sys_gettrapcount(uint64_t *counter) {
    message m;
    int ret = _kernel_call(SYS_GETTRAPCOUNT, &m);
    if (ret >= 0 && counter != NULL) {
        *counter = m.m_m1.m1ull1;
    }
    return ret;
}

int sys_getmsgcount(uint64_t *counter) {
    message m;
    int ret = _kernel_call(SYS_GETMSGCOUNT, &m);
    if (ret >= 0 && counter != NULL) {
        *counter = m.m_m1.m1ull1;
    }
    return ret;
}