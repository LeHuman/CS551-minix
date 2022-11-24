#ifndef _PA3_H_
#define _PA3_H_

#include <sys/types.h>

int increase_system_priority(const uint32_t& priority, const endpoint_t& endpoint);
int increase_user_priority(const uint32_t& priority);
#endif // _PA3_H_