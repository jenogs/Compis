import java.util.Stack;
import java.util.ArrayList;
import java.util.List;
import java.io.*;

public class MaquinaVirtual {
	
	Memoria memory;
	Memoria2 memEra;
	Memoria2 memEraTemp;
	List<Cuadruplo> listaCuadruplos;
	List<Procs> listaProcs;
	Stack<StackLocal> stackEra;
	Stack<StackLocal> stackEraTemp;
	int apuntaCuadruplo;
	int dirProc;
	int contInt, contFloat, contChar, contStr, contBool;

	MaquinaVirtual(List<Procs> listaProcs, List<Constantes> listaCteInt, List<Constantes> listaCteFloat, List<Constantes> listaCteChar, List<Constantes> listaCteStr, List<Constantes> listaCteBool, List<Cuadruplo> listaCuadruplos) {
		apuntaCuadruplo = 0;
		dirProc = 0;
		contInt = 0;
		contFloat = 0;
		contChar = 0;
		contStr = 0;
		contBool = 0;
		memory = new Memoria(1000);
		this.listaProcs = listaProcs;
		this.listaCuadruplos = listaCuadruplos;
		stackEra = new Stack<StackLocal>();
		stackEraTemp = new Stack<StackLocal>();
		agregaConstantes(listaCteInt, listaCteFloat, listaCteChar, listaCteStr, listaCteBool);
	}
	
	public void run(){
		dirProc = listaProcs.size()-1;
		for(apuntaCuadruplo = 0; apuntaCuadruplo < listaCuadruplos.size(); apuntaCuadruplo++){
			leeCuadruplo(listaCuadruplos.get(apuntaCuadruplo));	
		}
	}
	
