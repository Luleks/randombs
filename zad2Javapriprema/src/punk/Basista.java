package punk;

public class Basista extends Muzicar {
	private byte br_tonova;
	
	public Basista(){
		super();
		br_tonova = 0;
	}
	public Basista(int br_god, byte br_ton){
		super(br_god);
		br_tonova = br_ton;
	}
	public void print() {
		System.out.println("Bas, " + br_tonova + " " + br_god);
	}
}
