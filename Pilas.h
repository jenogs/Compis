#include <stdio.h>

// Tamaño de las pilas
#define TAMANO_PILA 300

int PilaO[TAMANO_PILA];
int POper[TAMANO_PILA];
int PTipos[TAMANO_PILA];
int PSaltos[TAMANO_PILA];

int topePilaO = 0;
int topePOper = 0;
int topePTipos = 0;
int topePSaltos = 0;

int pushPilaO(int i){
	PilaO[topePilaO] = i;
	topePilaO++;
}

int popPilaO(){
	topePilaO--;
	return PilaO[topePilaO];
}

int cimaPilaO(){
	return PilaO[topePilaO-1];
}

int pushPOper(int i){
	POper[topePOper] = i;
	topePOper++;
}

int popPOper(){
	topePOper--;
	return POper[topePOper];
}

int cimaPOper(){
	return PilaO[topePOper-1];
}

int pushPTipos(int i){
	PTipos[topePTipos] = i;
	topePTipos++;
}

int popPTipos(){
	topePTipos--;
	return PTipos[topePTipos];
}

int cimaPTipos(){
	return PTipos[topePTipos-1];
}

int pushPSaltos(int i){
	PSaltos[topePSaltos] = i;
	topePSaltos++;
}

int popPSaltos(){
	topePSaltos--;
	return PSaltos[topePSaltos];
}

int cimaPSaltos(){
	return PSaltos[topePSaltos-1];
}

void vaciar_pilas() {
	topePilaO = 0;
	topePOper = 0;
	topePTipos = 0;
	topePSaltos = 0;
}
