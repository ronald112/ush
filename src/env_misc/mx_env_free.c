#include "ush.h"

void mx_env_free(t_env *my_env) {
    for (int i = 0; i < MAX_ARGS; ++i) {
        if (my_env->bin_path[i]) {
            free(my_env->bin_path[i]);
            my_env->bin_path[i] = NULL;
        }
        if (my_env->new_envs[i]) {
            free(my_env->new_envs[i]);
            my_env->new_envs[i] = NULL;
        }
        if (my_env->uns_envs[i]) {
            free(my_env->uns_envs[i]);
            my_env->uns_envs[i] = NULL;
        }
    }
    if (my_env->new_path)
        free(my_env->new_path);
    my_env->new_path = NULL;
}
