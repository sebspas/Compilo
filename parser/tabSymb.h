#ifndef TAB_SYMB_H
#define TAB_SYMB_H

#define SIZE_NAME 16
#define MAX_SIZE 1024

#define IS_INIT 1
#define IS_NOT_INIT 0

/*
    - ajout de symbole
    - supression de symbole
    - get de symbole
    - remplacer un symbole
*/
typedef struct symb {
    char name[SIZE_NAME];
    int type;
    int depth;
    char init;
} symb;


/**
    Empile l'element dans la pile
    Retourne l'index d'ajout
*/
int add_symb(char name[SIZE_NAME], int type, char init, int depth);

/**
    Remove toutes les variables a la profondeurs indiquer
*/
int remove_depth(int depth);

int remove_var();

/**
    Retourne la variable pass� en parametre
    avec le nom ou l'index
*/
int get_index_by_name(char name[SIZE_NAME]);

// NULL SI la variable n'existe pas
char* get_name_by_index(int index);

symb get_symb_by_index(int index);

int check_exist(char name[SIZE_NAME], int depth);


int check_not_exist(char name[SIZE_NAME]);

int check_not_init(int index);

int print();

int get_NB_ERROR();

int get_SP();

#endif
