%{
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
int aux = 0;
int op; //operador
int auxif;

void generacionDeCuadruplos(int oper);
void asignaTipoAux(char tipo);
char * subString(char* str, int start, int length);

%}

%union {
	char ch;
	char *string;
};

%token BEGINP ENDP FUNCTION BEGINF ENDF IGU GLOBAL RETURN
%token MAY MEN DIF IF ELSE PRINT SUM RES MULT DIV STR INT FLOAT PROG VAR EQ BOOL AND OR REPEAT READ CHAR
%token DP PC COMA LLA LLC PARA PARC

%token <string> ID
%token <string> NOMBRE
%token <string> STRING
%token <string> CTEE
%token <string> CTEF
%token <string> BOOLEAN
%token <string> CH

%left SUM RES MULT DIV
%left MAY MEN DIF AND OR IGU
%right EQ

%%

programa: NOMBRE { insertaProc('n', $1); scope = 'g'; generaGoTo(); pushPSaltos(apunta_cuadruplo-1); } asignaglobal programa2 BEGINP { scope = 'l'; rellenaGoTo(popPSaltos(), apunta_cuadruplo); } bloque ENDP { printf("Programa completo\n"); }
	;

programa2: /* empty */
	| function programa2 { printf("Funcion\n"); }
	;

/*****ASIGNACION GLOBAL*****/

asignaglobal: /* empty */
	| GLOBAL asignaciong asignaglobal
	;

