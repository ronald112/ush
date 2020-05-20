#include "ush.h"

static void set_init_variables(t_env *my_env) {
    my_env->flags[0] = false; // i
    my_env->flags[1] = false; // P
    my_env->flags[2] = false; // u
    for (int i = 0; i < MAX_ARGS; ++i) {
        my_env->new_envs[i] = NULL;
        my_env->bin_path[i] = NULL;
        my_env->uns_envs[i] = NULL;
    }
    my_env->new_path = NULL;
    my_env->a_ind = 1;
    my_env->n_ind = 0;
    my_env->u_ind = 0;
    my_env->flag_ind = 1;
    my_env->sucsess = 0;
}

static void no_dash(char *args[MAX_ARGS], t_env *my_env) {
    for (; args[my_env->a_ind]; my_env->a_ind++) {
        if (mx_env_name_var(args[my_env->a_ind])) {
            my_env->new_envs[my_env->n_ind++] = mx_strdup(args[my_env->a_ind]);
        }
        else {
            break;
        }
    }
    for (int i = 0; args[my_env->a_ind]; my_env->a_ind++)
        my_env->bin_path[i++] = mx_strdup(args[my_env->a_ind]);
}

void mx_flag_dash(char *args[MAX_ARGS], t_env *my_env) {
    if (args[my_env->a_ind][my_env->flag_ind] == 'i') {
        my_env->flags[0] = true;
        my_env->flag_ind = 2;
        if (!(args[my_env->a_ind][my_env->flag_ind])) {
            my_env->a_ind++;
            no_dash(args, my_env);
            return;
        }
    }
    if (args[my_env->a_ind][my_env->flag_ind] == 'P') {
        mx_env_P_set(args, my_env);
    }
    else if (args[my_env->a_ind][my_env->flag_ind] == 'u') {
        mx_env_u_set(args, my_env);
    }
    else {
        mx_env_usage(args[my_env->a_ind][my_env->flag_ind]);
    }
}

t_env *mx_env_init(t_pargs *pargs) {
    t_env *my_env = malloc(sizeof(t_env));

    set_init_variables(my_env);
    if (pargs->args[my_env->a_ind][0] == '-') {
        mx_flag_dash(pargs->args, my_env);
    }
    else {
        no_dash(pargs->args, my_env);
    }

    return my_env;
}
