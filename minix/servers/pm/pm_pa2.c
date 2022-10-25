#include "pm.h"
#include "stdint.h"
#include <lib.h>
#include <limits.h>
#include <minix/callnr.h>
#include <minix/com.h>
#include <minix/endpoint.h>
#include <signal.h>

#include "mproc.h"

/*===========================================================================*
 *				do_gettrapcount				     *
 *===========================================================================*/
int do_pm_gettrapcount(void) {
    uint64_t cnt;
    sys_gettrapcount(&cnt);
    // printf("%llu %d %d\n", cnt, kernel_calls, getKernelCalls());
    // return (int)cnt;
    return kernel_calls;
}
/*===========================================================================*
 *				do_getmsgcount				     *
 *===========================================================================*/
int do_pm_getmsgcount(void) {
    uint64_t cnt;
    sys_getmsgcount(&cnt);
    // printf("%llu %d %d\n", cnt, msg_calls, getMsgCalls());
    // return (int)cnt;
    return msg_calls;
}
/*===========================================================================*
 *				do_resettrapcount				     *
 *===========================================================================*/
int do_pm_resettrapcount(void) {
    return kernel_calls = 0;
    // return sys_inittrapcount();
}
/*===========================================================================*
 *				do_resetmsgcount				     *
 *===========================================================================*/
int do_pm_resetmsgcount(void) {
    return msg_calls = 0;
    // return sys_initmsgcount();
}