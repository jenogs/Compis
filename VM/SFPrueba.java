import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class SFPrueba {

	static List<Procs> listaProcs = new ArrayList<Procs>();
	static List<Cuadruplo> listaCuadruplos = new ArrayList<Cuadruplo>();
	static List<Constantes> listaCteInt = new ArrayList<Constantes>();
	static List<Constantes> listaCteFloat = new ArrayList<Constantes>();
	static List<Constantes> listaCteChar = new ArrayList<Constantes>();
	static List<Constantes> listaCteStr = new ArrayList<Constantes>();
	static List<Constantes> listaCteBool = new ArrayList<Constantes>();

	static Procs proc;
	static Cuadruplo cuad;
	static Constantes cteAux;
	
	static MaquinaVirtual mv;

	public static void main(String[] args) {
		new SFPrueba().leeObj("obj");
		mv = new MaquinaVirtual(listaProcs, listaCteInt, listaCteFloat, listaCteChar, listaCteStr, listaCteBool, listaCuadruplos);
	}

	public void leeObj(String file) {
		BufferedReader bufferedReader = null;
		String line;
		String aux[];

		try {
			bufferedReader = new BufferedReader(new FileReader(file));
			line = bufferedReader.readLine();
			
			while(!line.equals("$")) {
				aux = line.split("#");
				proc = new Procs(aux[0],Integer.parseInt(aux[1]));
				listaProcs.add(proc);
				line = bufferedReader.readLine();
			}
			line = bufferedReader.readLine();
			
			while(!line.equals("$$")) {
				aux = line.split("#");
				cteAux = new Constantes(aux[0],Integer.parseInt(aux[1]));
				listaCteInt.add(cteAux);
				line = bufferedReader.readLine();
			}
			line = bufferedReader.readLine();
			
			while(!line.equals("$")) {
				aux = line.split("#");
				cteAux = new Constantes(aux[0],Integer.parseInt(aux[1]));
				listaCteFloat.add(cteAux);
				line = bufferedReader.readLine();
			}
			line = bufferedReader.readLine();
			
			while(!line.equals("$$")) {
				aux = line.split("#");
				cteAux = new Constantes(aux[0],Integer.parseInt(aux[1]));
				listaCteChar.add(cteAux);
				line = bufferedReader.readLine();
			}
			line = bufferedReader.readLine();

			while(!line.equals("$")) {
				aux = line.split("#");
				cteAux = new Constantes(aux[0],Integer.parseInt(aux[1]));
				listaCteStr.add(cteAux);
				line = bufferedReader.readLine();
			}
			line = bufferedReader.readLine();

			while(!line.equals("$$")) {
				aux = line.split("#");
				cteAux = new Constantes(aux[0],Integer.parseInt(aux[1]));
				listaCteBool.add(cteAux);
				line = bufferedReader.readLine();
			}
			line = bufferedReader.readLine();
			
			while(!line.equals("$")) {
				aux = line.split(",");
				cuad = new Cuadruplo(Integer.parseInt(aux[0]),Integer.parseInt(aux[1]),Integer.parseInt(aux[2]),Integer.parseInt(aux[3]));
				listaCuadruplos.add(cuad);
				line = bufferedReader.readLine();
			}
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (bufferedReader != null)
					bufferedReader.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}

	}

}

