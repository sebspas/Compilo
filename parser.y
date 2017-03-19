%{
#include <stdlib.h>
#include <stdio.h>
#include "tabSymb.h"
#include "tabFunc.h"
#include "error.h"
#define TYPE_INT 1

int var[26];
void yyerror(char *s);
int current_depth = 0;

enum {NOP, LOAD, STORE, AFC, COP, ADD, SUB, MUL, DIV, SUP, SUPE, INFE, EQU, OR, AND, INF, JMPC, JMP, JMPI, MOV };
char* TAB[] = {"NOP","LOAD", "STORE", "AFC", "COP", "ADD", "SUB", "MUL", "DIV", "SUP", "SUPE", "INFE", "EQU", "OR", "AND", "INF", "JMPC", "JMP", "JMPI", "MOV"};

int instr[1024][4];
int index_instr = 0;

void set_dest_jmp(int pos_inst, int dest) {
    instr[pos_inst][1] = dest;
}

void set_afc() {

}

int op_instr(int op, int a, int b, int c) {
    instr[index_instr][0] = op;
    instr[index_instr][1] = a;
    instr[index_instr][2] = b;
    instr[index_instr][3] = c;
    index_instr++;
}

int op_arith(int op, int a, int b) {

    op_instr(LOAD, 0, a, 42);
    op_instr(LOAD, 1, b, 42);
    op_instr(op, 0, 1, 42);
    op_instr(STORE, a, 0, 42);
    remove_var();
    return a;
}

int affect_instr(int b, int c) {
    op_instr(LOAD, 0, b, 42);
    op_instr(STORE, c, 0, 42);
}

void affiche_instrs() {
    printf(ANSI_COLOR_GREEN "Compilation terminé avec " ANSI_COLOR_RESET " " ANSI_COLOR_RED "%d" ANSI_COLOR_RESET " errors.\n", get_NB_ERROR());

    int i;
    for(i = 0; i < index_instr; i++) {
        printf("%d \t%s \t%d \t%d \t%d \n", i, TAB[instr[i][0]], instr[i][1], instr[i][2], instr[i][3]);
    }
}
%}
%union { int nb; char var[16]; }
%token tEGAL tPF tMOINS tPLUS tSTAR tDIV tMOD tRETURN
%token tMAIN tELSE tINT tOR tAND tVIR tPVIR tACO tACF
%token tEGEG tINF tINFEG tSUP tSUPEG
%token <nb> tNB tIF tWHILE tPO
%token <var> tID

%right tEGAL
%left tOR tAND
%left tSUP tINF tINFEG tSUPEG tEGEG
%left tPLUS tMOINS
%left tSTAR tDIV tMOD
%left tP0 tPF

%type <nb> E
%start Prg
%%
Prg :        Fonction Prg | ;
Fonction :    tINT tID { 
                    /*add_symb("@ret", TYPE_INT, IS_INIT, current_depth);*/
             } tPO Args tPF {
              add_func($2, index_instr); 
          } Body { /*printf("===== FONCTION ====\n");*/ };

Args :        Arg ListeArgs | { /*printf("Arg vide\n");*/};
ListeArgs :    tVIR Arg ListeArgs | ;
Arg :        tINT tID { 
                    add_symb($2, TYPE_INT, IS_INIT, current_depth+1);
                 };

Body :        tACO { current_depth++; print(); } Instrcs tACF { remove_depth(current_depth); current_depth--; };
Instrcs :    Instr Instrcs | ;
Instr :        Decl | If | While | Affect | Invoc tPVIR | Return;

Decl :        tINT DeclX tPVIR;
DeclX :        Decl1 | Decl1 tVIR DeclX;
Decl1 :        tID { 
                    /*printf("Decl \n");*/
                    check_exist($1, current_depth);
                    add_symb($1, TYPE_INT, IS_INIT, current_depth);  
                }
               | tID tEGAL E { 
                    remove_var();
                    /*printf("Decl = \n");*/
                    check_exist($1, current_depth);
                    int index = add_symb($1, TYPE_INT, IS_INIT, current_depth); 
                    //affect_instr($3, index);
                };

Affect :        tID tEGAL E tPVIR {
                    int index = get_index_by_name($1);
                    affect_instr($3, index);
                };

