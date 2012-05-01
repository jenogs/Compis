
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
char paramAux[50];
char flagTipo; //Bandera usada para revision del tipo en la asignación
int tipoAux; //Auxiliar para el tipo de variable en la asignación
int cParam = 0;
int numVarInt = 0;
int numVarFloat = 0;
int numVarChar = 0;
int numVarStr = 0;
int numVarBool = 0;
int aux = 1;
int op; //operador
int auxif;
int k = 0;
int numret = 0;
int numCuadFunc;
char tipoFunc;
int idReturn;
int valorReturn;

char nombreArchivo[100];

void generacionDeCuadruplos(int oper);
void asignaTipoAux(char tipo);
void sumaVar(char tipo);
void reiniciaContVars();
void reiniciaContTemp();
char * subString(char* str, int start, int length);
void insertaParam(char tipo, int cParam);
int asignaTemp(char tipo);



/* Line 189 of yacc.c  */
#line 126 "SimpleFlow.tab.c"

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
     UNTIL = 266,
     MAY = 267,
     MEN = 268,
     DIF = 269,
     IF = 270,
     ELSE = 271,
     PRINT = 272,
     SUM = 273,
     RES = 274,
     MULT = 275,
     DIV = 276,
     STR = 277,
     INT = 278,
     FLOAT = 279,
     PROG = 280,
     VAR = 281,
     EQ = 282,
     BOOL = 283,
     AND = 284,
     OR = 285,
     REPEAT = 286,
     READ = 287,
     CHAR = 288,
     DP = 289,
     PC = 290,
     COMA = 291,
     LLA = 292,
     LLC = 293,
     PARA = 294,
     PARC = 295,
     ID = 296,
     NOMBRE = 297,
     STRING = 298,
     CTEE = 299,
     CTEF = 300,
     BOOLEAN = 301,
     CH = 302
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 53 "SimpleFlow.y"

	char ch;
	char *string;



