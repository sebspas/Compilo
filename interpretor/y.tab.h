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
    tSUPE = 268,
    tINFE = 269,
    tEQU = 270,
    tOR = 271,
    tAND = 272,
    tINF = 273,
    tJMPC = 274,
    tJMP = 275,
    tJMPR = 276,
    tNEG = 277,
    tNB = 278,
    tID = 279,
    tEGAL = 280,
    tINFEG = 281,
    tSUPEG = 282,
    tEGEG = 283,
    tPLUS = 284,
    tMOINS = 285,
    tSTAR = 286,
    tMOD = 287,
    tP0 = 288,
    tPF = 289
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
#define tSUPE 268
#define tINFE 269
#define tEQU 270
#define tOR 271
#define tAND 272
#define tINF 273
#define tJMPC 274
#define tJMP 275
#define tJMPR 276
#define tNEG 277
#define tNB 278
#define tID 279
#define tEGAL 280
#define tINFEG 281
#define tSUPEG 282
#define tEGEG 283
#define tPLUS 284
#define tMOINS 285
#define tSTAR 286
#define tMOD 287
#define tP0 288
#define tPF 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 318 "interpretor.y" /* yacc.c:1909  */
 int nb; char var[16]; 

#line 125 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
