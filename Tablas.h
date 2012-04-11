/******************************************************/
/* Arcvhivo: Tablas.h                                 */
/* Implementación de tabla de variables y directorios */
/* de procedimientos para el compilador SimpleFlow    */
/* Adrián Ramos & Jerónimo Garza                      */
/******************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* TAMANO_HASH es el tamaño de las tablas de hash */
#define TAMANO_HASH 251

/* Espacios en memoria */
enum memoria {
     enteros_globales =   0,
     flotantes_globales = 1000,
     chars_globales =     2000,
     strings_globales =   3000,
     booleanos_globales = 4000,
     
     enteros_locales =    5000,
     flotantes_locales =  6000,
     chars_locales =      7000,
     strings_locales =    8000,
     booleanos_locales =  9000,
     
     enteros_temporales =   10000,
     flotantes_temporales = 11000,
     chars_temporales =     12000,
     strings_temporales =   13000,
     booleanos_temporales = 14000,
     
     enteros_const =        15000,
     flotantes_const =      16000,
     chars_const =          17000,
     strings_const =        18000,
     booleanos_const =      19000   
};

/* Apuntadores de las direcciones virtuales de las variables */

//Enteros Globales
int apunta_enteros_globales = 0, apunta_flotantes_globales = 0, apunta_chars_globales = 0, apunta_strings_globales = 0, apunta_booleanos_globales = 0;

// Enteros Locales    
int apunta_enteros_locales = 0, apunta_flotantes_locales = 0, apunta_chars_locales = 0, apunta_strings_locales = 0, apunta_booleanos_locales = 0;

// Enteros Temporales    
int apunta_enteros_temporales = enteros_temporales,
    apunta_flotantes_temporales = flotantes_temporales,
    apunta_chars_temporales = chars_temporales,
    apunta_strings_temporales = strings_temporales,
    apunta_booleanos_temporales = booleanos_temporales;

// Enteros Constantes
int apunta_enteros_const = enteros_const,
    apunta_flotantes_const = flotantes_const,
    apunta_chars_const = chars_const,
    apunta_strings_const = strings_const,
    apunta_booleanos_const = booleanos_const;

/* Apuntadores de las tablas de hash */
int hv; // Apuntador de variables
int hp; // Apuntador de procedimientos

/* Estructuras de Tablas y Directorios */

// Estructura de tabla de variables
typedef struct tabVars{
	struct tabVars *sig;
	char tipo;
	char *id;
	int dirvar;
} *vars;

// Estructura de parámetros para los procedimientos
struct params{
	char tipo;
	char *id;
};
 
/* Estructura de Directorio de Procedimientos */
typedef struct tabProcs{
	struct tabProcs *sig;
	char tipo;
	char *id;
	struct params parametro[50];
	vars stv[TAMANO_HASH];
} *procs;
/*
typedef vars *ptrNodoVars;
typedef vars *ptrPilaVars;

typedef vars *ptrNodoProcs;
typedef vars *ptrPilaProcs;
*/
/* Creación de las tablas */
static vars hashVars[TAMANO_HASH];
static procs hashProcs[TAMANO_HASH];

/* Función de hash */
unsigned int hash(char *key) {
    unsigned int i;
    unsigned int h;

    h = 1315423911;
    for (i = 0; *key; key++, i++) {
	   h ^= ((h << 5) + (*key) + (h >> 2));
    }
    h &= TAMANO_HASH;
    return h;
}

/* Insertar variable global */
void insertaVarGlobal(char tipo, char *id) {
	hv = hash(id);
	vars v =  hashVars[hv];

	v = (vars)malloc(sizeof(struct tabVars));
	v->tipo = tipo;
	v->id = id;

	switch (tipo){
		case 'c':
			v->dirvar = chars_globales + apunta_chars_globales;
			apunta_chars_globales++;
			break;
		case 'i':
			v->dirvar = enteros_globales + apunta_enteros_globales;
			apunta_enteros_globales++;
			break;
		case 'f':
			v->dirvar = flotantes_globales + apunta_flotantes_globales;
			apunta_flotantes_globales++;
			break;
		case 'b':
			v->dirvar = booleanos_globales + apunta_booleanos_globales;
			apunta_booleanos_globales++;
			break;
		case 's':
			v->dirvar = strings_globales + apunta_strings_globales;
			apunta_strings_globales++;
			break;
	}	

	v->sig = hashVars[hv];
	hashVars[hv] = v;
}

