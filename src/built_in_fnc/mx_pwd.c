#include "ush.h"

static void exec_pwd(bool flag) {
    if (flag == 1) {
        char buf[1000] = "\0";

        printf("%s\n", getcwd(buf, 1000));
    }
    else {
        printf("%s\n", getenv("PWD"));
    }
}

static void chk_flag_and_args(char *args[MAX_ARGS], bool flag) {
    if (strcmp("-P", args[1]) == 0)
        flag = 1;
    else if (strcmp("-LP", args[1]) == 0 || strcmp("-PL", args[1]) == 0)
        flag = 1;
    else if (strcmp("-L", args[1]) == 0)
        flag = 0;
    else {
        fprintf(stderr, "pwd: bad option: %s\n", args[1]);
        exit(1);
    }
    exec_pwd(flag);
}

// change if bash in reference
int mx_pwd(t_pargs *pargs) {
    int pid_stat = 0;
    bool flag = 0;
    pid_t pid;

    if ((pid = fork()) == 0) {
        if (pargs->args[2]) {
            fprintf(stderr, "pwd: too many arguments\n");
            exit(1);
        }
        else if (pargs->args[1])
            chk_flag_and_args(pargs->args, flag);
        else
            exec_pwd(flag);
        exit(0);
    }
    else
        waitpid(pid, &pid_stat, WUNTRACED);
    return 4;
}
