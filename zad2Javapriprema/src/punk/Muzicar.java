package punk;

public abstract class Muzicar implements Comparable<Muzicar> {
	protected int br_god;
	
	public int getBr_god() {
		return br_god;
	}
	public Muzicar() {
		br_god = 0;
	}
	public Muzicar(int br_god) {
		this.br_god = br_god;
	}
	
	public int compareTo(Muzicar m) {
		if (br_god < m.br_god)
			return 1;
		else if (br_god == m.br_god)
			return 0;
		return -1;
	}
	
	public abstract void print();
}
