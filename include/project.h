#ifndef __PROJECT_H__
#define __PROJECT_H__

#include <sys/cdefs.h>
#include <sys/featuretest.h>
#include <sys/types.h>

int get_trap_count(u_int64_t* trap_count_ptr);
int reset_trap_count();
int get_msg_count(u_int64_t* msg_count_ptr);
int reset_msg_count();

#endif /* __PROJECT_H__ */