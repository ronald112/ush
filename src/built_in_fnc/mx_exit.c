#include "ush.h"

int mx_exit(t_pargs *pargs) {
    if (pargs->args[2]) {
        fprintf(stderr, "exit: too many arguments\n");
        return 0;
    }
    else if (pargs->args[1]) {
        if (mx_is_nb_in_str(pargs->args[1])) {
            exit(mx_atoi(pargs->args[1]));
        }
        else {
            fprintf(stderr,
                    "zsh: bad math expression: operator expected at `%s'\n",
                    pargs->args[1]);
            exit(EXIT_SUCCESS);
        }
    }
    else
        exit(EXIT_SUCCESS);
    return 0;
}
