#include "ush.h"

void mx_read_input(char **input_main) {
    size_t size = MAX_LNG_LINE;
    getline(input_main, &size, stdin);
}
