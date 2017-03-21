%{
#include <stdlib.h>
#include <stdio.h>
#define TYPE_INT 1
int var[26];
void yyerror(char *s);

int reg[32];
int mem[1024];
int instr[1024][4];
int index_instr = 0;
int index_mem = 0;

enum {NOP, LOAD, STORE, AFC, COP, ADD, SUB, MUL, DIV, SUP, SUPE, INFE, EQU, OR, AND, INF, JMPC, JMP, JMPR };

char* TAB[] = {"NOP","LOAD", "STORE", "AFC", "COP", "ADD", "SUB", "MUL", "DIV", "SUP", "SUPE", "INFE", "EQU", "OR", "AND", "INF", "JMPC", "JMP", "JMPR" };

int tab_instr(int op, int a, int b, int c) {

    instr[index_instr][0] = op;
    instr[index_instr][1] = a;
    instr[index_instr][2] = b;
    instr[index_instr][3] = c;
    index_instr++;
}


int affiche_reg(){
	int i;
	printf("TAB_REG\n");
	for(i=0; i<32; i++){
		printf("%d \t%d \n", i, reg[i]);
	}
	printf("\n");
}

int affiche_mem(){
	int i;
	printf("TAB_MEM\n");
	for(i=0; i<index_mem; i++){
		printf("@%d \t%d \n", i, mem[i]);
	}
	printf("\n");
}


int translate(){
	int i;

	for(i=0; i<index_instr; i++){

		switch(instr[i][0]) {

			case NOP : 

				printf("NOP \n");
				break;

			case LOAD : 
				// LOAD Ri @j
				reg[instr[i][1]] = mem[instr[i][2]] ;

				printf("LOAD \tr%d \t@%d \n", instr[i][1], mem[instr[i][2]]);
				break;

			case STORE :
				// STORE @i Rj
				mem[instr[i][1]] = reg[instr[i][2]] ;
				index_mem++;

				printf("STORE \t@%d \tr%d \n", mem[instr[i][1]], instr[i][2]);
				break; 

			case AFC :
				// AFC Ri j
				reg[instr[i][1]] = instr[i][2] ;

				printf("AFC \tr%d \t%d \n", instr[i][1], instr[i][2]);
				break;

			case COP : 
				// COP Ri Rj
				reg[instr[i][1]] = reg[instr[i][2]];

				printf("COP \tr%d \tr%d \n", instr[i][1], instr[i][2]);
				break;

			case ADD : 
				// ADD Ri <- Rj + Rk

				if (instr[i][3] == 42){
					reg[instr[i][1]] = reg[instr[i][1]] + reg[instr[i][2]];

					printf("ADD \tr%d \tr%d \n", instr[i][1], instr[i][2]);
				}
				else{
					reg[instr[i][1]] = reg[instr[i][2]] + reg[instr[i][3]];

					printf("ADD \tr%d \tr%d \tr%d \n", instr[i][1], instr[i][2], instr[i][3]);
				}

				break;

			case SUB : 
				// SUB Ri <- Rj - Rk

				if (instr[i][3] == 42){
					reg[instr[i][1]] = reg[instr[i][1]] - reg[instr[i][2]];

					printf("SUB \tr%d \tr%d \n", instr[i][1], instr[i][2]);
				}
				else{
					reg[instr[i][1]] = reg[instr[i][2]] - reg[instr[i][3]];

					printf("SUB \tr%d \tr%d \tr%d \n", instr[i][1], instr[i][2], instr[i][3]);
				}

				break;

			case MUL : 
				// MUL Ri <- Rj * Rk

				if (instr[i][3] == 42){
					reg[instr[i][1]] = reg[instr[i][1]] * reg[instr[i][2]];

					printf("MUL \tr%d \tr%d \n", instr[i][1], instr[i][2]);
				}
				else{
					reg[instr[i][1]] = reg[instr[i][2]] * reg[instr[i][3]];

					printf("MUL \tr%d \tr%d \tr%d \n", instr[i][1], instr[i][2], instr[i][3]);
				}

				break;

			case DIV : 
				// DIV Ri <- Rj / Rk

				if (instr[i][3] == 42){
					reg[instr[i][1]] = reg[instr[i][1]] / reg[instr[i][2]];

					printf("DIV \tr%d \tr%d \n", instr[i][1], instr[i][2]);
				}
				else{
					reg[instr[i][1]] = reg[instr[i][2]] / reg[instr[i][3]];

					printf("DIV \tr%d \tr%d \tr%d \n", instr[i][1], instr[i][2], instr[i][3]);
				}

				break;

			case SUP : 
				// SUP Ri <- 1 si Rj > Rk; 0 sinon
				reg[instr[i][1]] = 0; //par defaut

				if (instr[i][3] == 42){

					if (reg[instr[i][1]] > reg[instr[i][2]]){
						reg[instr[i][1]] = 1;
					}
					printf("SUP \tr%d \tr%d \n", instr[i][1], instr[i][2]);
				}
				else{

					if (reg[instr[i][2]] > reg[instr[i][3]]){
						reg[instr[i][1]] = 1;
					}
					printf("SUP \tr%d \tr%d \tr%d \n", instr[i][1], instr[i][2], instr[i][3]);
				}

				break;

			case SUPE : 
				// SUPE Ri <- 1 si Rj >= Rk; 0 sinon
				reg[instr[i][1]] = 0; //par defaut

				if (instr[i][3] == 42){

					if (reg[instr[i][1]] >= reg[instr[i][2]]){
						reg[instr[i][1]] = 1;
					}
					printf("SUPE \tr%d \tr%d \n", instr[i][1], instr[i][2]);
				}
				else{

					if (reg[instr[i][2]] >= reg[instr[i][3]]){
						reg[instr[i][1]] = 1;
					}
					printf("SUPE \tr%d \tr%d \tr%d \n", instr[i][1], instr[i][2], instr[i][3]);
				}

				break;

			case INFE : 
				// INFE Ri <- 1 si Rj <= Rk; 0 sinon
				reg[instr[i][1]] = 0; //par defaut

				if (instr[i][3] == 42){

					if (reg[instr[i][1]] <= reg[instr[i][2]]){
						reg[instr[i][1]] = 1;
					}
					printf("INFE \tr%d \tr%d \n", instr[i][1], instr[i][2]);
				}
				else{

					if (reg[instr[i][2]] <= reg[instr[i][3]]){
						reg[instr[i][1]] = 1;
					}
					printf("INFE \tr%d \tr%d \tr%d \n", instr[i][1], instr[i][2], instr[i][3]);
				}

				break;

			case EQU : 
				// EQU Ri <- 1 si Rj == Rk; 0 sinon
				reg[instr[i][1]] = 0; //par defaut

				if (instr[i][3] == 42){

					if (reg[instr[i][1]] == reg[instr[i][2]]){
						reg[instr[i][1]] = 1;
					}
					printf("EQU \tr%d \tr%d \n", instr[i][1], instr[i][2]);
				}
				else{

					if (reg[instr[i][2]] == reg[instr[i][3]]){
						reg[instr[i][1]] = 1;
					}
					printf("EQU \tr%d \tr%d \tr%d \n", instr[i][1], instr[i][2], instr[i][3]);
				}

				break;

			case OR : 
				// a determiner

				break;

			case AND : 
				// a determiner

				break;

			case INF :
				// INF Ri <- 1 si Rj < Rk; 0 sinon
				reg[instr[i][1]] = 0; //par defaut

				if (instr[i][3] == 42){

					if (reg[instr[i][1]] < reg[instr[i][2]]){
						reg[instr[i][1]] = 1;
					}
					printf("INF \tr%d \tr%d \n", instr[i][1], instr[i][2]);
				}
				else{

					if (reg[instr[i][2]] < reg[instr[i][3]]){
						reg[instr[i][1]] = 1;
					}
					printf("INF \tr%d \tr%d \tr%d \n", instr[i][1], instr[i][2], instr[i][3]);
				} 

				break;

			case JMPC : 
				// JMPC @i Ri si Ri != 0

				if (reg[instr[i][2]] != 0){
						printf("saut à l'@ %d", mem[instr[i][1]]);
				}

				printf("JMPC \t@%d \tr%d \n", mem[instr[i][1]], instr[i][2]);
				break;

			case JMP : 
				// JMP @i

				printf("JMP \t%d \n", mem[instr[i][1]]);
				break;

			case JMPR :
				// JMPR Ri 
				// saut a l'@ mem contenu dans le registre Ri

				printf("JMPR \tr%d \n", instr[i][1]);
				break;

			default:
				printf("OP non reconnue \n");
		}
	}

}

%}
%union { int nb; char var[16]; }
%token tNOP tLOAD tSTORE tAFC tCOP tADD tSUB tMUL tDIV tSUP
%token tSUPE tINFE tEQU tOR tAND tINF tJMPC tJMP tJMPR
%token <nb> tNB
%token <var> tID

