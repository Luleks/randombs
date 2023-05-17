using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
	internal class QA : Zaposleni
	{
		private int testovaDnevno;

		public QA() : base()
		{
			testovaDnevno = 0;
		}
		public QA(string ime, string prezime, double plata, int testovaDnevno)
			: base(ime, prezime, plata)
		{
			this.testovaDnevno = testovaDnevno;
		}

		public override string Tekst
		{
			get { return $"QA\n{base.Tekst} {testovaDnevno}"; }
		}

		public override double Bonus
		{
			get { return testovaDnevno > 10 ? 10 : 5; }
		}

		public override void pisiBin(BinaryWriter bw)
		{
			bw.Write("QA");
			base.pisiBin(bw);
			bw.Write(testovaDnevno);
		}

		public override void citajBin(BinaryReader br)
		{
			base.citajBin(br);
			testovaDnevno = br.ReadInt32();
		}

	}
}
