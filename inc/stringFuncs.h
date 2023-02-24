#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>

int mx_strlen(const char *s);
char *mx_strcat(char *s1, const char *s2);
char *mx_strcpy(char *dst, const char *src);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);
char *mx_strjoin(char const *s1, char const *s2);
char *fileToStr(const char *filename);
bool mx_isnewline(char c);
int countWords(const char *str, bool (*check)(char));