	public void leeCuadruplo(Cuadruplo cuadruplo) {
		int op1 = cuadruplo.getOperando1();
		int op2 = cuadruplo.getOperando2();
		int res = cuadruplo.getResultado();

		char tipoOp1 = getTipo(op1);
		char tipoOp2 = getTipo(op2);
		char tipoRes = getTipo(res);

		char scopeOp1 = getScope(op1);
		char scopeOp2 = getScope(op2);
		char scopeRes = getScope(res);
		
		switch(cuadruplo.getOperador()) {
			/* SUMA */
			case 100:
				if(tipoOp1 =='i' && tipoOp2 == 'i') { /*Entero + Entero*/
					int operando1 = memory.getVarEntero(scopeOp1, op1);
					int operando2 = memory.getVarEntero(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1+operando2);
				}
				else if(tipoOp1 =='i' && tipoOp2 == 'f') { /*Entero + Flotante*/
					int operando1 = memory.getVarEntero(scopeOp1, op1);
					float operando2 = memory.getVarFlotante(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1+operando2);
				}
				else if(tipoOp1 =='f' && tipoOp2 == 'i') { /*Flotante + Entero*/
					float operando1 = memory.getVarFlotante(scopeOp1, op1);
					int operando2 = memory.getVarEntero(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1+operando2);
				}
				else if(tipoOp1 =='f' && tipoOp2 == 'f') { /*Flotante + Flotante*/
					float operando1 = memory.getVarFlotante(scopeOp1, op1);
					float operando2 = memory.getVarFlotante(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1+operando2);
				}
				break;
			
			/* RESTA */
			case 101:
				if(tipoOp1 =='i' && tipoOp2 == 'i') { /*Entero - Entero*/
					int operando1 = memory.getVarEntero(scopeOp1, op1);
					int operando2 = memory.getVarEntero(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1-operando2);
				}
				else if(tipoOp1 =='i' && tipoOp2 == 'f') { /*Entero - Flotante*/
					int operando1 = memory.getVarEntero(scopeOp1, op1);
					float operando2 = memory.getVarFlotante(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1-operando2);
				}
				else if(tipoOp1 =='f' && tipoOp2 == 'i') { /*Flotante - Entero*/
					float operando1 = memory.getVarFlotante(scopeOp1, op1);
					int operando2 = memory.getVarEntero(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1-operando2);
				}
				else if(tipoOp1 =='f' && tipoOp2 == 'f') { /*Flotante - Flotante*/
					float operando1 = memory.getVarFlotante(scopeOp1, op1);
					float operando2 = memory.getVarFlotante(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1-operando2);
				}
				break;
			
			/* MULTIPLICACION */
			case 102:
				if(tipoOp1 =='i' && tipoOp2 == 'i') { /*Entero * Entero*/
					int operando1 = memory.getVarEntero(scopeOp1, op1);
					int operando2 = memory.getVarEntero(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1*operando2);
				}
				else if(tipoOp1 =='i' && tipoOp2 == 'f') { /*Entero * Flotante*/
					int operando1 = memory.getVarEntero(scopeOp1, op1);
					float operando2 = memory.getVarFlotante(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1*operando2);
				}
				else if(tipoOp1 =='f' && tipoOp2 == 'i') { /*Flotante * Entero*/
					float operando1 = memory.getVarFlotante(scopeOp1, op1);
					int operando2 = memory.getVarEntero(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1*operando2);
				}
				else if(tipoOp1 =='f' && tipoOp2 == 'f') { /*Flotante * Flotante*/
					float operando1 = memory.getVarFlotante(scopeOp1, op1);
					float operando2 = memory.getVarFlotante(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1*operando2);
				}
				break;
			
			
			/* DIVISION */
			case 103:
				if(tipoOp1 =='i' && tipoOp2 == 'i') { /*Entero / Entero*/
					int operando1 = memory.getVarEntero(scopeOp1, op1);
					int operando2 = memory.getVarEntero(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1/operando2);
				}
				else if(tipoOp1 =='i' && tipoOp2 == 'f') { /*Entero / Flotante*/
					int operando1 = memory.getVarEntero(scopeOp1, op1);
					float operando2 = memory.getVarFlotante(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1/operando2);
				}
				else if(tipoOp1 =='f' && tipoOp2 == 'i') { /*Flotante / Entero*/
					float operando1 = memory.getVarFlotante(scopeOp1, op1);
					int operando2 = memory.getVarEntero(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1/operando2);
				}
				else if(tipoOp1 =='f' && tipoOp2 == 'f') { /*Flotante / Flotante*/
					float operando1 = memory.getVarFlotante(scopeOp1, op1);
					float operando2 = memory.getVarFlotante(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1/operando2);
				}
				break;
			
			/* AND */
			case 200:
				if(tipoOp1 =='b' && tipoOp2 == 'b') { /*Bool && Bool*/
					boolean operando1 = memory.getVarBooleanos(scopeOp1, op1);
					boolean operando2 = memory.getVarBooleanos(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1&&operando2);
				}
				break;
			
			/* OR */
			case 201:
				if(tipoOp1 =='b' && tipoOp2 == 'b') { /*Bool || Bool*/
					boolean operando1 = memory.getVarBooleanos(scopeOp1, op1);
					boolean operando2 = memory.getVarBooleanos(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1||operando2);
				}
				break;
			
			/* MAYOR QUE */
			case 202:
				if(tipoOp1 =='i' && tipoOp2 == 'i') { /*Entero > Entero*/
					int operando1 = memory.getVarEntero(scopeOp1, op1);
					int operando2 = memory.getVarEntero(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1>operando2);
				}
				else if(tipoOp1 =='i' && tipoOp2 == 'f') { /*Entero > Flotante*/
					int operando1 = memory.getVarEntero(scopeOp1, op1);
					float operando2 = memory.getVarFlotante(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1>operando2);
				}
				else if(tipoOp1 =='f' && tipoOp2 == 'i') { /*Flotante > Entero*/
					float operando1 = memory.getVarFlotante(scopeOp1, op1);
					int operando2 = memory.getVarEntero(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1>operando2);
				}
				else if(tipoOp1 =='f' && tipoOp2 == 'f') { /*Flotante > Flotante*/
					float operando1 = memory.getVarFlotante(scopeOp1, op1);
					float operando2 = memory.getVarFlotante(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1>operando2);
				}
				break;
			
			/* MENOR QUE */
			case 203:
				if(tipoOp1 =='i' && tipoOp2 == 'i') { /*Entero < Entero*/
					int operando1 = memory.getVarEntero(scopeOp1, op1);
					int operando2 = memory.getVarEntero(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1<operando2);
				}
				else if(tipoOp1 =='i' && tipoOp2 == 'f') { /*Entero < Flotante*/
					int operando1 = memory.getVarEntero(scopeOp1, op1);
					float operando2 = memory.getVarFlotante(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1<operando2);
				}
				else if(tipoOp1 =='f' && tipoOp2 == 'i') { /*Flotante < Entero*/
					float operando1 = memory.getVarFlotante(scopeOp1, op1);
					int operando2 = memory.getVarEntero(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1<operando2);
				}
				else if(tipoOp1 =='f' && tipoOp2 == 'f') { /*Flotante < Flotante*/
					float operando1 = memory.getVarFlotante(scopeOp1, op1);
					float operando2 = memory.getVarFlotante(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1<operando2);
				}
				break;
			
			/* DIFERENCIA */
			case 204:
				if(tipoOp1 =='i' && tipoOp2 == 'i') { /*Entero != Entero*/
					int operando1 = memory.getVarEntero(scopeOp1, op1);
					int operando2 = memory.getVarEntero(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1!=operando2);
				}
				else if(tipoOp1 =='i' && tipoOp2 == 'f') { /*Entero != Flotante*/
					int operando1 = memory.getVarEntero(scopeOp1, op1);
					float operando2 = memory.getVarFlotante(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1!=operando2);
				}
				else if(tipoOp1 =='f' && tipoOp2 == 'i') { /*Flotante != Entero*/
					float operando1 = memory.getVarFlotante(scopeOp1, op1);
					int operando2 = memory.getVarEntero(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1!=operando2);
				}
				else if(tipoOp1 =='f' && tipoOp2 == 'f') { /*Flotante != Flotante*/
					float operando1 = memory.getVarFlotante(scopeOp1, op1);
					float operando2 = memory.getVarFlotante(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1!=operando2);
				}
				else if(tipoOp1 =='c' && tipoOp2 == 'c') { /*Char != Char*/
					char operando1 = memory.getVarChar(scopeOp1, op1);
					char operando2 = memory.getVarChar(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1!=operando2);
				}
				else if(tipoOp1 =='c' && tipoOp2 == 's') { /*Char != String*/
					char operando1 = memory.getVarChar(scopeOp1, op1);
					String operando2 = memory.getVarStrings(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, !(operando2.equals(""+operando1)));
				} 
				else if(tipoOp1 =='s' && tipoOp2 == 'c') { /*String != Char*/
					String operando1 = memory.getVarStrings(scopeOp1, op1);
					char operando2 = memory.getVarChar(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, !(operando1.equals(""+operando2)));
				}
				else if(tipoOp1 =='s' && tipoOp2 == 's') { /*String != String*/
					String operando1 = memory.getVarStrings(scopeOp1, op1);
					String operando2 = memory.getVarStrings(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, !(operando1.equals(operando2)));
				}
				else if(tipoOp1 =='b' && tipoOp2 == 'b') { /*Boolean != Boolean*/
					boolean operando1 = memory.getVarBooleanos(scopeOp1, op1);
					boolean operando2 = memory.getVarBooleanos(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1!=operando2);
				}
				break;
			
			/* IGUALDAD */
			case 205:
				if(tipoOp1 =='i' && tipoOp2 == 'i') { /*Entero == Entero*/
					int operando1 = memory.getVarEntero(scopeOp1, op1);
					int operando2 = memory.getVarEntero(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1==operando2);
				}
				else if(tipoOp1 =='i' && tipoOp2 == 'f') { /*Entero == Flotante*/
					int operando1 = memory.getVarEntero(scopeOp1, op1);
					float operando2 = memory.getVarFlotante(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1==operando2);
				}
				else if(tipoOp1 =='f' && tipoOp2 == 'i') { /*Flotante == Entero*/
					float operando1 = memory.getVarFlotante(scopeOp1, op1);
					int operando2 = memory.getVarEntero(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1==operando2);
				}
				else if(tipoOp1 =='f' && tipoOp2 == 'f') { /*Flotante == Flotante*/
					float operando1 = memory.getVarFlotante(scopeOp1, op1);
					float operando2 = memory.getVarFlotante(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1==operando2);
				}
				else if(tipoOp1 =='c' && tipoOp2 == 'c') { /*Char == Char*/
					char operando1 = memory.getVarChar(scopeOp1, op1);
					char operando2 = memory.getVarChar(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1==operando2);
				}
				else if(tipoOp1 =='c' && tipoOp2 == 's') { /*Char == String*/
					char operando1 = memory.getVarChar(scopeOp1, op1);
					String operando2 = memory.getVarStrings(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, (operando2.equals(""+operando1)));
				} 
				else if(tipoOp1 =='s' && tipoOp2 == 'c') { /*String == Char*/
					String operando1 = memory.getVarStrings(scopeOp1, op1);
					char operando2 = memory.getVarChar(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, (operando1.equals(""+operando2)));
				}
				else if(tipoOp1 =='s' && tipoOp2 == 's') { /*String == String*/
					String operando1 = memory.getVarStrings(scopeOp1, op1);
					String operando2 = memory.getVarStrings(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, (operando1.equals(operando2)));
				}
				else if(tipoOp1 =='b' && tipoOp2 == 'b') { /*Boolean == Boolean*/
					boolean operando1 = memory.getVarBooleanos(scopeOp1, op1);
					boolean operando2 = memory.getVarBooleanos(scopeOp2, op2);
					memory.agregaVar(scopeRes, res, operando1==operando2);
				}
				break;
			
			/* IGUAL/ASIGNACION */
			case 300:
				if(tipoOp1 =='i' && tipoRes == 'i') { /*Entero -> Entero*/
					int operando1 = memory.getVarEntero(scopeOp1, op1);
					memory.agregaVar(scopeRes, res, operando1);
				}
				else if(tipoOp1 =='i' && tipoRes == 'f') { /*Entero -> Flotante*/
					float operando1 = memory.getVarEntero(scopeOp1, op1);
					memory.agregaVar(scopeRes, res, operando1);
				}
				else if(tipoOp1 =='f' && tipoRes == 'f') { /*Flotante -> Flotante*/
					float operando1 = memory.getVarFlotante(scopeOp1, op1);
					memory.agregaVar(scopeRes, res, operando1);
				}
				else if(tipoOp1 =='c' && tipoRes == 'c') { /*Char -> Char*/
					char operando1 = memory.getVarChar(scopeOp1, op1);
					memory.agregaVar(scopeRes, res, operando1);
				}
				else if(tipoOp1 =='c' && tipoRes == 's') { /*Char -> String*/
					char operando1 = memory.getVarChar(scopeOp1, op1);
					memory.agregaVar(scopeRes, res, ""+operando1);
				}
				else if(tipoOp1 =='s' && tipoRes == 's') { /*String -> String*/
					String operando1 = memory.getVarStrings(scopeOp1, op1);
					memory.agregaVar(scopeRes, res, operando1);
				}
				else if(tipoOp1 =='b' && tipoRes == 'b') { /*Bool -> Bool*/
					boolean operando1 = memory.getVarBooleanos(scopeOp1, op1);
					memory.agregaVar(scopeRes, res, operando1);
				}
				break;
			/* GoTo */
			case 400:
				apuntaCuadruplo = res-1;
				break;
			
			/* GoToF */
			case 401:
				boolean operando1 = memory.getVarBooleanos(scopeOp1, op1);
				if(!operando1){
					apuntaCuadruplo = res-1;
				}
				break;
			
			/* Print */
			case 405:
				if(tipoRes == 'i') { /*imprime Entero*/
					int impresion = memory.getVarEntero(scopeRes, res);
					System.out.println(impresion);
				}
				else if(tipoRes == 'f') { /*imprime Flotante*/
					float impresion = memory.getVarFlotante(scopeRes, res);
					System.out.println(impresion);
				}
				else if(tipoRes == 'c') { /*imprime Char*/
					char impresion = memory.getVarChar(scopeRes, res);
					System.out.println(impresion);
				}
				else if(tipoRes == 's') { /*imprime String*/
					String impresion = memory.getVarStrings(scopeRes, res);
					System.out.println(impresion);
				}
				else if(tipoRes == 'b') { /*imprime Boolean*/
					boolean impresion = memory.getVarBooleanos(scopeRes, res);
					System.out.println(impresion);
				}
				break;
			
			/* RET */
			case 410:
				StackLocal ret = stackEra.pop();
				dirProc = ret.getDirProc();
				memory.local = ret.getMemLocal();
				apuntaCuadruplo = ret.getDirRet();
				
				StackLocal retTemp = stackEraTemp.pop();
				dirProc = retTemp.getDirProc();
				memory.temporal = retTemp.getMemLocal();
				apuntaCuadruplo = retTemp.getDirRet();
				break;
			
			/* Return */
			case 415:
				if(tipoOp1 == 'i') {
					int valRet = memory.getVarEntero(scopeOp1, op1);
					memory.agregaVar('g', res, valRet);
				} else if(tipoOp1 == 'f') {
					float valRet = memory.getVarFlotante(scopeOp1, op1);
					memory.agregaVar('g', res, valRet);
				} else if(tipoOp1 == 'c') {
					char valRet = memory.getVarChar(scopeOp1, op1);
					memory.agregaVar('g', res, valRet);
				} else if(tipoOp1 == 's') {
					String valRet = memory.getVarStrings(scopeOp1, op1);
					memory.agregaVar('g', res, valRet);
				} else if(tipoOp1 == 'b') {
					boolean valRet = memory.getVarBooleanos(scopeOp1, op1);
					memory.agregaVar('g', res, valRet);
				}
				break;

			/* Parametro */
			case 450:
				if(tipoOp1 == 'i') {
					int valParam = memory.getVarEntero(scopeOp1, op1);
					memEra.setEntero(contInt, valParam);
					contInt++;
				} else if(tipoOp1 == 'f') {
					float valParam = memory.getVarFlotante(scopeOp1, op1);
					memEra.setFlotante(contFloat, valParam);
					contFloat++;
				} else if(tipoOp1 == 'c') {
					char valParam = memory.getVarChar(scopeOp1, op1);
					memEra.setChar(contChar, valParam);
					contChar++;
				} else if(tipoOp1 == 's') {
					String valParam = memory.getVarStrings(scopeOp1, op1);
					memEra.setStrings(contStr, valParam);
					contStr++;
				} else if(tipoOp1 == 'b') {
					boolean valParam = memory.getVarBooleanos(scopeOp1, op1);
					memEra.setBooleanos(contBool, valParam);
					contBool++;
				}
				break;
			
			/* ERA */
			case 500:
				StackLocal era = new StackLocal(dirProc, memory.local, apuntaCuadruplo);
				stackEra.push(era);
				StackLocal eraTemp = new StackLocal(dirProc, memory.temporal, apuntaCuadruplo);
				stackEraTemp.push(eraTemp);
				memEra = new Memoria2(1000,1000,1000,1000,1000);
				memEraTemp = new Memoria2(1000,1000,1000,1000,1000);
				for(int i = 0; i < listaProcs.size(); i++){
					if(listaProcs.get(i).getDir() == op1){
						dirProc = i;
						i = listaProcs.size();
					}
				}
				break;
					
			/* GoSub */
			case 550:
				contInt = 0;
				contFloat = 0;
				contChar = 0;
				contStr = 0;
				contBool = 0;
				if(!stackEra.empty()){
					stackEra.peek().setDirRet(apuntaCuadruplo);
				}
				if(!stackEraTemp.empty()){
					stackEraTemp.peek().setDirRet(apuntaCuadruplo);
				}
				for(int i = 0; i < listaProcs.size(); i++){
					if(listaProcs.get(i).getDir() == op1){
						apuntaCuadruplo = listaProcs.get(i).getCuadruplo()-1;
						i = listaProcs.size();
					}
				}
				memory.local =  memEra;
				memory.temporal =  memEraTemp;
				break;
			
			/* END */
			case 777:
				System.out.println("Fin del programa");
				break;
		}
	}
	
