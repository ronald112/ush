#include "ush.h"

static t_ush *init_struct() {
    t_ush *main_ush = (t_ush *)malloc(sizeof(t_ush));

    return main_ush;
}

int main() {
    t_ush *main_ush = init_struct();
    

    while (1) {
        mx_show_prompt();
        mx_read_input(main_ush);
        mx_istr_to_args(main_ush);

    }

    printf("Success!\n");
    return 0;
}
