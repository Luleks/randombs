using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Grupa2
{
	internal class Auto : Vozilo
	{
		readonly private static int brMesta = 1;

		public Auto() : base() { }

		public Auto(string registarskaOznaka, string proizvodjac, string model)
			: base(registarskaOznaka, proizvodjac, model, brMesta)
		{

		}

		public override string ToString()
		{
			StringBuilder sb = new StringBuilder();

			sb.Append("Auto ");
			sb.Append(base.ToString());
			sb.Append("\n");

			return sb.ToString();
		}
	}
}
