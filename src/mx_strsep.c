#include "ush.h"

char *mx_strsep(char **src_str, char *delim) {
    char *first_char = *src_str;

    if (first_char) {
        for (; *src_str != '|' && *src_str != '\0'
             && *src_str != NULL; *src_str++);
        if (**src_str)
            *(*src_str)++ = '\0';
        else
            *src_str = 0;
    }
    return first_char;
}
