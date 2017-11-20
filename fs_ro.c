#include "sysinc.h"
#include "module.h"
#include <mntent.h>

static int      item_timeout = 0;

int     zbx_module_fs_ro_status(AGENT_REQUEST *request, AGENT_RESULT *result);

static ZBX_METRIC keys[] =
{
        {"fs_ro.status",        0,              zbx_module_fs_ro_status,        NULL},
        {NULL}
};

int     zbx_module_api_version()
{
        return ZBX_MODULE_API_VERSION_ONE;
}

void    zbx_module_item_timeout(int timeout)
{
        item_timeout = timeout;
}

ZBX_METRIC      *zbx_module_item_list()
{
        return keys;
}

int     zbx_module_fs_ro_status(AGENT_REQUEST *request, AGENT_RESULT *result)
{
        struct mntent *m;
        FILE *f;

        SET_UI64_RESULT(result, 0);
        f = setmntent(_PATH_MOUNTED, "r");
        while ((m = getmntent(f)))
        {
                if (m->mnt_opts && !strcmp(m->mnt_type, "ext4") && hasmntopt(m, MNTOPT_RO))
                {
                        SET_UI64_RESULT(result, 1);
                        break;
                }
        }
        endmntent(f);

        return SYSINFO_RET_OK;
}

int     zbx_module_init()
{
        return ZBX_MODULE_OK;
}

int     zbx_module_uninit()
{
        return ZBX_MODULE_OK;
}
