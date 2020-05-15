#include "ush.h"

static void print_set_env(void) {
    for (int i = 0; environ[i]; ++i) {
        printf("%s\n", environ[i]);
    }
}

int mx_env(t_pargs *pargs) {
    int str_len = 0;

    for (int i = 1; pargs->args[i]; ++i)
        str_len += mx_strlen(pargs->args[i]);
    if (pargs->args[1] && str_len) {
        t_env *my_env = mx_env_init(pargs);

        mx_env_free(my_env);
    }
    else {
        print_set_env();
    }
    
    return 3;
}
