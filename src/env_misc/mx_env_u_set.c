#include "ush.h"

static void set_start(t_env *my_env) {
    my_env->flags[2] = true;
    my_env->flag_ind++;
    return;
}

static bool is_valid_str(char *args[MAX_ARGS], t_env *my_env) {
    int i = my_env->a_ind;
    int j = my_env->flag_ind;

    if (args[i][j] && mx_env_name_var(&args[i][j])) {
        fprintf(stderr, "env: unsetenv %s: Invalid argument", &args[i][j]);
        my_env->success = 0;
        return 0;
    }
    else if (args[i + 1] && mx_env_name_var(args[i + 1])) {
        fprintf(stderr, "env: unsetenv %s: Invalid argument", args[i + 1]);
        my_env->success = 0;
        return 0;
    }
    return 1;
}

// TODO check how to move on the next line
void mx_env_u_set(char *args[MAX_ARGS], t_env *my_env) {
    if (is_valid_str(args, my_env) == 0)
        return;
    set_start(my_env);
    if (args[my_env->a_ind][my_env->flag_ind])
        my_env->uns_envs[my_env->u_ind++] = mx_strdup(&args[my_env->a_ind++][my_env->flag_ind]);
    else {
        my_env->a_ind++;
        my_env->uns_envs[my_env->u_ind++] = mx_strdup(args[my_env->a_ind++]);
    }
    if (args[my_env->a_ind] && args[my_env->a_ind][0] == '-') {
        my_env->flag_ind = 1;
        mx_flag_dash(args, my_env);
    }
    else {
        for (int i = 0; args[my_env->a_ind]; my_env->a_ind++)
            my_env->bin_path[i++] = mx_strdup(args[my_env->a_ind]);
    }
    return;
}
