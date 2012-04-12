%{
#include <cstdio>
#include <iostream>
using namespace std;
#define YY_DECL extern "C" int yylex()

#include "SimpleFlow.tab.h"
%}

%%

[0-9]+						{ yylval.string=strdup(yytext); return CTEE; }
[0-9]+"."[0-9]+					{ yylval.string=strdup(yytext); return CTEF; }
":"						{ return DP; }
";"						{ return PC; }
","						{ return COMA; }
"{"						{ return LLA; }
"}"						{ return LLC; }
"="						{ return EQ; }
"("						{ return PARA; }
")"						{ return PARC; }
">"						{ return MAY; }
"<"						{ return MEN; }
"!="						{ return DIF; }
"+"						{ return SUM; }
"-"						{ return RES; }
"*"						{ return MULT; }
"/"						{ return DIV; }
"&&"						{ return AND; }
"||"						{ return OR; }
"=="						{ return IGU; }
"if"						{ return IF; }
"else"						{ return ELSE; }
"print"						{ return PRINT; }
"read"						{ return READ; }
"int"						{ return INT; }
"float"						{ return FLOAT; }
"string"					{ return STR; }
"bool"						{ return BOOL; }
"char"						{ return CHAR; }
"begin"						{ return BEGINP; }
"end"						{ return ENDP; }
"repeat"					{ return REPEAT; }
"function"					{ return FUNCTION; }
"beginf"					{ return BEGINF; }
"endf"						{ return ENDF; }
"global"					{ return GLOBAL; }
"true"|"false"					{ yylval.string=strdup(yytext); return BOOLEAN; }
[A-Z0-9]+					{ yylval.string=strdup(yytext); return NOMBRE; }
[a-zA-Z0-9]+					{ yylval.string=strdup(yytext); return ID; }
\'[a-z|A-Z]\'					{ yylval.string=strdup(yytext); return CH; }
\".+\"						{ yylval.string=strdup(yytext); return STRING; }
[ \t\n]						{}

%%
