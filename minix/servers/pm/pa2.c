#include "pm.h"
#include "stdint.h"
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
    return (int)cnt;
}
/*===========================================================================*
 *				do_getmsgcount				     *
 *===========================================================================*/
int do_pm_getmsgcount(void) {
    uint64_t cnt;
    sys_getmsgcount(&cnt);
    return (int)cnt;
}
/*===========================================================================*
 *				do_resettrapcount				     *
 *===========================================================================*/
int do_pm_resettrapcount(void) {
    return sys_inittrapcount();
}
/*===========================================================================*
 *				do_resetmsgcount				     *
 *===========================================================================*/
int do_pm_resetmsgcount(void) {
    return sys_initmsgcount();
}