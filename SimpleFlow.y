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

void generacionDeCuadruplos(int oper);
void asignaTipoAux(char tipo);
void sumaVar(char tipo);
void reiniciaContVars();
void reiniciaContTemp();
char * subString(char* str, int start, int length);
void insertaParam(char tipo, int cParam);
int asignaTemp(char tipo);

%}

%union {
	char ch;
	char *string;
};

%token BEGINP ENDP FUNCTION BEGINF ENDF IGU GLOBAL RETURN UNTIL
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

programa: NOMBRE { insertaProcIni('n', $1); scope = 'g'; } asignaglobal { generaGoTo(); pushPSaltos(apunta_cuadruplo-1); }programa2 BEGINP { scope = 'l'; rellenaGoTo(popPSaltos(), apunta_cuadruplo); } bloque ENDP { generaEnd(); printf("Programa completo\n"); }
	;

programa2: /* empty */
	| function programa2
	;

/*****ASIGNACION GLOBAL*****/

asignaglobal: /* empty */
	| GLOBAL asignaciong asignaglobal
	| asignaglobal2
	;

asignaglobal2: /* empty */
	| otraasignaciong asignaglobal2
	;

asignaciong: tipo ID EQ exp PC { pushPOper(300); asignaTipoAux(tipo);
				    if(buscaVar($2, 'g') != -1){
						yyerror("Variable global existente.\n");
				    } else {
					insertaVarGlobal(tipo, $2);
					if(cubo[cimaPTipos()][tipoAux][8] != 'x') {
						generaCuadruplo(popPOper(), popPilaO(), -1, buscaVar($2, 'g'));
						
					} else {
						yyerror("Tipos no compatibles en la asignacion global.\n");
					}
				   }
				}
	;

otraasignaciong: ID EQ exp PC { pushPOper(300); asignaTipoAux(buscaVarTipo($1, 'g'));
				    if(buscaVar($1, 'g') != -1){
					if(cubo[cimaPTipos()][tipoAux][8] != 'x') {
						generaCuadruplo(popPOper(), popPilaO(), -1, buscaVar($1, 'g'));
					}
				    } else {
					yyerror("Variable no existente en la asignacion global\n");
				} }
	;

/*****BLOQUES*****/

bloque: LLA bloque2 LLC
	;

bloque2: /* empty */
	| asignacion bloque2
	| bloque3
	;

bloque3: /* empty */
	| estatuto bloque3
	;

/*****ESTATUTOS*****/

estatuto: condicion
	| escritura
	| ciclo
	| funcion
	| otraasignacion
	;

/*****ESTATUTO-FUNCION*****/

funcion: NOMBRE PARA { if(buscaProc($1) == -1) {
			yyerror("Procedimiento llamado no existente.\n");
		 } else {
			generaCuadruploERA(buscaProc($1));
			k++;
		 }} funcion2 PARC PC{
			if((tipoParametro(k-1) != 0) || (tipoParametro(k-1) != 1) || (tipoParametro(k-1) != 2) || (tipoParametro(k-1) != 3) || (tipoParametro(k-1) != 4)) {
				generaGoSub(buscaProc($1));
				k = 0;
				pushPilaO(asignaTemp(buscaVarTipo($1, 'g')));
				generaCuadruplo(300, buscaVar($1, 'g'), -1, cimaPilaO());
				pushPTipos(buscaVarTipo($1, 'g'));
			} }
	;

funcion2: /* empty */
	| exp { if(popPTipos() == tipoParametro(k-1)) {
			generaCuadruploParametro(popPilaO(), k);
		} else {
			yyerror("Tipo incompatible de parametro en la llamada de procedimiento.\n");
		}} funcion3
	;

funcion3: /* empty */
	| COMA { k++; } funcion2
	;

/*****EXP-FUNCION*****/
funcionalt: NOMBRE PARA { pushPOper(350); if(buscaProc($1) == -1) {
			yyerror("Procedimiento llamado no existente.\n");
		 } else {
			generaCuadruploERA(buscaProc($1));
			k++;
		 }} funcion2 PARC { popPOper();
			if((tipoParametro(k-1) != 0) || (tipoParametro(k-1) != 1) || (tipoParametro(k-1) != 2) || (tipoParametro(k-1) != 3) || (tipoParametro(k-1) != 4)) {
				generaGoSub(buscaProc($1));
				k = 0;
				pushPilaO(asignaTemp(buscaVarTipo($1, 'g')));
				generaCuadruplo(300, buscaVar($1, 'g'), -1, cimaPilaO());
				asignaTipoAux(buscaVarTipo($1,'g'));
				pushPTipos(tipoAux);
			} }
	;
/*****Condición*****/

condicion: IF PARA expresion PARC { auxif = popPTipos();
				if(auxif != 4) {
					yyerror("Tipos no compatibles en la condicion\n");
				} else {
					generaGoToF(popPilaO());
					pushPSaltos(apunta_cuadruplo-1);
				}} 
	LLA bloque3 ret LLC condicion2
	;

condicion2: ELSE { generaGoTo(); rellenaGoToF(popPSaltos(), apunta_cuadruplo); pushPSaltos(apunta_cuadruplo-1); } LLA bloque3 ret LLC { rellenaGoTo(popPSaltos(), apunta_cuadruplo); }
	| condicion3
	;

condicion3: { rellenaGoToF(popPSaltos(), apunta_cuadruplo); }
	;

