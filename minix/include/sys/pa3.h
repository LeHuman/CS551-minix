#ifndef _PA3_H_
#define _PA3_H_

#include <sys/types.h>

int increase_system_priority(unsigned long long int priority, int endpoint);
int increase_user_priority(unsigned long long int priority);
int increase_cache(unsigned long long int increment_value);
int increase_zone(unsigned long long int blocks_per_zone);
#endif // _PA3_H_