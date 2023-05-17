using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
	internal class WebDev : Zaposleni
	{
		private List<string> tehnologije;

		public WebDev() : base()
		{
			tehnologije = new List<string>();
		}
		public WebDev(string ime, string prezime, double plata, params string[] tehnologije)
			: base(ime, prezime, plata)
		{
			this.tehnologije = new List<string>(tehnologije);
		}

		public override string Tekst
		{
			get { return $"WebDev\n{base.Tekst} {string.Join(" ", tehnologije)}"; }
		}

		public override double Bonus
		{
			get { return tehnologije.Count > 5 ? 20 : 10; }
		}

		public override void pisiBin(BinaryWriter bw)
		{
			bw.Write("WebDev");
			base.pisiBin(bw);
			bw.Write(tehnologije.Count);
			foreach(string s in tehnologije)
			{
				bw.Write(s);
			}
		}

		public override void citajBin(BinaryReader br)
		{
			base.citajBin(br);
			int count = br.ReadInt32();
			for (int i = 0; i < count; i++)
				tehnologije.Add(br.ReadString());
		}
	}
}
