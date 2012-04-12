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

/* SHIFT es la potencia de 2 usada como multiplicador en la funcion de hash  */
#define SHIFT 4

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

// Enteros Globales
int apunta_enteros_globales = 0,
    apunta_flotantes_globales = 0,
    apunta_chars_globales = 0,
    apunta_strings_globales = 0,
    apunta_booleanos_globales = 0;

// Enteros Locales    
int apunta_enteros_locales = 0,
    apunta_flotantes_locales = 0,
    apunta_chars_locales = 0,
    apunta_strings_locales = 0,
    apunta_booleanos_locales = 0;

// Enteros Temporales    
int apunta_enteros_temporales = 0,
    apunta_flotantes_temporales = 0,
    apunta_chars_temporales = 0,
    apunta_strings_temporales = 0,
    apunta_booleanos_temporales = 0;

// Enteros Constantes
int apunta_enteros_const = 0,
    apunta_flotantes_const = 0,
    apunta_chars_const = 0,
    apunta_strings_const = 0,
    apunta_booleanos_const = 0;

/* Apuntadores de las tablas de hash */
int hv; // Apuntador de variables
int hp; // Apuntador de procedimientos
int hc; // Apuntador de constantes

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
 
// Estructura de Directorio de Procedimientos
typedef struct tabProcs{
	struct tabProcs *sig;
	char tipo;
	char *id;
	struct params parametro[50];
} *procs;

// Estructuras de Constantes
typedef struct constante_int{
	struct constante_int *sig;
	int val;
	int dirvar;
} *cteInt;

typedef struct constante_float{
	struct constante_float *sig;
	float val;
	int dirvar;
} *cteFloat;

typedef struct constante_char{
	struct constante_char *sig;
	char *val;
	int dirvar;
} *cteChar;

typedef struct constante_str{
	struct constante_str *sig;
	char *val;
	int dirvar;
} *cteStr;

typedef struct constante_bool{
	struct constante_bool *sig;
	char *val;
	int dirvar;
} *cteBool;

/* Creación de las tablas */

// Tabla de variables global
static vars hashVars[TAMANO_HASH];

// Tabla de variables local
static vars hashVarsLocal[TAMANO_HASH];

// Directorio de Procedimientos
static procs hashProcs[TAMANO_HASH];

// Tablas de constantes
static cteInt hashInt[TAMANO_HASH];
static cteFloat hashFloat[TAMANO_HASH];
static cteChar hashChar[TAMANO_HASH];
static cteStr hashStr[TAMANO_HASH];
static cteBool hashBool[TAMANO_HASH];

/* Función de hash */
static int hash (char * key) {
	int temp = 0;
	int i = 0;
	while (key[i] != '\0') {
		temp = ((temp << SHIFT) + key[i]) % TAMANO_HASH;
		++i;
	}
	return temp;
}

/* Funciones de Tablas de Variables */

// Insertar variable global
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

// Insertar variable Local
void insertaVar(char tipo, char *id) {
	hv = hash(id);
	vars v =  hashVarsLocal[hv];

	v = (vars)malloc(sizeof(struct tabVars));
	v->tipo = tipo;
	v->id = id;
	switch (tipo){
		case 'c':
			v->dirvar = chars_locales + apunta_chars_locales;
			apunta_chars_locales++;
			break;
		case 'i':
			v->dirvar = enteros_locales + apunta_enteros_locales;
			apunta_enteros_locales++;
			break;
		case 'f':
			v->dirvar = flotantes_locales + apunta_flotantes_locales;
			apunta_flotantes_locales++;
			break;
		case 'b':
			v->dirvar = booleanos_locales + apunta_booleanos_locales;
			apunta_booleanos_locales++;
			break;
		case 's':
			v->dirvar = strings_locales + apunta_strings_locales;
			apunta_strings_locales++;
			break;
	}

	v->sig = hashVarsLocal[hv];
	hashVarsLocal[hv] = v;
}

// Buscar Variables en tabla
int buscaVar(char *id, char scope) {
	hv = hash(id);
	if(scope == 'g') {
		vars v =  hashVars[hv];
		while ((v != NULL) && (strcmp(id,v->id) != 0))
			v = v->sig;
		if (v == NULL)
			return -1;
		else
			return v->dirvar;
	} else if(scope == 'l') {
		vars v =  hashVarsLocal[hv];
		while ((v != NULL) && (strcmp(id,v->id) != 0))
			v = v->sig;
		if (v == NULL)
			return -1;
		else
			return v->dirvar;
	}
}

