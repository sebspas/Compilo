/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
    tMAIN = 266,
    tELSE = 267,
    tINT = 268,
    tOR = 269,
    tAND = 270,
    tVIR = 271,
    tPVIR = 272,
    tACO = 273,
    tACF = 274,
    tEGEG = 275,
    tINF = 276,
    tINFEG = 277,
    tSUP = 278,
    tSUPEG = 279,
    tNB = 280,
    tIF = 281,
    tWHILE = 282,
    tPO = 283,
    tID = 284,
    tP0 = 285
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
#define tMAIN 266
#define tELSE 267
#define tINT 268
#define tOR 269
#define tAND 270
#define tVIR 271
#define tPVIR 272
#define tACO 273
#define tACF 274
#define tEGEG 275
#define tINF 276
#define tINFEG 277
#define tSUP 278
#define tSUPEG 279
#define tNB 280
#define tIF 281
#define tWHILE 282
#define tPO 283
#define tID 284
#define tP0 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 63 "parser.y" /* yacc.c:1909  */
 int nb; char var[16]; 

#line 117 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
