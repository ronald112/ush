#include "ush.h"

static t_ush *init_struct() {
    t_ush *main_ush = (t_ush *)malloc(sizeof(t_ush));

    main_ush->p_args = (t_command *)malloc(sizeof(t_command));
    main_ush->hist_count = 0;

    return main_ush;
}

int main() {
    t_ush *main_ush = init_struct();

    signal(SIGINT, SIG_IGN);
    while (1) {
        mx_show_prompt();
        if (mx_read_input(main_ush))
            break;
        for (t_history *temp = main_ush->lhist_str; temp && temp->next; temp = temp->next)
            printf("%s\n", temp->i_str);
        // mx_istr_to_args(main_ush);
    }
    return 0;
}
