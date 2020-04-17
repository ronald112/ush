#pragma once

#include "defines.h"

typedef struct {
    bool pipe;
    char *parsed_args[MAX_HIST_BUF];
} t_command;

typedef struct {
    char i_str[MAX_LNG_LINE];
    t_history *next;
} t_history;

typedef struct {
    char *i_hist[MAX_HIST_BUF];
    char i_str[MAX_LNG_LINE];
    t_command *parsed_args;
    int nm;
} t_ush;
