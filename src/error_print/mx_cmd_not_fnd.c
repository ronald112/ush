#include "ush.h"

void mx_cmd_not_fnd(char *str) {
    mx_printerr("u$h: command not found: ");
    mx_printerr(str);
    mx_printerr("\n");
}
