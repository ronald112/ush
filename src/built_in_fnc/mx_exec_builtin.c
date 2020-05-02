#include "ush.h"

int mx_exec_builtin(int cmd_ind, t_pargs *args) {
    switch (cmd_ind) {
    case 1: //fallthrough
        exit(0);
    case 2: //fallthrough
        mx_ch_dir(args);
        return 0;
    default:
        break;
    }
    return 0;
}
