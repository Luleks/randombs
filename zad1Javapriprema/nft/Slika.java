package nft;

public class Slika extends NFT {
	private int visina;
	private int sirina;
	private int br_boja;
	private String opis_motiva;
	
	public Slika(){
		super();
		visina = sirina = br_boja = 0;
		opis_motiva = "";
	}
	public Slika(int cena, int visina, int sirina, int br_boja, String opis_motiva){
		super(cena);
		this.visina = visina;
		this.sirina = sirina;
		this.br_boja = br_boja;
		this.opis_motiva = opis_motiva;
	}
	public void print() {
		System.out.println("Slika (" + visina + "x" + sirina + " br_boja = " + br_boja + " " + opis_motiva);
	}
}
