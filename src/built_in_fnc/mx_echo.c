#include "ush.h"

int mx_echo(t_pargs *pargs) {
    if (pargs->args[1])
        printf("%s", pargs->args[1]);
    return 6;
}
