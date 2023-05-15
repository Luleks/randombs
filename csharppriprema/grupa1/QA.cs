using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Grupa1
{
	internal class QA : Zaposleni
	{
		private int testovaDnevno;

		public QA() : base()
		{
			testovaDnevno = 0;
		}

		public QA(string ime, string prezime, double plata, int brTestova)
			: base(ime, prezime, plata)
		{
			testovaDnevno = brTestova;
		}

		public override string ToString()
		{
			StringBuilder builder = new StringBuilder();
			builder.Append(base.ToString());
			builder.Append(Bonus() + " ");
			builder.Append(testovaDnevno);
			return builder.ToString();
		}

		public override int Bonus()
		{
			return testovaDnevno > 10 ? 10 : 5;
		}
	}
}
