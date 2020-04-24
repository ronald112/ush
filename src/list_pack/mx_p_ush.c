#include "ush.h"

void mx_pbargs(t_ush *ush) {
    if (ush->p_args) {
        t_semicomm *i = ush->p_args;

        for (; i->next; i = i->next);
        if (i->sargs) {
            t_pargs *j = i->sargs;

            for (; j->next; j = j->next);
            j->next = (t_pargs *)malloc(sizeof(t_pargs));
            j->next->next = NULL;
        }
        else {
            i->sargs = (t_pargs *)malloc(sizeof(t_pargs));
            i->sargs->next = NULL;
        }
    }
}

void mx_pbsemicomm(t_ush *ush) {
    if (ush->p_args) {
        t_semicomm *tmp_semi = (t_semicomm *)malloc(sizeof(t_semicomm));
        t_semicomm *i = ush->p_args;

        tmp_semi->next = NULL;
        for (; i->next; i = i->next);
        i->next = tmp_semi;
    }
    else {
        ush->p_args = (t_semicomm *)malloc(sizeof(t_semicomm));
        ush->p_args->next = NULL;
    }
}

void mx_pfsemicomm(t_ush *ush) {
    if (ush->p_args) {
        t_semicomm *tmp_semi = (t_semicomm *)malloc(sizeof(t_semicomm));

        tmp_semi->sargs = (t_pargs *)malloc(sizeof(t_pargs));
        tmp_semi->next = ush->p_args;
        ush->p_args = tmp_semi;
    }
    else {
        ush->p_args = (t_semicomm *)malloc(sizeof(t_semicomm));
        ush->p_args->next = NULL;
        ush->p_args->sargs = (t_pargs *)malloc(sizeof(t_pargs));
        ush->p_args->sargs->next = NULL;
    }
}
