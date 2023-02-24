#include "../inc/header.h"

int countWords(const char *str, bool (*check)(char)) {
    int count = 0;
    int is_blank = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (check(str[i]) && is_blank == 0) {
            count++;
            is_blank = 1;
        }
        else if (!check(str[i]) && is_blank == 1) {
            is_blank = 0;
        }
    }

    if (is_blank == 0) {
        count++;
    }

    return count;
}


