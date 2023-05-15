using System;
using System.Collections.Generic;
using System.Linq;
using System.Management.Instrumentation;
using System.Text;
using System.Threading.Tasks;

namespace Grupa2
{
	internal abstract class Vozilo
	{
		protected string registarskaOznaka;
		protected string proizvodjac;
		protected string model;
		protected int brojMesta;
		protected Parking<Vozilo> parking;

		public int BrojMesta
		{
			get { return brojMesta; }
		}

		public Vozilo()
		{
			registarskaOznaka = proizvodjac = model = string.Empty;
			brojMesta = 0;
			parking = null;
		}

		public Vozilo(string registarskaOznaka, string proizvodjac, string model, int brojMesta)
		{
			this.registarskaOznaka = registarskaOznaka;
			this.proizvodjac = proizvodjac;
			this.model = model;
			this.brojMesta = brojMesta;
			parking = null;
		}

		public void Parkiraj(Parking<Vozilo> p)
		{
			Isparkiraj();
			parking = p;
			p.Parkiraj(this, brojMesta);
		}

		public void Isparkiraj()
		{
			parking?.Isparkiraj(this);
			parking = null;
		}

		public override string ToString()
		{
			StringBuilder sb = new StringBuilder();

			sb.Append(registarskaOznaka + " ");
			sb.Append(proizvodjac + " ");
			sb.Append(model + " ");
			sb.Append(brojMesta + " ");

			return sb.ToString();
		}
	}
}
