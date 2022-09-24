// Copyright 2022 myrebean
#include "s21_grep.h"

int N_a(int f_n) {
    return f_n == 1 ? 0 & printf("%s", A):
    f_n == 2 ? 0 * printf("%s", B):
    f_n == 3 ? 0 * printf("%s", C):
    f_n == 4 ? 0 * printf("%s", D):
    f_n == 5 ? 0 * printf("%s", E):
    f_n == 6 ? 0 * printf("%s", F):
    1;
}

size_t str_ln(const char *string) {
    size_t count = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int sh_argv_ft(char *st, fl *f, int i) {
    f->ft[i].ft = f->grep_t_rue == 0 ? 3 : 1;
    f->grep_t_rue = f->ft[i].ft == 3 ? 1 : f->grep_t_rue;
    f->grep_f_c = f->ft[i].ft == 1 ? f->grep_f_c + 1 : f->grep_f_c;
    f->ft[i].name = st;
    return 1;
}

int is_f_null(int i, fl f) {
    FILE *fl = fopen(f.ft[i].name, "r");
    int a = fl == NULL ? -2 : -1;
    if (a == -1) {
        fclose(fl);
    }
    return a;
}

int fe_init(char *argv[], int *i, int j, fl *f, int argc) {
    int r = 0;
    if (argv[*i][j+1] != '\0') {
        f->ft[*i].ft = argv[*i][j] == 'f' ? 4 : 2;
        f->ft[*i].name = &argv[*i][j + 1];
        r = f->ft[*i].ft == 4 ? is_f_null(*i, *f) : -1;
    } else if (*i + 1 < argc) {
        f->ft[*i + 1].ft = argv[*i][j] == 'f' ? 4 : 2;
        f->ft[*i + 1].name = argv[*i + 1];
        *i += 1;
        r = f->ft[*i].ft == 4 ? is_f_null(*i, *f) : -1;
    }
    return r == -1 ? r :
    r == -2 ? printf("grep: %s: ", f->ft[*i].name) * N_a(3) :
    argv[*i][j] == 'f' ? N_a(6) * printf("%c\n", 'f') * N_a(1) :
    argv[*i][j] == 'e' ?N_a(6) * printf("%c\n", 'e') * N_a(1):
    1;
}

int init_flag(int j, char c, int *i, char *argv[], fl *f, int argc) {
    return c == 'i' ? f->grep_i = j + 1 :
    c == 'v' ? f->grep_v = j + 1 :
    c == 'c' ? f->grep_c = j + 1 :
    c == 'n' ? f->grep_n = j + 1 :
    c == 'h' ? f->grep_h = j + 1 :
    c == 's' ? f->grep_s = j + 1 :
    c == 'o' ? f->grep_o = j + 1 :
    c == 'l' ? f->grep_l = j + 1 :
    c == 'f' ? f->grep_f = fe_init(argv, i, j, f, argc):
    c == 'e' ? f->grep_e = fe_init(argv, i, j, f, argc):
    N_a(5) * printf("%c\n", c) * N_a(1);
}

int sh_argv_f(int argc, char *argv[], fl *f, int *i) {
    int j = 1;
    while (argv[*i][j] != '\0' && j > 0) {
        j = init_flag(j, argv[*i][j], i, argv, f , argc);
    }
    return j > 0 ? 1 :
    j < 0 ? 1: 0;
}

int pr_argv(int argc, char *argv[], fl *f, int *i) {
    return (argv[*i][0] == '-') ?
    sh_argv_f(argc, argv, f, i) :
    sh_argv_ft(argv[*i], f, *i);
}

int sh_argc(int argc, char *argv[], fl *f) {
    int i = 1;
    while (i < argc && i > 0) {
         i = pr_argv(argc, argv, f, &i) ? i + 1 : 0;
    }
    return i;
}

void file_raven_null(fl f, int i) {
    if (f.grep_s == 0) {
        printf("grep: %s: ", f.ft[i].name);
        N_a(3);
    }
}

void nl_fo_el(char * line) {
    if (str_ln(line) > 1) {
        if (line[(int)str_ln(line) - 1] == '\n') {
            line[(int)str_ln(line) - 1] = '\0';
            }
            }
            }

long int is_void_file(FILE *f_file) {
    fseek(f_file, 0, SEEK_END);
    long pos = ftell(f_file);
    rewind(f_file);
    return  pos > 0 ? 1 : 0;
}

void c_func(fl f, int i, int argc, FILE *file) {
    char *str = NULL;
    size_t size = 0;
    fp fl = {0};
    while (getline(&str, &size, file) != -1) {
        int exit = 1;
        fl.perv_sovp = 0;
        int j = 1;
        for (; j < argc && exit; j++) {
            if (f.ft[j].ft == 4) {
                FILE *f_file = fopen(f.ft[j].name, "r");
                if (is_void_file(f_file)) {
                    fl.func_stdout = 1;
                    char *ftr = NULL;
                    size_t fize = 0;
                    while (getline(&ftr, &fize, f_file) != -1 && exit) {
                        nl_fo_el(ftr);
                        regex_t rg = {0};
                        int rgr;
                        rgr = f.grep_i == 0 ? regcomp(&rg, ftr , 0) :
                              regcomp(&rg, ftr , REG_ICASE);
                        if (rgr) {
                            N_a(4);
                            regfree(&rg);
                            continue;
                        } else {
                            rgr = regexec(&rg, str, 0, NULL, 0);
                            if (!rgr) {
                                fl.perv_sovp = 1;
                                fl.count_sovp++;
                                exit = 0;
                            }
                            regfree(&rg);
                        }
                    }
                    free(ftr);
                    fclose(f_file);
                }
            } else if (f.ft[j].ft == 3 || f.ft[j].ft == 2) {
                fl.func_stdout = 1;
                regex_t rg = {0};
                int rgr;
                rgr = f.grep_i == 0 ? regcomp(&rg, f.ft[j].name , 0) :
                      regcomp(&rg, f.ft[j].name , REG_ICASE);
                if (rgr) {
                    N_a(4);
                    regfree(&rg);
                    continue;
                } else {
                    rgr = regexec(&rg, str, 0, NULL, 0);
                    if (!rgr) {
                        fl.perv_sovp = 1;
                        fl.count_sovp++;
                        exit = 0;
                    }
                    regfree(&rg);
                }
            }
        }
        if (!fl.perv_sovp) {
            fl.net_sovp++;
        }
    }
    free(str);
    if (fl.func_stdout) {
        if (f.grep_f_c > 1 && !f.grep_h) {
            printf("%s:", f.ft[i].name);
        }
        if (f.grep_l) {
            if (f.grep_v ? fl.net_sovp : fl.count_sovp) {
                printf("%d\n", 1);
                printf("%s\n", f.ft[i].name);
            } else {
                printf("%d\n", 0);
            }
        } else {
            printf("%d\n", f.grep_v ? fl.net_sovp : fl.count_sovp);
        }
    }
}

void recurs_o(char *str, pm *pos_match, fl f, int j, int *pos) {
    if (f.ft[j].ft == 3 || f.ft[j].ft == 2) {
        const size_t nmatch = 1;
        regmatch_t pmatch[1];
        regex_t reg = {0};
        int rgr = f.grep_i == 0 ? regcomp(&reg, f.ft[j].name , 0) :
                  regcomp(&reg, f.ft[j].name , REG_ICASE);
        if (!rgr) {
            int shift_eo = 0;
            int shift = 0;
            while (!regexec(&reg, str + shift, nmatch, pmatch, 0)) {
                shift += pmatch->rm_eo;
                pmatch->rm_so += shift_eo;
                pmatch->rm_eo += shift_eo;
                pos_match[*pos].so = pmatch->rm_so;
                pos_match[*pos].eo = pmatch->rm_eo;
                shift_eo = shift;
                *pos+=1;
            }
        } else {
            N_a(4);
        }
        regfree(&reg);

    } else if (f.ft[j].ft == 4) {
        FILE *f_file = fopen(f.ft[j].name, "r");
        if (is_void_file(f_file)) {
            char *ftr = NULL;
            size_t fize = 0;
            while (getline(&ftr, &fize, f_file) != -1) {
                if (str_ln(ftr) > 1) {
                    if (ftr[(int)str_ln(ftr) - 1] == '\n') {
                        ftr[(int)str_ln(ftr) - 1] = '\0';
                    }
                }
                const size_t nmatch = 1;
                regmatch_t pmatch[1];
                regex_t reg = {0};
                int rgr = f.grep_i == 0 ? regcomp(&reg, ftr , 0) :
                          regcomp(&reg, ftr , REG_ICASE);
                if (!rgr) {
                    int shift_eo = 0;
                    int shift = 0;
                    while (!regexec(&reg, str + shift, nmatch, pmatch, 0)) {
                        shift += pmatch->rm_eo;
                        pmatch->rm_so += shift_eo;
                        pmatch->rm_eo += shift_eo;
                        pos_match[*pos].so = pmatch->rm_so;
                        pos_match[*pos].eo = pmatch->rm_eo;
                        shift_eo = shift;
                        *pos+=1;
                    }
                } else {
                    N_a(4);
                }
                regfree(&reg);
            }
            free(ftr);
            fclose(f_file);
        }
    }
}

void o_func(fl f, int i, int argc, FILE *file) {
    int exit = 1;
    char *str = NULL;
    size_t size = 0;
    fp fl = {0};
    while (getline(&str, &size, file) != -1 && exit) {
        fl.count_line++;
        int sz = str_ln(str);
        pm *pos_match = calloc(sz, sizeof(pm));
        int pos = 0;
        for (int j = 1; j < argc; j++) {
            recurs_o(str, pos_match, f, j, &pos);
        }
        for (int j = 0; j < sz && exit; j++) {
            for (int y = 0; y < sz; y++) {
                if (pos_match[y].so == j && pos_match[y].eo != 0) {
                    if (f.grep_v) {
                        exit = 0;
                        break;
                    }
                    if (f.grep_l) {
                        printf("%s\n", f.ft[i].name);
                        exit = 0;
                        break;
                    }
                    if (!f.grep_h && f.grep_f_c > 1) {
                        printf("%s:", f.ft[i].name);
                    }
                    if (f.grep_n) {
                        printf("%d:", fl.count_line);
                    }
                    for (int u = pos_match[y].so; u < pos_match[y].eo; u++) {
                        putchar(str[u]);
                    }
                    putchar('\n');
                    j = pos_match[y].eo;
                }
            }
        }
        free(pos_match);
    }
    free(str);
}

int recourse_drugie(char *str, fl f, fp *fl, int j) {
    int result = 0;
    if (f.ft[j].ft == 3 || f.ft[j].ft == 2) {
        regex_t rg = {0};
        int rgr;
        rgr = f.grep_i == 0 ? regcomp(&rg, f.ft[j].name , 0) :
              regcomp(&rg, f.ft[j].name , REG_ICASE);
        if (!rgr) {
            if (!regexec(&rg, str, 0, NULL, 0)) {
                fl->perv_sovp = 1;
                result = 1;
            }
        } else {
            N_a(4);
        }
        regfree(&rg);
    } else if (f.ft[j].ft == 4) {
        FILE *f_file = fopen(f.ft[j].name, "r");
        if (is_void_file(f_file)) {
            char *ftr = NULL;
            size_t fize = 0;
            while (getline(&ftr, &fize, f_file) != -1) {
                if (str_ln(ftr) > 1) {
                    if (ftr[(int) str_ln(ftr) - 1] == '\n') {
                        ftr[(int) str_ln(ftr) - 1] = '\0';
                    }
                }
                regex_t rg = {0};
                int rgr = f.grep_i == 0 ? regcomp(&rg, ftr , 0) :
                          regcomp(&rg, ftr , REG_ICASE);
                if (!rgr) {
                    if (!regexec(&rg, str, 0, NULL, 0)) {
                        fl->perv_sovp = 1;
                        result = 1;
                        regfree(&rg);
                        break;
                    }
                } else {
                    N_a(4);
                }
                regfree(&rg);
            }
            free(ftr);
            fclose(f_file);
        }
    }
    return result;
}

void drugie_func(fl f, int i, int argc, FILE *file) {
    char *str = NULL;
    size_t size = 0;
    fp fl = {0};
    while (getline(&str, &size, file) != -1) {
        fl.count_line++;
        fl.perv_sovp = 0;
        for (int j = 1; j < argc; j++) {
            if (recourse_drugie(str, f, &fl, j)) {
                break;
            }
        }
        if (fl.perv_sovp && !f.grep_v) {
            if (f.grep_l) {
                printf("%s\n", f.ft[i].name);
                break;
            }
            if (!f.grep_h && f.grep_f_c > 1) {
                printf("%s:", f.ft[i].name);
            }
            if (f.grep_n) {
                printf("%d:", fl.count_line);
            }
            printf("%s", str);
            if (str[(int) str_ln(str) - 1] != '\n') {
                putchar('\n');
            }
        } else if (!fl.perv_sovp && f.grep_v) {
            if (f.grep_l) {
                printf("%s\n", f.ft[i].name);
                break;
            }
            if (!f.grep_h && f.grep_f_c > 1) {
                printf("%s:", f.ft[i].name);
            }
            if (f.grep_n) {
                printf("%d:", fl.count_line);
            }
            printf("%s", str);
            if (str[(int) str_ln(str) - 1] != '\n') {
                putchar('\n');
            }
        }
    }
    free(str);
}

void open_file(fl f, int i, int argc) {
    FILE *file = fopen(f.ft[i].name, "r");
    if (file == NULL) {
        file_raven_null(f, i);
    } else {
        if (f.grep_c) {
            c_func(f, i, argc, file);
        } else if (f.grep_o) {
            o_func(f, i, argc, file);
        } else {
            drugie_func(f, i, argc, file);
        }
        fclose(file);
    }
}

int stdout_file(int argc, fl f) {
    for (int i = 1; i < argc; i++) {
        if (f.ft[i].ft == 1) {
            open_file(f, i, argc);
        }
    }
    return 1;
}

void t_tf(fl *f, int argc) {
    if (f->grep_e != 0 || f->grep_f != 0) {
        for (int i = 1; i < argc; i++) {
            if (f->ft[i].ft == 3) {
                f->ft[i].ft = 1;
                f->grep_f_c +=1;
            }
        }
    }
}

int s21_grep(int argc, char *argv[]) {
    fl f = {0};
    f.ft = (fot*) calloc(argc, sizeof(fot));
    int a = (f.ft != NULL) ? sh_argc(argc, argv, &f) : 0;
    if (a) {
        t_tf(&f, argc);
        stdout_file(argc, f);
    }
    free(f.ft);
    return a;
}

int main(int argc, char *argv[]) {
    return argc > 2 ? s21_grep(argc, argv): N_a(1);
}
