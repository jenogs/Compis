
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "SimpleFlow.y"

#include <cstdio>
#include <iostream>
#include "Tablas.h"

using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
 
void yyerror(const char *s);

char tipo;
char tipocte;
char *proc;
int cParam = 0;




/* Line 189 of yacc.c  */
#line 95 "SimpleFlow.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NOMBRE = 258,
     BEGINP = 259,
     ENDP = 260,
     FUNCTION = 261,
     BEGINF = 262,
     ENDF = 263,
     CTEE = 264,
     CTEF = 265,
     IGU = 266,
     GLOBAL = 267,
     BOOLEAN = 268,
     ID = 269,
     MAY = 270,
     MEN = 271,
     DIF = 272,
     IF = 273,
     ELSE = 274,
     PRINT = 275,
     SUM = 276,
     RES = 277,
     MULT = 278,
     DIV = 279,
     STR = 280,
     INT = 281,
     FLOAT = 282,
     PROG = 283,
     VAR = 284,
     EQ = 285,
     BOOL = 286,
     AND = 287,
     OR = 288,
     STRING = 289,
     ELSEIF = 290,
     REPEAT = 291,
     READ = 292,
     CHAR = 293,
     CH = 294,
     DP = 295,
     PC = 296,
     COMA = 297,
     LLA = 298,
     LLC = 299,
     PARA = 300,
     PARC = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 22 "SimpleFlow.y"

	char *palabra;



