#include "ush.h"

void mx_error_cd(bool flags[], char **args) {
    for (int i = 0; i < 4; ++i) {
        if (flags[i] == true)
            if (args[4]) {
                fprintf(stderr, "cd: too many arguments\n");
                return;
            }
    }
    if (args[3]) {
        fprintf(stderr, "cd: too many arguments\n");
        return;
    }
}
