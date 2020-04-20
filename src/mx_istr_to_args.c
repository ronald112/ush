#include "ush.h"

// Check i_str for ';' character and return index on it
static int semicolon_check(t_ush *main_ush) {
    int i = 0;
    int index = 0;

    for (; i < MAX_LNG_LINE - 1; ++i) {
        if (main_ush->i_struct->i_str[i] == ';') {
            index = i;
            break;
        }
    }
    return index;
}

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
