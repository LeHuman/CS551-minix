#include "syslib.h"

int sys_msgcount(unsigned flags, endpoint_t proc_ep)
{
        message m;

        return(_kernel_call(SYS_MSGCOUNT, &m));
}