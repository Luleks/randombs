package punk;

public class Bubnjar extends Muzicar {
	private int masa;
	private long alkohol;
	
	public Bubnjar(){
		super();
		masa = 0;
		alkohol = 0;
	}
	public Bubnjar(int br_god, int masa, long alkohol){
		super(br_god);
		this.masa = masa;
		this.alkohol = alkohol;
	}
	public void print() {
		System.out.println("Bubanj, " + alkohol + " " + br_god);
	}
}
