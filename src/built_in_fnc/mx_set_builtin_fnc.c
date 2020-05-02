#include "ush.h"

char **mx_set_builtin_fnc() {
    char **own_cmds = (char **)malloc(sizeof(char *));

    own_cmds[0] = (char *)malloc(MAX_LNG_LINE * sizeof(char));
    own_cmds[0] = "exit";
    return own_cmds;
}
