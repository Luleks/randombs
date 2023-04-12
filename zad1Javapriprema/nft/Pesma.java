package nft;

public class Pesma extends NFT {
	private int trajanje;
	private int glasnoca;
	private String tekst;
	
	public Pesma(){
		super();
		trajanje = glasnoca = 0;
		tekst = "";
	}
	public Pesma(int cena, int trajanje, int glasnoca, String tekst){
		super(cena);
		this.trajanje = trajanje;
		this.glasnoca = glasnoca;
		this.tekst = tekst;
	}
	public void print() {
		System.out.println("Pesma: " + tekst + " " + "trajanje, glasnoca = " + trajanje + " " + glasnoca);
	}
}
