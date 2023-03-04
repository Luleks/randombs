
public class Otpornik extends Proizvod {
	private float otpornost;
	private float min_temp;
	private float max_temp;
	
	Otpornik(){
		super();
		otpornost = 0;
		min_temp = 0;
		max_temp = 0;
	}
	
	Otpornik(String barkod, float R, float minT, float maxT){
		super(barkod);
		otpornost = R;
		min_temp = minT;
		max_temp = maxT;
	}
	
	public void print() {
		super.print();
		System.out.println("Otpornik, (R, minT, maxT = " + otpornost + " " + min_temp + " " + max_temp + ")");
	}
	
	public void popravi(float val) {
		otpornost = val;
	}
	
	public boolean je_defektan() {
		return (otpornost == 0.0) || (otpornost == Double.POSITIVE_INFINITY); 
	}
}
