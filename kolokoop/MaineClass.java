

public class MaineClass {
	public static void main(String args[]) {
		PokretnaTraka traka = new PokretnaTraka(10);
		traka.dodaj(new Kondenzator("696969", (float)0.0));
		for (int i = 0; i < 2; i++) {
			traka.dodaj(new Kondenzator(Integer.toString(100000+i),(float)Math.random() * 10));
			traka.dodaj(new Otpornik(Integer.toString(100000+i), ((float)Math.random() * 10), 10, 15));
		}
		traka.dodaj(new Otpornik("585858", (float)0.0, 10, 15));
		
		traka.zameni_defektni(5, 25);
		traka.prosiri_traku(2);
		
		traka.dodaj(new Kondenzator("202020",(float)Math.random() * 10));
		traka.dodaj(new Kondenzator("202220",(float)Math.random() * 10));
		
		traka.isprazni_traku();
	}
}