ret: /* empty */
	| RETURN PARA exp PARC PC { numret++; asignaTipoAux(tipoFunc); generaCuadruploReturn(popPilaO(), idReturn);
					if(popPTipos() != tipoAux)
						yyerror("Tipo de valor de salida incompatible con el del metodo\n"); }
	;

/*****ASIGNACION LOCAL*****/

asignacion: tipo ID EQ asigna2 { pushPOper(300); asignaTipoAux(tipo);
				    if(buscaVar($2, 'l') != -1){
					yyerror("Variable local existente.\n");
				    } else {
					insertaVar(tipo, $2);
					sumaVar(tipo);
					if(cubo[cimaPTipos()][tipoAux][8] != 'x') {
						generaCuadruplo(popPOper(), popPilaO(), -1, buscaVar($2, 'l'));
					} else {
						yyerror("Tipos no compatibles. en asignacion local\n");
					}
				   }
				}
	;

asigna2: exp PC
	;

otraasignacion: ID EQ asigna2 { pushPOper(300); asignaTipoAux(buscaVarTipo($1, 'l'));
				    if(buscaVar($1, 'l') != -1){
					if(cubo[cimaPTipos()][tipoAux][8] != 'x') {
						generaCuadruplo(popPOper(), popPilaO(), -1, buscaVar($1, 'l'));
					}
				    } else {
					yyerror("Variable local asignada no existente.\n");
				}}
	;

/*****TIPO DE DATO*****/

tipo:	INT { tipo = 'i'; }
	| FLOAT { tipo = 'f'; }
	| BOOL { tipo = 'b'; }
	| CHAR { tipo = 'c'; }
	| STR { tipo = 's'; }
	;

/*****ESCRITURA*****/

escritura: PRINT PARA escritura2 PARC PC
	;

escritura2: exp { generaCuadruploPrint(popPilaO()); } COMA escritura2
	| exp { generaCuadruploPrint(popPilaO()); }
	;

/*****CICLO*****/

ciclo: REPEAT { pushPSaltos(apunta_cuadruplo); } LLA bloque3 LLC UNTIL PARA expresion PARC PC { generaGoToF(popPilaO()); rellenaGoToF(apunta_cuadruplo-1, popPSaltos()); }
	;

/*****EXPRESION*****/

expresion: expresion2 operadorl
	;

expresion2: exp MAY { pushPOper(202); } exp { if(cimaPOper() == 202) {
		  				generacionDeCuadruplos(6);
					      } pushPTipos(4); } 
	| exp MEN { pushPOper(203); } exp { if(cimaPOper() == 203) {
		  				generacionDeCuadruplos(7);
					      } pushPTipos(4); } 
	| exp DIF { pushPOper(204); } exp { if(cimaPOper() == 204) {
		  				generacionDeCuadruplos(10);
					      } pushPTipos(4); } 
	| exp IGU { pushPOper(205); } exp { if(cimaPOper() == 205) {
		  				generacionDeCuadruplos(9);
					      } pushPTipos(4); } 
	| PARA { pushPOper(350); } expresion2 PARC { popPOper(); }
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

factor: PARA { pushPOper(350); } exp PARC { popPOper(); }
	| SUM { aux = 1; } varcte 
	| RES { aux = -1; } varcte
	| varcte
	;

/*****VARIABLES CONSTANTES*****/

varcte: ID { op = buscaVar($1, scope); asignaTipoAux(buscaVarTipo($1, scope)); pushPTipos(tipoAux); pushPilaO(op); }
	| CTEE { agregaCte('i', $1, aux); op = buscaCteInt($1); pushPilaO(op); pushPTipos(0); }
	| CTEF { agregaCte('f', $1, aux); op = buscaCteFloat($1); pushPilaO(op); pushPTipos(1); } 
	| STRING { agregaCte('s', subString($1, 0, strlen($1)), 0); op = buscaCteStr($1); pushPilaO(op); pushPTipos(3); }
	| CH { agregaCte('c', subString($1, 0, strlen($1)), 0); op = buscaCteChar($1); pushPilaO(op); pushPTipos(2); }
	| BOOLEAN { agregaCte('b', $1, 0); op = buscaCteBool($1); pushPilaO(op); pushPTipos(4); }
	| funcionalt
	;

/****FUNCIÓN****/

function: tipo FUNCTION NOMBRE { scope = 'l'; tipoFunc = tipo; numCuadFunc = apunta_cuadruplo; reiniciaContTemp(); numret = 0;
				if(buscaProc($3) != -1) {
					yyerror("Procedimiento declarado existente.\n");
				 }
				} PARA function2 PARC BEGINF LLA asigna b2 { insertaProc(tipoFunc,$3,numVarInt,numVarFloat,numVarChar,numVarStr,numVarBool,cParam,numCuadFunc,paramAux); insertaVarGlobal(tipoFunc, $3); idReturn = buscaVar($3, 'g'); } bloque3 ret LLC ENDF {
		reiniciaContTemp();
		reiniciaContVars();
		reiniciaTablaVar();
		cParam = 0;
		generaRetorno();
		if(numret == 0)
			yyerror("Función no tiene valor de regreso (return).\n");
		}
	;

function2: /* empty */
	| tipo ID { insertaParam(tipo, cParam); cParam++; insertaVar(tipo, $2); } function3
	;

function3: /* empty */
	| COMA function2
	;

asigna: /* empty */
	| asignacion
	;

b2: /* empty */
	| asignacion b2
	;

%%

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
