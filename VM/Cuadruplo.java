public class Cuadruplo{

	private int operador;
	private int operando1;
	private int operando2;
	private int resultado;
	
	public Cuadruplo(int operador, int operando1, int operando2, int resultado) {
		this.operador = operador;
		this.operando1 = operando1;
		this.operando2 = operando2;
		this.resultado = resultado;
	}

	public int getOperador() {
		return operador;
	}
	
	public int getOperando1() {
		return operando1;
	}
	
	public int getOperando2() {
		return operando2;
	}
	
	public int getResultado() {
		return resultado;
	}
	
}
