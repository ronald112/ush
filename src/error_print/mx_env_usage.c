#include "ush.h"

void mx_env_usage(char illegal_opt, int err_case) {
    if (err_case == 1) {
        fprintf(stderr, "env: illegal option -- %c\n"
                , illegal_opt);
    }
    else if (err_case == 2) {
        fprintf(stderr, "env: option requires an argument -- %c\n"
                , illegal_opt);
    }
    fprintf(stderr, 
            "usage: env [-i] [-P utilpath] [-u name]\n"
            "           "
            "[name=value ...] [utility [argument ...]]\n");
}
