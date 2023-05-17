using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
	internal class Program
	{
		static void Main(string[] args)
		{
			Kompanija kompanija = new Kompanija();
			Zaposleni z1 = new WebDev("Luka", "Velickovic", 150000, "JavaScript", "HTML", "CSS", "React");
			Zaposleni z2 = new QA("Petar", "Petrovic", 80000, 5);
			Zaposleni z3 = new DevOps("Nemanja", "Nikolic", 120000, new DateTime(2023, 5, 16));
			Zaposleni z4 = new QA("Ana", "Jankovic", 88000, 15);
			Zaposleni z5 = new WebDev("Hulk", "Hogan", 1000000, "Python");
			Zaposleni z6 = new DevOps("Jana", "Velickovic", 120000, DateTime.Now);

			kompanija = kompanija + z1;
			kompanija = kompanija + z2;
			kompanija = kompanija + z3;
			kompanija = kompanija + z4;
			kompanija = kompanija + z5;
			kompanija = kompanija + z6;

			kompanija.prikaz();

			kompanija.pisiBin("info_o_kompaniji.bin");

			Kompanija k2 = new Kompanija();
			k2.citajBin("info_o_kompaniji.bin");

			k2.prikaz();
		}
	}
}
