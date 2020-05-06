#include "ush.h"

void mx_upd_env_path() {
    char dir[1000];
    char *old_pwd = mx_strdup(getenv("PWD"));

    getcwd(dir, 1000);
    setenv("OLDPWD", old_pwd, 1);
    setenv("PWD", dir, 1);
    free(old_pwd);
}
