#include "ush.h"

static void set_abs_path(char *old_pwd) {
    char dir[1000];
    printf("dbg abs\n");

    getcwd(dir, 1000);
    setenv("OLDPWD", old_pwd, 1);
    setenv("PWD", dir, 1);
}

void set_previous_path(char *old_pwd) {
    int i = mx_strlen(old_pwd);
    char *new_path = NULL;

    for (; i > 0 && old_pwd[i] != '/'; --i);
    new_path = mx_strndup(old_pwd, i + 1);
    setenv("OLDPWD", old_pwd, 1);
    setenv("PWD", new_path, 1);
    free(new_path);
}

void mx_upd_env_path(char *new_path) {
    char *old_pwd = mx_strdup(getenv("PWD"));
    char *new_pwd = NULL;

    if (new_path) {
        if (strcmp(new_path, "..") == 0)
            set_previous_path(old_pwd);
        else if (strcmp(new_path, ".") == 0)
            setenv("OLDPWD", old_pwd, 1);
        else {
            if (strcmp(old_pwd, "/") == 0) 
                new_pwd = mx_strjoin(old_pwd, new_path);
            else
                new_pwd = mx_addstr(mx_strjoin( old_pwd, "/"), new_path);
            setenv("OLDPWD", old_pwd, 1);
            setenv("PWD", new_pwd, 1);
        }
    }
    else
        set_abs_path(old_pwd);
    free(old_pwd);
    free(new_pwd);
}

void mx_swap_env_path(void) {
    char *old_pwd = mx_strdup(getenv("OLDPWD"));
    char *new_pwd = mx_strdup(getenv("PWD"));
    printf("dbg swap\n");

    setenv("OLDPWD", new_pwd, 1);
    setenv("PWD", old_pwd, 1);
    free(new_pwd);
    free(old_pwd);
}
