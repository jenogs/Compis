public class StackLocal {

	private int dirProc;
	private Memoria2 memLocal;
	private int dirRet;

	public StackLocal(int dirProc, Memoria2 memLocal, int dirRet) {
		this.dirProc = dirProc;
		this.memLocal = memLocal;
		this.dirRet = dirRet;
	}

	public int getDirProc() {
		return dirProc;
	}

	public Memoria2 getMemLocal() {
		return memLocal;
	}

	public void setDirRet(int dirRet) {
		this.dirRet = dirRet;
	}

	public int getDirRet() {
		return dirRet;
	}

}
