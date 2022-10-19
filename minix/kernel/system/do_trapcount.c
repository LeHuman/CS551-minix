#include "kernel/system.h"
#include <minix/endpoint.h>
#include "kernel/glo.h"

/*===========================================================================*
  *                                do_trapcount                                  *
  *===========================================================================*/
int do_trapcount(struct proc *caller_ptr, message *m_ptr)
{
    m_ptr->m_m1.m1ull1 = trap_counts; 
    return(OK);
}