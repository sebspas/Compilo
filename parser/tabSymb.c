#include "tabSymb.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "error.h"

extern void yyerror(const char *s);

symb table[MAX_SIZE];

int SP = 0;

/**
    Empile l'element dans la pile
    Retourne l'index d'ajout
*/
int add_symb(char name[SIZE_NAME], int type, char init, int depth) {
    strcpy(table[SP].name, name);
    table[SP].type = type;
    table[SP].init = init;
    table[SP].depth = depth;
    return SP++;
}

/**
    Remove toutes les variables a la profondeurs indiquer
*/
int remove_depth(int depth) {
    int i = SP;
    while(i > 0 && table[i - 1].depth == depth) {
        i--;
    }
    SP = i;
}

int remove_var() {
    if(SP > 0) SP--;
}

/**
    Retourne la variable passee en parametre
    avec le nom ou l'index
*/
int get_index_by_name(char name[SIZE_NAME]) {
    int i = SP-1;

    for ( ; i >= 0; --i) {
        if (strcmp(table[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

// NULL SI la variable n'existe pas
char* get_name_by_index(int index) {
    return table[index].name;
}

symb get_symb_by_index(int index) {
    return table[index];
}

int check_exist(char name[SIZE_NAME], int depth) {
    int i = SP-1;

    for ( ; i >= 0; --i)
    {
        if (strcmp(table[i].name, name) == 0 && table[i].depth == depth) {
            char *s; 
            asprintf(&s,"id " ANSI_COLOR_CYAN "%s"  ANSI_COLOR_RESET " already exists at this depth", table[i].name);
            yyerror(s);
        }
    }

    return 0;
}

int check_not_exist(char name[SIZE_NAME]) {
    int i = SP-1;

    for (; i >= 0; --i)
    {
        if (strcmp(table[i].name, name) == 0) {
            return 1;
        }
    }
    
    char *s; 
    asprintf(&s,"id"  ANSI_COLOR_CYAN " %s"  ANSI_COLOR_RESET " does not exist", name);
    yyerror(s);
    return -1;
}

int check_not_init(int index) {
    if (table[index].init == IS_NOT_INIT) {
        char *s; 
        asprintf(&s,"id" ANSI_COLOR_CYAN "%s" ANSI_COLOR_RESET " not init", table[index].name);
        yyerror(s);
    }

    return 0;
}

int print() {
    int i = 0;
    fprintf(stderr, "===============TAB_SYMBOLES=============\n");
    fprintf(stderr, "@ \tNom \tProfondeur\t \n");
    for (; i < SP; ++i)
    {
      fprintf(stderr, "%d \t%s \t%d \n", i, table[i].name, table[i].depth);
    }
    fprintf(stderr, "========================================\n");
    return 0;
}

int get_SP() {
    return SP;
}
