#include "ush.h"

bool mx_env_name_var(char *arg) {
    for (int i = 0; arg[i]; ++i) {
        if (arg[i] == '=')
            return 1;
    }
    return 0;
}
