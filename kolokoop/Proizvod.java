
public abstract class Proizvod {
	protected String barkod;
	
	public Proizvod() {
		barkod = "";
	}
	
	public Proizvod(String barkod) {
		this.barkod = barkod;
	}
	
	public void print() {
		System.out.print(barkod + " ");
	}
	
	public abstract void popravi(float val);
	public abstract boolean je_defektan();
}