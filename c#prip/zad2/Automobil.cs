using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
	internal class Automobil : Vozilo
	{
		private readonly static int mesta = 1;

		public Automobil() : base() { brMesta = mesta; }
		public Automobil(string oznaka, string proizvodjac, string model)
			: base(oznaka, proizvodjac, model, Automobil.mesta)
		{

		}

		public override void CitajBin(BinaryReader br)
		{
			base.CitajBin(br);
		}

		public override void PisiBin(BinaryWriter bw)
		{
			bw.Write("Automobil");
			base.PisiBin(bw);
		}
	}
}
