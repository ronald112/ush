#include "ush.h"

static void mx_set_args(t_ush *ush, char *str) {
    if (str) {
        t_semicomm *cur_comm = ush->p_args;
        t_pargs *cur_args = NULL;
        int i = 0;

        for (; cur_comm->next; cur_comm = cur_comm->next);
        for (cur_args = cur_comm->sargs; cur_args->next; cur_args = cur_args->next);
        for (; cur_args->args[i] != NULL; ++i);
        cur_args->args[i] = str;
    }
}

void mx_add_semicolon(t_ush *ush) {
    char *str_point = &ush->lhist_str->i_str[0];
    char *result = mx_strsep(&str_point, " ");

    mx_pbsemicomm(ush);
    mx_pbargs(ush);
    mx_set_args(ush, result);
    while (result) {
        result = mx_strsep(&str_point, " ");
        if (!result)
            break;
        else if (strcmp(result, ";") == 0) {
            mx_pbsemicomm(ush);
            mx_pbargs(ush);
        }
        else if (strcmp(result, "|") == 0) {
            mx_pbargs(ush);
        }
        else
            mx_set_args(ush, result);
    }
}

void mx_istr_to_args(t_ush *ush) {
    mx_add_semicolon(ush);
}
