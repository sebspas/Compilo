/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

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

#line 125 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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

union YYSTYPE
{
#line 59 "parser.y" /* yacc.c:355  */
 int nb; char var[16]; 

#line 228 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 245 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   185

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    76,    76,    76,    77,    79,    77,    83,    83,    84,
      84,    85,    89,    89,    90,    90,    91,    91,    91,    91,
      91,    91,    93,    94,    94,    95,   100,   108,   113,   113,
     162,   183,   183,   183,   184,   184,   185,   187,   191,   187,
     197,   197,   199,   199,   208,   211,   217,   228,   232,   233,
     234,   235,   236,   237,   238,   245,   246,   247,   248,   249
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tEGAL", "tPF", "tMOINS", "tPLUS",
  "tSTAR", "tDIV", "tMOD", "tRETURN", "tMAIN", "tELSE", "tINT", "tOR",
  "tAND", "tVIR", "tPVIR", "tACO", "tACF", "tEGEG", "tINF", "tINFEG",
  "tSUP", "tSUPEG", "tNB", "tIF", "tWHILE", "tPO", "tID", "tP0", "$accept",
  "Prg", "Fonction", "$@1", "$@2", "Args", "ListeArgs", "Arg", "Body",
  "$@3", "Instrcs", "Instr", "Decl", "DeclX", "Decl1", "Affect", "Invoc",
  "$@4", "Return", "Params", "ParamsNext", "Param", "If", "$@5", "$@6",
  "Else", "While", "$@7", "E", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285
};
# endif

#define YYPACT_NINF -91

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-91)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,   -14,    24,    -3,   -91,   -91,   -91,    -1,    12,     7,
      45,    34,   -91,   -91,    12,   -91,    10,    34,   -91,   -91,
     -91,   147,   -12,    22,    27,    28,    -2,    33,   147,   -91,
     -91,    40,   -91,   -91,   -91,   -91,   -12,    30,   -91,   101,
      67,    54,    56,   -12,   -12,   -12,   -91,   -91,   -91,   -91,
      39,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -91,   -12,
     -12,   -12,   -12,   -12,   -12,   -91,    22,    60,    81,   121,
     -12,   -91,    11,    11,   -91,   -91,   -91,   161,   161,     0,
       0,     0,     0,     0,   141,   -91,   -91,   -91,   -91,    69,
      61,   141,    10,    10,   -91,   -12,   -91,   -91,   -91,    62,
      64,   -12,    10,   -91,   -91,   -91
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     3,     4,     1,     2,     0,     8,     0,
       0,    10,    11,     5,     0,     7,     0,    10,    12,     6,
       9,    15,     0,     0,     0,     0,     0,     0,    15,    16,
      19,     0,    21,    17,    18,    45,     0,    46,    47,     0,
      25,     0,    23,     0,     0,     0,    28,    13,    14,    20,
       0,     0,     0,     0,     0,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     0,
      33,    44,    49,    48,    50,    51,    54,    52,    53,    55,
      57,    59,    56,    58,    26,    24,    37,    42,    27,     0,
      31,    36,     0,     0,    29,     0,    38,    43,    32,    34,
      41,     0,     0,    39,    35,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -91,    76,   -91,   -91,   -91,   -91,    74,    78,   -90,   -91,
      65,   -91,   -91,    31,   -91,   -91,   -17,   -91,   -91,   -91,
      -7,    29,   -91,   -91,   -91,   -91,   -91,   -91,   -22
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     7,    16,    10,    15,    11,    19,    21,
      27,    28,    29,    41,    42,    30,    38,    70,    32,    89,
      98,    99,    33,    92,   100,   103,    34,    93,    91
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,    45,    96,    97,    31,    51,    52,    53,    54,    55,
       1,    31,   105,    35,    50,     4,    36,    37,    53,    54,
      55,    67,    68,    69,     5,     9,    46,     8,    18,    72,
      73,    74,    75,    76,    77,    78,    12,    79,    80,    81,
      82,    83,    84,    71,    51,    52,    53,    54,    55,    13,
      14,    40,    47,    56,    57,    43,    44,    49,    46,    59,
      60,    61,    62,    63,    86,    51,    52,    53,    54,    55,
      64,    65,    66,    94,    56,    57,   102,    95,   101,     6,
      59,    60,    61,    62,    63,    87,    51,    52,    53,    54,
      55,    20,    17,    48,   104,    56,    57,    85,     0,    90,
       0,    59,    60,    61,    62,    63,    51,    52,    53,    54,
      55,     0,     0,     0,     0,    56,    57,     0,    58,     0,
       0,    59,    60,    61,    62,    63,    51,    52,    53,    54,
      55,     0,     0,     0,     0,    56,    57,     0,    88,     0,
       0,    59,    60,    61,    62,    63,    51,    52,    53,    54,
      55,     0,     0,     0,     0,    56,    57,    22,     0,     0,
      23,    59,    60,    61,    62,    63,    51,    52,    53,    54,
      55,     0,     0,    24,    25,     0,    26,     0,     0,     0,
       0,    59,    60,    61,    62,    63
};

