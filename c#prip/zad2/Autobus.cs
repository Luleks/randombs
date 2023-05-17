using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
	internal class Autobus : Vozilo
	{
		private readonly static int mesta = 5;
		private int brPutnika;

		public Autobus() : base()
		{
			brPutnika = 0;
			brMesta = mesta;
		}
		public Autobus(string oznaka, string proizvodjac, string model, int brPutnika)
			: base(oznaka, proizvodjac, model, Autobus.mesta)
		{
			brPutnika = 0;
		}
		public override void CitajBin(BinaryReader br)
		{
			base.CitajBin(br);
			brPutnika = br.ReadInt32();
		}

		public override void PisiBin(BinaryWriter bw)
		{
			bw.Write("Autobus");
			base.PisiBin(bw);
			bw.Write(brPutnika);
		}
	}
}
