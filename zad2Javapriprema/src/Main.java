import punk.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		PunkBand bend = new PunkBand();
		
		try {
			FileReader fr = new FileReader("bend.txt");
			BufferedReader br = new BufferedReader(fr);
			
			bend.evidentiraj(new Pevac(Integer.parseInt(br.readLine()), Integer.parseInt(br.readLine()), Integer.parseInt(br.readLine()),
					br.readLine()));
			bend.evidentiraj(new Gitarista(Integer.parseInt(br.readLine()), Integer.parseInt(br.readLine()), Integer.parseInt(br.readLine()),
					br.readLine()));
			bend.evidentiraj(new Basista(Integer.parseInt(br.readLine()), Byte.parseByte(br.readLine())));
			bend.evidentiraj(new Bubnjar(Integer.parseInt(br.readLine()), Integer.parseInt(br.readLine()), Long.parseLong(br.readLine())));
			
			br.close();
			
		}
		catch (IOException ioe) {
			System.out.println(ioe.getMessage());
		}
		
		bend.vodjaBenda();

	}

}
