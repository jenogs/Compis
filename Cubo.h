/*==============================================*/
/*						*/
/*			CUBO			*/
/*						*/
/*==============================================*/
 
/*============*/
/*   Tipos    */
/*============*/
//Int	 	= 0;
//Float 	= 1;
//Char 		= 2;
//String 	= 3;
//Bool 		= 4;

/*=================*/
/*    Operadores   */
/*=================*/
//Suma 			= 0
//Resta 		= 1
//Multiplicacion 	= 2
//Division 		= 3
//&& 			= 4 //and
//|| 			= 5 //or
//> 			= 6 //mayor que
//< 			= 7 //menor que
//= 			= 8 //igual
//== 			= 9 //igualdad
//!= 			= 10 //diferencia

/* Salidas */
char i = 'i'; //int 
char f = 'f'; //float
char c = 'c'; //char
char s = 's'; //string
char b = 'b'; //bool
char x = 'x'; //error

/* Cubo */

//cubo[Tipo1][Tipo2][Operador]

char cubo[5][5][11] =   /* Enteros */
		       {{{i,i,i,i,b,b,b,b,i,b,b},
			{f,f,f,f,b,b,b,b,x,b,b},
			{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,x,x}},
			/* Flotantes */
		       {{f,f,f,f,b,b,b,b,f,b,b},
			{f,f,f,f,b,b,b,b,f,b,b},
			{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,x,x}},
			/* Char */
		       {{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,c,b,b},
			{x,x,x,x,x,x,x,x,x,b,b},
			{x,x,x,x,x,x,x,x,x,x,x}},
			/* String */
		       {{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,b,b},
			{x,x,x,x,x,x,x,x,s,b,b},
			{x,x,x,x,x,x,x,x,x,x,x}},
			/* Bool */
		       {{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,x,x,x},
			{x,x,x,x,x,x,x,x,b,b,b}}};
