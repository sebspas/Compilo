/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tEGAL = 258,
    tPF = 259,
    tMOINS = 260,
    tPLUS = 261,
    tSTAR = 262,
    tDIV = 263,
    tMOD = 264,
    tRETURN = 265,
    tPRINTF = 266,
    tMAIN = 267,
    tELSE = 268,
    tINT = 269,
    tOR = 270,
    tAND = 271,
    tVIR = 272,
    tPVIR = 273,
    tACO = 274,
    tACF = 275,
    tEGEG = 276,
    tINF = 277,
    tINFEG = 278,
    tSUP = 279,
    tSUPEG = 280,
    tNB = 281,
    tIF = 282,
    tWHILE = 283,
    tPO = 284,
    tID = 285,
    tP0 = 286
  };
#endif
/* Tokens.  */
#define tEGAL 258
#define tPF 259
#define tMOINS 260
#define tPLUS 261
#define tSTAR 262
#define tDIV 263
#define tMOD 264
#define tRETURN 265
#define tPRINTF 266
#define tMAIN 267
#define tELSE 268
#define tINT 269
#define tOR 270
#define tAND 271
#define tVIR 272
#define tPVIR 273
#define tACO 274
#define tACF 275
#define tEGEG 276
#define tINF 277
#define tINFEG 278
#define tSUP 279
#define tSUPEG 280
#define tNB 281
#define tIF 282
#define tWHILE 283
#define tPO 284
#define tID 285
#define tP0 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 63 "parser.y" /* yacc.c:1909  */
 int nb; char var[16]; 

#line 119 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
