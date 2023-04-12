package nft;

public abstract class NFT implements Comparable<NFT> {
	protected int cena;
	
	public NFT() {
		cena = 0;
	}
	public NFT(int cena) {
		this.cena = cena;
	}
	public int getCena() {
		return cena;
	}
	
	public int compareTo(NFT nft) {
		if (this.cena < nft.cena)
			return -1;
		else if (this.cena == nft.cena)
			return 0;
		else
			return 1;
	}
	public abstract void print();
}
