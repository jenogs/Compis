
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
#include <string.h>
#include <stdlib.h>
#include "Tablas.h"
#include "Pilas.h"
#include "Cuadruplos.h"
#include "Cubo.h"

using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
 
void yyerror(const char *s);

char tipo;
char scope;
char flagTipo; //Bandera usada para revision del tipo en la asignación
int tipoAux; //Auxiliar para el tipo de variable en la asignación
int cParam = 0;
int numVarInt = 0;
int numVarFloat = 0;
int numVarChar = 0;
int numVarStr = 0;
int numVarBool = 0;
int aux = 0;
int op; //operador
int auxif;
int k = 0;
int numret = 0;
char tipoFunc;
char idProc[100];

void generacionDeCuadruplos(int oper);
void asignaTipoAux(char tipo);
void sumaVar(char tipo);
void reiniciaContVars();
void reiniciaContTemp();
char * subString(char* str, int start, int length);



/* Line 189 of yacc.c  */
#line 119 "SimpleFlow.tab.c"

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
     BEGINP = 258,
     ENDP = 259,
     FUNCTION = 260,
     BEGINF = 261,
     ENDF = 262,
     IGU = 263,
     GLOBAL = 264,
     RETURN = 265,
     MAY = 266,
     MEN = 267,
     DIF = 268,
     IF = 269,
     ELSE = 270,
     PRINT = 271,
     SUM = 272,
     RES = 273,
     MULT = 274,
     DIV = 275,
     STR = 276,
     INT = 277,
     FLOAT = 278,
     PROG = 279,
     VAR = 280,
     EQ = 281,
     BOOL = 282,
     AND = 283,
     OR = 284,
     REPEAT = 285,
     READ = 286,
     CHAR = 287,
     DP = 288,
     PC = 289,
     COMA = 290,
     LLA = 291,
     LLC = 292,
     PARA = 293,
     PARC = 294,
     ID = 295,
     NOMBRE = 296,
     STRING = 297,
     CTEE = 298,
     CTEF = 299,
     BOOLEAN = 300,
     CH = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 46 "SimpleFlow.y"

	char ch;
	char *string;



