#include "ush.h"

void mx_push_front_char(t_ush *main_ush) {
    if (main_ush) {
        if (main_ush->lhist_str) {
            t_history *temp = (t_history *)malloc(sizeof(t_history));

            temp->next = main_ush->lhist_str;
            main_ush->lhist_str = temp;
        }
        else {
            main_ush->lhist_str = (t_history *)malloc(sizeof(t_history));
            main_ush->lhist_str->next = NULL;
        }
    }
}
