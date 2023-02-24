#include "../inc/header.h"

int **translateMap(const char *filename) {
    char *str = fileToStr(filename);

    int rows = countWords(str, mx_isnewline);
    int cols = mx_strlen(str) / rows - 1;

    char *maze = mx_strnew(rows * cols);
    int j = 0;

    for(int i = 0; i < mx_strlen(str); i++) {
        if(str[i] == '\n') {
            continue;
        }
        maze[j++] = str[i];
    }

    int **maze2D = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        maze2D[i] = (int*)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            switch(maze[i * cols + j]) {
                case 'a':
                    maze2D[i][j] = 0;
                    break;
                case 'b':
                    maze2D[i][j] = 1;
                    break;
                case 'c':
                    maze2D[i][j] = 2;
                    break;
                case 'd':
                    maze2D[i][j] = 3;
                    break;
                case 'e':
                    maze2D[i][j] = 4;
                    break;
                case 'f':
                    maze2D[i][j] = 5;
                    break;
                case 'g':
                    maze2D[i][j] = 6;
                    break;
                case 'h':
                    maze2D[i][j] = 7;
                    break;
                case 'i':
                    maze2D[i][j] = 8;
                    break;
                case 'j':
                    maze2D[i][j] = 9;
                    break;
                case 'k':
                    maze2D[i][j] = 10;
                    break;
                case 'l':
                    maze2D[i][j] = 11;
                    break;
                case 'm':
                    maze2D[i][j] = 12;
                    break;
                case 'n':
                    maze2D[i][j] = 13;
                    break;
                case 'o':
                    maze2D[i][j] = 14;
                    break;
                case 'p':
                    maze2D[i][j] = 15;
                    break;
                case 'q':
                    maze2D[i][j] = 16;
                    break;
                case 'r':
                    maze2D[i][j] = 17;
                    break;
                case 's':
                    maze2D[i][j] = 18;
                    break;
                case 't':
                    maze2D[i][j] = 19;
                    break;
                case 'u':
                    maze2D[i][j] = 20;
                    break;
                case 'v':
                    maze2D[i][j] = 21;
                    break;
                case 'w':
                    maze2D[i][j] = 22;
                    break;
                case 'x':
                    maze2D[i][j] = 23;
                    break;
                case 'y':
                    maze2D[i][j] = 24;
                    break;
                default:
                    maze2D[i][j] = 200;
                    break;
            }
        }
    }

    free(maze);

    return maze2D;
}




