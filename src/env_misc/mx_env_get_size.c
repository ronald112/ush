#include "ush.h"

int mx_env_get_size(char **arr) {
    if (arr == NULL) {
        int size = 0;

        for (; environ[size]; ++size);
        return size;
    }
    else {
        int size = 0;

        for (; arr[size]; ++size);
        return size;
    }
}
