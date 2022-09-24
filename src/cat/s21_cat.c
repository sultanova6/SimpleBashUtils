#include "s21_cat.h"

int s21_parse(char *str, opci *opc) {
    unsigned int flag = 0, fl = 0;
    while (flag == 0 && *(++str) != '\0') {
        switch (*str) {
        case '-' : {  // GNU
            if (strcmp(str, "-number-nonblank") == 0) {
                opc->b = 1;
            } else if (strcmp(str, "-number") == 0) {
                    opc->n = 1;
            } else if (strcmp(str, "-squeeze-blank") == 0) {
                        opc->s = 1;
            } else {
                            fl = 1;
                            }
                            }
        break;
        case 'b': opc->b = 1;
        break;
        case 'e': opc->e = opc->v = 1;
        break;
        case 'E': opc->e = 1;
        break;
        case 'n': opc->n = 1;
        break;
        case 's': opc->s = 1;
        break;
        case 't': opc->t = opc->v = 1;
        break;
        case 'T': opc->t = 1;
        break;
        case 'v': opc->v = 1;
        break;
        default:
                fprintf(stderr, "s21_cat: illegal option -- %s\n", str);
                fprintf(stderr, "usage: s21_cat [-bestv] [file ...]\n");
                fl = 1;
        break;
        }
        }
        return fl;
}

void s21_flag_print(char *str, opci opc) {
    FILE *file = NULL;
    file = fopen(str, "r");
    if (file == NULL) {
        fprintf(stderr, "s21_cat: %s: No such file or directory\n", str);
    } else {
        int count = 0;
        int num = 1;
        int new = '\n';
        int ch = 0;
        while ((ch = fgetc(file)) != EOF) {
            if (opc.b && ch != '\n' && new == '\n') {
                printf("%6d\t", num++);
            }

            if (opc.e && ch == '\n') {
                printf("$");
            }

            if (opc.n && !opc.b && new == '\n') {
                printf("%6d\t", num++);
            }

            if (opc.s && ch == '\n' && new == '\n') {
                if (ch == '\n') {
                    if (count) {
                        continue;
                    }
                        count = 1;
                    } else {
                        count = 0;
                    }
            }

            if (opc.t && ch == '\t') {
                printf("^I");
                new = ch;
                continue;
            }
            if (opc.v == 1) {
                if (ch >= 0 && ch <= 31 && ch != 9 && ch != 10) {  // управляющие символы
                    printf("^");  // и (таб и перевод строки)
                    ch += 64;
                    }
                    if (ch >= 127 && ch <= 159) {  // печатные символы
                        if (ch == 127) {  // делет
                        printf("^");
                        } else {
                        printf("M-^");
                        ch -= 64;
                        }
                        }
                        }
            printf("%c", ch);
            new = ch;
            if (new != '\n') {
                count = 0;
            }
        }
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    opci opc = {0};
    int i = 1;
    int check_parser = 0;

    while (i < argc) {
        if (argv[i][0] == '-') {
            check_parser = s21_parse(argv[i], &opc);
        }
        i++;
    }
    i = 1;

    while (i < argc && check_parser != 1) {
        if (argv[i][0] != '-') {
            s21_flag_print(argv[i], opc);
        }
        i++;
    }

    return 0;
}
