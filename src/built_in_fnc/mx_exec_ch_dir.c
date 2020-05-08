#include "ush.h"

void mx_exec_cd_flag3(void) {
    if (chdir(getenv("OLDPWD")) < 0)
        fprintf(stderr, "cd: no such file or directory: %s\n", getenv("PWD"));
    else {
        char *pwd = mx_strdup(getenv("OLDPWD"));
        int i = 0;
        int j = 0;

        for (; pwd[i] && j <= 3; ++i)
            if (pwd[i] == '/')
                j++;
        if (j == 3)
            printf("~%s\n", &pwd[i]);
        else
            printf("%s\n", pwd);
        mx_swap_env_path();
        free(pwd);
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
        mx_upd_env_path(NULL);
}

void mx_exec_cd_flag1(char *path) {
    char *r_path = realpath(path, NULL);

    printf("%s\n", path);
    printf("r_path [%s]\n", r_path);
    free(r_path);
}

void mx_exec_cd_flag0(char *path) {
    

    printf("%s\n", path);

}

void mx_exec_cd_flag_else(char *path) {
    if (strcmp(path, "..") == 0) {
        mx_upd_env_path(path);
        if (chdir(getenv("PWD")) < 0) {
            fprintf(stderr,
                    "cd: no such file or directory: %s\n", getenv("PWD"));
        }
    }
    else {
        if (chdir(path) < 0) {
            fprintf(stderr, "cd: no such file or directory: %s\n", path);
        }
        else
            mx_upd_env_path(strcmp(path, "/") == 0 ? NULL : path);
    }
    
}
