
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 43 "SimpleFlow.y"

	char ch;
	char *string;



/* Line 1676 of yacc.c  */
#line 105 "SimpleFlow.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


