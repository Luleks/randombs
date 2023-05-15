using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Grupa2
{
	internal class Kamion : Vozilo
	{
		private int nosivost;
		public Kamion() : base() { nosivost = 0; }

		public Kamion(string registarskaOznaka, string proizvodjac, string model, int brMesta, int nosivost)
			: base(registarskaOznaka, proizvodjac, model, brMesta) 
		{
			this.nosivost = nosivost;
		}

		public override string ToString()
		{
			StringBuilder sb = new StringBuilder();

			sb.Append("Kamion ");
			sb.Append(base.ToString());
			sb.Append(nosivost + " ");
			sb.Append("\n");

			return sb.ToString();
		}
	}
}
