#include "ush.h"

static void clean_args(t_semicomm *cur_semi) {
    t_pargs *cur = cur_semi->sargs;
    t_pargs *next = NULL;

    while (cur) {
        next = cur->next;
        for (int i = 0; cur->args[i]; ++i)
            free(cur->args[i]);
        free(cur);
        cur = next;
    }
    cur_semi->sargs = NULL;
}

void mx_clean_ush(t_ush *ush) {
    t_semicomm *cur = ush->p_args;
    t_semicomm *next = NULL;

    while (cur ) {
        clean_args(cur);
        next = cur->next;
        free(cur);
        cur = next;
    }
    ush->p_args = NULL;
}
