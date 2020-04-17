#include "ush.h"

int main() {
    t_ush *main_ush = (t_ush *)malloc(sizeof(t_ush));

    while (1) {
        mx_show_prompt();
        mx_read_input(main_ush);

    }

    printf("Success!\n");
    return 0;
}
