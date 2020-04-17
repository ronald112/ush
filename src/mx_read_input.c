#include "ush.h"

void mx_read_input(t_ush *main_ush) {
    if(fgets(main_ush->, sizeof(*input_main), stdin) == NULL)
        break;
}
