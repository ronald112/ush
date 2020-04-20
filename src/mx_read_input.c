#include "ush.h"

int mx_read_input(t_ush *main_ush) {
    int exit_status = 0;

    mx_push_front_char(main_ush);
    main_ush->hist_count += 1;
    if(fgets(main_ush->lhist_str->i_str, sizeof(main_ush->lhist_str->i_str), stdin) == NULL) {
        exit_status = 1;
    }
    if (main_ush->lhist_str->i_str[strlen(main_ush->lhist_str->i_str) - 1] == '\n') {
        main_ush->lhist_str->i_str[strlen(main_ush->lhist_str->i_str) - 1] = '\0';
    }
    return exit_status;
}
