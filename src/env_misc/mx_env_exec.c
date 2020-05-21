#include "ush.h"

static void env_clean(t_env *my_env) {
    if (my_env->flags[0]) {
        for (int i = mx_env_get_size(NULL) - 1; i >= 0; --i) {
            char *unset = mx_env_get_name(environ[i]);

            unsetenv(unset);
            free(unset);
        }
    }
}

static void env_unset(t_env *my_env) {
    if (my_env->flags[2]) {
        for (int i = 0; i < mx_env_get_size(my_env->uns_envs); ++i) {
            unsetenv(my_env->uns_envs[i]);
        }
    }
}

static void env_execute(t_env *my_env) {
    if (my_env->flags[1]) {
        execvP(my_env->bin_path[0], my_env->new_path, my_env->bin_path);
        fprintf(stderr, "%s\n", strerror(errno));
        exit(errno);
    }
    else if (my_env->bin_path[0] && (mx_strlen(my_env->bin_path[0]) > 0)) {
        execvp(my_env->bin_path[0], my_env->bin_path);
        fprintf(stderr, "%s\n", strerror(errno));
        exit(errno);
    }
}

static void env_set_names(t_env *my_env) {
    for (int i = 0; i < mx_env_get_size(my_env->new_envs); ++i) {
        putenv(my_env->new_envs[i]);
    }
}

void mx_env_exec(t_env *my_env) {
    int pid_status;
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "%s\n", strerror(errno));
        exit(errno);
    }
    else if (pid == 0) {
        env_clean(my_env);
        env_unset(my_env);
        env_set_names(my_env);
        env_execute(my_env);
        exit(errno);
    }
    else {
        waitpid(pid, &pid_status, WUNTRACED);
    }
    return;
}
