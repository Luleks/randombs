using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
	internal class Kompanija
	{
		private Kolekcija<Zaposleni> zaposleni;
		private const int maxBonus = 25;

		public Kompanija()
		{
			zaposleni = new Kolekcija<Zaposleni>();
		}

		public static Kompanija operator+(Kompanija kompa, Zaposleni radnik)
		{
			kompa.zaposleni.addItem(radnik);
			return kompa;
		}

		public void prikaz()
		{
			for (int i = 0; i < zaposleni.Count; i++)
				Console.WriteLine(zaposleni[i].Tekst);
		}

		public void pisiBin(string filename)
		{
			try
			{
				FileStream fs = new FileStream(filename, FileMode.Create, FileAccess.Write);
				using (BinaryWriter bw = new BinaryWriter(fs))
				{
					for(int i = 0; i < zaposleni.Count; i++)
					{
						zaposleni[i].pisiBin(bw);
					}
				}
			}
			catch (Exception e)
			{
				Console.WriteLine(e.StackTrace);
			}
		}
		public void citajBin(string filename)
		{
			try
			{
				FileStream fs = new FileStream(filename, FileMode.Open, FileAccess.Read);
				using (BinaryReader br = new BinaryReader(fs))
				{
					while (br.PeekChar() != -1)
					{
						Zaposleni radnik;
						string pozicija = br.ReadString();
						if (pozicija == "QA")
						{
							radnik = new QA();
							radnik.citajBin(br);
							zaposleni.addItem(radnik);
						}
						else if (pozicija == "DevOps")
						{
							radnik = new DevOps();
							radnik.citajBin(br);
							zaposleni.addItem(radnik);
						}
						else if (pozicija == "WebDev")
						{
							radnik = new WebDev();
							radnik.citajBin(br);
							zaposleni.addItem(radnik);
						}	
					}
				}
			}
			catch (Exception e)
			{
				Console.WriteLine(e.StackTrace);
			}
		}
	}
}
