#include "ush.h"

static void clean_args(t_ush *ush) {
    t_pargs *cur = ush->p_args->sargs;
    t_pargs *next = NULL;

    while (cur) {
        next = cur->next;
        free(cur);
        cur = next;
    }
    ush->p_args->sargs = NULL;
}

void mx_clean_ush(t_ush *ush) {
    t_semicomm *cur = ush->p_args;
    t_semicomm *next = NULL;

    while (cur ) {
        clean_args(ush);
        next = cur->next;
        free(cur);
        cur = next;
    }
    clean_args(ush);
    ush->p_args = NULL;
}
