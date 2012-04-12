%{
#include <cstdio>
#include <iostream>
#include "Tablas.h"
#include "Pilas.h"
#include "Cuadruplos.h"

using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
 
void yyerror(const char *s);

char tipo;
char tipocte;
char nombreProc[251];
int tipoAux;
int cParam = 0;
int aux = 0;
int op; //operador

void generacionDeCuadruplos(int oper);

%}

%union {
	char *string;
};

%token BEGINP ENDP FUNCTION BEGINF ENDF IGU GLOBAL
%token MAY MEN DIF IF ELSE PRINT SUM RES MULT DIV STR INT FLOAT PROG VAR EQ BOOL AND OR ELSEIF REPEAT READ CHAR
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

programa: NOMBRE { insertaProc('n', $1); } asignaglobal programa2 BEGINP bloque ENDP { printf("Programa completo\n"); }
	;

programa2: /* empty */
	| function programa2 { printf("Funcion\n"); }
	;

/*****ASIGNACION GLOBAL*****/

asignaglobal: /* empty */
	| GLOBAL asignaciong asignaglobal { printf("Asignacion global\n"); }
	;

asignaciong: tipo ID EQ asigna2 PC { pushPOper(300); tipoAux = $1;
				    if(buscaVar($2) != -1){
					if(tipo == 'n') {
						if(cubo[cimaPTipos][tipoAux][8] != 'x') {
							generaCuadruplo(popPOper(), popPilaO(), -1, buscaVar($2));
						}
					} else {
						printf("Error: Variable global existente: %s", $2);
					}
				    } else {
					if(cubo[cimaPTipos][tipoAux][8] != 'x') {
						insertaVarGlobal(tipo, $2);
						printf("Asignacion Completa en tabla de Variables Globales\n");
						generaCuadruplo(popPOper(), popPilaO(), -1, buscaVar($2));
						
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

asignacion: tipo ID EQ asigna2 PC { if(buscaVar($2) != -1){
					if(tipo == 'n') {
						//asigna
					} else {
						printf("Error: Variable local existente: %s", $2);
					}
				    } else {
					if(tipo == tipocte) {
						insertaVar(tipo, $2, nombreProc);
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
	| INT { tipo = 'i'; $$ = 0; }
	| FLOAT { tipo = 'f'; $$ = 1; }
	| BOOL { tipo = 'b'; $$ = 4; }
	| CHAR { tipo = 'c'; $$ = 2; }
	| STR { tipo = 's'; $$ = 3; }
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

exp: 	termino { if(cimaPOper() == 100) {
		  	generacionDeCuadruplos(0);
		}} SUM { pushPOper(100); } exp
	| termino { if(cimaPOper() == 101) {
		  	generacionDeCuadruplos(1);
		}} RES { pushPOper(101); } exp
	| termino
	;

/*****MULTIPLICACION Y DIVISION*****/

termino: factor { if(cimaPOper() == 102) {
		  	generacionDeCuadruplos(2);
		}} MULT { pushPOper(102); } termino
	| factor { if(cimaPOper() == 103) {
		  	generacionDeCuadruplos(3);
		}} DIV { pushPOper(103); } termino
	| factor
	;

/***Factor positivo o negativo***/

factor: PARA exp PARC
	| SUM { aux = 1; } varcte 
	| RES { aux = -1; } varcte
	| varcte
	;

/*****VARIABLES CONSTANTES*****/

varcte: ID { op = buscaVar($1); pushPilaO(op); }
	| CTEE { agregaCte('i', $1, aux); tipocte = 'i'; op = buscaCteInt($1); pushPilaO(op); pushPTipos(0); }
	| CTEF { agregaCte('f', $1, aux); tipocte = 'f'; op = buscaCteFloat($1); pushPilaO(op); pushPTipos(1); } 
	| STRING { agregaCte('s', $1, 0); tipocte = 's'; op = buscaCteChar($1); pushPilaO(op); pushPTipos(2); }
	| CH { agregaCte('c', $1, 0); tipocte = 'c'; op = buscaCteStr($1); pushPilaO(op); pushPTipos(3); }
	| BOOLEAN { agregaCte('b', $1, 0); tipocte = 'b'; op = buscaCteBool($1); pushPilaO(op); pushPTipos(4); }
	;

/****FUNCIÓN****/

function: tipo FUNCTION NOMBRE { if(buscaProc($3) != -1) {
					insertaProc(tipo, $3);
					strcpy(nombreProc, $3);
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

/*==============================================*/
/*						*/
/*			CUBO			*/
/*						*/
/*==============================================*/
 
/*============*/
/*   Tipos    */
/*============*/
//Int	 	= 0;
//Float 	= 1;
//Char 		= 2;
//String 	= 3;
//Bool 		= 4;

/*=================*/
/*    Operadores   */
/*=================*/
//Suma 			= 0
//Resta 		= 1
//Multiplicacion 	= 2
//Division 		= 3
//&& 			= 4 //and
//|| 			= 5 //or
//> 			= 6 //mayor que
//< 			= 7 //menor que
//= 			= 8 //igual
//== 			= 9 //igualdad
//!= 			= 10 //diferencia

/* Salidas */
char i = 'i'; //int 
char f = 'f'; //float
char c = 'c'; //char
char s = 's'; //string
char b = 'b'; //bool
char x = 'x'; //error

/* Cubo */

//cubo[Tipo1][Tipo2][Operador]

char cubo[5][5][11] =   /* Enteros */
		       {{{i,i,i,i,b,b,b,b,i,b,b},
			{f,f,f,f,b,b,b,b,x,b,b},
			{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,x,x}},
			/* Flotantes */
		       {{f,f,f,f,b,b,b,b,f,b,b},
			{f,f,f,f,b,b,b,b,f,b,b},
			{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,x,x}},
			/* Char */
		       {{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,c,b,b},
			{x,x,x,x,x,x,x,x,x,b,b},
			{x,x,x,x,x,x,x,x,x,x,x}},
			/* String */
		       {{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,b,b},
			{x,x,x,x,x,x,x,x,s,b,b},
			{x,x,x,x,x,x,x,x,x,x,x}},
			/* Bool */
		       {{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,b,b,b}}};

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
			printf("Error: Tipos incompatibles (cuadruplos)");
			break;
	}
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

	//imprimeVar(myfile);
	//imprimeProc(myfile);
}

void yyerror(const char *s) {
	cout << "Error!  Mensaje: " << s << endl;
	exit(-1);
}
