#include "ush.h"

int main() {
    char input[1000] = "\0";

    while (1) {
        mx_show_prompt();
        mx_read_input(input);

        if (strcmp(input, "exit") == 0)
            exit(0);
        printf("%s", input);
    }
    printf("Success!\n");
    return 0;
}
