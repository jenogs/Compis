#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* TAMANO_HASH es el tamaño de las tablas de hash */
#define TAMANO_HASH 251

/* SHIFT es el cuadrado de 2 usado como multiplicador en la función hash */
#define SHIFT 4

/* Estructura de tabla de variables */
typedef struct tabVars{
	struct tabVars *sig;
	char tipo;
	char *id;
	char scope;
	int dirvar;
} *vars;

/* Estructura de Directorio de Procedimientos */
typedef struct tabProcs{
	struct tabProcs *sig;
	struct tabVars stv[50];
	char tipo;
	char *id;
	int apuntador;
	int idxchar;
	int idxint;
	int idxflt;
	int idxbool;
	int idxstr;
} *procs;


/* Función de hash */
static int hash(char *h) {
	int a;
	int temp = 0;
	int i = 0;
	for(a = 0; a < strlen(h); a++) {
		temp = ((temp << SHIFT) + h[i]) % TAMANO_PROCS;
	}
	return temp;
}

/* Creación de las tablas */
static vars hashVars[TAMANO_HASH];
static procs hashProcs[TAMANO_HASH];

/* Insertar variable */
void insertaVar(char tipo, char *id, char scope, int apuntador) {
	int h = hash(id);
	vars v =  hashVars[h];

	v = (vars)malloc(sizeof(struct tablaVars));
	v->tipo = tipo;
	v->id = id;
	v->scope = scope;
	v->dirvar = apuntador;
	v->sig = hashVars[h];
	hashVars[h] = v;
}

/* Buscar Variables en tabla */
int buscaVar(char *id) {
	int h = hash(name);
	vars v =  hashVars[h];
	while ((v != NULL) && ((strcmp(id,v->id) != 0) || (v->scope != scope)))
		v = v->sig;
	if (v == NULL)
		return -1;
	else
		return v->dirvar;
}

/* Insertar Procedimiento */
void insertaProc(char tipo, char *id, int apuntador){
	int h = hash(name);
	procs p =  hashProcs[h];

	p = (procs)malloc(sizeof(struct tablaProcs));
	p->tipo = tipo;
	p->id = id;
	switch (tipo){
		case 'c':
			p->idxchar++;
			break;
		case 'i':
			p->idxint++;
			break;
		case 'f':
			p->idxflt++;
			break;
		case 'b':
			p->idxbool++;
			break;
		case 's':
			p->idxstr++;
			break;
	}
}

/* Buscar Procedimiento en directorio */
int buscaProc(char *id) {
	int h = hash(id);
	procs p =  hashProcs[h];
	while ((p != NULL) && (strcmp(id,p->id) != 0))
		p = p->sig;
	if (p == NULL)
		return -1;
	else
		return p->apuntador;
}
