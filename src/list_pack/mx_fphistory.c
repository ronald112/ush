#include "ush.h"

void mx_pfhistory(t_ush *ush) {
    if (ush) {
        if (ush->lhist_str) {
            t_history *temp = (t_history *)malloc(sizeof(t_history));

            temp->next = ush->lhist_str;
            ush->lhist_str = temp;
        }
        else {
            ush->lhist_str = (t_history *)malloc(sizeof(t_history));
            ush->lhist_str->next = NULL;
        }
    }
}
