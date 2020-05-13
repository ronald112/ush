#include "ush.h"

static void print_set_env(void) {
    for (int i = 0; environ[i]; ++i) {
        printf("%s\n", environ[i]);
    }
}

static void exec_chk_flags(bool flags[3], char *args[MAX_ARGS]) {
    if (flags[0] || flags[1]) {

    }
    else if (flags[2]) {
        mx_env_unset(args);
    }
    else
        print_set_env();
}

static void exec_env(char *args[MAX_ARGS]) {
    bool flags[3] = {0, 0, 0};
    int er_case = 0;

    for(int i = 1; args[i]; ++i) {
        if (strcmp(args[i], "i") == 0)
            flags[0] = 1;
        else if (strcmp(args[i], "-P") == 0) {
            if (flags[0])
                er_case = 1;
            else
                flags[1] = 1;
        }
        else if (strcmp(args[i], "-u") == 0)
            flags[2] = 1;
    }
    mx_error_env(flags, args, er_case);
    exec_chk_flags(flags, args);
}

int mx_env(t_pargs *pargs) {
    int str_len = 0;

    for (int i = 1; pargs->args[i]; ++i)
        str_len += mx_strlen(pargs->args[i]);
    if (pargs->args[1] && str_len) {
        exec_env(pargs->args);
    }
    else {
        print_env();
    }
    return 3;
}
