import nft.*;
import java.io.*;

public class Galerija <T extends NFT> {
	private int broj_nfta;
	private NFT nftovi[];
	
	public Galerija() {
		broj_nfta = 0;
		nftovi = null;
	}
	
	void dodaj(T t) {
		try {
			if (t.getCena() == 0)
				throw new BesplatanNFT("Besplatan token");
			if (broj_nfta == 0) {
				nftovi = new NFT[1];
				nftovi[0] = t;
			}
			else {
				NFT temp[] = new NFT[broj_nfta + 1];
				for (int i = 0; i < broj_nfta; i++)
					temp[i] = nftovi[i];
				temp[broj_nfta] = t;
				nftovi = new NFT[broj_nfta + 1];
				nftovi = temp;
			}
			broj_nfta += 1;
		}
		catch (BesplatanNFT bnft) {
			System.out.println(bnft.getMessage());
		}
	}
	
	void dajNajveci() {
		int max = 0;
		for (int i = 1; i < broj_nfta; i++) {
			if (nftovi[max].compareTo(nftovi[i]) == -1)
				max = i;		
		}
		try {
			FileOutputStream fos = new FileOutputStream("18587.bin");
			BufferedOutputStream bos = new BufferedOutputStream(fos);
			DataOutputStream dos = new DataOutputStream(bos);
			
			dos.writeInt(nftovi[max].getCena());
			nftovi[max].print();
			
			dos.close();
		}
		catch (IOException ioe) {
			System.out.println(ioe.getMessage());
		}
	}
	
}
