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
    tNOP = 258,
    tLOAD = 259,
    tSTORE = 260,
    tAFC = 261,
    tCOP = 262,
    tADD = 263,
    tSUB = 264,
    tMUL = 265,
    tDIV = 266,
    tSUP = 267,
    tPRI = 268,
    tSUPE = 269,
    tINFE = 270,
    tEQU = 271,
    tOR = 272,
    tAND = 273,
    tINF = 274,
    tJMPC = 275,
    tJMP = 276,
    tJMPR = 277,
    tNEG = 278,
    tNB = 279,
    tID = 280,
    tEGAL = 281,
    tINFEG = 282,
    tSUPEG = 283,
    tEGEG = 284,
    tPLUS = 285,
    tMOINS = 286,
    tSTAR = 287,
    tMOD = 288,
    tP0 = 289,
    tPF = 290
  };
#endif
/* Tokens.  */
#define tNOP 258
#define tLOAD 259
#define tSTORE 260
#define tAFC 261
#define tCOP 262
#define tADD 263
#define tSUB 264
#define tMUL 265
#define tDIV 266
#define tSUP 267
#define tPRI 268
#define tSUPE 269
#define tINFE 270
#define tEQU 271
#define tOR 272
#define tAND 273
#define tINF 274
#define tJMPC 275
#define tJMP 276
#define tJMPR 277
#define tNEG 278
#define tNB 279
#define tID 280
#define tEGAL 281
#define tINFEG 282
#define tSUPEG 283
#define tEGEG 284
#define tPLUS 285
#define tMOINS 286
#define tSTAR 287
#define tMOD 288
#define tP0 289
#define tPF 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 330 "interpretor.y" /* yacc.c:1909  */
 int nb; char var[16]; 

#line 127 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
