#include "ush.h"

void mx_exec_cd_flag3(void) {
    if (chdir(getenv("OLDPWD")) < 0)
        fprintf(stderr, "cd: no such file or directory: %s\n",
                getenv("PWD"));
    else {
        char pwd[1000];
        int i = 0;
        int j = 0;

        getcwd(pwd, 1000);
        for (; pwd[i] && j <= 3; ++i)
            if (pwd[i] == '/')
                j++;
        if (j == 3)
            printf("~%s\n", &pwd[i]);
        else
            printf("%s\n", pwd);
        mx_upd_env_path();
    }
}

void mx_exec_cd_flag2(void) {
    if (chdir(getenv("HOME")) < 0) {
        if (getenv("HOME") == NULL)
            fprintf(stderr, "cd: HOME not set\n");
        else {
            fprintf(stderr, "cd: %s: ", getenv("HOME"));
            perror("");
        }
    }
    else
        mx_upd_env_path();
}

void mx_exec_cd_flag0(char *path) {
    if (chdir(path) < 0) {
        fprintf(stderr,
                "cd: no such file or directory: %s\n", path);
    }
    else
        mx_upd_env_path();
}
