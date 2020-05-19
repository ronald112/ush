#include "ush.h"

static void set_init_variables(t_env *my_env) {
    my_env->flags[0] = 0;
    my_env->flags[1] = 0;
    my_env->flags[2] = 0;
    for (int i = 0; i < MAX_ARGS; ++i)
        my_env->new_envs[i] = NULL;
    my_env->bin_path = NULL;
    my_env->new_path = NULL;
    my_env->sucsess = 0;
}

static void dash_chk(char *args[MAX_ARGS], t_env *my_env) {
    if (args[my_env->a_ind][0] == '-') {

    }
    else {
        
    }
}

static void set_my_env(char *args[MAX_ARGS], t_env *my_env) {
    for(my_env->a_ind = 1; args[my_env->a_ind]; ++my_env->a_ind) {

    }
}

t_env *mx_env_init(t_pargs *pargs) {
    t_env *my_env = malloc(sizeof(t_env));

    set_init_variables(my_env);
    set_my_env(pargs->args, my_env);

    return my_env;
}
