package nft;

public class Fajl extends NFT {
	private int duzina;
	private String ime;
	private String ekstenzija;
	
	public Fajl() {
		super();
		duzina = 0;
		ime = ekstenzija = "";
	}
	public Fajl(int cena, int duzina, String ime, String ekstenzija) {
		super(cena);
		this.duzina = duzina;
		this.ime = ime;
		this.ekstenzija = ekstenzija;
	}
	
	public void print() {
		System.out.println("Fajl " + ime + "." + ekstenzija + " " + duzina);
	}
}
