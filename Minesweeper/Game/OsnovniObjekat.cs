using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.IO;
using System.Xml.Serialization;

namespace Game
{
	[Serializable]
	public abstract class OsnovniObjekat
	{
		protected int[] rgbButtonColor;
		protected int mina;
		protected int brOkolnihMina;
		protected char oznaka;
		protected bool zastava;

		#region Properties
		public int[] RGBButtonColor
		{
			get { return rgbButtonColor; }
			set { rgbButtonColor = value; }
		}

		public int Mina
		{
			get { return mina; }
			set { mina = value; }
		}

		public int BrOkolnihMina
		{
			get { return brOkolnihMina; }
			set { brOkolnihMina = value; }
		}

		public char Oznaka
		{
			get { return oznaka; }
			set { oznaka = value; }
		}

		public bool Zastava
		{
			get { return zastava; }
			set { zastava = value; }
		}
		#endregion

		public OsnovniObjekat()
		{
			brOkolnihMina = 0;
			mina = 0;
			rgbButtonColor = null;
			oznaka = '0';
			zastava = false;
		}

		public OsnovniObjekat(int mina, int brOkolnihMina, int[] color, char oznaka)
		{
			this.mina = mina;
			this.brOkolnihMina = brOkolnihMina;
			rgbButtonColor = color;
			this.oznaka = oznaka;
			zastava = false;
		}

		public abstract OsnovniObjekat operacijaKlik();
		public abstract OsnovniObjekat operacijaZastava();
	}
}
