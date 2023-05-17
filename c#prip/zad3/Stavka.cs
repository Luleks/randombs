using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
	internal abstract class Stavka
	{
		protected string naziv;
		protected int godina;

		public Stavka()
		{
			naziv = string.Empty;
			godina = 0;
		}

		public Stavka(string naziv, int godina)
		{
			this.naziv = naziv;
			this.godina = godina;
		}

		public int Godina
		{
			get { return godina; }
		}

		public abstract string Tekst
		{
			get;
		}

		public abstract string TekstZaUpis
		{
			get;
		}

		public void PisiBin(StreamWriter sw)
		{
			sw.WriteLine(TekstZaUpis);
		}
		public abstract void CitajBin(StreamReader sr);
	}
}
