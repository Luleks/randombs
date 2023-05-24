using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Game
{
	[Serializable]
	[XmlInclude(typeof(PoljeSaBombom))]
	public class PoljeSaBombom : OsnovniObjekat
	{
		public PoljeSaBombom() : base() { }

		public PoljeSaBombom(int mina, int brOkolnihMina) 
			: base(mina, brOkolnihMina, new int[3] { 100, 100, 100 }, 'E')
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
