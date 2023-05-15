using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Grupa1
{
	internal class Kompanija
	{
		private List<Zaposleni> zaposleni;
		private const int maxBonus = 20;

		public Kompanija()
		{
			zaposleni = new List<Zaposleni>();
		}

		public static Kompanija operator +(Kompanija kompanija, Zaposleni radnik) 
		{
			if (radnik.Bonus() > maxBonus)
			{
				throw new PrevelikiBonus("PrevelikiBonus");
			}
			kompanija.zaposleni.Add(radnik);
			return kompanija;
		}

		public void pisiBin(string filename)
		{
			try
			{
				FileStream fs = new FileStream(filename, FileMode.Create, FileAccess.Write);
				using (BinaryWriter br = new BinaryWriter(fs))
				{
					foreach(Zaposleni z in zaposleni)
					{
						br.Write(z.ToString());
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
				BinaryReader br = new BinaryReader(fs);
				string s;
				while (br.PeekChar() != -1)
				{
					s = br.ReadString();
					Console.WriteLine(s);
				}

				br.Close();
			}
			catch (Exception e)
			{
				Console.WriteLine(e.StackTrace);
			}
		}
	}
}
