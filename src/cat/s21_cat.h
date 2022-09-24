#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct OPC {
    unsigned int b;
    unsigned int e;
    unsigned int n;
    unsigned int s;
    unsigned int t;
    unsigned int v;
} opci;

int s21_parse(char *str, opci *opc);
void s21_flag_print(char *str, opci opc);

#endif  // SRC_CAT_S21_CAT_H_
