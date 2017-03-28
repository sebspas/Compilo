%{
#include <stdlib.h>
#include <stdio.h>
#include "y.tab.h"
%}

%option yylineno

blancs [ \t\n]+ 
nb [0-9]+ 
id [a-zA-Z]+[0-9]*
%x C_COMMENT
%%

{blancs} {}
{nb} {
    yylval.nb = atoi(yytext);
    return tNB;
}



"/*"            { BEGIN(C_COMMENT); }
<C_COMMENT>"*/" { BEGIN(INITIAL); }
<C_COMMENT>\n   { }
<C_COMMENT>.    { }

"="         return tEGAL;
"-"         return tMOINS;
"+"         return tPLUS;
"*"         return tSTAR;
"%"         return tMOD;
"/"         return tDIV;
"("         return tPO;
")"         return tPF;
"if"        return tIF;
"else"      return tELSE;
"while"     return tWHILE;
"int"       return tINT;
"return"    return tRETURN;
{id} {
    if (strlen(yytext) >= sizeof(yylval.var)-1 ){
        fprintf(stderr, "Var trop longue\n");
        exit(1);
    }
    strcpy(yylval.var, yytext);
    return tID;
}
"||"        return tOR;
"=="        return tEGEG;
"&&"        return tAND;
","         return tVIR;
";"         return tPVIR;
"{"         return tACO;
"}"         return tACF;
">"         return tSUP;
"<"         return tINF;
">="        return tSUPEG;
"<="        return tINFEG;
