#include "ush.h"

char *mx_env_get_name(char *env_str) {
    char *name_res = NULL;

    for (int i = 0; env_str[i]; ++i) {
        if (env_str[i] == '=') {
            name_res = mx_strndup(env_str, i);
            return name_res;
        }
    }
    return name_res;
}

bool mx_env_name_var(char *arg) {
    for (int i = 0; arg[i]; ++i) {
        if (arg[i] == '=')
            return 1;
    }
    return 0;
}
