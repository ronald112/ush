#include "ush.h"

static void which_exec(char *args[MAX_ARGS], bool flags[2], bool status) {
    char *env_path = mx_strdup(getenv("PATH"));
    char *cp_path = env_path;
    char *str = mx_strsep(&cp_path, ":");

    for (int i = ((status == 1) ? 2 : 1); args[i]; ++i) {
        for (; str;) {
            char *symb_path = mx_addstr(mx_strjoin(str, "/"), args[i]);

            if (access(symb_path, F_OK) == 0)
                if (!flags[1])
                    printf("%s\n", symb_path);
            free(symb_path);
            str = mx_strsep(&cp_path, ":");
            if (!flags[0])
                break;
        }
    }
    free(env_path);
}

static void flags_check(char *args[MAX_ARGS], bool flags[2]) {
    bool status = 0;

    if (strcmp(args[1], "-a") == 0) {
        flags[0] = 1;
        status = 1;
    }
    else if (strcmp(args[1], "-s") == 0) {
        flags[1] = 1;
        status = 1;
    }
    else if ((strcmp(args[1], "-as") == 0) || (strcmp(args[1], "-sa") == 0)) {
        flags[0] = 1;
        flags[1] = 1;
        status = 1;
    }
    // else
        // which_error();
    which_exec(args, flags, status);
}

int mx_which(t_pargs *pargs) {
    bool flags[2] = {0, 0};

    if (pargs->args[1])
        flags_check(pargs->args, flags);
    else
        which_exec(pargs->args, flags, 0);
    return 5;
}
