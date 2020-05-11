#include "ush.h"

static void print_env(void) {
    for (int i = 0; environ[i]; ++i) {
        printf("%s\n", environ[i]);
    }
}

static void chk_flags(char *args) {

}

static void exec_env(char *args) {
    bool flags[3] = {0, 0, 0};

    for(int i = 1; args[i]; ++i) {
        if (strcmp(args[i], "i") == 0)
            flags[0] = 1;
        else if (strcmp(args[i], "-P") == 0)
            flags[1] = 1;
        else if (strcmp(args[i], "-u") == 0)
            flags[2] = 1;
    }
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
