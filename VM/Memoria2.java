public class Memoria2 {

	int enteros[];
	float flotantes[];
	char chars[];
	String strings[];
	boolean booleanos[];

	public Memoria2(int i, int f, int c, int s, int b){
		enteros = new int[i];
		flotantes = new float[f];
		chars = new char[c];
		strings = new String[s];
		booleanos = new boolean[b];
	}
	
	public void setEntero(int dir, int val){
		enteros[dir] = val;
	}

	public int getEntero(int dir){
		return enteros[dir];
	}
	
	public void setFlotante(int dir, float val){
		flotantes[dir] = val;
	}

	public float getFlotante(int dir){
		return flotantes[dir];
	}
	
	public void setChar(int dir, char val){
		chars[dir] = val;
	}

	public char getChar(int dir){
		return chars[dir];
	}
	
	public void setStrings(int dir, String val){
		strings[dir] = val;
	}

	public String getStrings(int dir){
		return strings[dir];
	}	
	
	public void setBooleanos(int dir, boolean val){
		booleanos[dir] = val;
	}

	public boolean getBooleanos(int dir){
		return booleanos[dir];
	}

}
