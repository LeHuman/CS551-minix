#include "kernel/system.h"
#include <minix/endpoint.h>
#include "kernel/glo.h"

/*===========================================================================*
  *                                do_trapcount                                  *
  *===========================================================================*/
int do_msgcount(struct proc *caller_ptr, message *m_ptr)
{
    m_ptr->m_m1.m1ull1 = msg_counts;
    return(OK);
}