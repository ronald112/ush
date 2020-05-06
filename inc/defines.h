#pragma once

#include "ush.h"
/*
 * 1 - exit "status"
 * 2 - cd "-s, -P, -"
 * 3 - env
 */

#define MAX_HIST_BUF 1000
#define MAX_LNG_LINE 101
#define MAX_ARGS 100
#define OWN_CMD 1
#define BUILTIN_FNC 3

    extern char **environ;

