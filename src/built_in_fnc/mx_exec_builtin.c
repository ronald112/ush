#include "ush.h"

int mx_exec_builtin(int cmd_ind, t_pargs *pargs) {
    switch (cmd_ind) {
    case 1: //fallthrough
        return mx_exit(pargs);
    case 2: //fallthrough
        return mx_ch_dir(pargs);
    case 3: //fallthrough
        return mx_env(pargs);
    default:
        break;
    }
    return -1;
}
