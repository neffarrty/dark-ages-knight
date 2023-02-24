#include "../inc/header.h"

bool mx_isnewline(char c) {
    return c == '\n';
}

char *mx_strcat(char *s1, const char *s2) {
    int len1 = mx_strlen(s1);
    int len2 = mx_strlen(s2);
    int new_len = len1 + len2;    

    for (int i = 0; i < len2; i++) {
        s1[len1 + i] = s2[i];
    }

    s1[new_len] = '\0';

    return s1;
}

char *mx_strcpy(char *dst, const char *src) {
    int i = 0;

    while(src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';

    return dst;
}

char *mx_strdup(const char *str) {
    char *dup = mx_strnew(mx_strlen(str));

    if(dup == NULL) {
        return NULL;
    }

    return mx_strcpy(dup, str);
}

char *mx_strjoin(char const *s1, char const *s2) {
    if(s1 == NULL && s2 == NULL) {
        return NULL;
    }
    if(s1 == NULL) {
        return mx_strdup(s2);
    }
    if(s2 == NULL) {
        return mx_strdup(s1);
    }

    char *new_string = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    
    if(new_string == NULL) {
        return NULL;
    }

    mx_strcpy(new_string, s1);
    mx_strcat(new_string, s2);
    
    return new_string;
}

int mx_strlen(const char *s) {
    int count = 0;

    while(*(s + count) != '\0') {
        count++;
    }

    return count;
}

char *mx_strnew(const int size) {
    if(size < 1) {
        return NULL;
    }

    char *new_string = (char *) malloc(sizeof(char) * (size + 1));

    if(new_string == NULL) {
        return NULL;
    }

    for(int i = 0; i <= size; i++) {
        new_string[i] = '\0';
    }

    return new_string;
}


