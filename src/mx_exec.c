#include "ush.h"

static void exec_pipe(t_pargs *tmp_j) {
    printf("pipe\n");
    for (; tmp_j; tmp_j = tmp_j->next) {
        for (int i = 0; tmp_j->args[i] != NULL; ++i) {
            printf("[[%s]]\n", tmp_j->args[i]);
        }
    }
}

static void exec_builtin(t_pargs *tmp_j, int *pid_status) {
    pid_t pid = fork();

    if (pid == 0) {
        signal(SIGINT, SIG_DFL);
        if (execvp(tmp_j->args[0], tmp_j->args) < 0) {
            perror(tmp_j->args[0]);
        }
        return;
    }
    else {
        waitpid(pid, pid_status, WUNTRACED);
        return;
    }
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
            exec_builtin(tmp_j, pid_stat);
        }
    }
}