static const yytype_int8 yycheck[] =
{
      22,     3,    92,    93,    21,     5,     6,     7,     8,     9,
      13,    28,   102,    25,    36,    29,    28,    29,     7,     8,
       9,    43,    44,    45,     0,    13,    28,    28,    18,    51,
      52,    53,    54,    55,    56,    57,    29,    59,    60,    61,
      62,    63,    64,     4,     5,     6,     7,     8,     9,     4,
      16,    29,    19,    14,    15,    28,    28,    17,    28,    20,
      21,    22,    23,    24,     4,     5,     6,     7,     8,     9,
       3,    17,    16,     4,    14,    15,    12,    16,    16,     3,
      20,    21,    22,    23,    24,     4,     5,     6,     7,     8,
       9,    17,    14,    28,   101,    14,    15,    66,    -1,    70,
      -1,    20,    21,    22,    23,    24,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    14,    15,    -1,    17,    -1,
      -1,    20,    21,    22,    23,    24,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    14,    15,    -1,    17,    -1,
      -1,    20,    21,    22,    23,    24,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    14,    15,    10,    -1,    -1,
      13,    20,    21,    22,    23,    24,     5,     6,     7,     8,
       9,    -1,    -1,    26,    27,    -1,    29,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    32,    33,    29,     0,    32,    34,    28,    13,
      36,    38,    29,     4,    16,    37,    35,    38,    18,    39,
      37,    40,    10,    13,    26,    27,    29,    41,    42,    43,
      46,    47,    49,    53,    57,    25,    28,    29,    47,    59,
      29,    44,    45,    28,    28,     3,    28,    19,    41,    17,
      59,     5,     6,     7,     8,     9,    14,    15,    17,    20,
      21,    22,    23,    24,     3,    17,    16,    59,    59,    59,
      48,     4,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    44,     4,     4,    17,    50,
      52,    59,    54,    58,     4,    16,    39,    39,    51,    52,
      55,    16,    12,    56,    51,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    32,    34,    35,    33,    36,    36,    37,
      37,    38,    40,    39,    41,    41,    42,    42,    42,    42,
      42,    42,    43,    44,    44,    45,    45,    46,    48,    47,
      49,    50,    50,    50,    51,    51,    52,    54,    55,    53,
      56,    56,    58,    57,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     0,     0,     8,     2,     0,     3,
       0,     2,     0,     4,     2,     0,     1,     1,     1,     1,
       2,     1,     3,     1,     3,     1,     3,     4,     0,     5,
       3,     1,     3,     0,     1,     3,     1,     0,     0,     8,
       2,     0,     0,     6,     3,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 77 "parser.y" /* yacc.c:1646  */
    { 
                    /*add_symb("@ret", TYPE_INT, IS_INIT, current_depth);*/
             }
#line 1409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 79 "parser.y" /* yacc.c:1646  */
    {
              add_func((yyvsp[-4].var), index_instr); 
          }
#line 1417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 81 "parser.y" /* yacc.c:1646  */
    { /*printf("===== FONCTION ====\n");*/ }
#line 1423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 83 "parser.y" /* yacc.c:1646  */
    { /*printf("Arg vide\n");*/}
#line 1429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 85 "parser.y" /* yacc.c:1646  */
    { 
                    add_symb((yyvsp[0].var), TYPE_INT, IS_INIT, current_depth+1);
                 }
#line 1437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 89 "parser.y" /* yacc.c:1646  */
    { current_depth++; print(); }
#line 1443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 89 "parser.y" /* yacc.c:1646  */
    { remove_depth(current_depth); current_depth--; }
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 95 "parser.y" /* yacc.c:1646  */
    { 
                    /*printf("Decl \n");*/
                    check_exist((yyvsp[0].var), current_depth);
                    add_symb((yyvsp[0].var), TYPE_INT, IS_INIT, current_depth);  
                }
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 100 "parser.y" /* yacc.c:1646  */
    { 
                    remove_var();
                    /*printf("Decl = \n");*/
                    check_exist((yyvsp[-2].var), current_depth);
                    int index = add_symb((yyvsp[-2].var), TYPE_INT, IS_INIT, current_depth); 
                    //affect_instr($3, index);
                }
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 108 "parser.y" /* yacc.c:1646  */
    {
                    int index = get_index_by_name((yyvsp[-3].var));
                    affect_instr((yyvsp[-1].nb), index);
                }
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 113 "parser.y" /* yacc.c:1646  */
    {
                    /*int lr = add_symb("@ret_invoke", TYPE_INT, IS_INIT, current_depth); 
                    op_instr(AFC, 0, -1, 42);
                    op_instr(STORE, lr, 0, 42); 
                    $2 = index_instr - 2;*/

                }
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 120 "parser.y" /* yacc.c:1646  */
    { 
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
                    int adr_f = get_adr_func((yyvsp[-4].var));
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
            }
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 162 "parser.y" /* yacc.c:1646  */
    { 
            remove_var();
            printf("return\n"); 
            print(); 

            // on met la valeur de retour dans r0
            op_instr(LOAD, 0, (yyvsp[-1].nb), 42);
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
}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 187 "parser.y" /* yacc.c:1646  */
    { 
                op_instr(LOAD, 0, (yyvsp[-1].nb), 42);                    
                op_instr(JMPC, -1, 0, 42);
                (yyvsp[-3].nb) = index_instr - 1; 
            }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 191 "parser.y" /* yacc.c:1646  */
    { 
                op_instr(JMP, -1, 42, 42); 
                set_dest_jmp((yyvsp[-5].nb), index_instr);
                (yyvsp[-5].nb) = index_instr - 1; 
            }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 195 "parser.y" /* yacc.c:1646  */
    { set_dest_jmp( (yyvsp[-7].nb), index_instr); }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 199 "parser.y" /* yacc.c:1646  */
    {
        op_instr(LOAD, 0, (yyvsp[-1].nb), 42);
        op_instr(JMPC, -1, 0, 42);
        (yyvsp[-3].nb) = index_instr - 1;
    }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 203 "parser.y" /* yacc.c:1646  */
    {
        set_dest_jmp((yyvsp[-5].nb), index_instr + 1);
        op_instr(JMP, ((yyvsp[-5].nb) - 1), 0, 42);
    }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 208 "parser.y" /* yacc.c:1646  */
    { 
                (yyval.nb) = (yyvsp[-1].nb);
         }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 211 "parser.y" /* yacc.c:1646  */
    { 
                int pos = add_symb("_", TYPE_INT, IS_INIT, current_depth);
                op_instr(AFC, 0, (yyvsp[0].nb), 0);
                op_instr(STORE, pos, 0, 0);
                (yyval.nb) = pos;
         }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 217 "parser.y" /* yacc.c:1646  */
    { 
                print();
                check_not_exist((yyvsp[0].var));
                int index = get_index_by_name((yyvsp[0].var));
                check_not_init(index);

                int pos = add_symb("_", TYPE_INT, IS_INIT, current_depth);
                op_instr(LOAD, 0, index, 0);
                op_instr(STORE, pos, 0, 0);
                (yyval.nb) = pos;
         }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 228 "parser.y" /* yacc.c:1646  */
    { 
                int pos = add_symb("_", TYPE_INT, IS_INIT, current_depth);
                (yyval.nb) = pos;
         }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 232 "parser.y" /* yacc.c:1646  */
    { (yyval.nb) = op_arith(ADD, (yyvsp[-2].nb), (yyvsp[0].nb)); }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 233 "parser.y" /* yacc.c:1646  */
    { (yyval.nb) = op_arith(SUB, (yyvsp[-2].nb), (yyvsp[0].nb)); }
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 234 "parser.y" /* yacc.c:1646  */
    { (yyval.nb) = op_arith(MUL, (yyvsp[-2].nb), (yyvsp[0].nb)); }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 235 "parser.y" /* yacc.c:1646  */
    { (yyval.nb) = op_arith(DIV, (yyvsp[-2].nb), (yyvsp[0].nb)); }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 236 "parser.y" /* yacc.c:1646  */
    { (yyval.nb) = op_arith(OR, (yyvsp[-2].nb), (yyvsp[0].nb));  }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 237 "parser.y" /* yacc.c:1646  */
    { (yyval.nb) = op_arith(AND, (yyvsp[-2].nb), (yyvsp[0].nb)); }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 238 "parser.y" /* yacc.c:1646  */
    {
            op_instr(AFC, 0, (yyvsp[-2].nb), 42);
            op_instr(AFC, 1, (yyvsp[0].nb), 42);
            op_instr(DIV, 2, 0, 1);
            op_instr(MUL, 1, 2, 42);
            op_instr(SUB, 0, 3, 42);
        }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 245 "parser.y" /* yacc.c:1646  */
    { (yyval.nb) = op_arith(EQU, (yyvsp[-2].nb), (yyvsp[0].nb)); }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 246 "parser.y" /* yacc.c:1646  */
    { (yyval.nb) = op_arith(SUP, (yyvsp[-2].nb), (yyvsp[0].nb)); }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 247 "parser.y" /* yacc.c:1646  */
    { (yyval.nb) = op_arith(INF, (yyvsp[-2].nb), (yyvsp[0].nb)); }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 248 "parser.y" /* yacc.c:1646  */
    { (yyval.nb) = op_arith(SUPE, (yyvsp[-2].nb), (yyvsp[0].nb)); }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 249 "parser.y" /* yacc.c:1646  */
    { (yyval.nb) = op_arith(INFE, (yyvsp[-2].nb), (yyvsp[0].nb)); }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1734 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 251 "parser.y" /* yacc.c:1906  */

void yyerror(char *s) { fprintf(stderr , "%s\n", s); }

int main(void) {
        //printf("Mon Parser\n"); // yydebug =1;
        yyparse ();
        affiche_instrs();
        return 0;
}
