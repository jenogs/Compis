public class Memoria {

	Memoria2 global;
	Memoria2 local;
	Memoria2 temporal;
	Memoria2 constante;

	public Memoria(int tamano){
		        global = new Memoria2    (tamano/*entero*/, tamano/*flotante*/, tamano/*char*/, tamano/*string*/, tamano/*booleano*/);
		        local = new Memoria2     (tamano/*entero*/, tamano/*flotante*/, tamano/*char*/, tamano/*string*/, tamano/*booleano*/);
		        temporal = new Memoria2  (tamano/*entero*/, tamano/*flotante*/, tamano/*char*/, tamano/*string*/, tamano/*booleano*/);
		        constante = new Memoria2 (tamano/*entero*/, tamano/*flotante*/, tamano/*char*/, tamano/*string*/, tamano/*booleano*/);
	}

	public void agregaVar(char scope, int dir, int val){ //valores ints
		switch (scope){
			case 'g':
				global.setEntero(dir - 0, val);
				break;
			case 'l':
				local.setEntero(dir - 5000, val);
				break;
			case 't':
				temporal.setEntero(dir - 10000, val);
				break;
			case 'c':
				constante.setEntero(dir - 15000, val);
				break;
		}
	}
	public void agregaVar(char scope, int dir, float val){ //valores floats
		switch (scope){
			case 'g':
				global.setFlotante(dir - 1000, val);
				break;
			case 'l':
				local.setFlotante(dir - 6000, val);
				break;
			case 't':
				temporal.setFlotante(dir - 11000, val);
				break;
			case 'c':
				constante.setFlotante(dir - 16000, val);
				break;
		}
	}
	public void agregaVar(char scope, int dir, char val){ //valores chars
		switch (scope){
			case 'g':
				global.setChar(dir - 2000, val);
				break;
			case 'l':
				local.setChar(dir - 7000, val);
				break;
			case 't':
				temporal.setChar(dir - 12000, val);
				break;
			case 'c':
				constante.setChar(dir - 17000, val);
				break;
		}
	}
	public void agregaVar(char scope, int dir, String val){ //valores Strings
		switch (scope){
			case 'g':
				global.setStrings(dir - 3000, val);
				break;
			case 'l':
				local.setStrings(dir - 8000, val);
				break;
			case 't':
				temporal.setStrings(dir - 13000, val);
				break;
			case 'c':
				constante.setStrings(dir - 18000, val);
				break;
		}
	}	
	public void agregaVar(char scope, int dir, boolean val){ //valores booleanos
		switch (scope){
			case 'g':
				global.setBooleanos(dir - 4000, val);
				break;
			case 'l':
				local.setBooleanos(dir - 9000, val);
				break;
			case 't':
				temporal.setBooleanos(dir - 14000, val);
				break;
			case 'c':
				constante.setBooleanos(dir - 19000, val);
				break;
		}
	}	
	
	
	public int getVarEntero(char scope, int dir){
		switch(scope){
			case 'g':
				return global.getEntero(dir - 0);
			case 'l':
				return local.getEntero(dir - 5000);
			case 't':
				return temporal.getEntero(dir - 10000);
			case 'c':
				return constante.getEntero(dir - 15000);
		}
		return -1;
   	}
	
	public int getVarFlotante(char scope, int dir){
		switch(scope){
			case 'g':
				return global.getFlotante(dir - 1000);
			case 'l':
				return local.getFlotante(dir - 6000);
			case 't':
				return temporal.getFlotante(dir - 11000);
			case 'c':
				return constante.getFlotante(dir - 16000);
		}
		return -1;
   	}
	
	public int getVarChar(char scope, int dir){
		switch(scope){
			case 'g':
				return global.getChar(dir - 2000);
			case 'l':
				return local.getChar(dir - 7000);
			case 't':
				return temporal.getChar(dir - 12000);
			case 'c':
				return constante.getChar(dir - 17000);
		}
		return -1;
   	}
	
	public int getVarStrings(char scope, int dir){
		switch(scope){
			case 'g':
				return global.getStrings(dir - 3000);
			case 'l':
				return local.getStrings(dir - 8000);
			case 't':
				return temporal.getStrings(dir - 13000);
			case 'c':
				return constante.getStrings(dir - 18000);
		}
		return -1;
   	}
	
	public int getVarBooleanos(char scope, int dir){
		switch(scope){
			case 'g':
				return global.getBooleanos(dir - 4000);
			case 'l':
				return local.getBooleanos(dir - 9000);
			case 't':
				return temporal.getBooleanos(dir - 14000);
			case 'c':
				return constante.getBooleanos(dir - 19000);
		}
		return -1;
   	}
}
