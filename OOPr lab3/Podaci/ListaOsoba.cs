using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Podaci
{
    public class ListaOsoba
    {
        public delegate int SortTypeDelegate(Osoba a, Osoba b);
        public SortTypeDelegate SortType { get; set; }

        #region Attributes
        private List<Osoba> _listaOsoba;
        #endregion

        #region Properties
        public List<Osoba> ListOsobaValues
        {
            get { return _listaOsoba; }
        }
        #endregion

        #region Constructors
        public ListaOsoba()
        {
            _listaOsoba = new List<Osoba>();
        }
        #endregion

        #region Methods
        public bool postojiOsobaUListi(Osoba o)
        {
            foreach (var v in _listaOsoba)
            {
                if (v.Ime == o.Ime && v.Prezime == o.Prezime && v.BrojTelefona == o.BrojTelefona
                    && v.DatumRodjenja == o.DatumRodjenja && v.Adresa == o.Adresa)
                    return true;
            }
            return false;
        }

        public bool dodajOsobu(Osoba o)
        {
            if (postojiOsobaUListi(o))
                return false;
            _listaOsoba.Insert(0, o);
            return true;
        }

        public bool obrisiOsobu(Osoba o)
        {
            if (!postojiOsobaUListi(o))
                return false;
            _listaOsoba.Remove(o);
            return true;
        }

        public bool obrisiOsobu(String atributi)
        {
            foreach (var osoba in _listaOsoba)
            {
                if (osoba.zaUporedjivanje == atributi)
                {
                    obrisiOsobu(osoba);
                    return true;
                }
            }
            return false;
        }

        public void obrisiSve()
        {
            while (ListOsobaValues.Count != 0)
            {
                _listaOsoba.RemoveAt(0);
            }
        }

        public void SortListValue()
        {
            _listaOsoba.Sort(new Comparison<Osoba>(ListaOsoba.Instance.SortType));
        }
        #endregion

        private static ListaOsoba _instance = null;

        public static ListaOsoba Instance
        {
            get
            {
                if (_instance == null)
                    _instance = new ListaOsoba();
                return _instance;
            }

        }
    }
}