/* Insertar variable Local */
void insertaVar(char tipo, char *id, char *idProc) {
	hp = hash(idProc);	
	hv = hash(id);
	procs p = hashProcs[hp];

	p = (procs)malloc(sizeof(struct tabProcs));
	p->stv[hv]->tipo = tipo;
	p->stv[hv]->id = id;
	switch (tipo){
		case 'c':
			p->stv[hv]->dirvar = chars_locales + apunta_chars_locales;
			apunta_chars_locales++;
			break;
		case 'i':
			p->stv[hv]->dirvar = enteros_locales + apunta_enteros_locales;
			apunta_enteros_locales++;
			break;
		case 'f':
			p->stv[hv]->dirvar = flotantes_locales + apunta_flotantes_locales;
			apunta_flotantes_locales++;
			break;
		case 'b':
			p->stv[hv]->dirvar = booleanos_locales + apunta_booleanos_locales;
			apunta_booleanos_locales++;
			break;
		case 's':
			p->stv[hv]->dirvar = strings_locales + apunta_strings_locales;
			apunta_strings_locales++;
			break;
	}

	p->sig = hashProcs[hp];
	hashProcs[hp] = p;
}

/* Buscar Variables en tabla */
int buscaVar(char *id) {
	hv = hash(id);
	vars v =  hashVars[hv];
	while ((v != NULL) && (strcmp(id,v->id) != 0))
		v = v->sig;
	if (v == NULL)
		return -1;
	else
		return v->dirvar;
}

/* Imprime tabla de variables 
void imprimeVar(FILE *listing) {
	int i;
	fprintf(listing,"Nombre de Variable  Direccion\n");
	fprintf(listing,"------------------  ---------\n");
	for (i=0;i<TAMANO_HASH;++i) {
		if (hashVars[i] != NULL) {
			vars v = hashVars[i];
			while (v != NULL) {
				fprintf(listing,"%-14s ",v->id);
				fprintf(listing,"%-8d  ",v->dirvar);
				fprintf(listing,"\n");
				v = v->sig;
			}
		}
	}
}*/

/* Insertar Procedimiento */
void insertaProc(char tipo, char *id){
	hp = hash(id);
	procs p =  hashProcs[hp];

	p = (procs)malloc(sizeof(struct tabProcs));
	p->tipo = tipo;
	p->id = id;

	p->sig = hashProcs[hp];
	hashProcs[hp] = p;

	apunta_enteros_locales = 0;
	apunta_flotantes_locales = 0;
	apunta_strings_locales = 0;
	apunta_chars_locales = 0;
	apunta_booleanos_locales = 0;
}

/* Buscar Procedimiento en directorio */
int buscaProc(char *id) {
	hp = hash(id);
	procs p =  hashProcs[hp];
	while ((p != NULL) && (strcmp(id,p->id) != 0))
		p = p->sig;
	if (p == NULL)
		return -1;
	else
		return hp;
}

/* Imprime directorio de procedimientos 
void imprimeProc(FILE *listing){
	int i;
	fprintf(listing,"Nombre del Procedimiento  Direccion\n");
	fprintf(listing,"------------------------  ---------\n");
	for (i=0;i<TAMANO_HASH;++i) {
		if (hashProcs[i] != NULL) {
			procs p = hashProcs[i];
			while (p != NULL) {
				fprintf(listing,"%-14s ", p->id);
				fprintf(listing,"%-8d  ", hp);
				fprintf(listing,"\n");
				p = p->sig;
			}
		}
	}
}*/

/* Insertar parámetros a los procedimientos */
void insertaParam(char tipo, char *id, int cParam) {
	procs p = hashProcs[hp];
	if(buscaProc(p->id)) {
		p->parametro[cParam].tipo = tipo;
		p->parametro[cParam].id = id;
	} else {
		printf("Error: El metodo no existe\n");
		exit(0);
	}
	hashProcs[hp] = p;
}
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
