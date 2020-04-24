#include "ush.h"

int mx_semicolon_check(t_ush *ush) {
    int i = 0;
    int index = 0;

    for (; i < MAX_LNG_LINE - 1; ++i) {
        if (ush->lhist_str->i_str[i] == ';') {
            index = i;
            break;
        }
    }
    return index;
}
