#include "ush.h"

void mx_error_cd(bool flags[], char **args) {
    int chk_arg = 3;

    for (int i = 0; i < 4; ++i)
        if (flags[i] == true)
            chk_arg++;
    if (args[chk_arg]) {
        fprintf(stderr, "cd: too many arguments\n");
        return;
    }
}
