#pragma once

#include "structures.h"

// Show u$h prompt in terminal
void mx_show_prompt(void);
// Read and save input, return value 0 - no CTRL + D, 1 - Yes
int mx_read_input(t_ush *main_ush);
// Separate src_str by delim
char *mx_strsep(char **src_str, char *delim);
// Make separate arguments from input str
void mx_istr_to_args(t_ush *main_ush);
