using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
	internal abstract class Vozilo
	{
		protected string oznaka;
		protected string proizvodjac;
		protected string model;
		protected int brMesta;

		public Vozilo()
		{
			oznaka = proizvodjac = model = string.Empty;
			brMesta = 0;
		}

		public Vozilo(string oznaka, string proizvodjac, string model, int brMesta)
		{
			this.oznaka = oznaka;
			this.proizvodjac = proizvodjac;
			this.model = model;
			this.brMesta = brMesta;
		}

		public int BrMesta
		{
			get { return brMesta; }
		}

		public virtual void PisiBin(BinaryWriter bw)
		{
			bw.Write(oznaka);
			bw.Write(proizvodjac);
			bw.Write(model);
		}

		public virtual void CitajBin(BinaryReader br)
		{
			oznaka = br.ReadString();
			proizvodjac = br.ReadString();
			model = br.ReadString();
		}
	}
}
