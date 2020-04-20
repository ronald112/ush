#include "ush.h"

int mx_semicolon_check(t_ush *main_ush) {
    int i = 0;
    int index = 0;

    for (; i < MAX_LNG_LINE - 1; ++i) {
        if (main_ush->lhist_str->i_str[i] == ';') {
            index = i;
            break;
        }
    }
    return index;
}