Invoc :         tID tPO {
                    /*int lr = add_symb("@ret_invoke", TYPE_INT, IS_INIT, current_depth); 
                    op_instr(AFC, 0, -1, 42);
                    op_instr(STORE, lr, 0, 42); 
                    $2 = index_instr - 2;*/

                }
                Params tPF { 
                    // on ajoute la valeur de retour
                    int adr_ret = add_symb("@ret", TYPE_INT, IS_INIT, current_depth);
                    // on retourne après le JMP vers la fonction
                    op_instr(STORE, adr_ret, index_instr + 1, 42);

                    // sauvegarde de BP
                    int adr_BP = add_symb("BP", TYPE_INT, IS_INIT, current_depth);
                    // on le met dans la memoire
                    op_instr(STORE, adr_BP, 31, 42);

                    // on met a jour notre BP
                    op_instr(AFC, 31, get_SP()+1, 42);

                    // on récupère l'addresse de la fonction ou l'on veut jump
                    int adr_f = get_adr_func($1);
                    // on load l'adr de la fonction
                    op_instr(LOAD, 0, adr_f, 42);
                    // on JMP a la fonction
                    op_instr(JMP, 0, 42, 42);

                    // on part de la fin de la table des symb et on récupère le BP le plus récent
                    int adr_old_BP = get_index_by_name("BP");
                    // on charge la valeur à l'adr adr_old_BP dans R7
                    op_instr(LOAD, 7, adr_old_BP, 42);
                    // on fait BP = old_BP
                    op_instr(MOV, 31, 7, 42);


                    /*
                    // @ret -> doit être a l'instr qui suit le JMP
                    $2 = index_instr + 2;
                    op_instr(STORE, get_index_by_name("@ret"), index_instr + 3, 42);
                    // bp
                    op_instr(LOAD, 0, adr_f, 42);
                    op_instr(JMP, 0, 42, 42);
                    // correction de l instr q $2 avec index_instr
                    set_afc();
                    // depiler les parametres !!!!
                    // bp corriger*/
            };

Return : tRETURN E tPVIR { 
            remove_var();
            printf("return\n"); 
            print(); 

            // on met la valeur de retour dans r0
            op_instr(LOAD, 0, $2, 42);
            // on charge BP dans un autre registre R7
            op_instr(MOV, 7, 31, 42);
            // on met 2 dans un registre pour le SUB
            op_instr(AFC, 8, 2, 42);
            // on enlève 2 pour remonter à l'adr de ret
            op_instr(SUB, 7, 8, 42);
            // on jmp a cette addresse
            op_instr(JMPI, 7, 42, 42);

            /*op_instr(LOAD, 0, $2, 42); 
            op_instr(LOAD, 1, get_index_by_name("@ret"), 42); 
            op_instr(JMPI, 1, 42, 42); */
};

Params :        Param | Param tVIR ParamsNext | ;
ParamsNext :    Param | Param tVIR ParamsNext;
Param :    E;

If :    tIF tPO E tPF { 
                op_instr(LOAD, 0, $3, 42);                    
                op_instr(JMPC, -1, 0, 42);
                $1 = index_instr - 1; 
            } Body { 
                op_instr(JMP, -1, 42, 42); 
                set_dest_jmp($1, index_instr);
                $1 = index_instr - 1; 
            } Else { set_dest_jmp( $1, index_instr); } ;

Else :  tELSE Body | ;

While : tWHILE tPO E tPF {
        op_instr(LOAD, 0, $3, 42);
        op_instr(JMPC, -1, 0, 42);
        $1 = index_instr - 1;
    } Body {
        set_dest_jmp($1, index_instr + 1);
        op_instr(JMP, ($1 - 1), 0, 42);
    } ;

E :     tPO E tPF { 
                $$ = $2;
         }
        | tNB { 
                int pos = add_symb("_", TYPE_INT, IS_INIT, current_depth);
                op_instr(AFC, 0, $1, 0);
                op_instr(STORE, pos, 0, 0);
                $$ = pos;
         }
        | tID { 
                print();
                check_not_exist($1);
                int index = get_index_by_name($1);
                check_not_init(index);

                int pos = add_symb("_", TYPE_INT, IS_INIT, current_depth);
                op_instr(LOAD, 0, index, 0);
                op_instr(STORE, pos, 0, 0);
                $$ = pos;
         } 
        | Invoc { 
                int pos = add_symb("_", TYPE_INT, IS_INIT, current_depth);
                $$ = pos;
         }
        | E tPLUS E     { $$ = op_arith(ADD, $1, $3); }
        | E tMOINS E    { $$ = op_arith(SUB, $1, $3); }
        | E tSTAR E     { $$ = op_arith(MUL, $1, $3); }
        | E tDIV E      { $$ = op_arith(DIV, $1, $3); }
        | E tOR E       { $$ = op_arith(OR, $1, $3);  }
        | E tAND E      { $$ = op_arith(AND, $1, $3); }
        | E tMOD E  {
            op_instr(AFC, 0, $1, 42);
            op_instr(AFC, 1, $3, 42);
            op_instr(DIV, 2, 0, 1);
            op_instr(MUL, 1, 2, 42);
            op_instr(SUB, 0, 3, 42);
        }
        | E tEGEG E     { $$ = op_arith(EQU, $1, $3); }
        | E tSUP E      { $$ = op_arith(SUP, $1, $3); }
        | E tINF E      { $$ = op_arith(INF, $1, $3); }
        | E tSUPEG E    { $$ = op_arith(SUPE, $1, $3); }
        | E tINFEG E    { $$ = op_arith(INFE, $1, $3); }; 

%%
void yyerror(char *s) { fprintf(stderr , "%s\n", s); }

int main(void) {
        //printf("Mon Parser\n"); // yydebug =1;
        yyparse ();
        affiche_instrs();
        return 0;
}