%right tEGAL
%left tOR tAND
%left tSUP tINF tINFEG tSUPEG tEGEG
%left tPLUS tMOINS
%left tSTAR tDIV tMOD
%left tP0 tPF

%start Asm
%%

Asm :	ListeInstr ;

ListeInstr :	Instr | Instr ListeInstr ;

Instr :		NOP | LOAD | STORE | AFC | COP | ADD | SUB | MUL | DIV | SUP | SUPE | INFE | EQU | OR | AND | INF | JMPC | JMP | JMPR ;

NOP : 		tNOP ;

LOAD : 		tLOAD tNB tNB tNB { tab_instr(LOAD, $2, $3, $4); } ;

STORE : 	tSTORE tNB tNB tNB { tab_instr(STORE, $2, $3, $4); } ;

AFC : 		tAFC tNB tNB tNB { tab_instr(AFC, $2, $3, $4); } ;

COP : 		tCOP tNB tNB tNB { tab_instr(COP, $2, $3, $4); } ;

ADD : 		tADD tNB tNB tNB { tab_instr(ADD, $2, $3, $4); } ;

SUB : 		tSUB tNB tNB tNB { tab_instr(SUB, $2, $3, $4); } ;

MUL : 		tMUL tNB tNB tNB { tab_instr(MUL, $2, $3, $4); } ;

