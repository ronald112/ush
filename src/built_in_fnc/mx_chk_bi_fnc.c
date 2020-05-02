#include "ush.h"

int mx_chk_bi_fnk(char *str) {
    char **own_cmds = mx_set_builtin_fnc();
    int i = 0;

    for (; own_cmds[i]; ++i) {
        if (strcmp(own_cmds[i], str) == 0)
            return i + 1;
    }
    return 0;
}
