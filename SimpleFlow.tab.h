
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

/* Line 1676 of yacc.c  */
#line 51 "SimpleFlow.y"

	char ch;
	char *string;



/* Line 1676 of yacc.c  */
#line 106 "SimpleFlow.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


