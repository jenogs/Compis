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
<<<<<<< HEAD
=======
int cParam = 0;
>>>>>>> 288bc3b6c5781ab8fcdce3757e6039361f0b0322


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
<<<<<<< HEAD
	;

asignaciong: tipo ID EQ asigna2 PC { if(buscaVar($2)){
					if(tipo == 'n') {
						//asigna
					} else {
						printf("Error: Variable global existente: %s", $2);
					}
				    } else {
					if(tipo == tipocte) {
						insertaVar(tipo, $2, 'g');
						printf("Asignacion Completa\n");
					} else {
						printf("Error: Tipos no compatibles");
					}
				   }
				}
=======
>>>>>>> 288bc3b6c5781ab8fcdce3757e6039361f0b0322
	;

asignaciong: tipo ID EQ asigna2 PC { if(buscaVar($2)){
					if(tipo == 'n') {
						//asigna
					} else {
						printf("Error: Variable global existente: %s", $2);
					}
				    } else {
					if(tipo == tipocte) {
						insertaVar(tipo, $2, 'g');
						printf("Asignacion Completa\n");
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

<<<<<<< HEAD
/*****Función*****/
=======
/*****ESTATUTO-FUNCION*****/
>>>>>>> 288bc3b6c5781ab8fcdce3757e6039361f0b0322

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
<<<<<<< HEAD

asignacion: tipo ID EQ asigna2 PC { if(buscaVar($2)){
					if(tipo == 'n') {
						//asigna
					} else {
						printf("Error: Variable local existente: %s", $2);
					}
				    } else {
					if(tipo == tipocte) {
						insertaVar(tipo, $2, 'l');
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
=======

asignacion: tipo ID EQ asigna2 PC { if(buscaVar($2)){
					if(tipo == 'n') {
						//asigna
					} else {
						printf("Error: Variable local existente: %s", $2);
					}
				    } else {
					if(tipo == tipocte) {
						insertaVar(tipo, $2, 'l');
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
>>>>>>> 288bc3b6c5781ab8fcdce3757e6039361f0b0322

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

expresion2: exp MAY { /*meterPOper(); */} exp { printf("Mayor que\n"); }
	| exp MEN { /*meterPOper(); */} exp { printf("Menor que\n"); }
	| exp DIF { /*meterPOper(); */} exp
	| exp IGU { /*meterPOper(); */} exp
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

<<<<<<< HEAD
termino: factor MULT { /*meterPOper(); */} termino 
	| factor DIV { /*meterPOper(); */} termino 
	| factor 
	;

factor: PARA exp PARC { printf("Cierra parentesis\n"); }
	| SUM { /*meterPOper(); */} varcte
	| RES { /*meterPOper(); */} varcte 
	| varcte 
	;

varcte: ID {}
	| CTEE { tipocte = 'i'; } { /*meterPOperandos(); */}
	| CTEF { tipocte = 'f'; } { /*meterPOperandos(); */}
	| STRING { tipocte = 's'; } { /*meterPOperandos(); */}
	| CH { tipocte = 'c';  } { /*meterPOperandos(); */}
	| BOOLEAN { tipocte = 'b'; } { /*meterPOperandos(); */}
	;

/****FUNCIÓN****/
=======
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

/****FUNCIÃ“N****/
>>>>>>> 288bc3b6c5781ab8fcdce3757e6039361f0b0322

function: tipo FUNCTION NOMBRE { if(!buscaProc($3)) {
					insertaProc(tipo, $3);
					proc = $3;
				 } else {
					printf("Error: Procedimiento existente.");
				 }
				}
<<<<<<< HEAD
	PARA function2 PARC BEGINF bloque ENDF
	;

function2: tipo ID { insertaParam(tipo, $2, proc) } function3
=======
	PARA function2 PARC { cParam = 0; } BEGINF bloque ENDF
	;

function2: tipo ID { insertaParam(tipo, $2, cParam) } function3
>>>>>>> 288bc3b6c5781ab8fcdce3757e6039361f0b0322
	;

function3: /* empty */
	| COMA function2
	;


%%

main() {
	FILE *myfile = fopen("prueba", "r");
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
	exit(-1);
}
