#include "ush.h"

int mx_read_input(t_ush *ush) {
    int exit_status = 0;

    mx_pfhistory(ush);
    ush->hist_count += 1;
    if(fgets(ush->lhist_str->i_str, sizeof(ush->lhist_str->i_str), stdin) == NULL) {
        exit_status = 1;
    }
    if (ush->lhist_str->i_str[strlen(ush->lhist_str->i_str) - 1] == '\n') {
        ush->lhist_str->i_str[strlen(ush->lhist_str->i_str) - 1] = '\0';
    }
    return exit_status;
}
