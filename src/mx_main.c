#include "ush.h"

static t_ush *init_struct() {
    t_ush *main_ush = (t_ush *)malloc(sizeof(t_ush));
    main_ush->p_args = (t_command *)malloc(sizeof(t_command));
    main_ush->i_str = (t_history *)malloc(sizeof (t_history));

    return main_ush;
}

int main() {
    t_ush *main_ush = init_struct();

    while (1) {
        mx_show_prompt();
        if (mx_read_input(main_ush))
            break;
        mx_istr_to_args(main_ush);
    }
    return 0;
}
