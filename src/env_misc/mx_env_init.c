#include "ush.h"

static void set_init_variables(t_env *my_env) {
    my_env->flags[0] = 0;
    my_env->flags[1] = 0;
    my_env->flags[2] = 0;
    for (int i = 0; i < MAX_ARGS; ++i)
        my_env->env_names[i] = NULL;
    my_env->file_name = NULL;
    my_env->search_path = NULL;
    my_env->sucsess = 0;
}

static int chk_path_str(char *args[MAX_ARGS], int i, t_env *my_env) {
    if (args[i][0] == '-' && args[i][1] == 'P') {
        my_env->flags[1] = 1;
        if (my_env->flags[0]) {
            fprintf(stderr, "env: %s: No such file or directory\n", args[i]);
            return -1;
        }
        if (my_env->search_path)
            free(my_env->search_path);
        if (args[i][2])
            my_env->search_path = mx_strdup(&args[i][2]);
        else if (args[i + 1]) {
            my_env->search_path = mx_strdup(args[i + 1]);
            return 1;
        }
        else
            my_env->search_path = NULL;
    }
    return 0;
}

static bool parse_args(int i, char *args[MAX_ARGS], t_env *my_env) {
    int rslt = 0;

    if ((rslt = strcmp(args[i], "-i")) == 0)
        my_env->flags[0] = 1;
    else if ((rslt = strcmp(args[i], "-u")) == 0)
        my_env->flags[2] = 1;
    else if ((rslt = chk_path_str(args, i, my_env)) == 1)
        i++;
    else if (rslt < 0)
        return 0;
    else {
        // check if args[i] is NAME for environ variable or just name of bin file
    }
    return 1;
}

static void set_my_env(char *args[MAX_ARGS], t_env *my_env) {
    for(int i = 1; args[i]; ++i) {
        if ((my_env->sucsess = parse_args(i, args, my_env)) == 0)
            break;
    }
}

t_env *mx_env_init(t_pargs *pargs) {
    t_env *my_env = malloc(sizeof(t_env));

    set_init_variables(my_env);
    set_my_env(pargs->args, my_env);

    return my_env;
}
