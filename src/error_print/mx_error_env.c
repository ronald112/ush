#include "ush.h"

void mx_error_env(bool flags[3], char *args) {
    int chk_arg = 3;

    for (int i = 0; i < 3; ++i)
        if (flags[1] == true)
            chk_arg += 2;
        else if (flags[i] == true)
            chk_arg++;
    if (args[chk_arg]) {
        fprintf(stderr, "cd: too many arguments\n");
        return;
    }
}
