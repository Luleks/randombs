
public class Kondenzator extends Proizvod {
	private float kapacitivnost;
	
	public Kondenzator() {
		super();
		kapacitivnost = 0;
	}
	
	public Kondenzator(String barkod, float c) {
		super(barkod);
		kapacitivnost = c;
	}
	
	public void print() {
		super.print();
		System.out.println("Kondenzator, (C = " + kapacitivnost + ")");
	}
	
	public void popravi(float val) {
		kapacitivnost = val;
	}
	
	public boolean je_defektan() {
		return kapacitivnost == 0.0;
	}
}
