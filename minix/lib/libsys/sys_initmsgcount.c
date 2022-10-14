#include "syslib.h"

int sys_initmsgcount(unsigned flags, endpoint_t proc_ep)
{
        message m;

        return(_kernel_call(SYS_INITMSGCOUNT, &m));
}