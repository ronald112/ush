#include "ush.h"

void mx_cmd_not_fnd(char *str) {
    fprintf(stderr, "u$h: command not found: %s\n", str);
}