/* Line 214 of yacc.c  */
#line 183 "SimpleFlow.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 195 "SimpleFlow.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   158

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNRULES -- Number of states.  */
#define YYNSTATES  150

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    12,    13,    16,    17,    21,    27,
      31,    32,    35,    37,    39,    41,    43,    45,    47,    53,
      56,    57,    60,    68,    69,    76,    77,    80,    86,    88,
      90,    91,    93,    95,    97,    99,   101,   107,   111,   113,
     119,   123,   126,   128,   132,   136,   140,   144,   148,   149,
     152,   155,   156,   161,   162,   167,   169,   170,   175,   176,
     181,   183,   187,   188,   192,   193,   197,   199,   201,   203,
     205,   207,   209,   211,   212,   213,   225,   226,   231,   232
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    -1,     3,    49,    51,    50,     4,    53,
       5,    -1,    -1,    82,    50,    -1,    -1,    12,    52,    51,
      -1,    64,    14,    30,    63,    41,    -1,    43,    54,    44,
      -1,    -1,    55,    54,    -1,    62,    -1,    59,    -1,    65,
      -1,    68,    -1,    67,    -1,    56,    -1,     3,    45,    57,
      46,    41,    -1,    14,    58,    -1,    -1,    42,    57,    -1,
      18,    45,    69,    46,    53,    60,    61,    -1,    -1,    35,
      45,    69,    46,    53,    60,    -1,    -1,    19,    53,    -1,
      64,    14,    30,    63,    41,    -1,    72,    -1,    56,    -1,
      -1,    26,    -1,    27,    -1,    31,    -1,    38,    -1,    25,
      -1,    20,    45,    66,    46,    41,    -1,    72,    42,    66,
      -1,    72,    -1,    37,    45,    14,    46,    41,    -1,    36,
      81,    53,    -1,    70,    71,    -1,    81,    -1,    72,    15,
      72,    -1,    72,    16,    72,    -1,    72,    17,    72,    -1,
      72,    11,    72,    -1,    45,    70,    46,    -1,    -1,    32,
      69,    -1,    33,    69,    -1,    -1,    75,    21,    73,    72,
      -1,    -1,    75,    22,    74,    72,    -1,    75,    -1,    -1,
      78,    23,    76,    75,    -1,    -1,    78,    24,    77,    75,
      -1,    78,    -1,    45,    72,    46,    -1,    -1,    21,    79,
      81,    -1,    -1,    22,    80,    81,    -1,    81,    -1,    14,
      -1,     9,    -1,    10,    -1,    34,    -1,    39,    -1,    13,
      -1,    -1,    -1,    64,     6,     3,    83,    45,    85,    46,
      84,     7,    53,     8,    -1,    -1,    64,    14,    86,    87,
      -1,    -1,    42,    85,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    38,    38,    38,    41,    42,    47,    48,    51,    70,
      73,    74,    79,    80,    81,    82,    83,    84,    89,    92,
      95,    96,   101,   104,   105,   108,   109,   114,   131,   132,
     137,   138,   139,   140,   141,   142,   147,   150,   151,   156,
     161,   166,   167,   170,   171,   172,   173,   174,   177,   178,
     179,   184,   184,   185,   185,   186,   191,   191,   192,   192,
     193,   198,   199,   199,   200,   200,   201,   206,   207,   208,
     209,   210,   211,   216,   223,   216,   226,   226,   229,   230
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NOMBRE", "BEGINP", "ENDP", "FUNCTION",
  "BEGINF", "ENDF", "CTEE", "CTEF", "IGU", "GLOBAL", "BOOLEAN", "ID",
  "MAY", "MEN", "DIF", "IF", "ELSE", "PRINT", "SUM", "RES", "MULT", "DIV",
  "STR", "INT", "FLOAT", "PROG", "VAR", "EQ", "BOOL", "AND", "OR",
  "STRING", "ELSEIF", "REPEAT", "READ", "CHAR", "CH", "DP", "PC", "COMA",
  "LLA", "LLC", "PARA", "PARC", "$accept", "programa", "$@1", "programa2",
  "asignaglobal", "asignaciong", "bloque", "bloque2", "estatuto",
  "funcion", "funcion2", "funcion3", "condicion", "condicion2",
  "condicion3", "asignacion", "asigna2", "tipo", "escritura", "escritura2",
  "lectura", "ciclo", "expresion", "expresion2", "operadorl", "exp", "$@2",
  "$@3", "termino", "$@4", "$@5", "factor", "$@6", "$@7", "varcte",
  "function", "$@8", "$@9", "function2", "$@10", "function3", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    49,    48,    50,    50,    51,    51,    52,    53,
      54,    54,    55,    55,    55,    55,    55,    55,    56,    57,
      58,    58,    59,    60,    60,    61,    61,    62,    63,    63,
      64,    64,    64,    64,    64,    64,    65,    66,    66,    67,
      68,    69,    69,    70,    70,    70,    70,    70,    71,    71,
      71,    73,    72,    74,    72,    72,    76,    75,    77,    75,
      75,    78,    79,    78,    80,    78,    78,    81,    81,    81,
      81,    81,    81,    83,    84,    82,    86,    85,    87,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     7,     0,     2,     0,     3,     5,     3,
       0,     2,     1,     1,     1,     1,     1,     1,     5,     2,
       0,     2,     7,     0,     6,     0,     2,     5,     1,     1,
       0,     1,     1,     1,     1,     1,     5,     3,     1,     5,
       3,     2,     1,     3,     3,     3,     3,     3,     0,     2,
       2,     0,     4,     0,     4,     1,     0,     4,     0,     4,
       1,     3,     0,     3,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     0,     0,    11,     0,     4,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     6,     1,    30,     4,    35,    31,    32,
      33,    34,     6,     0,     0,     0,     4,     7,     0,     0,
       0,     5,     0,    10,     0,    73,     0,    68,    69,    72,
      67,    62,    64,    70,    71,     0,    29,     0,    28,    55,
      60,    66,     0,     0,     0,     0,     0,    10,    17,    13,
      12,     0,    14,    16,    15,     3,     0,     0,     0,     0,
       0,     8,    51,    53,    56,    58,     0,     0,     0,     0,
       9,    11,     0,    30,    20,     0,    63,    65,    61,     0,
       0,     0,     0,     0,     0,    48,     0,    66,     0,    38,
      40,     0,     0,     0,     0,     0,    19,     0,    52,    54,
      57,    59,     0,     0,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,     0,     0,    76,    74,    21,    18,
      47,    23,    49,    50,    46,    43,    44,    45,    36,    37,
      39,    27,    78,     0,     0,    25,    30,    77,     0,     0,
       0,    22,    79,     0,     0,    26,    75,     0,    23,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    14,     6,    12,    24,    46,    47,    36,
      75,    96,    49,   135,   141,    50,    37,    15,    52,    88,
      53,    54,    84,    85,   107,    86,    79,    80,    39,    81,
      82,    40,    58,    59,    41,    16,    56,   133,    94,   132,
     137
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -80
static const yytype_int16 yypact[] =
{
       8,   -80,    17,    12,   -80,   110,   107,   -80,   -80,   -80,
     -80,   -80,    12,    34,    45,    46,   107,   -80,    24,    13,
      52,   -80,     0,    92,    54,   -80,    16,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,    19,   -80,    26,   -80,   -14,
     -19,   -80,    30,    32,    37,    33,    21,    92,   -80,   -80,
     -80,    71,   -80,   -80,   -80,   -80,    41,    73,    37,    37,
      42,   -80,   -80,   -80,   -80,   -80,    70,    19,    13,    75,
     -80,   -80,    60,   110,    51,    48,   -80,   -80,   -80,    19,
      19,    19,    19,    70,    56,   -13,   105,    59,    61,    55,
     -80,    62,     0,    97,    68,    73,   -80,    83,   -80,   -80,
     -80,   -80,    79,    20,    13,    70,    70,   -80,    19,    19,
      19,    19,    85,    19,    86,    98,   -80,   -80,   -80,   -80,
     -80,   108,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   100,   133,    99,   127,   110,   -80,    13,    70,
      13,   -80,   -80,   139,   103,   -80,   -80,    13,   108,   -80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -80,   134,   140,   -80,   -66,   104,   -80,   -17,
      58,   -80,   -80,     6,   -80,   -80,    63,    -5,   -80,    43,
     -80,   -80,   -79,    74,   -80,   -10,   -80,   -80,   -38,   -80,
     -80,   -80,   -80,   -80,   -43,   -80,   -80,   -80,    22,   -80,
     -80
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -43
static const yytype_int16 yytable[] =
{
      13,    68,    90,    26,    64,    65,    48,    62,    63,    27,
      28,     1,    38,    29,    30,    76,    77,     4,    51,   105,
     106,    31,    32,    87,     5,    60,   122,   123,    27,    28,
      48,   108,    29,    30,    33,   109,   110,   111,   121,    34,
      31,    32,    51,   100,   101,    35,    27,    28,    18,    19,
      29,    30,    20,    33,    22,    25,    23,    89,    34,    55,
     144,    57,    87,    87,    35,    70,    78,    61,    93,    98,
      99,    33,   143,   103,   145,    66,    34,    67,    69,    27,
      28,   148,    38,    29,    30,    72,    73,    74,    78,    91,
      92,    31,    32,    95,    97,    26,    87,   113,   124,   125,
     126,   127,   104,    89,    33,   -42,   -30,   112,   114,    34,
      42,   116,    43,   -30,   117,    83,   108,     7,     8,     9,
     109,   110,   111,    10,   119,   120,   128,   130,    44,    45,
      11,    93,     7,     8,     9,     7,     8,     9,    10,   131,
     138,    10,   136,   134,   139,    11,   140,   146,    11,   147,
      21,    71,    17,   118,   149,   115,   129,   102,   142
};

static const yytype_uint8 yycheck[] =
{
       5,    44,    68,     3,    23,    24,    23,    21,    22,     9,
      10,     3,    22,    13,    14,    58,    59,     0,    23,    32,
      33,    21,    22,    66,    12,    35,   105,   106,     9,    10,
      47,    11,    13,    14,    34,    15,    16,    17,   104,    39,
      21,    22,    47,    81,    82,    45,     9,    10,    14,     4,
      13,    14,     6,    34,    30,     3,    43,    67,    39,     5,
     139,    45,   105,   106,    45,    44,    46,    41,    73,    79,
      80,    34,   138,    83,   140,    45,    39,    45,    45,     9,
      10,   147,    92,    13,    14,    14,    45,    14,    46,    14,
      30,    21,    22,    42,    46,     3,   139,    42,   108,   109,
     110,   111,    46,   113,    34,    46,    14,    46,    46,    39,
      18,    14,    20,     6,    46,    45,    11,    25,    26,    27,
      15,    16,    17,    31,    41,    46,    41,    41,    36,    37,
      38,   136,    25,    26,    27,    25,    26,    27,    31,    41,
       7,    31,    42,    35,    45,    38,    19,     8,    38,    46,
      16,    47,    12,    95,   148,    92,   113,    83,   136
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    48,    49,     0,    12,    51,    25,    26,    27,
      31,    38,    52,    64,    50,    64,    82,    51,    14,     4,
       6,    50,    30,    43,    53,     3,     3,     9,    10,    13,
      14,    21,    22,    34,    39,    45,    56,    63,    72,    75,
      78,    81,    18,    20,    36,    37,    54,    55,    56,    59,
      62,    64,    65,    67,    68,     5,    83,    45,    79,    80,
      72,    41,    21,    22,    23,    24,    45,    45,    81,    45,
      44,    54,    14,    45,    14,    57,    81,    81,    46,    73,
      74,    76,    77,    45,    69,    70,    72,    81,    66,    72,
      53,    14,    30,    64,    85,    42,    58,    46,    72,    72,
      75,    75,    70,    72,    46,    32,    33,    71,    11,    15,
      16,    17,    46,    42,    46,    63,    14,    46,    57,    41,
      46,    53,    69,    69,    72,    72,    72,    72,    41,    66,
      41,    41,    86,    84,    35,    60,    42,    87,     7,    45,
      19,    61,    85,    53,    69,    53,     8,    46,    53,    60
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 38 "SimpleFlow.y"
    { insertaProc('n', (yyvsp[(1) - (1)].palabra));;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 38 "SimpleFlow.y"
    { printf("Programa completo\n"); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 42 "SimpleFlow.y"
    { printf("Funcion\n"); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 48 "SimpleFlow.y"
    { printf("Asignacion global\n"); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 51 "SimpleFlow.y"
    { if(buscaVar((yyvsp[(2) - (5)].palabra))){
					if(tipo == 'n') {
						//asigna
					} else {
						printf("Error: Variable global existente: %s", (yyvsp[(2) - (5)].palabra));
					}
				    } else {
					if(tipo == tipocte) {
						insertaVarGlobal(tipo, (yyvsp[(2) - (5)].palabra));
						printf("Asignacion Completa en tabla de Variables Globales\n");
					} else {
						printf("Error: Tipos no compatibles");
					}
				   }
				;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 70 "SimpleFlow.y"
    { printf("Bloque completo\n"); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 74 "SimpleFlow.y"
    { printf("Bloque2 completo\n"); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 89 "SimpleFlow.y"
    { printf("Funcion\n"); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 101 "SimpleFlow.y"
    { printf("Condicion Completa\n"); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 114 "SimpleFlow.y"
    { if(buscaVar((yyvsp[(2) - (5)].palabra))){
					if(tipo == 'n') {
						//asigna
					} else {
						printf("Error: Variable local existente: %s", (yyvsp[(2) - (5)].palabra));
					}
				    } else {
					if(tipo == tipocte) {
						insertaVar(tipo, (yyvsp[(2) - (5)].palabra), proc);
						printf("Asignacion Completa\n");
					} else {
						printf("Error: Tipos no compatibles");
					}
				     }
				   ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 137 "SimpleFlow.y"
    { tipo = 'n'; ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 138 "SimpleFlow.y"
    { tipo = 'i'; ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 139 "SimpleFlow.y"
    { tipo = 'f'; ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 140 "SimpleFlow.y"
    { tipo = 'b'; ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 141 "SimpleFlow.y"
    { tipo = 'c'; ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 142 "SimpleFlow.y"
    { tipo = 's'; ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 147 "SimpleFlow.y"
    { printf("Escritura Completa\n"); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 156 "SimpleFlow.y"
    { printf("Lectura completa\n"); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 161 "SimpleFlow.y"
    { printf("Ciclo completo\n"); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 166 "SimpleFlow.y"
    { printf("Termina expresion\n"); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 167 "SimpleFlow.y"
    { printf("Termina expresion booleana\n"); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 170 "SimpleFlow.y"
    { printf("Mayor que\n"); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 171 "SimpleFlow.y"
    { printf("Menor que\n"); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 174 "SimpleFlow.y"
    { printf("Termina expresion2\n"); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 184 "SimpleFlow.y"
    { /*meterPOper(); */;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 185 "SimpleFlow.y"
    { /*meterPOper(); */;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 191 "SimpleFlow.y"
    { /*meterPOper(); */;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 192 "SimpleFlow.y"
    { /*meterPOper(); */;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 199 "SimpleFlow.y"
    { /*meterPOper(); */;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 200 "SimpleFlow.y"
    { /*meterPOper(); */;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 206 "SimpleFlow.y"
    {/*meterPilaO(); */;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 207 "SimpleFlow.y"
    { agragaCte('i', (yyvsp[(1) - (1)].palabra)); tipocte = 'i'; /*meterPilaO(); */;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 208 "SimpleFlow.y"
    { agragaCte('f', (yyvsp[(1) - (1)].palabra)); tipocte = 'f'; /*meterPilaO(); */;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 209 "SimpleFlow.y"
    { agragaCte('s', (yyvsp[(1) - (1)].palabra)); tipocte = 's'; /*meterPilaO(); */;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 210 "SimpleFlow.y"
    { agragaCte('c', (yyvsp[(1) - (1)].palabra)); tipocte = 'c';  /*meterPilaO(); */;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 211 "SimpleFlow.y"
    { agragaCte('b', (yyvsp[(1) - (1)].palabra)); tipocte = 'b'; /*meterPilaO(); */;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 216 "SimpleFlow.y"
    { if(!buscaProc((yyvsp[(3) - (3)].palabra))) {
					insertaProc(tipo, (yyvsp[(3) - (3)].palabra));
					proc = (yyvsp[(3) - (3)].palabra);
				 } else {
					printf("Error: Procedimiento existente.");
				 }
				;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 223 "SimpleFlow.y"
    { cParam = 0; ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 226 "SimpleFlow.y"
    { insertaParam(tipo, (yyvsp[(2) - (2)].palabra), cParam); cParam++; ;}
    break;



/* Line 1455 of yacc.c  */
#line 1829 "SimpleFlow.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 233 "SimpleFlow.y"


main() {
	
	FILE *myfile = fopen("prueba", "r");
	if (!myfile) {
		printf("No se puede abrir el archivo!");
		return -1;
	}
	yyin = myfile;
	
	do {
		yyparse();
	} while (!feof(yyin));
}

void yyerror(const char *s) {
	cout << "Error!  Mensaje: " << s << endl;
	exit(-1);
}

