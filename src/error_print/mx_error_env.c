#include "ush.h"

void mx_error_env(bool flags[3], char *args[MAX_ARGS], int er_case) {
    if (er_case == 0)
        mx_env_val_args(args);
    else if (er_case == 1)
        fprintf(stderr, "");
}
