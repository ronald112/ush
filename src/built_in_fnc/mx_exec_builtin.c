#include "ush.h"

int mx_exec_builtin(int cmd_ind, t_pargs *pargs) {
    switch (cmd_ind) {
    case 1: //fallthrough
        return mx_exit(pargs);
    case 2: //fallthrough
        return mx_cd(pargs);
    case 3: //fallthrough
        return mx_env(pargs);
    case 4: //fallthrough
        return mx_pwd(pargs);
    case 5:
        return mx_which(pargs);
    default:
        break;
    }
    return -1;
}