	public void agregaConstantes(List<Constantes> listaCteInt, List<Constantes> listaCteFloat, List<Constantes> listaCteChar, List<Constantes> listaCteStr, List<Constantes> listaCteBool) {
		int i;
		/* Agrega Constantes Enteras */
		for(i = 0; i < listaCteInt.size(); i++) {
			memory.agregaVar('c', listaCteInt.get(i).getDir(), Integer.parseInt(listaCteInt.get(i).getValor()));
		}
		/* Agrega Constantes Flotantes */
		for(i = 0; i < listaCteFloat.size(); i++) {
			memory.agregaVar('c', listaCteFloat.get(i).getDir(), Float.parseFloat(listaCteFloat.get(i).getValor()));
		}
		/* Agrega Constantes Chars */
		for(i = 0; i < listaCteChar.size(); i++) {
			char charAux = listaCteChar.get(i).getValor().charAt(0);
			memory.agregaVar('c', listaCteChar.get(i).getDir(), charAux);
		}
		/* Agrega Constantes Strings */
		for(i = 0; i < listaCteStr.size(); i++) {
			memory.agregaVar('c', listaCteStr.get(i).getDir(), listaCteStr.get(i).getValor());
		}
		/* Agrega Constantes Booleanas */
		for(i = 0; i < listaCteBool.size(); i++) {
			memory.agregaVar('c', listaCteBool.get(i).getDir(), Boolean.parseBoolean(listaCteBool.get(i).getValor()));
		}
	}
	
