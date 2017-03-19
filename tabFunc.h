#ifndef TAB_FUNC_H
#define TAB_FUNC_H

#define SIZE_NAME_FUNC 16
#define MAX_SIZE_FUNC 1024

typedef struct func {
    char name[SIZE_NAME_FUNC];
    int adr;
} func;

int get_adr_func(char name[SIZE_NAME_FUNC]);

int add_func(char name[SIZE_NAME_FUNC], int adr);

#endif