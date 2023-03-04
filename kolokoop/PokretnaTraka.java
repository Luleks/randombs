
public class PokretnaTraka {
	private Proizvod[] proizvodi;
	private int n;
	
	public PokretnaTraka() {
		proizvodi = null;
		n = 0;
	}
	
	public PokretnaTraka(int n) {
		this.n = n;
		proizvodi = new Proizvod[this.n];
		for (int i = 0; i < n; i++)
			proizvodi[i] = null;
	}
	
	public void prosiri_traku(int br_mesta) {
		int novo_n = n + br_mesta;
		Proizvod[] novi_proizvodi = new Proizvod[novo_n];
		for (int i = 0; i < n; i++) {
			novi_proizvodi[i] = proizvodi[i];
		}
		proizvodi = novi_proizvodi;
		n = novo_n;
	}
	
	public void zameni_defektni(int index, float val) {
		if ((index < n / 3) && (proizvodi[index].je_defektan()))
			proizvodi[index].popravi(val);
		else if (proizvodi[index].je_defektan())
			proizvodi[index] = null;
	}
	
	public int br_defektnih() {
		int s = 0;
		for (int i = 0; i < n; i++) {
			if (proizvodi[i] != null && proizvodi[i].je_defektan())
				s += 1;
		}
		return s;
	}
	
	public int br_praznih() {
		int s = 0;
		for (int i = 0; i < n; i++) {
			if (proizvodi[i] == null)
				s += 1;
		}
		return s;
	}
	
	public void pokreni_traku() {
		if (proizvodi[n-1] == null)
			System.out.println();
		else
			proizvodi[n-1].print();
		for (int i = n - 1; i > 0; i--) {
			proizvodi[i] = proizvodi[i-1];
		}
		proizvodi[0] = null;
	}
	
	public void print() {
		for (int i = 0; i < n; i++) {
			System.out.print(i + " ");
			if (proizvodi[i] != null)
				proizvodi[i].print();
			else
				System.out.println();
		}
	}
	
	public void dodaj(Proizvod p) {
		pokreni_traku();
		proizvodi[0] = p;
	}
	
	public void isprazni_traku() {
		while (br_praznih() != n)
			pokreni_traku();
	}
}
