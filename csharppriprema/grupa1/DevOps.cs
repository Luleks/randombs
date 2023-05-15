using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Grupa1
{
	internal class DevOps : Zaposleni
	{
		private DateTime poslednjiPregled;

		public DevOps() : base()
		{
			poslednjiPregled = DateTime.MinValue;
		}
		
		public DevOps(string ime, string prezime, double plata, DateTime datumPregleda)
			: base(ime, prezime, plata)
		{
			poslednjiPregled = datumPregleda;
		}

		public override string ToString()
		{
			StringBuilder builder = new StringBuilder();
			builder.Append(base.ToString());
			builder.Append(Bonus() + " ");
			builder.Append(poslednjiPregled.ToString("dd.MM.yyyy."));
			return builder.ToString();
		}

		public override int Bonus()
		{
			return DateTime.Now <= poslednjiPregled.AddDays(7) ? 30 : 15;
		}
	}
}
