#include "ush.h"

char *mx_strsep(char **src_str, char *delim) {
    char *first_char = *src_str;

    if (first_char) {
        *src_str += strcspn(*src_str, delim);
        if (**src_str)
            *(*src_str)++ = '\0';
        else
            *src_str = 0;
    }
    return first_char;
}
