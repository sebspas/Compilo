#include "tabSymb.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "error.h"

symb table[MAX_SIZE];

int SP = 0;

int NB_ERROR = 0;

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

    while(i > 0 && table[i].depth == depth) {
        i--;
    }

    SP = i;

    //printf("Last index : %d\n", last_index);
    
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

            printf(ANSI_COLOR_RED "Error : " ANSI_COLOR_RESET "id " ANSI_COLOR_CYAN "%s" ANSI_COLOR_RESET " already exists at this depth.\n", name);
            NB_ERROR++;
            //exit(2);
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

    printf(ANSI_COLOR_RED "Error : " ANSI_COLOR_RESET "id " ANSI_COLOR_CYAN "%s" ANSI_COLOR_RESET " does not exist.\n", name);
    NB_ERROR++;
    //exit(2);
    return -1;
}

int check_not_init(int index) {
    if (table[index].init == IS_NOT_INIT) {
        printf(ANSI_COLOR_RED "Error : " ANSI_COLOR_RESET "id " ANSI_COLOR_CYAN "%s" ANSI_COLOR_RESET " not init.\n", table[index].name);
        NB_ERROR++;
        //exit(2);
    }

    return 0;
}

int print() {
    int i = 0;
    printf("===============TAB_SYMBOLES=============\n");
    printf("@ \tNom \tProfondeur\t \n");
    for (; i < SP; ++i)
    {
      printf("%d \t%s \t%d \n", i, table[i].name, table[i].depth);
    }
    printf("========================================\n");
    return 0;
}

int get_NB_ERROR() {
    return NB_ERROR;
}

int get_SP() {
    return SP;
}