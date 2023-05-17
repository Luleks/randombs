using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
	internal class Kamion : Vozilo
	{
		private int nosivost;

		public Kamion() : base()
		{
			nosivost = 0;
		}

		public Kamion(string oznaka, string proizvodjac, string model, int mesta, int nosivost)
			: base(oznaka, proizvodjac, model, mesta)
		{
			this.nosivost = nosivost;
		}

		public override void CitajBin(BinaryReader br)
		{
			base.CitajBin(br);
			brMesta = br.ReadInt32();
			nosivost = br.ReadInt32();
		}

		public override void PisiBin(BinaryWriter bw)
		{
			bw.Write("Kamion");
			base.PisiBin(bw);
			bw.Write(brMesta);
			bw.Write(nosivost);
		}
	}
}
