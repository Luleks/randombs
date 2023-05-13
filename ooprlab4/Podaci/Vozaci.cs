using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Podaci
{
    public class Vozaci
    {
        private List<Vozac> vozaci;

        public delegate int SortTypeDelegate(Vozac a, Vozac b);
        public SortTypeDelegate SortType { get; set; }

        #region Singleton
        private static Vozaci _instance = null;

        public static Vozaci Instance
        {
            get
            {
                if (_instance == null)
                    _instance = new Vozaci();
                return _instance;
            }
        }
        #endregion

        #region Constructors
        public List<Vozac> ListaVozaca
        {
            get { return vozaci; }
        }

        public Vozaci()
        {
            vozaci = new List<Vozac>();
        }
        #endregion

        #region Methods
        public void Sort()
        {
            vozaci.Sort(new Comparison<Vozac>(Vozaci.Instance.SortType));
        }
        public bool postojiVozacUListi(int id)
        {
            foreach(Vozac v in vozaci) 
            {
                if (v.DozvolaID == id)
                    return true;
            }
            return false;
        }

        public bool dodajVozaca(Vozac v)
        {
            if (postojiVozacUListi(v.DozvolaID))
                return false;
            vozaci.Add(v);
            return true;
        }

        public Vozac getVozac(int id)
        {
            foreach (Vozac v in vozaci)
            {
                if (v.DozvolaID == id)
                    return v;
            }
            return null;
        }

        public bool izmeniVozaca(Vozac v)
        {
            Vozac vozac = getVozac(v.DozvolaID);
            if (vozac == null)
                return false;
            vozac.Ime = v.Ime;
            vozac.Prezime = v.Prezime;
            vozac.MestoIzdavanja = v.MestoIzdavanja;
            vozac.Zabrane = v.Zabrane;
            vozac.Kategorije = v.Kategorije;
            vozac.DatRodj = v.DatRodj;
            vozac.DozvolaOd = v.DozvolaOd;
            vozac.DozvolaDo = v.DozvolaDo;
            vozac.Pol = v.Pol;
            vozac.Path = v.Path;
            return true;
        }

        public bool obrisiVozaca(int id)
        {
            Vozac v = getVozac(id);
            if (v == null) return false;
            vozaci.Remove(v);
            return true;
        }
        #endregion
    }
}
