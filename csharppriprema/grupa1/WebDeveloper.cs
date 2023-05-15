using System;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Grupa1
{
	internal class WebDeveloper : Zaposleni
	{
		List<string> tehnologije;

		public WebDeveloper() : base()
		{
			tehnologije = new List<string>();
		}

		public WebDeveloper(string ime, string prezime, double plata, params string[] tehno)
			: base(ime, prezime, plata)
		{
			tehnologije = new List<string>(tehno);
		}

		public override string ToString()
		{
			StringBuilder builder = new StringBuilder();
			builder.Append(base.ToString());
			builder.Append(Bonus() + " ");
			foreach (string tech in tehnologije)
			{
				builder.Append(tech + " ");
			}
			return builder.ToString();
		}

		public override int Bonus()
		{
			return tehnologije.Count > 5 ? 20 : 10;
		}
	}
}
