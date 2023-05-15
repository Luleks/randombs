using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Grupa1
{
	internal class Program
	{
		static void Main(string[] args)
		{
			Kompanija kompa = new Kompanija();

			try
			{
				kompa = kompa + new QA("Ime", "Prezime", 150000, 6);
				kompa = kompa + new WebDeveloper("Ime", "Prezime", 120000, "JavaScript", "Angular", "React");
				kompa = kompa + new DevOps("Ime", "Prezime", 180000, new DateTime(2023, 5, 6));
				kompa = kompa + new QA("Ime", "Prezime", 145000, 16);
			}
			catch (PrevelikiBonus pb)
			{
				Console.WriteLine(pb.StackTrace);
			}
			kompa.pisiBin("podaci.bin");
			kompa.citajBin("podaci.bin");
		}
	}
}
