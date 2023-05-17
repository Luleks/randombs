using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
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

		public abstract double Bonus
		{
			get;
		}
		public virtual string Tekst
		{
			get { return $"{ime} {prezime} {plata}"; }
		}

		public virtual void pisiBin(BinaryWriter bw)
		{
			bw.Write(ime);
			bw.Write(prezime);
			bw.Write(plata);
		}

		public virtual void citajBin(BinaryReader br)
		{
			ime = br.ReadString();
			prezime = br.ReadString();
			plata = br.ReadDouble();
		}
	}
}
