#include <stdio.h>
#include <stdlib.h>

int apunta_cuadruplo = 0;

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

/*
typedef vars *ptrNodoVars;
typedef vars *ptrPilaVars;

typedef vars *ptrNodoProcs;
typedef vars *ptrPilaProcs;
*/


/*
void pushVars(ptrPilaVars *pilavar, char id_v, struct siguiente_v, char tipo_v, char scope_v, int dirvar_v) {
	ptrNodoVars nodo;
	nodo = (ptrNodoVars)malloc(sizeof(vars));
	if (nodo != NULL) {
		nodo->*id = id;
		nodo->tipo = tipo_v;
		nodo->scope = scope_v;
		nodo->dirvar = dirvar_v;
		nodo->*sig = *pilavar;
	// pila va a apuntar al nuevo nodo, con esto hacemos que el nuevo nodo sea ahora el primer nodo de la lista ligada
		*pilavar = nodo;
	}
}

char popVarss(ptrPilaVars *pila) {
	ptrNodoVars nodo;
	//struct x;
	//nodo = *pila;
	//x = (*pila)->dato;
	*pila = (*pila)->sig;
	free(nodo);
	return x;
}
    
void pushProcs(ptrPilaProcs *pilaproc, char tipo_p, char *id_p, struct parametro_p, vars stv_p) {
	ptrNodoProcs nodo;
	nodo = (ptrNodoProcs)malloc(sizeof(procs));
	if (nodo != NULL) {
		nodo->*id = id_p;
		nodo->tipo = tipo_p;
		nodo->parametro = *parametro_p;
		nodo->stv_p = *stv_p;
		nodo->*sig = *pilaproc;
	// pila va a apuntar al nuevo nodo, con esto hacemos que el nuevo nodo sea ahora el primer nodo de la lista ligada
		*pilaproc = nodo;
	}
}

char popProcs(ptrPilaProcs *pila) {
	ptrNodoProcs nodo;
	//struct x;
	//nodo = *pila;
	//x = (*pila)->dato;
	*pila = (*pila)->sig;
	free(nodo);
	return x;
}
*/