asignaciong: tipo ID EQ asigna2 PC { pushPOper(300); asignaTipoAux(tipo);
				    if(buscaVar($2, 'g') != -1){
					if(tipo == 'n') {
						if(cubo[cimaPTipos()][tipoAux][8] != 'x') {
							generaCuadruplo(popPOper(), popPilaO(), -1, buscaVar($2, 'g'));
						}
					} else {
						printf("Error: Variable global existente: %s\n", $2);
					}
				    } else {
					insertaVarGlobal(tipo, $2);
					printf("Asignacion Completa en tabla de Variables Globales\n");
					if(cubo[cimaPTipos()][tipoAux][8] != 'x') {
						generaCuadruplo(popPOper(), popPilaO(), -1, buscaVar($2, 'g'));
						
					} else {
						printf("Error: Tipos no compatibles\n");
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

condicion: IF PARA expresion PARC { auxif = popPTipos();
				if(auxif != 4) {
					printf("Error: Error Semantico");
				} else {
					generaGoToF(popPilaO());
					pushPSaltos(apunta_cuadruplo-1);
				}} 
	bloque condicion2 { printf("Condicion Completa\n"); }
	;

condicion2: ELSE { generaGoTo(); rellenaGoToF(popPSaltos(), apunta_cuadruplo); pushPSaltos(apunta_cuadruplo-1); } bloque { printf("apuntador = %i\n",apunta_cuadruplo);rellenaGoTo(popPSaltos(), apunta_cuadruplo); }
	| condicion3
	;

condicion3: { rellenaGoToF(popPSaltos(), apunta_cuadruplo); }
	;

/*****ASIGNACION LOCAL*****/

asignacion: tipo ID EQ asigna2 PC { pushPOper(300); asignaTipoAux(tipo);
				    if(buscaVar($2, 'l') != -1){
					if(tipo == 'n') {
						if(cubo[cimaPTipos()][tipoAux][8] != 'x') {
							generaCuadruplo(popPOper(), popPilaO(), -1, buscaVar($2, 'l'));
						}
					} else {
						printf("Error: Variable global existente: %s\n", $2);
					}
				    } else {
					insertaVar(tipo, $2);
					printf("Asignacion Completa en tabla de Variables Locales\n");
					if(cubo[cimaPTipos()][tipoAux][8] != 'x') {
						generaCuadruplo(popPOper(), popPilaO(), -1, buscaVar($2, 'l'));
						
					} else {
						printf("Error: Tipos no compatibles\n");
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

escritura2: exp { generaCuadruploPrint(popPilaO()); } COMA escritura2
	| exp { generaCuadruploPrint(popPilaO()); }
	;

/*****LECTURA*****/

lectura: READ PARA ID PARC PC { printf("Lectura completa\n"); }
	;

/*****CICLO*****/

ciclo: REPEAT varcte bloque {printf("Ciclo completo\n"); }
	;

/*****EXPRESION*****/

expresion: expresion2 operadorl { printf("Termina expresion\n"); }
	;

expresion2: exp MAY { pushPOper(202); } exp { if(cimaPOper() == 202) {
		  				generacionDeCuadruplos(6);
					      }} 
	| exp MEN { pushPOper(203); } exp { if(cimaPOper() == 203) {
		  				generacionDeCuadruplos(7);
					      }} 
	| exp DIF { pushPOper(204); } exp { if(cimaPOper() == 204) {
		  				generacionDeCuadruplos(10);
					      }} 
	| exp IGU { pushPOper(205); } exp { if(cimaPOper() == 205) {
		  				generacionDeCuadruplos(9);
					      }} 
	| PARA expresion2 PARC
	;

operadorl: /* empty */
	| AND { pushPOper(200); } expresion { if(cimaPOper() == 200) {
		  				generacionDeCuadruplos(4);
					      }} 
	| OR { pushPOper(201); } expresion { if(cimaPOper() == 201) {
		  				generacionDeCuadruplos(5);
					      }} 
	;

/*****SUMA Y RESTA*****/

exp: 	termino exp1 exp11
	;

exp1: { if(cimaPOper() == 100) {
		  	generacionDeCuadruplos(0);
	} else if(cimaPOper() == 101) {
		  	generacionDeCuadruplos(1);
	}} 
	;

exp11: /* empty */
	|SUM { pushPOper(100); } exp
	| RES { pushPOper(101); } exp
	;

/*****MULTIPLICACION Y DIVISION*****/

termino: factor termino1 termino11
	;

termino1: { if(cimaPOper() == 102) {
		  	generacionDeCuadruplos(2);
	} else if(cimaPOper() == 103) {
		  	generacionDeCuadruplos(3);
	}}
	;

termino11: /* empty */
	| MULT { pushPOper(102); } termino
	| DIV { pushPOper(103); } termino
	;

/***Factor positivo o negativo***/

factor: PARA exp PARC
	| SUM { aux = 1; } varcte 
	| RES { aux = -1; } varcte
	| varcte
	;

/*****VARIABLES CONSTANTES*****/

varcte: ID { op = buscaVar($1, scope); pushPilaO(op); }
	| CTEE { agregaCte('i', $1, aux); op = buscaCteInt($1); pushPilaO(op); pushPTipos(0); }
	| CTEF { agregaCte('f', $1, aux); op = buscaCteFloat($1); pushPilaO(op); pushPTipos(1); } 
	| STRING { agregaCte('s', subString($1, 1, strlen($1)), 0); op = buscaCteChar($1); pushPilaO(op); pushPTipos(3); }
	| CH { agregaCte('c', subString($1, 1, strlen($1)), 0); op = buscaCteStr($1); pushPilaO(op); pushPTipos(2); }
	| BOOLEAN { agregaCte('b', $1, 0); op = buscaCteBool($1); pushPilaO(op); pushPTipos(4); }
	;

/****FUNCIÓN****/

function: tipo FUNCTION NOMBRE { scope = 'l';
				if(buscaProc($3) == -1) {
					insertaProc(tipo, $3);
					printf("Inserto Procedimiento a directorio.\n");
				 } else {
					printf("Error: Procedimiento existente.\n");
				 }
				}
	PARA function2 PARC { cParam = 0; } BEGINF LLA bloque2 RETURN PARA exp PARC PC LLC ENDF { reiniciaTablaVar(); generaRetorno(); }
	;

function2: tipo ID { insertaParam(tipo, cParam); cParam++; insertaVar(tipo, $2); printf("Inserto Parametro.\n");} function3
	;

function3: /* empty */
	| COMA function2
	;

%%

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
	} else {
		printf("Error: Tipo no aplicable\n");
	}
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
