#include "ush.h"

static void print_set_env(void) {
    for (int i = 0; environ[i]; ++i) {
        printf("%s\n", environ[i]);
    }
}

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
}

int mx_env(t_pargs *pargs) {
    int str_len = 0;

    for (int i = 1; pargs->args[i]; ++i)
        str_len += mx_strlen(pargs->args[i]);
    if (pargs->args[1] && str_len) {
        t_env *my_env = mx_env_init(pargs);

        dbg_print_env_struct(my_env);
        mx_env_free(my_env);
        free(my_env);
    }
    else {
        print_set_env();
    }
    
    return 3;
}
