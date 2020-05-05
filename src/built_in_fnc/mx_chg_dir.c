#include "ush.h"

static void home_dir(void) {
    int result = chdir(getenv("HOME"));
    char *newdir = getenv("HOME");

    if (result < 0) {
        if (newdir == NULL)
            fprintf(stderr, "cd: HOME not set\n");
        else {
            fprintf(stderr, "cd: %s: ", newdir);
            perror("");
        }
    }
}

static void exec_chdir(bool flags[4], char **args) {
    if (flags[3]) {
        if (chdir(getenv("OLDPWD")) < 0)
            fprintf(stderr, "cd: no such file or directory: /PWD\n");
    }
    else {
        if (chdir(args[1]) < 0)
            fprintf(stderr, "cd: no such file or directory: %s\n", args[1]);
    }
}

static void chk_flag_and_args(char **args) {
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

int mx_ch_dir(t_pargs *pargs) {
    if (!pargs->args[1])
        home_dir();
    else if (pargs->args[1]) {
        chk_flag_and_args(pargs->args);
        
    }

    return 2; // 2 - SUCSESS
}
