import java.io.*;
import nft.*;

public class MaineKlasen {

	public static void main(String[] args) {
		Galerija<NFT> galerija = new Galerija <> ();
		try {
			NFT fajl, slika, pesma;
			FileReader fr = new FileReader("fajl.txt");
			BufferedReader br = new BufferedReader(fr);
			
			fajl = new Fajl(Integer.parseInt(br.readLine()), Integer.parseInt(br.readLine()), br.readLine(), br.readLine());
			slika = new Slika(Integer.parseInt(br.readLine()), Integer.parseInt(br.readLine()), Integer.parseInt(br.readLine()), 
					Integer.parseInt(br.readLine()), br.readLine());
			pesma = new Pesma(Integer.parseInt(br.readLine()), Integer.parseInt(br.readLine()), Integer.parseInt(br.readLine()),
					br.readLine());
			
			br.close();
			
			galerija.dodaj(fajl);
			galerija.dodaj(slika);
			galerija.dodaj(pesma);
			
			galerija.dajNajveci();

		}
		catch (IOException ioe) {
			System.out.println(ioe.getMessage());
		}

	}

}
