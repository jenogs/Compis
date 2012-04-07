#include <glib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//espacios en memoria
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



//aountadores de control de memoria
int apunta_cuadruplos_cont = 0,
    apunta_enteros_globales = 0,
    apunta_flotantes_globales = 0,
    apunta_chars_globales = 0,
    apunta_strings_globales = 0,
    apunta_booleanos_globales = 0,
    
    apunta_enteros_locales = 0,
    apunta_flotantes_locales = 0,
    apunta_chars_locales = 0,
    apunta_strings_locales = 0,
    apunta_booleanos_locales = 0,
    
    apunta_enteros_temporales = enteros_temporales,
    apunta_flotantes_temporales = flotantes_temporales,
    apunta_chars_temporales = chars_temporales,
    apunta_strings_temporales = strings_temporales,
    apunta_booleanos_temporales = booleanos_temporales,
    
    apunta_enteros_const = enteros_const,
    apunta_flotantes_const = flotantes_const,
    apunta_chars_const = chars_const,
    apunta_strings_const = strings_const,
    apunta_booleanos_const = booleanos_const;  
     
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
      ((strcmp("booleanos", var1)== 0) && (strcmp("booleanos", var2) == 0)) 
      )
      return 5; // booleanos
    else return 0; // invalida  
    }
     
void struct formato_cuadruplo{
     char* operador;
     char* operando1;
     char* operando2;
     char* resultado;
     }

void resetea_tabla_temporales(){
    enteros_temporales = enteros_temporales,
    flotantes_temporales = flotantes_temporales,
    chars_temporales = chars_temporales,
    strings_temporales = strings_temporales,
    booleanosos_temporales = booleanosos_temporales,
     }


     
