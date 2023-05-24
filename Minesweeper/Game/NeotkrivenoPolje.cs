using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.Xml;

namespace Game
{
	[Serializable]
	[XmlInclude(typeof(NeotkrivenoPolje))]
	public class NeotkrivenoPolje : OsnovniObjekat
	{
		public NeotkrivenoPolje() : base(0, 0, new int[3] { 128, 128, 128 }, 'O') 
		{
			zastava = false;
		}

		public NeotkrivenoPolje(int mina, int brOkolnihMina, char oznaka)
			: base(mina, brOkolnihMina, new int[3] { 128, 128, 128 }, oznaka)
		{
			zastava = false;
		}

		public override OsnovniObjekat operacijaKlik()
		{

			if (mina == 1)
				return new PoljeSaBombom(mina, BrOkolnihMina);
			if (brOkolnihMina == 0)
				return new PraznoPolje(mina, BrOkolnihMina);
			else
				return new PoljeSaBrojem(mina, BrOkolnihMina);
		}

		public override OsnovniObjekat operacijaZastava()
		{
			zastava = true;
			return this;
		}
	}
}
