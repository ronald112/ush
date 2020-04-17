#include "ush.h"

void mx_read_input(t_ush *main_ush) {
    if(fgets(main_ush->i_str, sizeof(main_ush->i_str), stdin) == NULL) {
        perror("input error");
        exit(errno);
    }
    if (main_ush->i_str[strlen(main_ush->i_str) - 1] == '\n') {
        main_ush->i_str[strlen(main_ush->i_str) - 1] = '\0';
    }
}