/* Line 214 of yacc.c  */
#line 208 "SimpleFlow.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 220 "SimpleFlow.tab.c"

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
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNRULES -- Number of states.  */
#define YYNSTATES  190

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
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,    14,    15,    18,    19,    23,
      25,    26,    29,    35,    40,    44,    45,    48,    50,    51,
      54,    56,    58,    60,    62,    64,    66,    67,    74,    75,
      76,    80,    81,    82,    86,    87,    98,    99,   106,   108,
     109,   110,   116,   121,   124,   126,   130,   132,   134,   136,
     138,   140,   146,   147,   152,   154,   160,   161,   168,   171,
     172,   177,   178,   183,   184,   189,   190,   195,   199,   200,
     201,   205,   206,   210,   214,   215,   216,   217,   221,   222,
     226,   230,   231,   232,   233,   237,   238,   242,   246,   247,
     251,   252,   256,   258,   260,   262,   264,   266,   268,   270,
     271,   272,   287,   288,   289,   294,   295
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    -1,    -1,    41,    49,    52,    51,     3,
      50,    56,     4,    -1,    -1,   105,    51,    -1,    -1,     9,
      54,    52,    -1,    53,    -1,    -1,    55,    53,    -1,    75,
      40,    26,    91,    34,    -1,    40,    26,    91,    34,    -1,
      36,    57,    37,    -1,    -1,    72,    57,    -1,    58,    -1,
      -1,    59,    58,    -1,    66,    -1,    76,    -1,    80,    -1,
      79,    -1,    60,    -1,    74,    -1,    -1,    41,    38,    61,
      62,    39,    34,    -1,    -1,    -1,    91,    63,    64,    -1,
      -1,    -1,    35,    65,    62,    -1,    -1,    14,    38,    82,
      39,    67,    36,    58,    71,    37,    68,    -1,    -1,    15,
      69,    36,    58,    71,    37,    -1,    70,    -1,    -1,    -1,
      10,    38,    91,    39,    34,    -1,    75,    40,    26,    73,
      -1,    91,    34,    -1,    60,    -1,    40,    26,    73,    -1,
      22,    -1,    23,    -1,    27,    -1,    32,    -1,    21,    -1,
      16,    38,    77,    39,    34,    -1,    -1,    91,    78,    35,
      77,    -1,    91,    -1,    31,    38,    40,    39,    34,    -1,
      -1,    30,   104,    81,    36,    58,    37,    -1,    83,    88,
      -1,    -1,    91,    11,    84,    91,    -1,    -1,    91,    12,
      85,    91,    -1,    -1,    91,    13,    86,    91,    -1,    -1,
      91,     8,    87,    91,    -1,    38,    83,    39,    -1,    -1,
      -1,    28,    89,    82,    -1,    -1,    29,    90,    82,    -1,
      96,    92,    93,    -1,    -1,    -1,    -1,    17,    94,    91,
      -1,    -1,    18,    95,    91,    -1,   101,    97,    98,    -1,
      -1,    -1,    -1,    19,    99,    96,    -1,    -1,    20,   100,
      96,    -1,    38,    91,    39,    -1,    -1,    17,   102,   104,
      -1,    -1,    18,   103,   104,    -1,   104,    -1,    40,    -1,
      43,    -1,    44,    -1,    42,    -1,    46,    -1,    45,    -1,
      -1,    -1,    75,     5,    41,   106,    38,   108,    39,   107,
       6,    36,    57,    71,    37,     7,    -1,    -1,    -1,    75,
      40,   109,   110,    -1,    -1,    35,   108,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    69,    69,    69,    69,    72,    73,    78,    79,    80,
      83,    84,    87,   103,   115,   118,   119,   120,   123,   124,
     129,   130,   131,   132,   133,   134,   139,   139,   151,   152,
     152,   157,   158,   158,   163,   163,   173,   173,   174,   177,
     180,   181,   188,   205,   206,   209,   221,   222,   223,   224,
     225,   230,   233,   233,   234,   239,   244,   244,   254,   257,
     257,   260,   260,   263,   263,   266,   266,   269,   272,   273,
     273,   276,   276,   283,   286,   293,   294,   294,   295,   295,
     300,   303,   310,   311,   311,   312,   312,   317,   318,   318,
     319,   319,   320,   325,   326,   327,   328,   329,   330,   335,
     343,   335,   346,   347,   347,   350,   351
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BEGINP", "ENDP", "FUNCTION", "BEGINF",
  "ENDF", "IGU", "GLOBAL", "RETURN", "MAY", "MEN", "DIF", "IF", "ELSE",
  "PRINT", "SUM", "RES", "MULT", "DIV", "STR", "INT", "FLOAT", "PROG",
  "VAR", "EQ", "BOOL", "AND", "OR", "REPEAT", "READ", "CHAR", "DP", "PC",
  "COMA", "LLA", "LLC", "PARA", "PARC", "ID", "NOMBRE", "STRING", "CTEE",
  "CTEF", "BOOLEAN", "CH", "$accept", "programa", "$@1", "$@2",
  "programa2", "asignaglobal", "asignaglobal2", "asignaciong",
  "otraasignaciong", "bloque", "bloque2", "bloque3", "estatuto", "funcion",
  "$@3", "funcion2", "$@4", "funcion3", "$@5", "condicion", "$@6",
  "condicion2", "$@7", "condicion3", "ret", "asignacion", "asigna2",
  "otraasignacion", "tipo", "escritura", "escritura2", "$@8", "lectura",
  "ciclo", "$@9", "expresion", "expresion2", "$@10", "$@11", "$@12",
  "$@13", "operadorl", "$@14", "$@15", "exp", "exp1", "exp11", "$@16",
  "$@17", "termino", "termino1", "termino11", "$@18", "$@19", "factor",
  "$@20", "$@21", "varcte", "function", "$@22", "$@23", "function2",
  "$@24", "function3", 0
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
       0,    47,    49,    50,    48,    51,    51,    52,    52,    52,
      53,    53,    54,    55,    56,    57,    57,    57,    58,    58,
      59,    59,    59,    59,    59,    59,    61,    60,    62,    63,
      62,    64,    65,    64,    67,    66,    69,    68,    68,    70,
      71,    71,    72,    73,    73,    74,    75,    75,    75,    75,
      75,    76,    78,    77,    77,    79,    81,    80,    82,    84,
      83,    85,    83,    86,    83,    87,    83,    83,    88,    89,
      88,    90,    88,    91,    92,    93,    94,    93,    95,    93,
      96,    97,    98,    99,    98,   100,    98,   101,   102,   101,
     103,   101,   101,   104,   104,   104,   104,   104,   104,   106,
     107,   105,   108,   109,   108,   110,   110
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     8,     0,     2,     0,     3,     1,
       0,     2,     5,     4,     3,     0,     2,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     0,     6,     0,     0,
       3,     0,     0,     3,     0,    10,     0,     6,     1,     0,
       0,     5,     4,     2,     1,     3,     1,     1,     1,     1,
       1,     5,     0,     4,     1,     5,     0,     6,     2,     0,
       4,     0,     4,     0,     4,     0,     4,     3,     0,     0,
       3,     0,     3,     3,     0,     0,     0,     3,     0,     3,
       3,     0,     0,     0,     3,     0,     3,     3,     0,     3,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     0,
       0,    14,     0,     0,     4,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     7,     1,     0,     0,     5,     9,    10,
      50,    46,    47,    48,    49,     7,     0,     0,     0,     0,
       5,    11,     8,     0,    88,    90,     0,    93,    96,    94,
      95,    98,    97,     0,    74,    81,    92,     3,     0,     6,
       0,     0,     0,     0,    13,    75,    82,     0,    99,     0,
      89,    91,    87,    76,    78,    73,    83,    85,    80,    15,
       0,     0,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,    24,    20,    15,    25,
       0,    21,    23,    22,     4,   102,    77,    79,    84,    86,
       0,     0,    56,     0,     0,    26,    14,    19,    16,     0,
       0,     0,     0,     0,    68,     0,     0,    52,     0,     0,
      44,    45,     0,    28,     0,   103,   100,     0,     0,    34,
      69,    71,    58,    65,    59,    61,    63,     0,     0,    18,
       0,    43,     0,    29,    42,   105,     0,    67,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,    55,     0,
      31,   102,   104,     0,    18,    70,    72,    66,    60,    62,
      64,    53,    57,    27,    32,    30,   106,    15,    40,    28,
      40,     0,     0,    33,     0,     0,    39,     0,     0,    36,
      35,    38,   101,     0,     0,    41,    18,    40,     0,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    47,    18,     7,     8,    15,     9,    60,
      73,    74,    75,    76,   113,   132,   150,   165,   169,    77,
     138,   180,   184,   181,   172,    78,   111,    79,    80,    81,
     106,   128,    82,    83,   108,   103,   104,   142,   143,   144,
     141,   122,   139,   140,   105,    45,    55,    63,    64,    34,
      46,    58,    65,    66,    35,    41,    42,    36,    20,    61,
     136,   101,   135,   152
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -156
static const yytype_int16 yypact[] =
{
     -36,  -156,     8,    -3,  -156,    48,    -8,    48,  -156,   -11,
    -156,  -156,  -156,  -156,  -156,    -3,    -9,    22,    33,    40,
      48,  -156,  -156,    23,  -156,  -156,    22,  -156,  -156,  -156,
    -156,  -156,  -156,    25,  -156,  -156,  -156,  -156,    16,  -156,
      22,    44,    44,    24,  -156,    55,     1,    46,  -156,    27,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,     3,
      72,    57,  -156,    22,    22,    22,    22,    60,    62,    44,
      64,    67,    76,    79,  -156,    78,  -156,  -156,     3,  -156,
      83,  -156,  -156,  -156,  -156,    48,  -156,  -156,  -156,  -156,
      61,    22,  -156,    88,    10,  -156,  -156,  -156,  -156,   106,
      93,    95,    61,    96,    82,   109,    97,    98,   102,   100,
    -156,  -156,   107,    22,    10,  -156,  -156,   101,    -1,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,   108,   110,    78,
     112,  -156,   104,  -156,  -156,   113,   138,  -156,   114,    61,
      61,    22,    22,    22,    22,  -156,    22,   116,  -156,   115,
     119,    48,  -156,   120,    78,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,     3,   141,    22,
     141,   117,   122,  -156,   123,    22,   142,   154,   124,  -156,
    -156,  -156,  -156,   128,   129,  -156,    78,   141,   127,  -156
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,  -156,  -156,  -156,   146,   152,   159,  -156,  -156,  -156,
     -76,   -71,  -156,   -72,  -156,     0,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -155,  -156,    56,  -156,    -4,  -156,
      26,  -156,  -156,  -156,  -156,   -27,    69,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,   -17,  -156,  -156,  -156,  -156,    65,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,   -28,  -156,  -156,
    -156,    28,  -156,  -156
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -55
static const yytype_int16 yytable[] =
{
      33,    16,    98,    19,    97,     1,     5,   123,     4,    43,
     124,   125,   126,    50,    51,   174,    19,    67,    17,    68,
      56,    57,   110,    49,    10,    11,    12,    24,    25,     6,
      13,    23,   188,    69,    70,    14,    37,     6,    52,    24,
      25,    92,   110,    71,    72,    38,    86,    87,    26,    40,
      27,    72,    28,    29,    30,    31,    32,    48,   147,    44,
      26,    62,    27,    52,    28,    29,    30,    31,    32,    10,
      11,    12,    53,    54,   107,    13,    84,   112,    24,    25,
      14,   100,    59,   168,    27,   118,    28,    29,    30,    31,
      32,   170,    67,    94,    68,    85,   133,   112,    90,   102,
      91,    27,    93,    28,    29,    30,    31,    32,    69,    70,
     120,   121,   155,   156,    95,   187,    96,   123,    71,    72,
     124,   125,   126,    99,   157,   158,   159,   160,   109,   107,
      88,    89,   114,   115,   116,   119,   127,   -54,   129,   130,
     137,   131,   145,   149,   153,   146,   148,   100,   151,   163,
     154,   171,   133,   162,   164,   175,   167,   179,   178,   176,
     177,   182,   185,   183,   189,   186,    39,    22,    21,   173,
     134,   117,   161,     0,     0,     0,     0,     0,     0,   166
};

static const yytype_int16 yycheck[] =
{
      17,     5,    78,     7,    75,    41,     9,     8,     0,    26,
      11,    12,    13,    41,    42,   170,    20,    14,    26,    16,
      19,    20,    94,    40,    21,    22,    23,    17,    18,    40,
      27,    40,   187,    30,    31,    32,     3,    40,    39,    17,
      18,    69,   114,    40,    41,     5,    63,    64,    38,    26,
      40,    41,    42,    43,    44,    45,    46,    41,   129,    34,
      38,    34,    40,    39,    42,    43,    44,    45,    46,    21,
      22,    23,    17,    18,    91,    27,     4,    94,    17,    18,
      32,    85,    36,   154,    40,   102,    42,    43,    44,    45,
      46,   167,    14,    26,    16,    38,   113,   114,    38,    38,
      38,    40,    38,    42,    43,    44,    45,    46,    30,    31,
      28,    29,   139,   140,    38,   186,    37,     8,    40,    41,
      11,    12,    13,    40,   141,   142,   143,   144,    40,   146,
      65,    66,    26,    40,    39,    39,    39,    39,    36,    39,
      39,    34,    34,    39,     6,    35,    34,   151,    35,    34,
      36,    10,   169,    37,    35,    38,    36,    15,   175,    37,
      37,     7,    34,    39,    37,    36,    20,    15,     9,   169,
     114,   102,   146,    -1,    -1,    -1,    -1,    -1,    -1,   151
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    48,    49,     0,     9,    40,    52,    53,    55,
      21,    22,    23,    27,    32,    54,    75,    26,    51,    75,
     105,    53,    52,    40,    17,    18,    38,    40,    42,    43,
      44,    45,    46,    91,    96,   101,   104,     3,     5,    51,
      26,   102,   103,    91,    34,    92,    97,    50,    41,    91,
     104,   104,    39,    17,    18,    93,    19,    20,    98,    36,
      56,   106,    34,    94,    95,    99,   100,    14,    16,    30,
      31,    40,    41,    57,    58,    59,    60,    66,    72,    74,
      75,    76,    79,    80,     4,    38,    91,    91,    96,    96,
      38,    38,   104,    38,    26,    38,    37,    58,    57,    40,
      75,   108,    38,    82,    83,    91,    77,    91,    81,    40,
      60,    73,    91,    61,    26,    40,    39,    83,    91,    39,
      28,    29,    88,     8,    11,    12,    13,    39,    78,    36,
      39,    34,    62,    91,    73,   109,   107,    39,    67,    89,
      90,    87,    84,    85,    86,    34,    35,    58,    34,    39,
      63,    35,   110,     6,    36,    82,    82,    91,    91,    91,
      91,    77,    37,    34,    35,    64,   108,    36,    58,    65,
      57,    10,    71,    62,    71,    38,    37,    37,    91,    15,
      68,    70,     7,    39,    69,    34,    36,    58,    71,    37
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
#line 69 "SimpleFlow.y"
    { insertaProc('n', (yyvsp[(1) - (1)].string)); scope = 'g'; generaGoTo(); pushPSaltos(apunta_cuadruplo-1); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 69 "SimpleFlow.y"
    { scope = 'l'; rellenaGoTo(popPSaltos(), apunta_cuadruplo); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 69 "SimpleFlow.y"
    { printf("Programa completo\n"); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 73 "SimpleFlow.y"
    { printf("Funcion\n"); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 87 "SimpleFlow.y"
    { pushPOper(300); asignaTipoAux(tipo);
				    if(buscaVar((yyvsp[(2) - (5)].string), 'g') != -1){
						printf("Error: Variable global existente: %s\n", (yyvsp[(2) - (5)].string));
				    } else {
					insertaVarGlobal(tipo, (yyvsp[(2) - (5)].string));
					printf("Asignacion Completa en tabla de Variables Globales\n");
					if(cubo[cimaPTipos()][tipoAux][8] != 'x') {
						generaCuadruplo(popPOper(), popPilaO(), -1, buscaVar((yyvsp[(2) - (5)].string), 'g'));
						
					} else {
						printf("Error: Tipos no compatibles\n");
					}
				   }
				;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 103 "SimpleFlow.y"
    { pushPOper(300); asignaTipoAux(buscaVarTipo((yyvsp[(1) - (4)].string), 'g'));
				    if(buscaVar((yyvsp[(1) - (4)].string), 'g') != -1){
					if(cubo[cimaPTipos()][tipoAux][8] != 'x') {
						generaCuadruplo(popPOper(), popPilaO(), -1, buscaVar((yyvsp[(1) - (4)].string), 'g'));
					}
				    } else {
					printf("Error: Variable no existente: %s\n", (yyvsp[(1) - (4)].string));
				} ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 115 "SimpleFlow.y"
    { printf("Bloque completo\n"); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 124 "SimpleFlow.y"
    { printf("Bloque3 completo\n"); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 139 "SimpleFlow.y"
    { if(buscaProc((yyvsp[(1) - (2)].string)) == -1) {
			printf("Error: Procedimiento no existente.\n");
		 } else {
			generaCuadruploERA(buscaProc((yyvsp[(1) - (2)].string)));
			strcpy(idProc, (yyvsp[(1) - (2)].string));
			k=k+1;
		 };}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 145 "SimpleFlow.y"
    { if(tipoParametro(k-1, idProc) == '\0') {
							generaGoSub(buscaProc((yyvsp[(1) - (6)].string)));
							k = 0;
						} printf("Funcion\n"); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 152 "SimpleFlow.y"
    { printf("tipoP=%i cimaptipos=%i\n", tipoParametro(k-1, idProc), cimaPTipos());if(popPTipos() == tipoParametro(k-1, idProc)) {
			generaCuadruploParametro(popPilaO(), k); printf("entra param\n");
		}else{printf("tipo incompatible de param\n");};}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 158 "SimpleFlow.y"
    { k++; ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 163 "SimpleFlow.y"
    { auxif = popPTipos();
				if(auxif != 4) {
					printf("Error: Error Semantico");
				} else {
					generaGoToF(popPilaO());
					pushPSaltos(apunta_cuadruplo-1);
				};}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 170 "SimpleFlow.y"
    { printf("Condicion Completa\n"); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 173 "SimpleFlow.y"
    { generaGoTo(); rellenaGoToF(popPSaltos(), apunta_cuadruplo); pushPSaltos(apunta_cuadruplo-1); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 173 "SimpleFlow.y"
    { rellenaGoTo(popPSaltos(), apunta_cuadruplo); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 177 "SimpleFlow.y"
    { rellenaGoToF(popPSaltos(), apunta_cuadruplo); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 181 "SimpleFlow.y"
    { numret++; asignaTipoAux(tipoFunc); generaCuadruploReturn(popPilaO(), tipoAux); 
					if(popPTipos() != tipoAux)
						printf("Error: Tipo de valor de salida incompatible con el del metodo\n"); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 188 "SimpleFlow.y"
    { pushPOper(300); asignaTipoAux(tipo);
				    if(buscaVar((yyvsp[(2) - (4)].string), 'l') != -1){
					printf("Error: Variable global existente: %s\n", (yyvsp[(2) - (4)].string));
				    } else {
					insertaVar(tipo, (yyvsp[(2) - (4)].string));
					sumaVar(tipo);
					printf("Asignacion Completa en tabla de Variables Locales\n");
					if(cubo[cimaPTipos()][tipoAux][8] != 'x') {
						generaCuadruplo(popPOper(), popPilaO(), -1, buscaVar((yyvsp[(2) - (4)].string), 'l'));
						
					} else {
						printf("Error: Tipos no compatibles\n");
					}
				   }
				;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 209 "SimpleFlow.y"
    { pushPOper(300); asignaTipoAux(buscaVarTipo((yyvsp[(1) - (3)].string), 'l'));
				    if(buscaVar((yyvsp[(1) - (3)].string), 'l') != -1){
					if(cubo[cimaPTipos()][tipoAux][8] != 'x') {
						generaCuadruplo(popPOper(), popPilaO(), -1, buscaVar((yyvsp[(1) - (3)].string), 'l'));
					}
				    } else {
					printf("Error: Variable no existente: %s\n", (yyvsp[(1) - (3)].string));
				};}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 221 "SimpleFlow.y"
    { tipo = 'i'; ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 222 "SimpleFlow.y"
    { tipo = 'f'; ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 223 "SimpleFlow.y"
    { tipo = 'b'; ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 224 "SimpleFlow.y"
    { tipo = 'c'; ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 225 "SimpleFlow.y"
    { tipo = 's'; ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 230 "SimpleFlow.y"
    { printf("Escritura Completa\n"); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 233 "SimpleFlow.y"
    { generaCuadruploPrint(popPilaO()); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 234 "SimpleFlow.y"
    { generaCuadruploPrint(popPilaO()); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 239 "SimpleFlow.y"
    { generaCuadruploRead(popPilaO()); printf("Lectura completa\n"); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 244 "SimpleFlow.y"
    { if(popPTipos() == 0) {
				pushPSaltos(apunta_cuadruplo);
				generaGoToF(popPilaO());
			} else {
				printf("Error: Tipo incompatible en el repeat.");
			} ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 249 "SimpleFlow.y"
    { rellenaGoToF(popPSaltos(), apunta_cuadruplo); printf("Ciclo completo\n"); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 254 "SimpleFlow.y"
    { printf("Termina expresion\n"); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 257 "SimpleFlow.y"
    { pushPOper(202); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 257 "SimpleFlow.y"
    { if(cimaPOper() == 202) {
		  				generacionDeCuadruplos(6);
					      } pushPTipos(4); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 260 "SimpleFlow.y"
    { pushPOper(203); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 260 "SimpleFlow.y"
    { if(cimaPOper() == 203) {
		  				generacionDeCuadruplos(7);
					      } pushPTipos(4); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 263 "SimpleFlow.y"
    { pushPOper(204); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 263 "SimpleFlow.y"
    { if(cimaPOper() == 204) {
		  				generacionDeCuadruplos(10);
					      } pushPTipos(4); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 266 "SimpleFlow.y"
    { pushPOper(205); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 266 "SimpleFlow.y"
    { if(cimaPOper() == 205) {
		  				generacionDeCuadruplos(9);
					      } pushPTipos(4); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 273 "SimpleFlow.y"
    { pushPOper(200); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 273 "SimpleFlow.y"
    { if(cimaPOper() == 200) {
		  				generacionDeCuadruplos(4);
					      };}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 276 "SimpleFlow.y"
    { pushPOper(201); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 276 "SimpleFlow.y"
    { if(cimaPOper() == 201) {
		  				generacionDeCuadruplos(5);
					      };}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 286 "SimpleFlow.y"
    { if(cimaPOper() == 100) {
		  	generacionDeCuadruplos(0);
	} else if(cimaPOper() == 101) {
		  	generacionDeCuadruplos(1);
	};}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 294 "SimpleFlow.y"
    { pushPOper(100); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 295 "SimpleFlow.y"
    { pushPOper(101); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 303 "SimpleFlow.y"
    { if(cimaPOper() == 102) {
		  	generacionDeCuadruplos(2);
	} else if(cimaPOper() == 103) {
		  	generacionDeCuadruplos(3);
	};}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 311 "SimpleFlow.y"
    { pushPOper(102); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 312 "SimpleFlow.y"
    { pushPOper(103); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 318 "SimpleFlow.y"
    { aux = 1; ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 319 "SimpleFlow.y"
    { aux = -1; ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 325 "SimpleFlow.y"
    { op = buscaVar((yyvsp[(1) - (1)].string), scope); asignaTipoAux(buscaVarTipo((yyvsp[(1) - (1)].string), scope)); pushPTipos(tipoAux); pushPilaO(op); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 326 "SimpleFlow.y"
    { agregaCte('i', (yyvsp[(1) - (1)].string), aux); op = buscaCteInt((yyvsp[(1) - (1)].string)); pushPilaO(op); pushPTipos(0); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 327 "SimpleFlow.y"
    { agregaCte('f', (yyvsp[(1) - (1)].string), aux); op = buscaCteFloat((yyvsp[(1) - (1)].string)); pushPilaO(op); pushPTipos(1); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 328 "SimpleFlow.y"
    { agregaCte('s', subString((yyvsp[(1) - (1)].string), 1, strlen((yyvsp[(1) - (1)].string))), 0); op = buscaCteChar((yyvsp[(1) - (1)].string)); pushPilaO(op); pushPTipos(3); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 329 "SimpleFlow.y"
    { agregaCte('c', subString((yyvsp[(1) - (1)].string), 1, strlen((yyvsp[(1) - (1)].string))), 0); op = buscaCteStr((yyvsp[(1) - (1)].string)); pushPilaO(op); pushPTipos(2); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 330 "SimpleFlow.y"
    { agregaCte('b', (yyvsp[(1) - (1)].string), 0); op = buscaCteBool((yyvsp[(1) - (1)].string)); pushPilaO(op); pushPTipos(4); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 335 "SimpleFlow.y"
    { scope = 'l'; tipoFunc = tipo; insertaNumCuadruplo(apunta_cuadruplo); reiniciaContTemp(); numret = 0;
				if(buscaProc((yyvsp[(3) - (3)].string)) == -1) {
					insertaProc(tipo, (yyvsp[(3) - (3)].string));
					printf("Inserto Procedimiento a directorio.\n");
				 } else {
					printf("Error: Procedimiento existente.\n");
				 }
				;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 343 "SimpleFlow.y"
    { insertaNumParams(cParam); cParam = 0; ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 343 "SimpleFlow.y"
    { insertaNumVars(numVarInt, numVarFloat, numVarChar, numVarStr, numVarBool); reiniciaContTemp(); reiniciaContVars(); reiniciaTablaVar(); generaRetorno(); if(numret == 0) printf("Error: Función no tiene valor de regreso (return).\n"); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 347 "SimpleFlow.y"
    { insertaParam(tipo, cParam); cParam++; insertaVar(tipo, (yyvsp[(2) - (2)].string)); printf("Inserto Parametro.\n");;}
    break;



/* Line 1455 of yacc.c  */
#line 2115 "SimpleFlow.tab.c"
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
#line 354 "SimpleFlow.y"


/* Generación de Cuadruplos */
void generacionDeCuadruplos(int oper){
	char type;
	int temp;
	int operando1, operando2;
	type = cubo[popPTipos()][popPTipos()][oper];
	operando1 = popPilaO();
	operando2 = popPilaO();
	switch(type) {
		case 'i':
			temp = enteros_temporales+apunta_enteros_temporales;
			generaCuadruplo(popPOper(), operando1, operando2, temp);
			if((operando1 >= 10000) && (operando1 < 11000)){
				apunta_enteros_temporales--;
			}
			if((operando2 >= 10000) && (operando2 < 11000)){
				apunta_enteros_temporales--;
			}
			pushPilaO(temp);
			pushPTipos(0);
			apunta_enteros_temporales++;
			break;
		case 'f':
			temp = flotantes_temporales+apunta_flotantes_temporales;
			generaCuadruplo(popPOper(), operando1, operando2, temp);
			if((operando1 >= 11000) && (operando1 < 12000)){
				apunta_flotantes_temporales--;
			}
			if((operando2 >= 11000) && (operando2 < 12000)){
				apunta_flotantes_temporales--;
			}
			pushPilaO(temp);
			pushPTipos(1);
			apunta_flotantes_temporales++;
			break;
		case 'c':
			temp = chars_temporales+apunta_chars_temporales;
			generaCuadruplo(popPOper(), operando1, operando2, temp);
			if((operando1 >= 12000) && (operando1 < 13000)){
				apunta_chars_temporales--;
			}
			if((operando2 >= 12000) && (operando2 < 13000)){
				apunta_chars_temporales--;
			}
			pushPilaO(temp);
			pushPTipos(2);
			apunta_chars_temporales++;
			break;
		case 's':
			temp = strings_temporales+apunta_strings_temporales;
			generaCuadruplo(popPOper(), operando1, operando2, temp);
			if((operando1 >= 13000) && (operando1 < 14000)){
				apunta_strings_temporales--;
			}
			if((operando2 >= 13000) && (operando2 < 14000)){
				apunta_strings_temporales--;
			}
			pushPilaO(temp);
			pushPTipos(3);
			apunta_strings_temporales++;
			break;
		case 'b':
			temp = booleanos_temporales+apunta_booleanos_temporales;
			generaCuadruplo(popPOper(), operando1, operando2, temp);
			if((operando1 >= 14000) && (operando1 < 15000)){
				apunta_booleanos_temporales--;
			}
			if((operando2 >= 14000) && (operando2 < 15000)){
				apunta_booleanos_temporales--;
			}
			pushPilaO(temp);
			pushPTipos(4);
			apunta_booleanos_temporales++;
			break;
		case 'x':
			printf("Error: Tipos incompatibles (cuadruplos)\n");
			break;
	}
}

void asignaTipoAux(char tipo) {
	if(tipo == 'i') {
		tipoAux = 0;
	} else if(tipo == 'f') {
		tipoAux = 1;
	} else if(tipo == 'c') {
		tipoAux = 2;
	} else if(tipo == 's') {
		tipoAux = 3;
	} else if(tipo == 'b') {
		tipoAux = 4;
	}
}

void sumaVar(char tipo) {
	if(tipo == 'i') {
		numVarInt++;
	} else if(tipo == 'f') {
		numVarFloat++;
	} else if(tipo == 'c') {
		numVarChar++;
	} else if(tipo == 's') {
		numVarStr++;
	} else if(tipo == 'b') {
		numVarBool++;
	}
}

void reiniciaContVars() {
	numVarInt = 0;
	numVarFloat = 0;
	numVarChar = 0;
	numVarStr = 0;
	numVarBool = 0;
}

void reiniciaContTemp(){
	apunta_enteros_temporales =   0;
	apunta_flotantes_temporales = 0;
	apunta_chars_temporales =     0;
	apunta_strings_temporales =   0;
	apunta_booleanos_temporales = 0;
}

char * subString(char* str, int start, int length) {
	char *newString = (char *)malloc(length * sizeof(char));
	int i, x = 0;
	int end=start+length;
	for(i = start ; i < end; i++)
		newString[x++] = str[i];
	newString[x] = '\0';
	return newString;
}

/* Funcion Main */
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

	imprimeCuadruplos();

	//imprimeVar(myfile);
	//imprimeProc(myfile);
}

void yyerror(const char *s) {
	cout << "Error!  Mensaje: " << s << endl;
	exit(-1);
}

