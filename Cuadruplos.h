#include <stdio.h>
#include <stdlib.h>

int apunta_cuadruplo = 0;

/*============
100 = SUM
101 = RES
102 = MULT
103 = DIV
200 = AND
201 = OR
202 = MAY
203 = MEN
204 = DIF
205 = IGU
300 = EQ

350 = Fondo Falso

400 = GoTo
401 = GoToF
405 = Print
406 = Repeat
410 = RET
415 = return
450 = Parametro
500 = ERA
550 = GOSUB
777 = END
===============*/

/* Estructura de un cuádruplo */
struct cuadruplo{
     int operador;
     int operando1;
     int operando2;
     int resultado;
};

struct cuadruplo cuad[5000];

/* Genera cuadruplos */
void generaCuadruplo(int operador, int operando1, int operando2, int resultado){
	cuad[apunta_cuadruplo].operador = operador;
	cuad[apunta_cuadruplo].operando1 = operando1;
	cuad[apunta_cuadruplo].operando2 = operando2;
	cuad[apunta_cuadruplo].resultado = resultado;
	apunta_cuadruplo++;
}

void generaCuadruploPrint(int resultado) {
	cuad[apunta_cuadruplo].operador = 405;
	cuad[apunta_cuadruplo].operando1 = -1;
	cuad[apunta_cuadruplo].operando2 = -1;
	cuad[apunta_cuadruplo].resultado = resultado;
	apunta_cuadruplo++;
}

void generaRetorno(){
	cuad[apunta_cuadruplo].operador = 410;
	cuad[apunta_cuadruplo].operando1 = -1;
	cuad[apunta_cuadruplo].operando2 = -1;
	cuad[apunta_cuadruplo].resultado = -1;
	apunta_cuadruplo++;
}

void generaCuadruploReturn(int valor, int varGlobal){
	cuad[apunta_cuadruplo].operador = 415;
	cuad[apunta_cuadruplo].operando1 = valor;
	cuad[apunta_cuadruplo].operando2 = -1;
	cuad[apunta_cuadruplo].resultado = varGlobal;
	apunta_cuadruplo++;
}

void generaGoTo(){
	cuad[apunta_cuadruplo].operador = 400;
	cuad[apunta_cuadruplo].operando1 = -1;
	cuad[apunta_cuadruplo].operando2 = -1;
	apunta_cuadruplo++;
}

void generaGoToF(int operando1) {
	cuad[apunta_cuadruplo].operador = 401;
	cuad[apunta_cuadruplo].operando1 = operando1;
	cuad[apunta_cuadruplo].operando2 = -1;
	apunta_cuadruplo++;
}

void generaCuadruploParametro(int argumento, int parametroK) {
	cuad[apunta_cuadruplo].operador = 450;
	cuad[apunta_cuadruplo].operando1 = argumento;
	cuad[apunta_cuadruplo].operando2 = -1;
	cuad[apunta_cuadruplo].resultado = parametroK;
	apunta_cuadruplo++;
}

void generaCuadruploERA(int direccion) {
	cuad[apunta_cuadruplo].operador = 500;
	cuad[apunta_cuadruplo].operando1 = direccion;
	cuad[apunta_cuadruplo].operando2 = -1;
	cuad[apunta_cuadruplo].resultado = -1;
	apunta_cuadruplo++;
}

void generaGoSub(int direccion) {
	cuad[apunta_cuadruplo].operador = 550;
	cuad[apunta_cuadruplo].operando1 = direccion;
	cuad[apunta_cuadruplo].operando2 = -1;
	cuad[apunta_cuadruplo].resultado = -1;
	apunta_cuadruplo++;
}

void generaEnd(){ 
	cuad[apunta_cuadruplo].operador = 777;
	cuad[apunta_cuadruplo].operando1 = -1;
	cuad[apunta_cuadruplo].operando2 = -1;
	cuad[apunta_cuadruplo].resultado = -1;
	apunta_cuadruplo++;	
}

void rellenaGoTo(int apuntador, int resultado){
	cuad[apuntador].resultado = resultado;
}

void rellenaGoToF(int apuntador, int resultado){
	cuad[apuntador].resultado = resultado;
}

void imprimeCuadruplos(char *myfile){
	int i;
	FILE *obj;
	obj = fopen(myfile,"w+");
	imprimeProc(obj);
	imprimeCteInt(obj);
	imprimeCteFloat(obj);
	imprimeCteChar(obj);
	imprimeCteStr(obj);
	imprimeCteBool(obj);
	for(i=0;i<apunta_cuadruplo;i++){
		printf("%d: [%d, %d, %d, %d]\n",i, cuad[i].operador,cuad[i].operando1,cuad[i].operando2,cuad[i].resultado);
		fprintf(obj, "%d,%d,%d,%d\n", cuad[i].operador,cuad[i].operando1,cuad[i].operando2,cuad[i].resultado);
	}	
	fprintf(obj,"$\n");
	fclose(obj);
}
