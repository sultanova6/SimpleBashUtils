#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

static const char *A = "usage: grep [-abcDEFGHhIiJLlmnOoqRSsUVvwxZ] [-A num] [-B num] [-C[num]]\n"
                         "\t[-e pattern] [-f file] [--binary-files=value] [--color=when]\n"
                         "\t[--context[=num]] [--directories=action] [--label] [--line-buffered]\n"
                         "\t[--null] [pattern] [file ...]\n";

static const char *B = "No files found\n";

static const char *C = "No such file or directory\n";

static const char *D = "Regex comp. fail\n";

static const char *E = "grep: invalid option -- ";

static const char *F = "grep: option requires an argument -- ";

typedef struct pos_match {
    int so;
    int eo;
}pm;

typedef struct fparams {
    int count_line;
    int true_liniya;
    int count_sovp;
    int net_sovp;
    int func_stdout;
    int perv_sovp;
}fp;

typedef struct f_or_t {
    int ft;
    char *name;
}fot;

typedef struct flagi {
    int grep_e;
    int grep_i;
    int grep_v;
    int grep_c;
    int grep_l;
    int grep_n;
    int grep_h;
    int grep_s;
    int grep_f;
    int grep_o;
    int grep_f_c;
    int grep_t_rue;
    fot *ft;
} fl;

int N_a(int f_n);

int s21_grep(int argc, char *argv[]);

int sh_argc(int argc, char *argv[], fl *f);

int pr_argv(int argc, char *argv[], fl *f, int *i);

int sh_argv_f(int argc, char *argv[], fl *f, int *i);

int init_flag(int j, char c, int *i, char *argv[], fl *f, int argc);

int fe_init(char *argv[], int *i, int j, fl *f, int argc);

int sh_argv_ft(char* st, fl *f, int i);

int stdout_file(int argc, fl f);

void open_file(fl f, int i, int argc);

void t_tf(fl *f, int argc);

size_t str_ln(const char *string);

int esli_f_null(int i, fl f);

void file_raven_null(fl f, int i);

void nl_fo_el(char * line);

long int is_void_file(FILE *f_file);

void c_func(fl f, int i, int argc, FILE * file);

void recurs_o(char *str, pm *pos_match, fl f, int j, int *pos);

void o_func(fl f, int i, int argc, FILE *file);

int recourse_drugie(char *str, fl f, fp *fl, int j);

void drugie_func(fl f, int i, int argc, FILE *file);

#endif  // SRC_GREP_S21_GREP_H_
