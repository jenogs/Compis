
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
int valorReturn;

void generacionDeCuadruplos(int oper);
void asignaTipoAux(char tipo);
void sumaVar(char tipo);
void reiniciaContVars();
void reiniciaContTemp();
char * subString(char* str, int start, int length);
void insertaParam(char tipo, int cParam);
int asignaTemp(char tipo);



/* Line 189 of yacc.c  */
#line 123 "SimpleFlow.tab.c"

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
#line 50 "SimpleFlow.y"

	char ch;
	char *string;



/* Line 214 of yacc.c  */
#line 212 "SimpleFlow.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 224 "SimpleFlow.tab.c"

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
#define YYLAST   171

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNRULES -- Number of states.  */
#define YYNSTATES  201

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
      76,    80,    81,    82,    86,    87,    93,    94,   105,   106,
     113,   115,   116,   117,   123,   128,   131,   135,   137,   139,
     141,   143,   145,   151,   152,   157,   159,   165,   166,   173,
     176,   177,   182,   183,   188,   189,   194,   195,   200,   201,
     206,   207,   208,   212,   213,   217,   221,   222,   223,   224,
     228,   229,   233,   237,   238,   239,   240,   244,   245,   249,
     250,   255,   256,   260,   261,   265,   267,   269,   271,   273,
     275,   277,   279,   281,   282,   283,   300,   301,   302,   307,
     308,   311,   312,   314,   315
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    -1,    -1,    41,    49,    52,    51,     3,
      50,    56,     4,    -1,    -1,   109,    51,    -1,    -1,     9,
      54,    52,    -1,    53,    -1,    -1,    55,    53,    -1,    77,
      40,    26,    94,    34,    -1,    40,    26,    94,    34,    -1,
      36,    57,    37,    -1,    -1,    74,    57,    -1,    58,    -1,
      -1,    59,    58,    -1,    68,    -1,    78,    -1,    82,    -1,
      81,    -1,    60,    -1,    76,    -1,    -1,    41,    38,    61,
      62,    39,    34,    -1,    -1,    -1,    94,    63,    64,    -1,
      -1,    -1,    35,    65,    62,    -1,    -1,    41,    38,    67,
      62,    39,    -1,    -1,    14,    38,    84,    39,    69,    36,
      58,    73,    37,    70,    -1,    -1,    15,    71,    36,    58,
      73,    37,    -1,    72,    -1,    -1,    -1,    10,    38,    94,
      39,    34,    -1,    77,    40,    26,    75,    -1,    94,    34,
      -1,    40,    26,    75,    -1,    22,    -1,    23,    -1,    27,
      -1,    32,    -1,    21,    -1,    16,    38,    79,    39,    34,
      -1,    -1,    94,    80,    35,    79,    -1,    94,    -1,    31,
      38,    40,    39,    34,    -1,    -1,    30,   108,    83,    36,
      58,    37,    -1,    85,    91,    -1,    -1,    94,    11,    86,
      94,    -1,    -1,    94,    12,    87,    94,    -1,    -1,    94,
      13,    88,    94,    -1,    -1,    94,     8,    89,    94,    -1,
      -1,    38,    90,    85,    39,    -1,    -1,    -1,    28,    92,
      84,    -1,    -1,    29,    93,    84,    -1,    99,    95,    96,
      -1,    -1,    -1,    -1,    17,    97,    94,    -1,    -1,    18,
      98,    94,    -1,   104,   100,   101,    -1,    -1,    -1,    -1,
      19,   102,    99,    -1,    -1,    20,   103,    99,    -1,    -1,
      38,   105,    94,    39,    -1,    -1,    17,   106,   108,    -1,
      -1,    18,   107,   108,    -1,   108,    -1,    40,    -1,    43,
      -1,    44,    -1,    42,    -1,    46,    -1,    45,    -1,    66,
      -1,    -1,    -1,    77,     5,    41,   110,    38,   112,    39,
       6,    36,   115,   116,   111,    58,    73,    37,     7,    -1,
      -1,    -1,    77,    40,   113,   114,    -1,    -1,    35,   112,
      -1,    -1,    74,    -1,    -1,    74,   116,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    73,    73,    73,    73,    76,    77,    82,    83,    84,
      87,    88,    91,   106,   118,   121,   122,   123,   126,   127,
     132,   133,   134,   135,   136,   137,   142,   142,   157,   158,
     158,   165,   166,   166,   170,   170,   187,   187,   197,   197,
     198,   201,   204,   205,   212,   227,   230,   242,   243,   244,
     245,   246,   251,   254,   254,   255,   260,   265,   265,   275,
     278,   278,   281,   281,   284,   284,   287,   287,   290,   290,
     293,   294,   294,   297,   297,   304,   307,   314,   315,   315,
     316,   316,   321,   324,   331,   332,   332,   333,   333,   338,
     338,   339,   339,   340,   340,   341,   346,   347,   348,   349,
     350,   351,   352,   357,   361,   357,   372,   373,   373,   376,
     377,   380,   381,   384,   385
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
  "$@3", "funcion2", "$@4", "funcion3", "$@5", "funcionalt", "$@6",
  "condicion", "$@7", "condicion2", "$@8", "condicion3", "ret",
  "asignacion", "asigna2", "otraasignacion", "tipo", "escritura",
  "escritura2", "$@9", "lectura", "ciclo", "$@10", "expresion",
  "expresion2", "$@11", "$@12", "$@13", "$@14", "$@15", "operadorl",
  "$@16", "$@17", "exp", "exp1", "exp11", "$@18", "$@19", "termino",
  "termino1", "termino11", "$@20", "$@21", "factor", "$@22", "$@23",
  "$@24", "varcte", "function", "$@25", "$@26", "function2", "$@27",
  "function3", "asigna", "b2", 0
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
      62,    64,    65,    64,    67,    66,    69,    68,    71,    70,
      70,    72,    73,    73,    74,    75,    76,    77,    77,    77,
      77,    77,    78,    80,    79,    79,    81,    83,    82,    84,
      86,    85,    87,    85,    88,    85,    89,    85,    90,    85,
      91,    92,    91,    93,    91,    94,    95,    96,    97,    96,
      98,    96,    99,   100,   101,   102,   101,   103,   101,   105,
     104,   106,   104,   107,   104,   104,   108,   108,   108,   108,
     108,   108,   108,   110,   111,   109,   112,   113,   112,   114,
     114,   115,   115,   116,   116
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     8,     0,     2,     0,     3,     1,
       0,     2,     5,     4,     3,     0,     2,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     0,     6,     0,     0,
       3,     0,     0,     3,     0,     5,     0,    10,     0,     6,
       1,     0,     0,     5,     4,     2,     3,     1,     1,     1,
       1,     1,     5,     0,     4,     1,     5,     0,     6,     2,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     0,     3,     0,     3,     3,     0,     0,     0,     3,
       0,     3,     3,     0,     0,     0,     3,     0,     3,     0,
       4,     0,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     0,    16,     0,     0,     4,     0,
       2,     0,     1,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     7,     1,     0,     0,     5,     9,    10,
      51,    47,    48,    49,    50,     7,     0,     0,     0,     0,
       5,    11,     8,     0,    91,    93,    89,    96,     0,    99,
      97,    98,   101,   100,   102,     0,    76,    83,    95,     3,
       0,     6,     0,     0,     0,     0,    34,    13,    77,    84,
       0,   103,     0,    92,    94,     0,    28,    78,    80,    75,
      85,    87,    82,    15,     0,     0,    12,    90,     0,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    18,    24,    20,    15,    25,     0,    21,    23,
      22,     4,   106,    35,    31,    79,    81,    86,    88,     0,
       0,    57,     0,     0,    26,    14,    19,    16,     0,     0,
       0,    32,    30,    68,     0,    70,     0,     0,    53,     0,
       0,    46,     0,    28,     0,   107,     0,    28,     0,    36,
      71,    73,    59,    66,    60,    62,    64,     0,     0,    18,
       0,    45,     0,    44,   109,     0,    33,     0,     0,     0,
       0,     0,     0,     0,     0,    52,     0,     0,    56,     0,
     106,   108,   111,    69,    18,    72,    74,    67,    61,    63,
      65,    54,    58,    27,   110,   112,   113,    42,   113,   104,
       0,     0,   114,    18,     0,    41,    42,     0,    38,    37,
      40,     0,     0,     0,     0,    43,    18,   105,    42,     0,
      39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    50,    18,     7,     8,    15,     9,    64,
      80,    81,    82,    83,   123,    68,    94,   112,   127,    34,
      56,    84,   148,   189,   193,   190,   181,    85,   121,    86,
      87,    88,   117,   138,    89,    90,   119,   114,   115,   152,
     153,   154,   151,   128,   132,   149,   150,   116,    48,    59,
      70,    71,    36,    49,    62,    72,    73,    37,    45,    43,
      44,    38,    20,    65,   183,   110,   144,   161,   176,   179
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -178
static const yytype_int16 yypact[] =
{
     -27,  -178,    27,    -2,  -178,    34,    15,    34,  -178,    18,
    -178,  -178,  -178,  -178,  -178,    -2,    20,     2,    61,    60,
      34,  -178,  -178,    41,  -178,  -178,  -178,  -178,    30,  -178,
    -178,  -178,  -178,  -178,  -178,    35,  -178,  -178,  -178,  -178,
      38,  -178,     2,    49,    49,     2,  -178,  -178,    -5,    10,
      44,  -178,    37,  -178,  -178,    42,     2,  -178,  -178,  -178,
    -178,  -178,  -178,   101,    78,    47,  -178,  -178,    48,  -178,
       2,     2,     2,     2,    58,    59,    49,    62,    72,    63,
      65,  -178,    -8,  -178,  -178,   101,  -178,    64,  -178,  -178,
    -178,  -178,    34,  -178,    70,  -178,  -178,  -178,  -178,    32,
       2,  -178,    68,     2,  -178,  -178,  -178,  -178,    73,    69,
      74,  -178,  -178,  -178,    75,   -11,    23,    79,    80,    76,
      81,  -178,    77,     2,     2,  -178,   115,     2,    32,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,    91,    92,    -8,
      95,  -178,    87,  -178,   103,    94,  -178,   104,   108,    32,
      32,     2,     2,     2,     2,  -178,     2,   109,  -178,   106,
      34,  -178,    34,  -178,    -8,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,    34,   135,    34,  -178,
     110,   112,  -178,    -8,     2,   132,   135,   111,  -178,  -178,
    -178,   114,   118,   117,   147,  -178,    -8,  -178,   135,   120,
    -178
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,  -178,  -178,  -178,   138,   140,   150,  -178,  -178,  -178,
      83,   -80,  -178,  -178,  -178,  -112,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -177,  -152,    36,  -178,
      -4,  -178,     5,  -178,  -178,  -178,  -178,   -98,    43,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,   -17,  -178,  -178,
    -178,  -178,   -10,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,   -39,  -178,  -178,  -178,     3,  -178,  -178,  -178,   -16
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -56
static const yytype_int16 yytable[] =
{
      35,    16,   106,    19,    53,    54,    74,     5,    75,   191,
     175,   142,    57,    58,     1,   146,    19,   130,   131,    24,
      25,   199,    76,    77,   178,    52,   178,     4,    55,    60,
      61,   133,    78,    79,   134,   135,   136,   101,     6,    69,
      26,    17,    27,    28,    29,    30,    31,    32,    33,    24,
      25,   165,   166,    95,    96,    10,    11,    12,     6,   157,
      23,    13,    97,    98,    39,    40,    14,    42,    46,    47,
     113,    66,    27,    28,    29,    30,    31,    32,    33,    51,
      63,    67,    91,   118,   177,    92,   122,    93,   109,    27,
      28,    29,    30,    31,    32,    33,    99,   100,   103,   124,
     102,   104,   105,   186,   108,   111,    69,   122,   120,   125,
      69,   141,   139,   126,   129,    74,   198,    75,   137,   -55,
     140,   145,    10,    11,    12,   155,   159,   156,    13,   158,
     162,    76,    77,    14,   167,   168,   169,   170,   160,   118,
     173,    78,    79,   163,   164,   180,   172,   188,   184,   185,
     192,   194,   195,   196,   197,    22,   109,   200,    41,    21,
     143,   171,   182,   174,     0,     0,     0,   187,   107,     0,
       0,   147
};

static const yytype_int16 yycheck[] =
{
      17,     5,    82,     7,    43,    44,    14,     9,    16,   186,
     162,   123,    17,    18,    41,   127,    20,    28,    29,    17,
      18,   198,    30,    31,   176,    42,   178,     0,    45,    19,
      20,     8,    40,    41,    11,    12,    13,    76,    40,    56,
      38,    26,    40,    41,    42,    43,    44,    45,    46,    17,
      18,   149,   150,    70,    71,    21,    22,    23,    40,   139,
      40,    27,    72,    73,     3,     5,    32,    26,    38,    34,
      38,    34,    40,    41,    42,    43,    44,    45,    46,    41,
      36,    39,     4,   100,   164,    38,   103,    39,    92,    40,
      41,    42,    43,    44,    45,    46,    38,    38,    26,    26,
      38,    38,    37,   183,    40,    35,   123,   124,    40,    40,
     127,    34,    36,    39,    39,    14,   196,    16,    39,    39,
      39,     6,    21,    22,    23,    34,    39,    35,    27,    34,
      36,    30,    31,    32,   151,   152,   153,   154,    35,   156,
      34,    40,    41,    39,    36,    10,    37,    15,    38,    37,
      39,    37,    34,    36,     7,    15,   160,    37,    20,     9,
     124,   156,   178,   160,    -1,    -1,    -1,   184,    85,    -1,
      -1,   128
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    48,    49,     0,     9,    40,    52,    53,    55,
      21,    22,    23,    27,    32,    54,    77,    26,    51,    77,
     109,    53,    52,    40,    17,    18,    38,    40,    41,    42,
      43,    44,    45,    46,    66,    94,    99,   104,   108,     3,
       5,    51,    26,   106,   107,   105,    38,    34,    95,   100,
      50,    41,    94,   108,   108,    94,    67,    17,    18,    96,
      19,    20,   101,    36,    56,   110,    34,    39,    62,    94,
      97,    98,   102,   103,    14,    16,    30,    31,    40,    41,
      57,    58,    59,    60,    68,    74,    76,    77,    78,    81,
      82,     4,    38,    39,    63,    94,    94,    99,    99,    38,
      38,   108,    38,    26,    38,    37,    58,    57,    40,    77,
     112,    35,    64,    38,    84,    85,    94,    79,    94,    83,
      40,    75,    94,    61,    26,    40,    39,    65,    90,    39,
      28,    29,    91,     8,    11,    12,    13,    39,    80,    36,
      39,    34,    62,    75,   113,     6,    62,    85,    69,    92,
      93,    89,    86,    87,    88,    34,    35,    58,    34,    39,
      35,   114,    36,    39,    36,    84,    84,    94,    94,    94,
      94,    79,    37,    34,   112,    74,   115,    58,    74,   116,
      10,    73,   116,   111,    38,    37,    58,    94,    15,    70,
      72,    73,    39,    71,    37,    34,    36,     7,    58,    73,
      37
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
#line 73 "SimpleFlow.y"
    { insertaProcIni('n', (yyvsp[(1) - (1)].string)); scope = 'g'; generaGoTo(); pushPSaltos(apunta_cuadruplo-1); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 73 "SimpleFlow.y"
    { scope = 'l'; rellenaGoTo(popPSaltos(), apunta_cuadruplo); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 73 "SimpleFlow.y"
    { generaEnd(); printf("Programa completo\n"); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 91 "SimpleFlow.y"
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

  case 13:

/* Line 1455 of yacc.c  */
#line 106 "SimpleFlow.y"
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
#line 142 "SimpleFlow.y"
    { if(buscaProc((yyvsp[(1) - (2)].string)) == -1) {
			yyerror("Procedimiento llamado no existente.\n");
		 } else {
			generaCuadruploERA(buscaProc((yyvsp[(1) - (2)].string)));
			k++;
		 };}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 147 "SimpleFlow.y"
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
#line 158 "SimpleFlow.y"
    { if(popPTipos() == tipoParametro(k-1)) {
			generaCuadruploParametro(popPilaO(), k);
		} else {
			yyerror("Tipo incompatible de parametro en la llamada de procedimiento.\n");
		};}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 166 "SimpleFlow.y"
    { k++; ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 170 "SimpleFlow.y"
    { pushPOper(350); if(buscaProc((yyvsp[(1) - (2)].string)) == -1) {
			yyerror("Procedimiento llamado no existente.\n");
		 } else {
			generaCuadruploERA(buscaProc((yyvsp[(1) - (2)].string)));
			k++;
		 };}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 175 "SimpleFlow.y"
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
#line 187 "SimpleFlow.y"
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
#line 197 "SimpleFlow.y"
    { generaGoTo(); rellenaGoToF(popPSaltos(), apunta_cuadruplo); pushPSaltos(apunta_cuadruplo-1); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 197 "SimpleFlow.y"
    { rellenaGoTo(popPSaltos(), apunta_cuadruplo); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 201 "SimpleFlow.y"
    { rellenaGoToF(popPSaltos(), apunta_cuadruplo); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 205 "SimpleFlow.y"
    { numret++; asignaTipoAux(tipoFunc); valorReturn = cimaPilaO(); generaCuadruploReturn(popPilaO());
					if(popPTipos() != tipoAux)
						yyerror("Tipo de valor de salida incompatible con el del metodo\n"); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 212 "SimpleFlow.y"
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
#line 230 "SimpleFlow.y"
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
#line 242 "SimpleFlow.y"
    { tipo = 'i'; ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 243 "SimpleFlow.y"
    { tipo = 'f'; ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 244 "SimpleFlow.y"
    { tipo = 'b'; ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 245 "SimpleFlow.y"
    { tipo = 'c'; ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 246 "SimpleFlow.y"
    { tipo = 's'; ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 254 "SimpleFlow.y"
    { generaCuadruploPrint(popPilaO()); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 255 "SimpleFlow.y"
    { generaCuadruploPrint(popPilaO()); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 260 "SimpleFlow.y"
    { generaCuadruploRead(popPilaO()); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 265 "SimpleFlow.y"
    { if(popPTipos() == 0) {
				pushPSaltos(apunta_cuadruplo);
				generaGoToF(popPilaO());
			} else {
				yyerror("Tipo incompatible en el repeat.\n");
			} ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 270 "SimpleFlow.y"
    { rellenaGoToF(popPSaltos(), apunta_cuadruplo); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 278 "SimpleFlow.y"
    { pushPOper(202); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 278 "SimpleFlow.y"
    { if(cimaPOper() == 202) {
		  				generacionDeCuadruplos(6);
					      } pushPTipos(4); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 281 "SimpleFlow.y"
    { pushPOper(203); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 281 "SimpleFlow.y"
    { if(cimaPOper() == 203) {
		  				generacionDeCuadruplos(7);
					      } pushPTipos(4); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 284 "SimpleFlow.y"
    { pushPOper(204); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 284 "SimpleFlow.y"
    { if(cimaPOper() == 204) {
		  				generacionDeCuadruplos(10);
					      } pushPTipos(4); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 287 "SimpleFlow.y"
    { pushPOper(205); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 287 "SimpleFlow.y"
    { if(cimaPOper() == 205) {
		  				generacionDeCuadruplos(9);
					      } pushPTipos(4); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 290 "SimpleFlow.y"
    { pushPOper(350); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 290 "SimpleFlow.y"
    { popPOper(); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 294 "SimpleFlow.y"
    { pushPOper(200); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 294 "SimpleFlow.y"
    { if(cimaPOper() == 200) {
		  				generacionDeCuadruplos(4);
					      };}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 297 "SimpleFlow.y"
    { pushPOper(201); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 297 "SimpleFlow.y"
    { if(cimaPOper() == 201) {
		  				generacionDeCuadruplos(5);
					      };}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 307 "SimpleFlow.y"
    { if(cimaPOper() == 100) {
		  	generacionDeCuadruplos(0);
	} else if(cimaPOper() == 101) {
		  	generacionDeCuadruplos(1);
	};}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 315 "SimpleFlow.y"
    { pushPOper(100); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 316 "SimpleFlow.y"
    { pushPOper(101); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 324 "SimpleFlow.y"
    { if(cimaPOper() == 102) {
		  	generacionDeCuadruplos(2);
	} else if(cimaPOper() == 103) {
		  	generacionDeCuadruplos(3);
	};}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 332 "SimpleFlow.y"
    { pushPOper(102); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 333 "SimpleFlow.y"
    { pushPOper(103); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 338 "SimpleFlow.y"
    { pushPOper(350); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 338 "SimpleFlow.y"
    { popPOper(); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 339 "SimpleFlow.y"
    { aux = 1; ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 340 "SimpleFlow.y"
    { aux = -1; ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 346 "SimpleFlow.y"
    { op = buscaVar((yyvsp[(1) - (1)].string), scope); asignaTipoAux(buscaVarTipo((yyvsp[(1) - (1)].string), scope)); pushPTipos(tipoAux); pushPilaO(op); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 347 "SimpleFlow.y"
    { agregaCte('i', (yyvsp[(1) - (1)].string), aux); op = buscaCteInt((yyvsp[(1) - (1)].string)); pushPilaO(op); pushPTipos(0); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 348 "SimpleFlow.y"
    { agregaCte('f', (yyvsp[(1) - (1)].string), aux); op = buscaCteFloat((yyvsp[(1) - (1)].string)); pushPilaO(op); pushPTipos(1); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 349 "SimpleFlow.y"
    { agregaCte('s', subString((yyvsp[(1) - (1)].string), 1, strlen((yyvsp[(1) - (1)].string))), 0); op = buscaCteChar((yyvsp[(1) - (1)].string)); pushPilaO(op); pushPTipos(3); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 350 "SimpleFlow.y"
    { agregaCte('c', subString((yyvsp[(1) - (1)].string), 1, strlen((yyvsp[(1) - (1)].string))), 0); op = buscaCteStr((yyvsp[(1) - (1)].string)); pushPilaO(op); pushPTipos(2); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 351 "SimpleFlow.y"
    { agregaCte('b', (yyvsp[(1) - (1)].string), 0); op = buscaCteBool((yyvsp[(1) - (1)].string)); pushPilaO(op); pushPTipos(4); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 357 "SimpleFlow.y"
    { scope = 'l'; tipoFunc = tipo; numCuadFunc = apunta_cuadruplo; reiniciaContTemp(); numret = 0;
				if(buscaProc((yyvsp[(3) - (3)].string)) != -1) {
					yyerror("Procedimiento declarado existente.\n");
				 }
				;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 361 "SimpleFlow.y"
    { insertaProc(tipoFunc,(yyvsp[(3) - (11)].string),numVarInt,numVarFloat,numVarChar,numVarStr,numVarBool,cParam,numCuadFunc,paramAux, valorReturn); insertaVarGlobal(tipoFunc, (yyvsp[(3) - (11)].string)); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 361 "SimpleFlow.y"
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

  case 107:

/* Line 1455 of yacc.c  */
#line 373 "SimpleFlow.y"
    { insertaParam(tipo, cParam); cParam++; insertaVar(tipo, (yyvsp[(2) - (2)].string)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2152 "SimpleFlow.tab.c"
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
#line 388 "SimpleFlow.y"


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

void insertaParam(char tipo, int cParam) {
	paramAux[cParam] = tipo;
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

	imprimeCuadruplos("obj");
}

void yyerror(const char *s) {
	cout << "Error!  " << s << endl;
	exit(-1);
}

