#include "ush.h"

void mx_istr_to_args(t_ush *main_ush) {
    int i = 0;
    int j = 0;

    for (; i < MAX_LNG_LINE - 1; ++i) {
        main_ush->p_args[j].parsed_args[i] = strsep(&main_ush->i_str, " ");
        if (main_ush->p_args[j].parsed_args[i] == NULL) {
            break;
        }

    }
}
