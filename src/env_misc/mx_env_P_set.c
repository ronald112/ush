#include "ush.h"

static void init_start(t_env *my_env) {
    my_env->flags[1] = true;
    if (my_env->new_path)
        free(my_env->new_path);
    my_env->flag_ind++;
}

void mx_env_P_set(char *args[MAX_ARGS], t_env *my_env) {
    init_start(my_env);
    if (args[my_env->a_ind][my_env->flag_ind]) {
        my_env->new_path = mx_strdup(&args[my_env->a_ind++][my_env->flag_ind]);
    }
    else {
        my_env->a_ind++;
        my_env->new_path = mx_strdup(args[my_env->a_ind++]);
    }
    if (args[my_env->a_ind] && args[my_env->a_ind][0] == '-') {
        my_env->flag_ind = 1;
        mx_flag_dash(args, my_env);
    }
    else {
        for (int i = 0; args[my_env->a_ind]; my_env->a_ind++)
            my_env->bin_path[i] = mx_strdup(args[my_env->a_ind]);
    }
    return;
}
