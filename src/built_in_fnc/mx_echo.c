#include "ush.h"

static void flags_check(char *args[MAX_ARGS], bool flags[3]) {
    bool status = 0;
    bool success = 1;

    for (int i = 1; args[1][i]; ++i) {
        if (args[1][i] == 'n') {
            flags[0] = 1;
            status = 1;
        }
        else if (args[1][i] == 's') {
            flags[1] = 1;
            status = 1;
        }
        else {
            // echo_error(args[1][i]);
            success = 0;
            break;
        }
    }
    // if (success)
        // echo_exec(args, flags, status);
}

int mx_echo(t_pargs *pargs) {
    bool flags[3] = {0, 0, 0};

    if (pargs->args[1] && pargs->args[1][0] == '-')
        flags_check(pargs->args, flags);
    // else
        // echo_exec(pargs->args, flags, 0);
    return 6;
}
