#include "../inc/header.h"

char *fileToStr(const char *filename) {
    if(filename == NULL) {
        return NULL;
    }

    int fd = open(filename, O_RDONLY);

    if(fd == -1) {
        return NULL;
    }

    char buffer[1];
    int len = 0;

    while(read(fd, buffer, 1) > 0) {
        len++;
    }

    if(close(fd) == -1) {
        return NULL;
    }

    fd = open(filename, O_RDONLY);

    if(fd == -1) {
        return NULL;
    }

    char *str = mx_strnew(len);

    for(int i = 0; read(fd, buffer, 1) > 0; i++) {
        str[i] = buffer[0];
    }

    if(close(fd) == -1) {
        return NULL;
    }

    return str;
}


