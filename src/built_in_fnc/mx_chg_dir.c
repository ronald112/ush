#include "ush.h"

static void exec_chdir(bool flags[4], char *args[MAX_ARGS]) {
    if (flags[3])
        mx_exec_cd_flag3();
    else if (flags[2])
        mx_exec_cd_flag2();
    else if (flags[1] || flags[0])
        mx_exec_cd_flag1(flags[0], flags[1], args[2]);
    else
        mx_exec_cd_flag_else(args[1]);
}

static void chk_flag_and_args(char *args[MAX_ARGS]) {
    bool flags[4] = {0, 0, 0, 0};

    for (int i = 1; args[i]; ++i) {
        if (strcmp("-sP", args[i]) == 0 || strcmp("-Ps", args[i]) == 0) {
            flags[0] = 1;
            flags[1] = 1;
        }
        else if (strcmp("-s", args[i]) == 0)
            flags[0] = 1;
        else if (strcmp("-P", args[i]) == 0)
            flags[1] = 1;
        else if (strcmp("~", args[i]) == 0)
            flags[2] = 1;
        else if (strcmp("-", args[i]) == 0)
            flags[3] = 1;
    }
    mx_error_cd(flags, args);
    exec_chdir(flags, args);
}

int mx_cd(t_pargs *pargs) {
    if (pargs->args[1])
        chk_flag_and_args(pargs->args);
    else
        mx_exec_cd_flag2();
    return 2; // 2 - SUCCESS
}
