using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.Xml;
using System.IO;

namespace Game
{
    [Serializable]
    public class Polje
    {
        private Settings settingsSet;
        private OsnovniObjekat[][] matrica;
        private int seconds;

        public int Seconds
        {
            get { return seconds; }
            set { seconds = value; }
        }

        public Settings SettingsSet
        {
            get { return settingsSet; }
            set { settingsSet = value; }
        }

        public OsnovniObjekat[][] Matrica
        {
            get { return matrica; }
            set { matrica =  value; }
        }

		public OsnovniObjekat this[int i, int j]
        {
            get { return matrica[i][j]; }
        }


		private int DaLiJeMina(int i, int j)
        {
            if (i < 0 || i >= settingsSet.BrPolja || j < 0 || j >= settingsSet.BrPolja)
                return 0;
            return matrica[i][j].Mina;
        }

        public Polje()
        {
            settingsSet = new Settings();
            GenerateNewTable();
            seconds = 0;
        }

        public Polje(Settings set)
        {
            settingsSet = set;
            GenerateNewTable();
            seconds = 0;
        }

        public void SaveBoardConfig(string filename)
        {
			using (XmlTextWriter tw = new XmlTextWriter(filename, Encoding.ASCII))
			{
				tw.Formatting = Formatting.Indented;
				XmlSerializer sr = new XmlSerializer(typeof(OsnovniObjekat[][]), new Type[] { typeof(NeotkrivenoPolje),
					typeof(PoljeSaBombom), typeof(PoljeSaBrojem), typeof(PraznoPolje) });

				sr.Serialize(tw, matrica);
			}
		}
        public void GenerateNewTable()
        {
            int dim = settingsSet.BrPolja;
            int brMina = settingsSet.BrMina;

            matrica = new OsnovniObjekat[dim][];
            for (int i = 0; i < dim; i++)
                matrica[i] = new OsnovniObjekat[dim];
            for (int i = 0; i < dim; i++)
                for (int j = 0; j < dim; j++)
                    matrica[i][j] = new NeotkrivenoPolje();

            Dictionary<Tuple<int, int>, bool> bombs = new Dictionary<Tuple<int, int>, bool>();
            Random random = new Random();
            while (bombs.Count != brMina)
            {
                int i = random.Next(dim - 1);
                int j = random.Next(dim - 1);
                if (!bombs.ContainsKey(new Tuple<int, int>(i, j))) {
                    bombs.Add(new Tuple<int, int>(i, j), true);
                    matrica[i][j].Oznaka = 'E';
                    matrica[i][j].Mina = 1;
                }
            }

            for (int i = 0; i < dim; i++)
            {
                for (int j = 0; j < dim; j++)
                {
                    int okolneMine = 0;
					okolneMine += DaLiJeMina(i - 1, j - 1) + DaLiJeMina(i - 1, j) + DaLiJeMina(i - 1, j + 1);
					okolneMine += DaLiJeMina(i, j - 1) + DaLiJeMina(i, j + 1);
					okolneMine += DaLiJeMina(i + 1, j - 1) + DaLiJeMina(i + 1, j) + DaLiJeMina(i + 1, j + 1);

                    matrica[i][j].BrOkolnihMina = okolneMine;
				}
            }
            SaveBoardConfig($"{DateTime.Now.ToString("dd.MM.yyyy. hh_mm_ss")}.xml");
        }

        public static Polje Load(string filename)
        {
			using (StreamReader sr = new StreamReader(filename, Encoding.ASCII))
			{
				XmlSerializer xsr = new XmlSerializer(typeof(Polje), new Type[] { typeof(NeotkrivenoPolje),
					typeof(PoljeSaBombom), typeof(PoljeSaBrojem), typeof(PraznoPolje) });
				Polje polje = (Polje)xsr.Deserialize(sr);

				return polje;
			}
		}

        public void Save(string filename)
        {
            using (XmlTextWriter tw = new XmlTextWriter(filename, Encoding.ASCII))
            {
                tw.Formatting = Formatting.Indented;
                XmlSerializer sr = new XmlSerializer(typeof(Polje), new Type[] { typeof(NeotkrivenoPolje),
                    typeof(PoljeSaBombom), typeof(PoljeSaBrojem), typeof(PraznoPolje) });

				sr.Serialize(tw, this);
			}
		}

        public void OtvarajPolja(int i, int j)
        {
			if (i < 0 || j < 0 || i >= settingsSet.BrPolja || j >= settingsSet.BrPolja)
			{
                return;
			}
            OsnovniObjekat obj = matrica[i][j].operacijaKlik();
            if (obj is PoljeSaBombom)
                return;
            else if (obj is PoljeSaBrojem)
            {
                matrica[i][j] = obj;
            }
            else if (obj == null)
                return;
            else
            {
                matrica[i][j] = obj;
                OtvarajPolja(i - 1, j);
                OtvarajPolja(i + 1, j);
                OtvarajPolja(i, j - 1);
                OtvarajPolja(i, j + 1);
            }

		}

		public int GetNeotvrena()
		{
			int s = 0;
            for (int i = 0; i < settingsSet.BrPolja; i++)
            {
                for (int j = 0; j < settingsSet.BrPolja; j++)
                {
                    if (matrica[i][j] is NeotkrivenoPolje)
                        s += 1;
                }
                    
            }
            return s;
		}

		public void OtvoriSve()
        {
            for(int i = 0; i < settingsSet.BrPolja; i++)
            {
                for (int j = 0; j < settingsSet.BrPolja; j++)
                {
                    if (matrica[i][j] is NeotkrivenoPolje)
                        matrica[i][j] = matrica[i][j].operacijaKlik();
                }
            }
        }

        public int KliknutoPolje(int i, int j)
        {
            if (matrica[i][j] is NeotkrivenoPolje)
            {
                OsnovniObjekat otvoreni = matrica[i][j].operacijaKlik();
                if (otvoreni is PoljeSaBombom)
                {
                    matrica[i][j] = otvoreni;
                    return 2;
                }
                else if (otvoreni is PoljeSaBrojem)
                {
                    matrica[i][j] = otvoreni;
                    return 1;
                }
                else
                {
                    OtvarajPolja(i, j);
                    return 1;

                }
            }
            return 0;
        }

    }
}
