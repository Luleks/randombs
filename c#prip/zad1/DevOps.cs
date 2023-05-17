using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
	internal class DevOps : Zaposleni
	{
		private DateTime poslednjiPregled;

		public DevOps() : base()
		{
			poslednjiPregled = DateTime.MinValue;
		}

		public DevOps(string ime, string prezime, double plata, DateTime poslednjiPregled)
			: base(ime, prezime, plata)
		{
			this.poslednjiPregled = poslednjiPregled;
		}

		public override string Tekst
		{
			get { return $"DevOps\n{base.Tekst} {poslednjiPregled.ToString("dd.MM.yyyy.")}"; }
		}

		public override double Bonus
		{
			get { return poslednjiPregled.AddDays(7) > DateTime.Now ? 30 : 15; }
		}

		public override void pisiBin(BinaryWriter bw)
		{
			bw.Write("DevOps");
			base.pisiBin(bw);
			bw.Write(poslednjiPregled.ToString("dd.MM.yyyy."));
		}

		public override void citajBin(BinaryReader br)
		{
			base.citajBin(br);
			string datum = br.ReadString();
			poslednjiPregled = DateTime.ParseExact(datum, "dd.MM.yyyy.", CultureInfo.InvariantCulture);
		}
	}
}