// Imprime tabla de variables 
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
}

/* Funciones de Directorio de Procedimientos */

// Insertar Procedimiento
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

// Buscar Procedimiento en directorio
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

// Imprime directorio de procedimientos 
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
}

// Insertar parámetros a los procedimientos
void insertaParam(char tipo, char *id, int cParam) {
	procs p = hashProcs[hp];
	p = (procs)malloc(sizeof(struct tabProcs));
	p->parametro[cParam].tipo = tipo;
	p->parametro[cParam].id = id;
	
	hashProcs[hp] = p;
}

/* Funciones de Tablas de Constantes */

// Busca constante entera
int buscaCteInt(char *val){
	hc = hash(val);
	cteInt c =  hashInt[hc];
	while ((c != NULL) && (atoi(val) != c->val))
		c = c->sig;
	if (c == NULL)
		return -1;
	else
		return hc;
}

// Busca constante flotante
int buscaCteFloat(char *val){
	hc = hash(val);
	cteFloat c =  hashFloat[hc];
	while ((c != NULL) && (atof(val) != c->val))
		c = c->sig;
	if (c == NULL)
		return -1;
	else
		return hc;
}

// Busca constante char
int buscaCteChar(char *val){
	hc = hash(val);
	cteChar c =  hashChar[hc];
	while ((c != NULL) && (strcmp(val,c->val) != 0))
		c = c->sig;
	if (c == NULL)
		return -1;
	else
		return hc;
}

// Busca constante string
int buscaCteStr(char *val){
	hc = hash(val);
	cteStr c =  hashStr[hc];
	while ((c != NULL) && (strcmp(val,c->val) != 0))
		c = c->sig;
	if (c == NULL)
		return -1;
	else
		return hc;
}

// Busca constante booleana
int buscaCteBool(char *val){
	hc = hash(val);
	cteBool c =  hashBool[hc];
	while ((c != NULL) && (strcmp(val,c->val) != 0))
		c = c->sig;
	if (c == NULL)
		return -1;
	else
		return hc;
}

// Agrega constante
void agregaCte(char tipo, char *val, int auxN){
	switch(tipo) {
		case 'i':
			if(buscaCteInt(val) == -1) {
				hc = hash(val);
				cteInt c =  hashInt[hc];
				c = (cteInt)malloc(sizeof(struct constante_int));
				c->val = atoi(val)*auxN;
				c->dirvar = enteros_const + apunta_enteros_const;
				apunta_enteros_const++;
				c->sig = hashInt[hc];
				hashInt[hc] = c;
			}
			break;
		case 'f':
			if(buscaCteFloat(val) == -1) {
				hc = hash(val);
				cteFloat c =  hashFloat[hc];
				c = (cteFloat)malloc(sizeof(struct constante_float));
				c->val = atof(val)*auxN;
				c->dirvar = flotantes_const + apunta_flotantes_const;
				apunta_flotantes_const++;
				c->sig = hashFloat[hc];
				hashFloat[hc] = c;
			}
			break;
		case 'c':
			if(buscaCteChar(val) == -1) {
				hc = hash(val);
				cteChar c =  hashChar[hc];
				c = (cteChar)malloc(sizeof(struct constante_char));
				c->val = val;
				c->dirvar = chars_const + apunta_chars_const;
				apunta_chars_const++;
				c->sig = hashChar[hc];
				hashChar[hc] = c;
			}
			break;
		case 's':
			if(buscaCteStr(val) == -1) {
				hc = hash(val);
				cteStr c =  hashStr[hc];
				c = (cteStr)malloc(sizeof(struct constante_str));
				c->val = val;
				c->dirvar = strings_const + apunta_strings_const;
				apunta_strings_const++;
				c->sig = hashStr[hc];
				hashStr[hc] = c;
			}
			break;
		case 'b':
			if(buscaCteBool(val) == -1) {
				hc = hash(val);
				cteBool c =  hashBool[hc];
				c = (cteBool)malloc(sizeof(struct constante_bool));
				c->val = val;
				c->dirvar = booleanos_const + apunta_booleanos_const;
				apunta_booleanos_const++;
				c->sig = hashBool[hc];
				hashBool[hc] = c;
			}
			break;
	}
}
