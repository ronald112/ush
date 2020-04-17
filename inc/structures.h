#pragma once

#include "defines.h"

typedef struct s_history {
    char i_str[MAX_LNG_LINE];
    struct s_history *next;
}              t_history;


typedef struct s_command {
    bool pipe;
    char *parsed_args[MAX_ARGS];
    struct s_command *next;
}              t_command;

typedef struct {
    char *sep_comm[MAX_HIST_BUF];
    t_history *i_struct;
    t_command *p_args;
} t_ush;
