#include "ush.h"

void mx_env_usage(char illegal_opt) {
    fprintf(stderr, "env: illegal option -- %c\n"
            "usage: env [-i] [-P utilpath] [-u name]\n"
            "           "
            "[name=value ...] [utility [argument ...]]\n", illegal_opt);
}
