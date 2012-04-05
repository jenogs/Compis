#include <glib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//espacios en memoria
enum memoria{
     enteros_globales =   0,
     flotantes_globales = 1000,
     char_globales =      2000,
     strings_globales =   3000,
     boolean_globales =   4000,
     enteros_locales =    5000,
     flotantes_locales =  6000,
     char_locales =       7000,
     strings_locales =    8000,
     boolean_locales =    9000,
     
     enteros_temporales =   10000,
     flotantes_temporales = 11000,
     char_temporales =      12000,
     strings_temporales =   13000,
     boolean_temporales =   14000,
     enteros_const =        15000,
     flotantes_const =      16000,
     char_const =           17000,
     strings_const =        18000,
     boolean_const =        19000   
     };

//aountadores de control de memoria
int cuadruplos_cont = 0,
    apunta_enteros_globales = 0,
    apunta_flotantes_globales = 0,
    apunta_char_globales = 0,
    apunta_strings_globales = 0,
    apunta_boolean_globales = 0,
    apunta_enteros_locales = 0,
    apunta_flotantes_locales = 0,
    apunta_char_locales = 0,
    apunta_strings_locales = 0,
    apunta_boolean_locales = 0,
    
    apunta_enteros_temporales = 0,
    apunta_flotantes_temporales = 0,
    apunta_char_temporales = 0,
    apunta_strings_temporales = 0,
    apunta_boolean_temporales = 0,
    apunta_enteros_const = 0,
    apunta_flotantes_const = 0,
    apunta_char_const = 0,
    apunta_strings_const = 0,
    apunta_boolean_const = 0;  
     
     int tabla_tipos(char *var1, char *var2){
    if(
      (strcmp("integer", var1) == 0) && (strcmp("integer", var2) == 0) 
      )
      return 1; //integers
    else if (
      ((strcmp("integer", var1)== 0) && (strcmp("float", var2) == 0))
    ||((strcmp("float", var1)== 0) && (strcmp("integer", var2) == 0))
    ||((strcmp("float", var1)== 0) && (strcmp("float", var2) == 0)) 
    )
      return 2; // float
    else if (
      (strcmp("char", var1)== 0) && (strcmp("char", var2) == 0) 
      )
      return 3; // char
    else if (
      ((strcmp("string", var1)== 0) && (strcmp("char", var2) == 0))
    ||((strcmp("string", var1)== 0) && (strcmp("integer", var2) == 0))
    ||((strcmp("string", var1)== 0) && (strcmp("float", var2) == 0))
    ||((strcmp("string", var1)== 0) && (strcmp("string", var2) == 0))
    ||((strcmp("char", var1) == 0)  && (strcmp("string", var2) == 0))
    ||((strcmp("integer", var1)== 0)&& (strcmp("string", var2) == 0))
    ||((strcmp("float", var1)== 0)  && (strcmp("string", var2) == 0)) 
    )
      return 4; // string
    else if (
      ((strcmp("boolean", var1)== 0) && (strcmp("boolean", var2) == 0)) 
      )
      return 5; // boolean
    else return 0; // invalida  
    }
     
void struct formato_cuadruplo{
     char* operador;
     char* operando1;
     char* operando2;
     char* resultado;
     }

     
