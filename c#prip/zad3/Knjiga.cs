using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
	internal class Knjiga : Stavka
	{
		private string mestoIzdavanja;
		private List<string> autori;
		
		public Knjiga() : base()
		{
			mestoIzdavanja = string.Empty;
			autori = new List<string>();
		}

		public Knjiga(string naziv, int godina, string mesto, params string[] autori)
			: base(naziv, godina)
		{
			mestoIzdavanja = mesto;
			this.autori = new List<string>(autori);
		}

		public override string Tekst
		{
			get { return $"Knjiga {naziv} {godina} {mestoIzdavanja} {string.Join(" ", autori)}"; }
		}

		public override string TekstZaUpis
		{
			get { return $"Knjiga\n{naziv}\n{godina}\n{mestoIzdavanja}\n{autori.Count}\n{string.Join("\n", autori)}"; }
		}
		public override void CitajBin(StreamReader sr)
		{
			naziv = sr.ReadLine();
			godina = Int32.Parse(sr.ReadLine());
			mestoIzdavanja = sr.ReadLine();
			int count = Int32.Parse(sr.ReadLine());
			for (int i = 0; i < count; i++)
				autori.Add(sr.ReadLine());
		}
	}
}