DIV : 		tDIV tNB tNB tNB { tab_instr(DIV, $2, $3, $4); } ;

SUP : 		tSUP tNB tNB tNB { tab_instr(SUP, $2, $3, $4); } ;

SUPE : 		tSUPE tNB tNB tNB { tab_instr(SUPE, $2, $3, $4); } ;

INFE : 		tINFE tNB tNB tNB { tab_instr(INFE, $2, $3, $4); } ;

EQU : 		tEQU tNB tNB tNB { tab_instr(EQU, $2, $3, $4); } ;

OR : 		tOR tNB tNB tNB { tab_instr(OR, $2, $3, $4); } ;

AND : 		tAND tNB tNB tNB { tab_instr(AND, $2, $3, $4); } ;

INF : 		tINF tNB tNB tNB { tab_instr(INF, $2, $3, $4); } ; 

JMPC : 		tJMPC tNB tNB tNB { tab_instr(JMPC, $2, $3, $4); } ;

JMP : 		tJMP tNB tNB tNB { tab_instr(JMP, $2, $3, $4); } ;

JMPR : 		tJMPR tNB tNB tNB { tab_instr(JMPR, $2, $3, $4); } ;


%%
void yyerror(char *s) { fprintf(stderr , "%s\n", s); }

int main(void) {
        //printf("Mon Interpreteur\n"); // yydebug =1;
        yyparse ();
        translate ();
		printf("\n");
		affiche_reg ();
		affiche_mem ();
        return 0;
}