using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Grupa2
{
	internal class Parking<T> where T : Vozilo
	{
		private Vozilo[,] parking;
		private int brVrsta;
		private int brKolona;

		public Parking(int n, int m)
		{
			brVrsta = n;
			brKolona = m;
			parking = new Vozilo[n, m];
		}

		public void Parkiraj(Vozilo v, int brMesta)
		{
			for (int i = 0; i < brVrsta; i++)
			{
				for (int j = 0; j < brKolona - brMesta + 1; j++)
				{
					int k = 0;
					while (k < brMesta && parking[i, j+k] == null)
						k += 1;
					if (k == brMesta)
					{
						for (k = 0; k < brMesta; k++)
							parking[i, j + k] = v;
						return;
					}
				}
			}
			throw new NemaMesta("Nema mesta na parkingu za vozilo");
		}
		public void Isparkiraj(Vozilo v)
		{
			for (int i = 0; i < brVrsta; i++)
			{
				for (int j = 0; j < brKolona; j++)
				{
					if (parking[i, j] == v)
						parking[i, j] = null;
				}
			}
		}

		public void Stanje()
		{
			for (int i = 0; i < brVrsta; i++)
			{
				for (int j = 0; j < brKolona; j++)
				{
					if (parking[i, j] != null)
						Console.Write("- ");
					else
						Console.Write("o ");
				}
				Console.WriteLine();
			}
			Console.WriteLine();
		}

		public void PisiTxt(string path)
		{
			try
			{
				FileStream fs = new FileStream(path, FileMode.Create, FileAccess.Write);
				using (BinaryWriter tw = new BinaryWriter(fs))
				{
					Dictionary<Vozilo, bool> vecVidjen = new Dictionary<Vozilo, bool>();
					for (int i = 0; i < brVrsta; i++)
					{
						for (int j = 0; j < brKolona; j++)
						{
							if (parking[i, j] != null && !vecVidjen.ContainsKey(parking[i,j]))
							{
								vecVidjen.Add(parking[i, j], true);
								tw.Write($"{i} {j} {parking[i, j]} ");
								//tw.Write(parking[i, j].ToString());
							}
						}
					}
				}
			}
			catch (Exception e)
			{
				Console.WriteLine(e.StackTrace);
			}
		}

		public void CitajTxt(string path)
		{
			try
			{
				FileStream fs = new FileStream(path, FileMode.Open, FileAccess.Read);
				using (BinaryReader br = new BinaryReader(fs))
				{
					while (br.PeekChar() != -1)
					{
						string[] loaded = br.ReadString().Split(" ".ToCharArray());
						int i = int.Parse(loaded[0]);
						int j = int.Parse(loaded[1]);
						string type = loaded.ElementAt(2);
						if (type == "Auto")
						{
							Vozilo v = new Auto(loaded.ElementAt(3), loaded.ElementAt(4),
								loaded.ElementAt(5));
							parking[i, j] = v;
						}
						else if (type == "Autobus")
						{
							Vozilo v = new Autobus(loaded.ElementAt(3), loaded.ElementAt(4),
								loaded.ElementAt(5), int.Parse(loaded.ElementAt(6)));
							for (int k = 0; k < v.BrojMesta; k++)
								parking[i, j + k] = v;
						}
						else if (type == "Kamion")
						{
							Vozilo v = new Kamion(loaded.ElementAt(3), loaded.ElementAt(4),
								loaded.ElementAt(5), int.Parse(loaded.ElementAt(6)),
								int.Parse(loaded.ElementAt(7)));
							for (int k = 0; k < v.BrojMesta; k++)
								parking[i, j + k] = v;
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
