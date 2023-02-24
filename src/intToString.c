#include "../inc/header.h"

char* intToString(int i) {
  char* res = malloc(8 * sizeof(int));
  sprintf(res, "%d", i);
  return res;
}