/* Line 214 of yacc.c  */
#line 216 "SimpleFlow.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 228 "SimpleFlow.tab.c"

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
#define YYLAST   166

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNRULES -- Number of states.  */
#define YYNSTATES  200

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

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
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,     6,    16,    17,    20,    21,
      25,    27,    28,    31,    37,    42,    46,    47,    50,    52,
      53,    56,    58,    60,    62,    64,    66,    67,    74,    75,
      76,    80,    81,    82,    86,    87,    93,    94,   105,   106,
     113,   115,   116,   117,   123,   128,   131,   135,   137,   139,
     141,   143,   145,   151,   152,   157,   159,   160,   171,   174,
     175,   180,   181,   186,   187,   192,   193,   198,   199,   204,
     205,   206,   210,   211,   215,   219,   220,   221,   222,   226,
     227,   231,   235,   236,   237,   238,   242,   243,   247,   248,
     253,   254,   258,   259,   263,   265,   267,   269,   271,   273,
     275,   277,   279,   280,   281,   298,   299,   300,   305,   306,
     309,   310,   312,   313
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    -1,    -1,    -1,    42,    50,    54,    51,
      53,     3,    52,    58,     4,    -1,    -1,   110,    53,    -1,
      -1,     9,    56,    54,    -1,    55,    -1,    -1,    57,    55,
      -1,    79,    41,    27,    95,    35,    -1,    41,    27,    95,
      35,    -1,    37,    59,    38,    -1,    -1,    76,    59,    -1,
      60,    -1,    -1,    61,    60,    -1,    70,    -1,    80,    -1,
      83,    -1,    62,    -1,    78,    -1,    -1,    42,    39,    63,
      64,    40,    35,    -1,    -1,    -1,    95,    65,    66,    -1,
      -1,    -1,    36,    67,    64,    -1,    -1,    42,    39,    69,
      64,    40,    -1,    -1,    15,    39,    85,    40,    71,    37,
      60,    75,    38,    72,    -1,    -1,    16,    73,    37,    60,
      75,    38,    -1,    74,    -1,    -1,    -1,    10,    39,    95,
      40,    35,    -1,    79,    41,    27,    77,    -1,    95,    35,
      -1,    41,    27,    77,    -1,    23,    -1,    24,    -1,    28,
      -1,    33,    -1,    22,    -1,    17,    39,    81,    40,    35,
      -1,    -1,    95,    82,    36,    81,    -1,    95,    -1,    -1,
      31,    84,    37,    60,    38,    11,    39,    85,    40,    35,
      -1,    86,    92,    -1,    -1,    95,    12,    87,    95,    -1,
      -1,    95,    13,    88,    95,    -1,    -1,    95,    14,    89,
      95,    -1,    -1,    95,     8,    90,    95,    -1,    -1,    39,
      91,    86,    40,    -1,    -1,    -1,    29,    93,    85,    -1,
      -1,    30,    94,    85,    -1,   100,    96,    97,    -1,    -1,
      -1,    -1,    18,    98,    95,    -1,    -1,    19,    99,    95,
      -1,   105,   101,   102,    -1,    -1,    -1,    -1,    20,   103,
     100,    -1,    -1,    21,   104,   100,    -1,    -1,    39,   106,
      95,    40,    -1,    -1,    18,   107,   109,    -1,    -1,    19,
     108,   109,    -1,   109,    -1,    41,    -1,    44,    -1,    45,
      -1,    43,    -1,    47,    -1,    46,    -1,    68,    -1,    -1,
      -1,    79,     5,    42,   111,    39,   113,    40,     6,    37,
     116,   117,   112,    60,    75,    38,     7,    -1,    -1,    -1,
      79,    41,   114,   115,    -1,    -1,    36,   113,    -1,    -1,
      76,    -1,    -1,    76,   117,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    76,    76,    76,    79,    80,    85,    86,
      87,    90,    91,    94,   109,   121,   124,   125,   126,   129,
     130,   135,   136,   137,   138,   139,   144,   144,   159,   160,
     160,   167,   168,   168,   172,   172,   189,   189,   199,   199,
     200,   203,   206,   207,   214,   229,   232,   244,   245,   246,
     247,   248,   253,   256,   256,   257,   262,   262,   267,   270,
     270,   273,   273,   276,   276,   279,   279,   282,   282,   285,
     286,   286,   289,   289,   296,   299,   306,   307,   307,   308,
     308,   313,   316,   323,   324,   324,   325,   325,   330,   330,
     331,   331,   332,   332,   333,   338,   339,   340,   341,   342,
     343,   344,   349,   353,   349,   364,   365,   365,   368,   369,
     372,   373,   376,   377
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BEGINP", "ENDP", "FUNCTION", "BEGINF",
  "ENDF", "IGU", "GLOBAL", "RETURN", "UNTIL", "MAY", "MEN", "DIF", "IF",
  "ELSE", "PRINT", "SUM", "RES", "MULT", "DIV", "STR", "INT", "FLOAT",
  "PROG", "VAR", "EQ", "BOOL", "AND", "OR", "REPEAT", "READ", "CHAR", "DP",
  "PC", "COMA", "LLA", "LLC", "PARA", "PARC", "ID", "NOMBRE", "STRING",
  "CTEE", "CTEF", "BOOLEAN", "CH", "$accept", "programa", "$@1", "$@2",
  "$@3", "programa2", "asignaglobal", "asignaglobal2", "asignaciong",
  "otraasignaciong", "bloque", "bloque2", "bloque3", "estatuto", "funcion",
  "$@4", "funcion2", "$@5", "funcion3", "$@6", "funcionalt", "$@7",
  "condicion", "$@8", "condicion2", "$@9", "condicion3", "ret",
  "asignacion", "asigna2", "otraasignacion", "tipo", "escritura",
  "escritura2", "$@10", "ciclo", "$@11", "expresion", "expresion2", "$@12",
  "$@13", "$@14", "$@15", "$@16", "operadorl", "$@17", "$@18", "exp",
  "exp1", "exp11", "$@19", "$@20", "termino", "termino1", "termino11",
  "$@21", "$@22", "factor", "$@23", "$@24", "$@25", "varcte", "function",
  "$@26", "$@27", "function2", "$@28", "function3", "asigna", "b2", 0
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
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    50,    51,    52,    49,    53,    53,    54,    54,
      54,    55,    55,    56,    57,    58,    59,    59,    59,    60,
      60,    61,    61,    61,    61,    61,    63,    62,    64,    65,
      64,    66,    67,    66,    69,    68,    71,    70,    73,    72,
      72,    74,    75,    75,    76,    77,    78,    79,    79,    79,
      79,    79,    80,    82,    81,    81,    84,    83,    85,    87,
      86,    88,    86,    89,    86,    90,    86,    91,    86,    92,
      93,    92,    94,    92,    95,    96,    97,    98,    97,    99,
      97,   100,   101,   102,   103,   102,   104,   102,   106,   105,
     107,   105,   108,   105,   105,   109,   109,   109,   109,   109,
     109,   109,   111,   112,   110,   113,   114,   113,   115,   115,
     116,   116,   117,   117
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     9,     0,     2,     0,     3,
       1,     0,     2,     5,     4,     3,     0,     2,     1,     0,
       2,     1,     1,     1,     1,     1,     0,     6,     0,     0,
       3,     0,     0,     3,     0,     5,     0,    10,     0,     6,
       1,     0,     0,     5,     4,     2,     3,     1,     1,     1,
       1,     1,     5,     0,     4,     1,     0,    10,     2,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       0,     3,     0,     3,     3,     0,     0,     0,     3,     0,
       3,     3,     0,     0,     0,     3,     0,     3,     0,     4,
       0,     3,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     0,    16,     0,     0,     4,     0,     2,
       0,     1,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     8,     1,     0,     0,     3,    10,    11,
      51,    47,    48,    49,    50,     8,     0,     0,     6,    12,
       9,     0,    90,    92,    88,    95,     0,    98,    96,    97,
     100,    99,   101,     0,    75,    82,    94,     0,     0,     6,
       0,     0,     0,     0,    34,    14,    76,    83,     4,     0,
       7,     0,    91,    93,     0,    28,    77,    79,    74,    84,
      86,    81,     0,   102,    13,    89,     0,    29,     0,     0,
       0,     0,    16,     0,     0,    35,    31,    78,    80,    85,
      87,     0,     0,    56,     0,     0,     0,    18,    19,    24,
      21,    16,    25,     0,    22,    23,     5,   105,    32,    30,
       0,     0,     0,     0,    26,    15,    20,    17,     0,     0,
       0,    28,    67,     0,    69,     0,     0,    53,    19,    46,
       0,    28,     0,   106,     0,    33,     0,    36,    70,    72,
      58,    65,    59,    61,    63,     0,     0,     0,    45,     0,
      44,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,     0,     0,     0,   105,   107,   110,    68,    19,
      71,    73,    66,    60,    62,    64,    54,     0,    27,   109,
     111,   112,    42,     0,   112,   103,     0,     0,     0,   113,
      19,     0,    41,     0,    42,     0,    38,    37,    40,    57,
       0,     0,     0,     0,    43,    19,   104,    42,     0,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    18,    62,    37,     7,     8,    15,     9,
      73,    86,    87,    88,    89,   121,    66,    76,    99,   111,
      32,    55,    90,   144,   187,   192,   188,   177,    91,   119,
      92,    93,    94,   116,   136,    95,   102,   113,   114,   148,
     149,   150,   147,   126,   130,   145,   146,   115,    46,    58,
      68,    69,    34,    47,    61,    70,    71,    35,    43,    41,
      42,    36,    39,    74,   180,   110,   141,   156,   171,   175
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -179
static const yytype_int16 yypact[] =
{
     -31,  -179,    15,    -7,  -179,    34,    23,  -179,  -179,    12,
    -179,  -179,  -179,  -179,  -179,    -7,    20,    -2,    34,  -179,
    -179,    37,  -179,  -179,  -179,  -179,    24,  -179,  -179,  -179,
    -179,  -179,  -179,    30,  -179,  -179,  -179,    63,    64,    34,
      -2,    77,    77,    -2,  -179,  -179,    -9,    -8,  -179,    26,
    -179,    35,  -179,  -179,    31,    -2,  -179,  -179,  -179,  -179,
    -179,  -179,    39,  -179,  -179,  -179,    32,  -179,    -2,    -2,
      -2,    -2,    75,    69,    46,  -179,    51,  -179,  -179,  -179,
    -179,    49,    50,  -179,    73,    52,    58,  -179,     5,  -179,
    -179,    75,  -179,    60,  -179,  -179,  -179,    34,  -179,  -179,
      36,    -2,    65,    -2,  -179,  -179,  -179,  -179,    80,    68,
      71,    -2,  -179,    72,    19,    17,    74,    85,     5,  -179,
      78,    -2,    -2,  -179,   109,  -179,    36,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,    91,    92,    89,  -179,    94,
    -179,    93,    99,    97,   101,    36,    36,    -2,    -2,    -2,
      -2,  -179,    -2,   128,   105,    34,  -179,    34,  -179,     5,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,   102,  -179,  -179,
    -179,    34,   132,    36,    34,  -179,   104,   106,   107,  -179,
       5,    -2,   129,   111,   132,   108,  -179,  -179,  -179,  -179,
     112,   114,   115,   146,  -179,     5,  -179,   132,   116,  -179
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -179,  -179,  -179,  -179,  -179,   117,   140,   148,  -179,  -179,
    -179,    67,   -85,  -179,  -179,  -179,  -103,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -178,  -150,    38,
    -179,    -4,  -179,     7,  -179,  -179,  -179,  -141,    40,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,   -17,  -179,  -179,
    -179,  -179,   -43,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
    -179,    18,  -179,  -179,  -179,     6,  -179,  -179,  -179,   -12
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -56
static const yytype_int16 yytable[] =
{
      33,    16,     5,   106,   160,   161,   190,   170,   125,    56,
      57,     1,    59,    60,    38,     4,    22,    23,   139,   198,
      81,   174,    82,    51,   174,   131,    54,    79,    80,   132,
     133,   134,   178,   137,     6,    38,    83,    24,    67,    25,
      26,    27,    28,    29,    30,    31,    84,    85,   128,   129,
      17,    77,    78,     6,    22,    23,    10,    11,    12,    52,
      53,    21,    13,    44,    40,    45,    48,    14,    63,    49,
      64,    65,    75,    96,   172,   112,    72,    25,    26,    27,
      28,    29,    30,    31,   117,    97,   120,    98,   100,   101,
      81,   104,    82,   109,    67,   184,   105,    10,    11,    12,
     103,   108,   118,    13,    67,   120,    83,   122,    14,   123,
     197,   124,   127,   138,   135,   142,    84,    85,    25,    26,
      27,    28,    29,    30,    31,   -55,   151,   153,   152,   155,
     162,   163,   164,   165,   154,   117,   157,   158,   159,   167,
     168,   173,   176,   181,   182,   186,   189,   183,   191,   194,
     193,   109,   195,   196,   199,    20,    50,    19,   107,   166,
     140,   169,   179,     0,   185,     0,   143
};

static const yytype_int16 yycheck[] =
{
      17,     5,     9,    88,   145,   146,   184,   157,   111,    18,
      19,    42,    20,    21,    18,     0,    18,    19,   121,   197,
      15,   171,    17,    40,   174,     8,    43,    70,    71,    12,
      13,    14,   173,   118,    41,    39,    31,    39,    55,    41,
      42,    43,    44,    45,    46,    47,    41,    42,    29,    30,
      27,    68,    69,    41,    18,    19,    22,    23,    24,    41,
      42,    41,    28,    39,    27,    35,     3,    33,    42,     5,
      35,    40,    40,     4,   159,    39,    37,    41,    42,    43,
      44,    45,    46,    47,   101,    39,   103,    36,    39,    39,
      15,    39,    17,    97,   111,   180,    38,    22,    23,    24,
      27,    41,    37,    28,   121,   122,    31,    27,    33,    41,
     195,    40,    40,    35,    40,     6,    41,    42,    41,    42,
      43,    44,    45,    46,    47,    40,    35,    38,    36,    36,
     147,   148,   149,   150,    40,   152,    37,    40,    37,    11,
      35,    39,    10,    39,    38,    16,    35,    40,    40,    35,
      38,   155,    37,     7,    38,    15,    39,     9,    91,   152,
     122,   155,   174,    -1,   181,    -1,   126
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    49,    50,     0,     9,    41,    54,    55,    57,
      22,    23,    24,    28,    33,    56,    79,    27,    51,    55,
      54,    41,    18,    19,    39,    41,    42,    43,    44,    45,
      46,    47,    68,    95,   100,   105,   109,    53,    79,   110,
      27,   107,   108,   106,    39,    35,    96,   101,     3,     5,
      53,    95,   109,   109,    95,    69,    18,    19,    97,    20,
      21,   102,    52,    42,    35,    40,    64,    95,    98,    99,
     103,   104,    37,    58,   111,    40,    65,    95,    95,   100,
     100,    15,    17,    31,    41,    42,    59,    60,    61,    62,
      70,    76,    78,    79,    80,    83,     4,    39,    36,    66,
      39,    39,    84,    27,    39,    38,    60,    59,    41,    79,
     113,    67,    39,    85,    86,    95,    81,    95,    37,    77,
      95,    63,    27,    41,    40,    64,    91,    40,    29,    30,
      92,     8,    12,    13,    14,    40,    82,    60,    35,    64,
      77,   114,     6,    86,    71,    93,    94,    90,    87,    88,
      89,    35,    36,    38,    40,    36,   115,    37,    40,    37,
      85,    85,    95,    95,    95,    95,    81,    11,    35,   113,
      76,   116,    60,    39,    76,   117,    10,    75,    85,   117,
     112,    39,    38,    40,    60,    95,    16,    72,    74,    35,
      75,    40,    73,    38,    35,    37,     7,    60,    75,    38
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
#line 76 "SimpleFlow.y"
    { insertaProcIni('n', (yyvsp[(1) - (1)].string)); scope = 'g'; ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 76 "SimpleFlow.y"
    { generaGoTo(); pushPSaltos(apunta_cuadruplo-1); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 76 "SimpleFlow.y"
    { scope = 'l'; rellenaGoTo(popPSaltos(), apunta_cuadruplo); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 76 "SimpleFlow.y"
    { generaEnd(); printf("Programa completo\n"); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 94 "SimpleFlow.y"
    { pushPOper(300); asignaTipoAux(tipo);
				    if(buscaVar((yyvsp[(2) - (5)].string), 'g') != -1){
						yyerror("Variable global existente.\n");
				    } else {
					insertaVarGlobal(tipo, (yyvsp[(2) - (5)].string));
					if(cubo[cimaPTipos()][tipoAux][8] != 'x') {
						generaCuadruplo(popPOper(), popPilaO(), -1, buscaVar((yyvsp[(2) - (5)].string), 'g'));
						
					} else {
						yyerror("Tipos no compatibles en la asignacion global.\n");
					}
				   }
				;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 109 "SimpleFlow.y"
    { pushPOper(300); asignaTipoAux(buscaVarTipo((yyvsp[(1) - (4)].string), 'g'));
				    if(buscaVar((yyvsp[(1) - (4)].string), 'g') != -1){
					if(cubo[cimaPTipos()][tipoAux][8] != 'x') {
						generaCuadruplo(popPOper(), popPilaO(), -1, buscaVar((yyvsp[(1) - (4)].string), 'g'));
					}
				    } else {
					yyerror("Variable no existente en la asignacion global\n");
				} ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 144 "SimpleFlow.y"
    { if(buscaProc((yyvsp[(1) - (2)].string)) == -1) {
			yyerror("Procedimiento llamado no existente.\n");
		 } else {
			generaCuadruploERA(buscaProc((yyvsp[(1) - (2)].string)));
			k++;
		 };}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 149 "SimpleFlow.y"
    {
			if((tipoParametro(k-1) != 0) || (tipoParametro(k-1) != 1) || (tipoParametro(k-1) != 2) || (tipoParametro(k-1) != 3) || (tipoParametro(k-1) != 4)) {
				generaGoSub(buscaProc((yyvsp[(1) - (6)].string)));
				k = 0;
				pushPilaO(asignaTemp(buscaVarTipo((yyvsp[(1) - (6)].string), 'g')));
				generaCuadruplo(300, buscaVar((yyvsp[(1) - (6)].string), 'g'), -1, cimaPilaO());
				pushPTipos(buscaVarTipo((yyvsp[(1) - (6)].string), 'g'));
			} ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 160 "SimpleFlow.y"
    { if(popPTipos() == tipoParametro(k-1)) {
			generaCuadruploParametro(popPilaO(), k);
		} else {
			yyerror("Tipo incompatible de parametro en la llamada de procedimiento.\n");
		};}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 168 "SimpleFlow.y"
    { k++; ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 172 "SimpleFlow.y"
    { pushPOper(350); if(buscaProc((yyvsp[(1) - (2)].string)) == -1) {
			yyerror("Procedimiento llamado no existente.\n");
		 } else {
			generaCuadruploERA(buscaProc((yyvsp[(1) - (2)].string)));
			k++;
		 };}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 177 "SimpleFlow.y"
    { popPOper();
			if((tipoParametro(k-1) != 0) || (tipoParametro(k-1) != 1) || (tipoParametro(k-1) != 2) || (tipoParametro(k-1) != 3) || (tipoParametro(k-1) != 4)) {
				generaGoSub(buscaProc((yyvsp[(1) - (5)].string)));
				k = 0;
				pushPilaO(asignaTemp(buscaVarTipo((yyvsp[(1) - (5)].string), 'g')));
				generaCuadruplo(300, buscaVar((yyvsp[(1) - (5)].string), 'g'), -1, cimaPilaO());
				asignaTipoAux(buscaVarTipo((yyvsp[(1) - (5)].string),'g'));
				pushPTipos(tipoAux);
			} ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 189 "SimpleFlow.y"
    { auxif = popPTipos();
				if(auxif != 4) {
					yyerror("Tipos no compatibles en la condicion\n");
				} else {
					generaGoToF(popPilaO());
					pushPSaltos(apunta_cuadruplo-1);
				};}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 199 "SimpleFlow.y"
    { generaGoTo(); rellenaGoToF(popPSaltos(), apunta_cuadruplo); pushPSaltos(apunta_cuadruplo-1); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 199 "SimpleFlow.y"
    { rellenaGoTo(popPSaltos(), apunta_cuadruplo); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 203 "SimpleFlow.y"
    { rellenaGoToF(popPSaltos(), apunta_cuadruplo); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 207 "SimpleFlow.y"
    { numret++; asignaTipoAux(tipoFunc); generaCuadruploReturn(popPilaO(), idReturn);
					if(popPTipos() != tipoAux)
						yyerror("Tipo de valor de salida incompatible con el del metodo\n"); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 214 "SimpleFlow.y"
    { pushPOper(300); asignaTipoAux(tipo);
				    if(buscaVar((yyvsp[(2) - (4)].string), 'l') != -1){
					yyerror("Variable local existente.\n");
				    } else {
					insertaVar(tipo, (yyvsp[(2) - (4)].string));
					sumaVar(tipo);
					if(cubo[cimaPTipos()][tipoAux][8] != 'x') {
						generaCuadruplo(popPOper(), popPilaO(), -1, buscaVar((yyvsp[(2) - (4)].string), 'l'));
					} else {
						yyerror("Tipos no compatibles. en asignacion local\n");
					}
				   }
				;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 232 "SimpleFlow.y"
    { pushPOper(300); asignaTipoAux(buscaVarTipo((yyvsp[(1) - (3)].string), 'l'));
				    if(buscaVar((yyvsp[(1) - (3)].string), 'l') != -1){
					if(cubo[cimaPTipos()][tipoAux][8] != 'x') {
						generaCuadruplo(popPOper(), popPilaO(), -1, buscaVar((yyvsp[(1) - (3)].string), 'l'));
					}
				    } else {
					yyerror("Variable local asignada no existente.\n");
				};}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 244 "SimpleFlow.y"
    { tipo = 'i'; ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 245 "SimpleFlow.y"
    { tipo = 'f'; ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 246 "SimpleFlow.y"
    { tipo = 'b'; ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 247 "SimpleFlow.y"
    { tipo = 'c'; ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 248 "SimpleFlow.y"
    { tipo = 's'; ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 256 "SimpleFlow.y"
    { generaCuadruploPrint(popPilaO()); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 257 "SimpleFlow.y"
    { generaCuadruploPrint(popPilaO()); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 262 "SimpleFlow.y"
    { pushPSaltos(apunta_cuadruplo); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 262 "SimpleFlow.y"
    { generaGoToF(popPilaO()); rellenaGoToF(apunta_cuadruplo-1, popPSaltos()); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 270 "SimpleFlow.y"
    { pushPOper(202); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 270 "SimpleFlow.y"
    { if(cimaPOper() == 202) {
		  				generacionDeCuadruplos(6);
					      } pushPTipos(4); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 273 "SimpleFlow.y"
    { pushPOper(203); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 273 "SimpleFlow.y"
    { if(cimaPOper() == 203) {
		  				generacionDeCuadruplos(7);
					      } pushPTipos(4); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 276 "SimpleFlow.y"
    { pushPOper(204); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 276 "SimpleFlow.y"
    { if(cimaPOper() == 204) {
		  				generacionDeCuadruplos(10);
					      } pushPTipos(4); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 279 "SimpleFlow.y"
    { pushPOper(205); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 279 "SimpleFlow.y"
    { if(cimaPOper() == 205) {
		  				generacionDeCuadruplos(9);
					      } pushPTipos(4); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 282 "SimpleFlow.y"
    { pushPOper(350); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 282 "SimpleFlow.y"
    { popPOper(); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 286 "SimpleFlow.y"
    { pushPOper(200); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 286 "SimpleFlow.y"
    { if(cimaPOper() == 200) {
		  				generacionDeCuadruplos(4);
					      };}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 289 "SimpleFlow.y"
    { pushPOper(201); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 289 "SimpleFlow.y"
    { if(cimaPOper() == 201) {
		  				generacionDeCuadruplos(5);
					      };}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 299 "SimpleFlow.y"
    { if(cimaPOper() == 100) {
		  	generacionDeCuadruplos(0);
	} else if(cimaPOper() == 101) {
		  	generacionDeCuadruplos(1);
	};}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 307 "SimpleFlow.y"
    { pushPOper(100); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 308 "SimpleFlow.y"
    { pushPOper(101); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 316 "SimpleFlow.y"
    { if(cimaPOper() == 102) {
		  	generacionDeCuadruplos(2);
	} else if(cimaPOper() == 103) {
		  	generacionDeCuadruplos(3);
	};}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 324 "SimpleFlow.y"
    { pushPOper(102); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 325 "SimpleFlow.y"
    { pushPOper(103); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 330 "SimpleFlow.y"
    { pushPOper(350); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 330 "SimpleFlow.y"
    { popPOper(); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 331 "SimpleFlow.y"
    { aux = 1; ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 332 "SimpleFlow.y"
    { aux = -1; ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 338 "SimpleFlow.y"
    { op = buscaVar((yyvsp[(1) - (1)].string), scope); asignaTipoAux(buscaVarTipo((yyvsp[(1) - (1)].string), scope)); pushPTipos(tipoAux); pushPilaO(op); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 339 "SimpleFlow.y"
    { agregaCte('i', (yyvsp[(1) - (1)].string), aux); op = buscaCteInt((yyvsp[(1) - (1)].string)); pushPilaO(op); pushPTipos(0); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 340 "SimpleFlow.y"
    { agregaCte('f', (yyvsp[(1) - (1)].string), aux); op = buscaCteFloat((yyvsp[(1) - (1)].string)); pushPilaO(op); pushPTipos(1); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 341 "SimpleFlow.y"
    { agregaCte('s', subString((yyvsp[(1) - (1)].string), 0, strlen((yyvsp[(1) - (1)].string))), 0); op = buscaCteStr((yyvsp[(1) - (1)].string)); pushPilaO(op); pushPTipos(3); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 342 "SimpleFlow.y"
    { agregaCte('c', subString((yyvsp[(1) - (1)].string), 0, strlen((yyvsp[(1) - (1)].string))), 0); op = buscaCteChar((yyvsp[(1) - (1)].string)); pushPilaO(op); pushPTipos(2); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 343 "SimpleFlow.y"
    { agregaCte('b', (yyvsp[(1) - (1)].string), 0); op = buscaCteBool((yyvsp[(1) - (1)].string)); pushPilaO(op); pushPTipos(4); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 349 "SimpleFlow.y"
    { scope = 'l'; tipoFunc = tipo; numCuadFunc = apunta_cuadruplo; reiniciaContTemp(); numret = 0;
				if(buscaProc((yyvsp[(3) - (3)].string)) != -1) {
					yyerror("Procedimiento declarado existente.\n");
				 }
				;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 353 "SimpleFlow.y"
    { insertaProc(tipoFunc,(yyvsp[(3) - (11)].string),numVarInt,numVarFloat,numVarChar,numVarStr,numVarBool,cParam,numCuadFunc,paramAux); insertaVarGlobal(tipoFunc, (yyvsp[(3) - (11)].string)); idReturn = buscaVar((yyvsp[(3) - (11)].string), 'g'); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 353 "SimpleFlow.y"
    {
		reiniciaContTemp();
		reiniciaContVars();
		reiniciaTablaVar();
		cParam = 0;
		generaRetorno();
		if(numret == 0)
			yyerror("Función no tiene valor de regreso (return).\n");
		;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 365 "SimpleFlow.y"
    { insertaParam(tipo, cParam); cParam++; insertaVar(tipo, (yyvsp[(2) - (2)].string)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2145 "SimpleFlow.tab.c"
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
#line 380 "SimpleFlow.y"


/* Generación de Cuadruplos */
void generacionDeCuadruplos(int oper){
	char type;
	int temp;
	int operando1, operando2;
	type = cubo[popPTipos()][popPTipos()][oper];
	operando2 = popPilaO();
	operando1 = popPilaO();
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

int asignaTemp(char tipo) {
	int t;
	switch(tipo) {
		case 'i':
			t = enteros_temporales + apunta_enteros_temporales;
			apunta_enteros_temporales++;
			break;
		case 'f':
			t = flotantes_temporales+apunta_flotantes_temporales;
			apunta_flotantes_temporales++;
			break;
		case 'c':
			t = chars_temporales + apunta_chars_temporales;
			apunta_chars_temporales++;
			break;
		case 's':
			t = strings_temporales + apunta_strings_temporales;
			apunta_strings_temporales++;
			break;
		case 'b':
			t = booleanos_temporales+ apunta_booleanos_temporales;
			apunta_booleanos_temporales++;
			break;
	}
	return t;
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

void insertaParam(char tipo, int cParam) {
	paramAux[cParam] = tipo;
}

/* Funcion Main */
int main(int argc, char *argv[]) {
	FILE *myfile = fopen(argv[1], "r");
	strcpy(nombreArchivo,argv[1]);
	strcat(nombreArchivo,"obj");
	if (!myfile) {
		printf("No se puede abrir el archivo!");
		return -1;
	}
	yyin = myfile;
	
	do {
		yyparse();
	} while (!feof(yyin));

	imprimeCuadruplos(nombreArchivo);
	exit(0);
}

void yyerror(const char *s) {
	cout << "Error!  " << s << endl;
	exit(-1);
}

