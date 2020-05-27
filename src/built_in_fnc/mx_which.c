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

static void which_error(char c) {
    fprintf(stderr, "which: illegal option -- %c\n", c);
}

static void flags_check(char *args[MAX_ARGS], bool flags[2]) {
    bool status = 0;
    bool success = 1;

    for (int i = 1; args[1][i]; ++i) {
        if (args[1][i] == 'a') {
            flags[0] = 1;
            status = 1;
        }
        else if (args[1][i] == 's') {
            flags[1] = 1;
            status = 1;
        }
        else {
            which_error(args[1][i]);
            success = 0;
            break;
        }
    }
    if (success)
        which_exec(args, flags, status);
}

int mx_which(t_pargs *pargs) {
    bool flags[2] = {0, 0};

    if (pargs->args[1] && pargs->args[1][0] == '-')
        flags_check(pargs->args, flags);
    else
        which_exec(pargs->args, flags, 0);
    return 5;
}
