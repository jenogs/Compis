%{
#include <cstdio>
#include <iostream>
using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
 
void yyerror(const char *s);
%}

%union {
	char *id;
	int entero;
	float flotante;
};

%token NOMBRE BEGINP ENDP FUNCTION BEGINF ENDF CTEE CTEF IGU GLOBAL
%token MAY MEN DIF IF ELSE PRINT SUM RES MULT DIV STR INT FLOAT PROG VAR EQ BOOL AND OR STRING ELSEIF REPEAT READ CHAR CH
%token ID
%token DP PC COMA LLA LLC PARA PARC

%type <entero> CTEE
%type <flotante> CTEF
%type <id> ID

%left SUM RES MULT DIV
%left MAY MEN DIF AND OR IGU
%right EQ

%%

programa: NOMBRE asignaglobal programa2 BEGINP bloque ENDP { printf("Programa completo\n"); }
	;

programa2: /* empty */
	| function programa2 { printf("Funcion\n"); }
	;

asignaglobal: /* empty */
	| GLOBAL asignacion asignaglobal { printf("Asignacion global\n"); }
	;

bloque: LLA bloque2 LLC { printf("Bloque completo\n"); }
	;

bloque2: /* empty */
	| estatuto bloque2 { printf("Bloque2 completo\n"); }
	;

estatuto: asignacion
	| condicion
	| escritura
	| ciclo
	| lectura
	| funcion
	;

/*****Función*****/

funcion: NOMBRE PARA funcion2 PARC PC { printf("Funcion\n"); }
	;

funcion2: ID funcion3
	;

funcion3: /* empty */
	| COMA funcion2
	;

/*****Condición*****/

condicion: IF PARA expresion PARC bloque condicion2 condicion3 { printf("Condicion Completa\n"); }
	;

condicion2: /* empty */
	| ELSEIF PARA expresion PARC bloque condicion2
	;

condicion3: /* empty */
	| ELSE bloque
	;

/*****ASIGNACION*****/

asignacion: tipo ID EQ asigna2 PC { printf("Asignacion Completa\n"); }
	;

asigna2: exp | funcion 
    ;

tipo:	/* empty*/
	| INT { printf("Asigna Entero\n"); }
	| FLOAT
	| BOOL
	| CHAR
	| STR
	;

/*****ESCRITURA*****/

escritura: PRINT PARA escritura2 PARC PC { printf("Escritura Completa\n"); }
	;

escritura2: exp COMA escritura2
	| exp
	;

/*****LECTURA*****/

lectura: READ PARA ID PARC PC { printf("Lectura completa\n"); }
	;

/*****CICLO*****/

ciclo: REPEAT varcte bloque { printf("Ciclo completo\n"); }
	;

expresion: expresion2 operadorl { printf("Termina expresion\n"); }
	|  varcte { printf("Termina expresion booleana\n"); }
	;

expresion2: exp MAY exp { printf("Mayor que\n"); }
	| exp MEN exp { printf("Menor que\n"); }
	| exp DIF exp
	| exp IGU exp
	| PARA expresion2 PARC { printf("Termina expresion2\n"); }
	;

operadorl: /* empty */
	| AND expresion { printf("And\n"); }
	| OR expresion { printf("Or\n"); }
	;

exp: 	termino SUM exp { printf("Exp\n"); }
	| termino RES exp
	| termino
	;

termino: factor MULT termino
	| factor DIV termino
	| factor
	;

factor: PARA exp PARC { printf("Cierra parentesis\n"); }
	| SUM varcte
	| RES varcte
	| varcte
	;

varcte: ID
	| CTEE
	| CTEF
	| STRING
	| CH
	;

function: tipo FUNCTION NOMBRE PARA function2 PARC BEGINF bloque ENDF { printf("Funcion terminada\n"); }
	;

function2: tipo ID function3
	;

function3: /* empty */
	| COMA function2
	;

%%

main() {
	// open a file handle to a particular file:
	FILE *myfile = fopen("prueba", "r");
	// make sure it is valid:
	if (!myfile) {
		cout << "No se puede abrir el archivo programa!" << endl;
		return -1;
	}
	// set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	
}

void yyerror(const char *s) {
	cout << "Error!  Mensaje: " << s << endl;
	// might as well halt now:
	exit(-1);
}
