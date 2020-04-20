#include "ush.h"

t_history *mx_push_front_char(t_ush *main_ush) {
    if (main_ush) {
        if (main_ush->i_struct) {
            t_history *temp = (t_history *)malloc(sizeof(t_history));

            temp->next = main_ush->i_struct;
            main_ush->i_struct = temp;
        }
        else {
            main_ush->i_struct = (t_history *)malloc(sizeof(t_history));
            main_ush->i_struct->next = NULL;
        }
        
    }
}
