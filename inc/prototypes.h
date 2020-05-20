#pragma once

#include "ush.h"

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
char **mx_set_builtin_fnc(void);
// execute builtin commands
int mx_exec_builtin(int cmd_ind, t_pargs *pargs);
// error case command not found
void mx_cmd_not_fnd(char *str);
// change current directory
int mx_ch_dir(t_pargs *pargs);
// cd error handler
void mx_error_cd(bool flags[], char **args);
// exit command main function
int mx_exit(t_pargs *pargs);
// env command main function
int mx_env(t_pargs *pargs);
// upd PATH variable in environ for cur process
void mx_upd_env_path(char *new_path);
// swap PWD and OLDPWD in environ variable
void mx_swap_env_path(void);
// main execute "-" for cd
void mx_exec_cd_flag3(void);
// main execute HOME case for cd
void mx_exec_cd_flag2(void);
// main execute -sP flag for cd
void mx_exec_cd_flag1(bool flg_s, bool flg_P, char *path);
// common use of cd and ".."
void mx_exec_cd_flag_else(char *path);
// unset one of the environ variables
void mx_env_unset(char *args[MAX_ARGS]);
// free object of t_env struct
void mx_env_free(t_env *my_env);
// initialize object of t_env struct
t_env *mx_env_init(t_pargs *pargs);
// 
bool mx_env_name_var(char *arg);
// 
void mx_env_P_set(char *args[MAX_ARGS], t_env *my_env);
// 
void mx_env_u_set(char *args[MAX_ARGS], t_env *my_env);
// 
void mx_env_usage(char illegal_opt);
// 
void mx_flag_dash(char *args[MAX_ARGS], t_env *my_env);
