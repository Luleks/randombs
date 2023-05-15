using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Grupa1
{
	internal abstract class Zaposleni
	{
		protected string ime;
		protected string prezime;
		protected double plata;

		public Zaposleni()
		{
			ime = prezime = string.Empty;
			plata = 0.0;
		}

		public Zaposleni(string ime, string prezime, double plata)
		{
			this.ime = ime;
			this.prezime = prezime;
			this.plata = plata;
		}

		public override string ToString()
		{
			return $"{ime} {prezime}, plata = {plata}, bonus = ";
		}
		public abstract int Bonus();
	}	
}
