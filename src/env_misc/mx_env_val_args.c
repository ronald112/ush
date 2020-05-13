#include "ush.h"

void mx_env_val_args(char *args[MAX_ARGS]) {
    char *arg = NULL;

    for (unsigned int i = 1; args[i]; ++i) {
        for (unsigned int j = 0; args[i][j]; ++j) {
            if ((args[i][j] == '=') && (j == 0)) {
                fprintf(stderr, "ush: %s not found\n", args[i]);
                return;
            }
        }
    }
}
