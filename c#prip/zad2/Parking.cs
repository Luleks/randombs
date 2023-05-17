using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
	internal class Parking
	{
		private Matrica<Vozilo> parking;
		
		public Parking(int n, int m)
		{
			parking = new Matrica<Vozilo>(n, m);
		}

		public void Parkiraj(Vozilo v)
		{
			if (!parking.Dodaj(v))
				throw new NemaMestaException("Nema mesta");
		}

		public void Isparkiraj(Vozilo v)
		{
			parking.Ukloni(v);
		}

		public Vozilo this[int i, int j]
		{
			get { return parking[i, j]; }
		}

		public void Stanje()
		{
			for (int i = 0; i < parking.N; i++)
			{
				for (int j = 0; j < parking.M; j++)
				{
					if (parking[i, j] == null)
						Console.Write("O ");
					else
						Console.Write("X ");
				}
				Console.WriteLine();
			}
		}

		public void PisiBin(string filename)
		{
			try
			{
				FileStream fs = new FileStream(filename, FileMode.Create, FileAccess.Write);
				Dictionary<Vozilo, bool> vecVidjen = new Dictionary<Vozilo, bool>();
				using (BinaryWriter bw = new BinaryWriter(fs))
				{
					for (int i = 0; i < parking.N; i++)
					{
						for (int j = 0; j < parking.M; j++)
						{
							if (parking[i, j] != null && !vecVidjen.ContainsKey(parking[i, j]))
							{
								parking[i, j].PisiBin(bw);
								vecVidjen.Add(parking[i, j], true);
							}
						}
					}
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
				using (BinaryReader br = new BinaryReader(fs))
				{
					while (br.PeekChar() != -1)
					{
						string tip = br.ReadString();
						if (tip == "Automobil")
						{
							Vozilo v = new Automobil();
							v.CitajBin(br);
							Parkiraj(v);
						}
						else if (tip == "Autobus")
						{
							Vozilo v = new Autobus();
							v.CitajBin(br);
							Parkiraj(v);
						}
						else if (tip == "Kamion")
						{
							Vozilo v = new Kamion();
							v.CitajBin(br);
							Parkiraj(v);
						}
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