	public char getTipo(int dir){
		if((dir >= 0 && dir < 1000) || (dir >= 5000 && dir < 6000) || (dir >= 10000 && dir < 11000) || (dir >= 15000 && dir < 16000)) {
			return 'i';
		}else if((dir >= 1000 && dir < 2000) || (dir >= 6000 && dir < 7000) || (dir >= 11000 && dir < 12000) || (dir >= 16000 && dir < 17000)) {
			return 'f';
		}else if((dir >= 2000 && dir < 3000) || (dir >= 7000 && dir < 8000) || (dir >= 12000 && dir < 13000) || (dir >= 17000 && dir < 18000)) {
			return 'c';
		}else if((dir >= 3000 && dir < 4000) || (dir >= 8000 && dir < 9000) || (dir >= 13000 && dir < 14000) || (dir >= 18000 && dir < 19000)) {
			return 's';
		}else if((dir >= 4000 && dir < 5000) || (dir >= 9000 && dir < 10000) || (dir >= 14000 && dir < 15000) || (dir >= 19000 && dir < 20000)) {
			return 'b';
		}
		return 'x';
	}

	public char getScope(int dir){
		if(dir >= 0 && dir < 5000){
			return 'g';
		}else if(dir >= 5000 && dir < 10000) {
			return 'l';
		}else if(dir >= 10000 && dir < 15000) {
			return 't';
		}else if(dir >= 15000 && dir < 20000) {
			return 'c';
		}
		return'x';
	}

}
