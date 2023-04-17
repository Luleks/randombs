package punk;

public class Pevac extends Muzicar {
	private int raspon_glasa;
	private int koef_tel_aktiv;
	private String scen_ime;
	
	public Pevac() {
		super();
		raspon_glasa = 0;
		koef_tel_aktiv = 0;
		scen_ime = "";
	}
	
	public Pevac(int br_god, int ras_gl, int koef_tel_ak, String ime) {
		super(br_god);
		raspon_glasa = ras_gl;
		this.koef_tel_aktiv = koef_tel_ak;
		this.scen_ime = ime;
	}
	
	public void print() {
		System.out.println("Muzicar, " + scen_ime + " " + br_god);
	}
}
