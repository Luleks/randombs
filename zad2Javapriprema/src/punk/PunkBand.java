package punk;
import java.util.*;
import java.io.*;

public class PunkBand {
	private ArrayList<Muzicar> sastav;
	
	public PunkBand() {
		sastav = new ArrayList<>();
	}
	
	public void evidentiraj(Muzicar mu) {
		try {
			if (mu.getBr_god() < 0)
				throw new Antimaterija("Somina bio u bend pre bend");
			sastav.add(mu);
		}
		catch (Antimaterija som) {
			System.out.println("Novi som " + som.getMessage());
		}
	}
	
	public void vodjaBenda() {
		sastav.sort(null);
		Muzicar vodja = sastav.get(0);
		vodja.print();
		try {
			FileOutputStream fos = new FileOutputStream("18587.bin");
			BufferedOutputStream bos = new BufferedOutputStream(fos);
			DataOutputStream dos = new DataOutputStream(bos);
			
			dos.writeInt(vodja.getBr_god());
			
			dos.close();
		}
		catch (IOException ioe) {
			System.out.println(ioe.getMessage());
		}
		
	}
}
