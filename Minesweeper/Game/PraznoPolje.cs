using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Game
{
	[Serializable]
	[XmlInclude(typeof(PraznoPolje))]
	public class PraznoPolje : OsnovniObjekat
	{
		public PraznoPolje() : base() { }

		public PraznoPolje(int mina, int brOkolnihMina)
			: base(mina, brOkolnihMina, new int[3] { 150, 150, 150 }, 'P')
		{

		}

		public override OsnovniObjekat operacijaKlik()
		{
			return null;
		}

		public override OsnovniObjekat operacijaZastava()
		{
			return null;
		}

	}
}
