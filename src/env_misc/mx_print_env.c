#include "ush.h"

int mx_print_env(void) {
    for (int i = 0; environ[i]; ++i) {
        printf("%s\n", environ[i]);
    }
    return 3;
}
