using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
	internal class Literatura
	{
		private Kolekcija<Stavka> kolekcija;
		private const int maxStavke = 10;

		public Literatura()
		{
			kolekcija = new Kolekcija<Stavka>();
		}

		public void DodajStavku(Stavka stavka)
		{
			if (kolekcija.Count == maxStavke)
				throw new NemaMestaException("Mesta nema");
			kolekcija.Add(stavka);
		}

		public void SortByGodina(bool opadajuci)
		{
			for (int i = 1; i < kolekcija.Count; i++)
			{
				int j = i - 1;
				Stavka pom = kolekcija[i];
				if (opadajuci)
					while (j >= 0 && kolekcija[j].Godina < pom.Godina)
					{
						kolekcija[j + 1] = kolekcija[j];
						j -= 1;
					}
				else
					while (j >= 0 && kolekcija[j].Godina > pom.Godina)
					{
						kolekcija[j + 1] = kolekcija[j];
						j -= 1;
					}
				kolekcija[j + 1] = pom;
			}
		}

		public void SortByTekst(bool opadajuci)
		{
			for (int i = 1; i < kolekcija.Count; i++)
			{
				int j = i - 1;
				Stavka pom = kolekcija[i];
				if (opadajuci)
					while (j >= 0 && string.Compare(kolekcija[j].Tekst, pom.Tekst) > 0)
					{
						kolekcija[j + 1] = kolekcija[j];
						j -= 1;
					}
				else
					while (j >= 0 && string.Compare(kolekcija[j].Tekst, pom.Tekst) < 0)
					{
						kolekcija[j + 1] = kolekcija[j];
						j -= 1;
					}
				kolekcija[j + 1] = pom;
			}
		}

		public void Print()
		{
			for (int i = 0; i < kolekcija.Count; i++)
				Console.WriteLine(kolekcija[i].Tekst);
		}

		public void PisiBin(string filename)
		{
			try
			{
				FileStream fs = new FileStream(filename, FileMode.Create, FileAccess.Write);
				using (StreamWriter sw = new StreamWriter(fs))
				{
					for (int i = 0; i < kolekcija.Count; i++)
						kolekcija[i].PisiBin(sw);
				}
			}
			catch (Exception ec)
			{
				Console.WriteLine(ec.StackTrace);
			}
		}
		public void CitajBin(string filename)
		{
			try
			{
				FileStream fs = new FileStream(filename, FileMode.Open, FileAccess.Read);
				using (StreamReader sr = new StreamReader(fs))
				{
					while (sr.Peek() != -1)
					{
						string tip = sr.ReadLine();
						Stavka stavka;
						if (tip == "Knjiga")
							stavka = new Knjiga();
						else if (tip == "Clanak")
							stavka = new Clanak();
						else
							stavka = new WebStranica();
						stavka.CitajBin(sr);
						kolekcija.Add(stavka);
					}
				}
			}
			catch (Exception ec)
			{
				Console.WriteLine(ec.StackTrace);
			}
		}
	}
}
