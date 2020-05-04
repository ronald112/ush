#include "ush.h"

static void exec_pipe(t_pargs *tmp_j) {
    printf("pipe\n");
    for (; tmp_j; tmp_j = tmp_j->next) {
        for (int i = 0; tmp_j->args[i] != NULL; ++i) {
            printf("[[%s]] [%d]\n", tmp_j->args[i], i);
        }
    }
}

static void exec_no_builtin_no_pipe(t_pargs *tmp_j, int *pid_status) {
    pid_t pid = fork();

    signal(SIGINT, SIG_DFL);
    if (pid == 0) {
        if (execvp(tmp_j->args[0], tmp_j->args) < 0)
            mx_cmd_not_fnd(tmp_j->args[0]);
        exit(errno);
    }
    else
        waitpid(pid, pid_status, WUNTRACED);
}

static void exec_no_pipe(t_pargs *tmp_j, int *pid_status) {
    int builtin_rslt = 0;

    errno = 0;
    if ((builtin_rslt =  mx_chk_bi_fnk(tmp_j->args[0])) > 0) {
        if (mx_exec_builtin(builtin_rslt, tmp_j) < 0)
            mx_cmd_not_fnd(tmp_j->args[0]);
    }
    else if (builtin_rslt < 0)
        exec_no_builtin_no_pipe(tmp_j, pid_status);
}

void mx_execution(t_ush *ush, int *pid_stat) {
    t_semicomm *tmp_i = ush->p_args;
    t_pargs *tmp_j = NULL;

    for (; tmp_i; tmp_i = tmp_i->next) {
        tmp_j = tmp_i->sargs;

        if (tmp_j->next) {
            exec_pipe(tmp_j);
        }
        else {
            exec_no_pipe(tmp_j, pid_stat);
        }
    }
}
