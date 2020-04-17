#pragma once

#include "defines.h"

typedef struct {
    char *i_hist[MAX_HIST_BUF + 1];
    char i_str[MAX_LNG_LINE + 1];
    char *parsed_args[MAX_HIST_BUF + 1];
    int nm;
} t_ush;
