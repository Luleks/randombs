using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
	internal class Program
	{
		static void Main(string[] args)
		{
			Parking p1 = new Parking(5, 7);
			Vozilo v1 = new Automobil("A123", "Hundai", "Accent");
			Vozilo v2 = new Automobil("B251", "Honda", "Civic");
			Vozilo v3 = new Autobus("LL24", "Lasta", "GradskiPrevoz", 50);
			Vozilo v4 = new Autobus("NS125", "Lasta", "Putnicki", 100);
			Vozilo v5 = new Kamion("ABCDE", "Man", "Sleper", 7, 100);
			Vozilo v6 = new Kamion("FGHIJ", "Tam", "75", 5, 10);

			p1.Parkiraj(v1);
			p1.Parkiraj(v2);
			p1.Parkiraj(v3);
			p1.Parkiraj(v4);
			p1.Parkiraj(v5);
			p1.Parkiraj(v6);

			p1.Stanje();

			p1.PisiBin("parking.bin");

			Parking p2 = new Parking(5, 10);
			p2.CitajBin("parking.bin");

			p2.Stanje();
		}
	}
}
