#include "ush.h"

static void set_args(t_ush *ush, char *str) {
    if (str) {
        t_semicomm *cur_comm = ush->p_args;
        t_pargs *cur_args = NULL;
        int i = 0;

        for (; cur_comm->next; cur_comm = cur_comm->next);
        cur_args = cur_comm->sargs;
        for (; cur_args->args[i] != NULL; ++i);
        cur_args->args[i] = mx_strdup(str);
    }
}

static char *upd_strsep(char **strt_point, char *delim) {
    char *result = NULL;

    for (char *sep = mx_strsep(strt_point, delim); sep && strlen(sep) > 0;) {
        result = mx_addstr(result, sep);
        if (result[strlen(result) - 1] == '\\') {
            result[strlen(result) - 1] = ' ';
            sep = mx_strsep(strt_point, delim);
        }
        else
            break;
    }
    return result;
}

static void convert_to_list(t_ush *ush) {
    char *strt_point = &ush->lhist_str->i_str[0];
    char *result = upd_strsep(&strt_point, " ");

    mx_pbsemicomm(ush);
    mx_pfargs(ush);
    set_args(ush, result);
    while (result) {
        free(result);
        result = upd_strsep(&strt_point, " ");
        if (!result)
            break;
        else if (strcmp(result, ";") == 0) {
            mx_pbsemicomm(ush);
            mx_pfargs(ush);
        }
        else if (strcmp(result, "|") == 0)
            mx_pfargs(ush);
        else
            set_args(ush, result);
    }
}

void mx_istr_to_args(t_ush *ush) {
    convert_to_list(ush);
}
