using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
	internal class WebStranica : Stavka
	{
		public WebStranica() : base() { }
		public WebStranica(string adresa, int godina)
			: base(adresa, godina) { }

		public override string Tekst
		{
			get { return $"WebStranica\n{naziv} {godina}"; }
		}
		public override string TekstZaUpis
		{
			get { return $"WebStranica\n{naziv}\n{godina}"; }
		}

		public override void CitajBin(StreamReader sr)
		{
			naziv = sr.ReadLine();
			godina = Int32.Parse(sr.ReadLine());
		}
	}
}
