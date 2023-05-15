using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Grupa2
{
	internal class Autobus : Vozilo
	{
		readonly private static int brMesta = 5;
		private int brPutnika;

		public Autobus() : base() { brPutnika = 0; }

		public Autobus(string registarskaOznaka, string proizvodjac, string model, int brPutnika)
			: base(registarskaOznaka, proizvodjac, model, brMesta)
		{
			this.brPutnika = brPutnika;
		}

		public override string ToString()
		{
			StringBuilder sb = new StringBuilder();

			sb.Append("Autobus ");
			sb.Append(base.ToString());
			sb.Append(brPutnika + " ");
			sb.Append("\n");

			return sb.ToString();
		}
	}
}
