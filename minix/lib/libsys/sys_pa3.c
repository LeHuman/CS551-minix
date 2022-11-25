#include "syslib.h"

int sys_niceto(uint64_t process_id) {
    message m;
    m.m_m1.m1ull1 = process_id;
    return (_kernel_call(SYS_NICETO, &m));
}
int sys_morecache(uint64_t increment_value) {
    message m;
    m.m_m1.m1ull1 = increment_value;
    return(_syscall(VFS_PROC_NR, VFS_ADD_BUF, &m));
    // return (_kernel_call(SYS_MORECACHE, &m));
}
int sys_morezone(uint64_t blocks_per_zone) {
    message m;
    m.m_m1.m1ull1 = blocks_per_zone;
    return(_syscall(VFS_PROC_NR, VFS_ADD_ZONE, &m));
    // return (_kernel_call(SYS_MOREZONE, &m));
}