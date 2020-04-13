#include "ush.h"

int main() {
    char input_history[MAX_HIST_BUF] = "\0";
    char *input = NULL;

    while (1) {
        mx_show_prompt();
        mx_read_input(&input);

        if (input == NULL) {
            printf("\n");
            exit(0);
        }
        printf("%s", input);
    }

    printf("Success!\n");
    return 0;
}
