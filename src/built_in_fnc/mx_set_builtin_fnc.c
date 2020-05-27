#include "ush.h"

char **mx_set_builtin_fnc() {
    char **own_cmds = (char **)malloc((BUILTIN_FNC + 1) * sizeof(char *));

    own_cmds[0] = "exit";
    own_cmds[1] = "cd";
    own_cmds[2] = "env";
    own_cmds[3] = "pwd";
    own_cmds[4] = "which";
    own_cmds[5] = "echo";
    own_cmds[BUILTIN_FNC] = NULL;
    return own_cmds;
}
