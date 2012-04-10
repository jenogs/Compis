/****************************************************/
/* Arcvhivo: Tablas.h                               */
/* Archivo de tabla de variables y directorios de   */
/* procedimientos para el compilador SimpleFlow     */
/* Adrián Ramos & Jerónimo Garza                    */
/****************************************************/

/* TABLAS DE VARIABLES */
/* Insertar variable */
void insertaVar(char tipo, char *id, char scope);

/* Buscar Variables en tabla */
int buscaVar(char *id);

/* Imprime tabla de variables */
void imprimeVar(FILE * listing);

/* DIRECTORIOS DE PROCEDIMIENTOS */
/* Insertar Procedimiento */
void insertaProc(char tipo, char *id);

/* Buscar Procedimiento en directorio */
int buscaProc(char *id);

/* Imprime directorio de procedimientos */
void imprimeProc(FILE * listing);

/* Insertar Parámetros al procedimiento */
void insertaParam(char tipo, char *id, int cParam);
