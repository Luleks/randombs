package punk;

public class Gitarista extends Muzicar {
	private int faktor_sujete;
	private int koef_fac_eksp;
	private String scen_ime;
	
	public Gitarista(){
		super();
		faktor_sujete = 0;
		koef_fac_eksp = 0;
		scen_ime = "";
	}
	public Gitarista(int br_god, int fak_suj, int koef, String ime){
		super(br_god);
		faktor_sujete = fak_suj;
		this.koef_fac_eksp = koef;
		this.scen_ime = ime;
	}
	
	public void print() {
		System.out.println("Gitarista, " + scen_ime + " " + br_god);
	}
	
}
