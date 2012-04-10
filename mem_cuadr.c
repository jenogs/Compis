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

//GENERA CUADRUPLOS WORKING ON THIS!!.. :S
void genera_cuadruplos(){
    char *operando_uno, *operando_dos, *temporal;  // Top y Top-1 de la pila de tipos
    int *temp_count;
    int operator, first_oper, second_oper, valid_type;

    operator = (int)g_queue_pop_tail(StackOper);    // Saca primer operador de la pila de operadores
    first_oper = g_queue_pop_tail(StackO);          // Solo sacamos el primer_oper en caso de que sea math_function

    if (operator == INDEX) {      // Si llega index de arreglos, mete para generar verificacion y meter desplazamiento
        g_queue_push_tail(StackO, first_oper);  
    } else if (operator == ABS || operator == COS || operator == SIN || // 'as' 'cs' 'sn'    // Generacion de Math_function
        operator == LOG || operator == TAN || operator == SQRT) { // 'lg' 'tn' 'st'
		insert_quadruple_to_array(operator, first_oper, 0, temp_decimals_count);
        g_queue_push_tail(StackO, (gpointer)temp_decimals_count);   // Se da push al temp que guarda el valor de la fn
        g_queue_push_tail(StackTypes, (gpointer)"decimal");         // Se da push al tipo decimal que sera igual para todos
        temp_decimals_count = temp_decimals_count + 1;              // Se incrementa en uno el temp de decimales
    } else if (operator == PRINT || operator == PRINTLINE || operator == READINT || operator == READLINE) {  
        //default_functions     
        insert_quadruple_to_array(operator, first_oper, 0, 0); // El pop es 0 cuando no es arr
        g_queue_push_tail(StackOper, (gpointer)operator);
    } else {    // Genera cuadruplos para asignacion o el resto de tipo de cuadruplos (que no son math_functions)
        second_oper = g_queue_pop_tail(StackO);         // Saca el siguiente operando para hacer las operaciones
        operando_uno = g_queue_pop_tail(StackTypes);      // Saca primer operando
        operando_dos = g_queue_pop_tail(StackTypes);     // Saca siguiente operando
        valid_type = valid_var_types(operando_uno, operando_dos); // Obtiene el tipo de valor al cual se casteara la operacion
        if (valid_type != 0){ // Si es valido, se genera el cuadruplo
            if (operator == EQUALS) {
                if (array_in == 1) { second_oper = equals_id_address; array_in = 0; equals_id_address = 0; }
                insert_quadruple_to_array(operator, second_oper, 0, first_oper);
            } else {    // Asigna el tipo de dato a la variable que guardara el resultado de la operacion
                    if (valid_type == 1) { temp_count = &temp_integers_count; temp_type = "integer"; }
                    if (valid_type == 2) { temp_count = &temp_strings_count; temp_type = "string"; }
                    if (valid_type == 3) { temp_count = &temp_booleans_count; temp_type = "boolean"; }
                    if (valid_type == 4) { temp_count = &temp_decimals_count; temp_type = "decimal"; }
				    insert_quadruple_to_array(operator, second_oper, first_oper, *temp_count);
                    // Mete el temporal a la pila para incluirse en las operaciones
                    g_queue_push_tail(StackO, (gpointer)*temp_count);  
                    g_queue_push_tail(StackTypes, (gpointer)temp_type);
				    //Si es un operador logico, mete un tipo booleano a la pila de tipos
				    if(operator == LT || operator == GT || operator == G_EQUAL_T ||
                       operator == L_EQUAL_T || operator == SAME || operator == DIFF ||
                       operator == AND || operator == OR) {
					    g_queue_push_tail(StackTypes, (gpointer)"boolean");
                        g_queue_push_tail(StackTypes, (gpointer)"boolean");
				    }
                    *temp_count = *temp_count + 1;
                //}
            }   
        } else { // Error semantico, tipos incompatibles (var_type == 0)
            printf("Error al hacer la operacion entre los tipos de dato\n");
            exit(0);
        }
    }
}

     
