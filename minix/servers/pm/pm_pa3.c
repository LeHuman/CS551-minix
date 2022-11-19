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
 *				do_pm_niceto				     *
 *===========================================================================*/
int do_pm_niceto(void) {
    return sys_niceto(m_in.m_m1.m1ull1);
}
/*===========================================================================*
 *				do_pm_morecache				     *
 *===========================================================================*/
int do_pm_morecache(void) {
    return sys_morecache(m_in.m_m1.m1ull1);
}
/*===========================================================================*
 *				do_pm_morezone				     *
 *===========================================================================*/
int do_pm_morezone(void) {
    return sys_morezone(m_in.m_m1.m1ull1);
}