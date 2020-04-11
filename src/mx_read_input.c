#include "ush.h"

void mx_read_input(char *input_main) {
    char *input = mx_strnew(1000);
    char *p = input;

    while ((*p++ = getchar()) != '\n');
    *p = '\0';
    p = NULL;
    strcpy(input_main, input);
    mx_strdel(&input);
}
