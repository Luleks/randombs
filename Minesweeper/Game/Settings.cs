using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Serialization;
using System.IO;

namespace Game
{
	[Serializable]
	public class Settings
	{
		private int brPolja;
		private int brMina;
		private string bombImagePath;
		private string flagImagePath;
		private string neotvorenoPoljePath;

		public int BrPolja
		{
			get { return brPolja; }
			set { brPolja = value; }
		}

		public int BrMina
		{
			get { return brMina; }
			set { brMina = value; }
		}

		public string BombImagePath
		{
			get { return bombImagePath; }
			set { bombImagePath = value; }
		}

		public string FlagImagePath
		{
			get { return flagImagePath; }
			set { flagImagePath = value; }
		}

		public string NeotvorenoPoljePath
		{
			get { return neotvorenoPoljePath; }
			set { neotvorenoPoljePath = value; }
		}

		public Settings()
		{
			brPolja = 9;
			brMina = 10;
			bombImagePath = @"C:\Users\Luka&Jana\Desktop\Minesweeper\Game\bombImages\bomb.png";
			flagImagePath = @"C:\Users\Luka&Jana\Desktop\Minesweeper\Game\flagImages\flag.png";
			neotvorenoPoljePath = @"C:\Users\Luka&Jana\Desktop\Minesweeper\Game\neotvorenoPoljeImg\neotvorenoPolje.png";
		}

		public void Save(string filename)
		{
			using (XmlTextWriter tw = new XmlTextWriter(filename, Encoding.ASCII))
			{
				tw.Formatting = Formatting.Indented;
				XmlSerializer sr = new XmlSerializer(typeof(Settings));

				sr.Serialize(tw, this);
			}
		}

		public static Settings Load(string filename)
		{
			using (StreamReader sr = new StreamReader(filename, Encoding.ASCII))
			{
				XmlSerializer xsr = new XmlSerializer(typeof(Settings));
				Settings loadedSettings = (Settings)xsr.Deserialize(sr);

				return loadedSettings;
			}
		}
	}
}
