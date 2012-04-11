%{
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


%}

%union {
	char *palabra;
	char caracter;
	int entero;
	float flotante;
};

%token NOMBRE BEGINP ENDP FUNCTION BEGINF ENDF CTEE CTEF IGU GLOBAL BOOLEAN ID
%token MAY MEN DIF IF ELSE PRINT SUM RES MULT DIV STR INT FLOAT PROG VAR EQ BOOL AND OR STRING ELSEIF REPEAT READ CHAR CH
%token DP PC COMA LLA LLC PARA PARC

%type <entero> CTEE
%type <flotante> CTEF
%type <palabra> ID NOMBRE STRING
%type <caracter> CH

%left SUM RES MULT DIV
%left MAY MEN DIF AND OR IGU
%right EQ

%%

programa: NOMBRE asignaglobal programa2 BEGINP bloque ENDP { printf("Programa completo\n"); }
	;

programa2: /* empty */
	| function programa2 { printf("Funcion\n"); }
	;

/*****ASIGNACION GLOBAL*****/

asignaglobal: /* empty */
	| GLOBAL asignaciong asignaglobal { printf("Asignacion global\n"); }
	;

asignaciong: tipo ID EQ asigna2 PC { if(buscaVar($2)){
					if(tipo == 'n') {
						//asigna
					} else {
						printf("Error: Variable global existente: %s", $2);
					}
				    } else {
					if(tipo == tipocte) {
						insertaVarGlobal(tipo, $2);
						printf("Asignacion Completa en tabla de Variables Globales\n");
					} else {
						printf("Error: Tipos no compatibles");
					}
				   }
				}
	;

/*****BLOQUES*****/

bloque: LLA bloque2 LLC { printf("Bloque completo\n"); }
	;

bloque2: /* empty */
	| estatuto bloque2 { printf("Bloque2 completo\n"); }
	;

/*****ESTATUTOS*****/

estatuto: asignacion
	| condicion
	| escritura
	| ciclo
	| lectura
	| funcion
	;

/*****ESTATUTO-FUNCION*****/

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

/*****ASIGNACION LOCAL*****/

asignacion: tipo ID EQ asigna2 PC { if(buscaVar($2)){
					if(tipo == 'n') {
						//asigna
					} else {
						printf("Error: Variable local existente: %s", $2);
					}
				    } else {
					if(tipo == tipocte) {
						insertaVar(tipo, $2, proc);
						printf("Asignacion Completa\n");
					} else {
						printf("Error: Tipos no compatibles");
					}
				     }
				   }
	;

asigna2: exp
	| funcion 
	;

/*****TIPO DE DATO*****/

tipo:	/* empty*/ { tipo = 'n'; }
	| INT { tipo = 'i'; }
	| FLOAT { tipo = 'f'; }
	| BOOL { tipo = 'b'; }
	| CHAR { tipo = 'c'; }
	| STR { tipo = 's'; }
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

/*****EXPRESION*****/

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
	| AND expresion
	| OR expresion
	;

/*****EXP*****/

exp: 	termino SUM { /*meterPOper(); */} exp
	| termino RES { /*meterPOper(); */} exp
	| termino
	;

/*****MULTIPLICACION Y DIVISION*****/

termino: factor MULT { /*meterPOper(); */} termino
	| factor DIV { /*meterPOper(); */} termino
	| factor
	;

/*****SUMA Y RESTA*****/

factor: PARA exp PARC
	| SUM { /*meterPOper(); */} varcte
	| RES { /*meterPOper(); */} varcte
	| varcte
	;

/*****VARIABLES CONSTANTES*****/

varcte: ID {/*meterPilaO(); */}
	| CTEE { tipocte = 'i'; /*meterPilaO(); */}
	| CTEF { tipocte = 'f'; /*meterPilaO(); */} 
	| STRING { tipocte = 's'; /*meterPilaO(); */}
	| CH { tipocte = 'c';  /*meterPilaO(); */}
	| BOOLEAN { tipocte = 'b'; /*meterPilaO(); */}
	;

/****FUNCIÓN****/

function: tipo FUNCTION NOMBRE { if(!buscaProc($3)) {
					insertaProc(tipo, $3);
					proc = $3;
				 } else {
					printf("Error: Procedimiento existente.");
				 }
				}
	PARA function2 PARC { cParam = 0; } BEGINF bloque ENDF
	;

function2: tipo ID { insertaParam(tipo, $2, cParam); cParam++; } function3
	;

function3: /* empty */
	| COMA function2
	;

%%

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
