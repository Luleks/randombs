using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Game
{
	[Serializable]
	[XmlInclude(typeof(PoljeSaBrojem))]
	public class PoljeSaBrojem : OsnovniObjekat
	{
		public PoljeSaBrojem() : base() { }

		public PoljeSaBrojem(int mina, int brOkolnihMina)
			: base(mina, brOkolnihMina, new int[3] { 150, 150, 150 }, 'B')
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
