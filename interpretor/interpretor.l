%{
#include <stdlib.h>
#include <stdio.h>
#include "y.tab.h"
%}

blancs [ \t\n]+ 
nb [0-9]+ 
id [a-zA-Z]+[0-9]*

%%

{blancs} {}
{nb} {
    yylval.nb = atoi(yytext);
    return tNB;
}

"NOP"		return tNOP;
"LOAD"		return tLOAD;
"STORE"		return tSTORE;
"AFC"		return tAFC;
"COP"		return tCOP;
"ADD"		return tADD;
"SUB"		return tSUB;
"MUL"		return tMUL;
"DIV"		return tDIV;
"SUP"		return tSUP;
"SUPE"		return tSUPE;
"INFE"		return tINFE;
"EQU"		return tEQU;
"OR"		return tOR;
"AND"		return tAND;
"INF"		return tINF;
"JMPC"		return tJMPC;
"JMP"		return tJMP;
"JMPR"		return tJMPR;
"NEG"		return tNEG;

{id} {
    if (strlen(yytext) >= sizeof(yylval.var)-1 ){
        fprintf(stderr, "Var trop longue\n");
        exit(1);
    }
    strcpy(yylval.var, yytext);
    return tID;
}
