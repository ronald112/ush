#include "ush.h"

int mx_read_input(t_ush *main_ush) {
    int exit_status = 0;

    mx_push_front_char(main_ush);
    if(fgets(main_ush->i_str, sizeof(main_ush->i_struct->i_str), stdin) == NULL) {
        exit_status = 1;
    }
    if (main_ush->i_str[strlen(main_ush->i_str) - 1] == '\n') {
        main_ush->i_str[strlen(main_ush->i_str) - 1] = '\0';
    }
    return exit_status;
}
