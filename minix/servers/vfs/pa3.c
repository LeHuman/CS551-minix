#include "fs.h"

#include <minix/com.h>

#include <minix/const.h>

#include <minix/endpoint.h>

#include <minix/u64.h>

#include <minix/vfsif.h>

#include <sys/dirent.h>

#include <sys/stat.h>

#include <sys/statvfs.h>

#include <assert.h>

#include <stddef.h>

#include <string.h>

#include <unistd.h>

#include <time.h>

#include "path.h"

#include "vmnt.h"

#include "vnode.h"

int do_add_buf(void) {
    struct vmnt *vmp;
    int r = OK;

    for (vmp = &vmnt[0]; vmp < &vmnt[NR_MNTS]; ++vmp) {
        if ((r = lock_vmnt(vmp, VMNT_READ)) != OK)
            break;
        if (vmp->m_dev != NO_DEV && vmp->m_fs_e != NONE && vmp->m_root_node != NULL) {
            message m;

            m.m_type = REQ_BUF_ADD;
            m.m_m1.m1ull1 = m_in.m_m1.m1ull1;

            r = fs_sendrec(vmp->m_fs_e, &m);
        }
        unlock_vmnt(vmp);
    }

    return (r);
}

int do_add_zone(void) {
    struct vmnt *vmp;
    int r = OK;

    for (vmp = &vmnt[0]; vmp < &vmnt[NR_MNTS]; ++vmp) {
        if ((r = lock_vmnt(vmp, VMNT_READ)) != OK)
            break;
        if (vmp->m_dev != NO_DEV && vmp->m_fs_e != NONE && vmp->m_root_node != NULL) {
            message m;

            m.m_type = REQ_ZONE_ADD;
            m.m_m1.m1ull1 = m_in.m_m1.m1ull1;

            r = fs_sendrec(vmp->m_fs_e, &m);
        }
        unlock_vmnt(vmp);
    }

    return (r);
}