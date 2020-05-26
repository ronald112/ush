#include "ush.h"

void mx_env_print_all_env(void) {
    for (int i = 0; environ[i]; ++i) {
        printf("%s\n", environ[i]);
    }
}

static void env_success_chk(t_env *my_env) {
    if (my_env->flags[1] && (mx_strlen(my_env->new_path) == 0)) {
        mx_env_usage('P', 2);
        my_env->success = 0;
    }
    if (my_env->flags[2]) {
        int size = 0;

        for (int i = 0; my_env->uns_envs[i]; ++i)
            size += mx_strlen(my_env->uns_envs[i]);
        if (size == 0) {
            mx_env_usage('u', 2);
            my_env->success = 0;
        }
    }
}

// DEBUG
static void dbg_print_env_struct(t_env *my_env) {
    printf("\nbool flags\n");
    for (int i = 0; i < 3; ++i)
        printf("%d ", my_env->flags[i]);
    printf("\nbin path\n");
    for (int i = 0; my_env->bin_path[i]; ++i)
        printf("[%s] ", my_env->bin_path[i]);
    printf("\nnew_envs\n");
    for (int i = 0; my_env->new_envs[i]; ++i)
        printf("[%s] ", my_env->new_envs[i]);
    if (my_env->new_path)
        printf("\nnew path\n%s\n", my_env->new_path);
    printf("\nuns_envs\n");
    for (int i = 0; my_env->uns_envs[i]; ++i)
        printf("[%s] ", my_env->uns_envs[i]);
    printf("\na_ind: %d\n", my_env->a_ind);
    printf("n_ind: %d\n", my_env->n_ind);
    printf("flag_ind: %d\n", my_env->flag_ind);
    printf("success: %d\n", my_env->success);
}

int mx_env(t_pargs *pargs) {
    if (pargs->args[1]) {
        t_env *my_env = mx_env_init(pargs);

        if (DBG_MESSAGE_VISIBLE == 1)
            dbg_print_env_struct(my_env);
        env_success_chk(my_env);
        if (my_env->success)
            mx_env_exec(my_env);
        mx_env_free(my_env);
        free(my_env);
    }
    else {
        mx_env_print_all_env();
    }
    return 3;
}
