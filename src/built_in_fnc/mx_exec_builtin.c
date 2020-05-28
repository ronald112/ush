#include "ush.h"

int mx_exec_builtin(int cmd_ind, t_pargs *pargs) {
    if (cmd_ind == 1)
        return mx_exit(pargs);
    else if (cmd_ind == 2)
        return mx_cd(pargs);
    else if (cmd_ind == 3)
        return mx_env(pargs);
    else if (cmd_ind == 4)
        return mx_pwd(pargs);
    else if (cmd_ind == 5)
        return mx_which(pargs);
    else if (cmd_ind == 6)
        return mx_echo(pargs);
    return -1;
}
