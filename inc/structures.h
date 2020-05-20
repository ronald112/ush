#pragma once

#include "ush.h"

typedef struct s_history {
    char i_str[MAX_LNG_LINE];
    struct s_history *next;
}              t_history;

typedef struct s_pargs {
    char *args[MAX_ARGS];
    struct s_pargs *next;
}              t_pargs;

typedef struct s_semicomm {
    t_pargs *sargs;
    struct s_semicomm *next;
}              t_semicomm;

typedef struct {
    char *sep_comm[MAX_HIST_BUF];
    t_history *lhist_str;
    t_semicomm *p_args;
    int hist_count;
} t_ush;

typedef struct {
    bool flags[3];
    char *bin_path[MAX_ARGS];
    char *new_path;
    char *new_envs[MAX_ARGS];
    char *uns_envs[MAX_ARGS];
    int a_ind;
    int u_ind;
    int n_ind;
    int flag_ind;
    bool sucsess;

} t_env;
