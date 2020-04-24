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
// Check i_str for ';' character and return index on it
int mx_semicolon_check(t_ush *ush);
// create or push at the begining new node
void mx_pfhistory(t_ush *ush);
// 
void mx_pbsemicomm(t_ush *ush);
// 
void mx_pfsemicomm(t_ush *ush);
// 
void mx_pbargs(t_ush *ush);
// Clean temp list's in ush
void mx_clean_ush(t_ush *ush);
