#include "ush.h"

static t_ush *init_struct(void) {
    t_ush *ush = (t_ush *)malloc(sizeof(t_ush));
    // char *ush_misc = mx_strjoin(getenv("PWD"), "/ush");
    char *ush_misc = NULL;

    // setenv("SHELL", ush_misc, 1);
    // free(ush_misc);
    if ((ush_misc = getenv("SHLVL")) == NULL)
        setenv("SHLVL", "1", 1);
    else {
        setenv("SHLVL", (ush_misc = mx_itoa(mx_atoi(ush_misc) + 1)), 1);
        free(ush_misc);
    }
    ush->hist_count = 0;
    return ush;
}

int main() {
    t_ush *ush = init_struct();
    int pid_stat = 0;
    errno = 0;

    signal(SIGINT, SIG_DFL);
    while (1) {
        mx_show_prompt();
        if (mx_read_input(ush))
            break;
        //for (t_history *temp = ush->lhist_str; temp; temp = temp->next)
        //    printf("hist [%s]\n", temp->i_str);
        mx_istr_to_args(ush);
        mx_execution(ush, &pid_stat);
        mx_clean_ush(ush);
    }

    // for (t_semicomm *tmp_sc = ush->p_args; tmp_sc; tmp_sc = tmp_sc->next) {
    //     for (t_pargs *tmp_args = tmp_sc->sargs; tmp_args; tmp_args = tmp_args->next) {
    //         for (int i = 0; tmp_args->args[i] != NULL; i++)
    //             printf("%2s[%d]", tmp_args->args[i], i);
    //     }
    // }
    
    
    system("leaks -q ush");
    return errno;
}
