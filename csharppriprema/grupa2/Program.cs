using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Grupa2
{
	internal class Program
	{
		static void Main(string[] args)
		{
			Parking<Vozilo> p1 = new Parking<Vozilo>(5, 7);
			Vozilo v1 = new Auto("NI-244-GZ", "Golf", "Dvojka");
			Vozilo v2 = new Autobus("BG-1568-AU", "Ikarbus", "Lep", 40);
			Vozilo v3 = new Kamion("NS-214-AD", "Kamion", "Sestoton", 7, 6);
			Vozilo v4 = new Autobus("Registracija", "Aftobus", "Lasta", 25);
			Vozilo v5 = new Auto("Limuzina", "Limuzina", "Limuzina");
			Vozilo v6 = new Kamion("Mali", "Man", "Neki", 3, 3);

			v1.Parkiraj(p1);
			v2.Parkiraj(p1);
			v3.Parkiraj(p1);
			v4.Parkiraj(p1);
			v5.Parkiraj(p1);
			v6.Parkiraj(p1);

			p1.Stanje();

			v4.Isparkiraj();
			v2.Isparkiraj();

			p1.Stanje();

			p1.PisiTxt("parking.bin");

			Parking<Vozilo> p2 = new Parking<Vozilo>(5, 7);
			p2.CitajTxt("parking.bin");
			p2.PisiTxt("novi.bin");
			p2.Stanje();
		}
	}
}
