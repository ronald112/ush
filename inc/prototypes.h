#pragma once

#include "structures.h"

// Show u$h prompt in terminal
void mx_show_prompt(void);
// Read and save input, return value 0, 1 (pressed CTRL + D)
int mx_read_input(t_ush *ush);
// Separate src_str by delim
char *mx_strsep(char **src_str, char *delim);
// Make separate arguments from input str
void mx_istr_to_args(t_ush *ush);
// create or push at the begining new node
void mx_pfhistory(t_ush *ush);
// push back command separated by ;
void mx_pbsemicomm(t_ush *ush);
// push front command separated by ;
void mx_pfsemicomm(t_ush *ush);
// push back args
void mx_pbargs(t_ush *ush);
// push front args
void mx_pfargs(t_ush *ush);
// Clean temp list's in ush
void mx_clean_ush(t_ush *ush);
// main execution fnc
void mx_execution(t_ush *ush, int *pid_stat);
// check if the str is built in fnc
int mx_chk_bi_fnk(char *str);
// crt the list of built in functions
char **mx_set_builtin_fnc();
// 
int mx_exec_builtin(int cmd_ind);
// 
void mx_cmd_not_fnd(char *str);
