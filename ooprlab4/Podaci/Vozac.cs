using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Podaci
{
    public class Vozac
    {
        #region Attributes
        private String _ime;
        private String _prezime;
        private DateTime _datRodj;
        private DateTime _dozvolaOd;
        private DateTime _dozvolaDo;
        private int _dozvolaID;
        private String _mestoIzdavanja;
        private char _pol;
        private String _slikaPath;
        private List<Kategorija> _kategorije;
        private List<Zabrana> _zabrane;

        private List<String> _kola;
        #endregion

        #region Properties
        public List<String> Kola
        {
            get { return _kola; }
            set { _kola = value; }
        }
        public String Ime
        {
            get { return _ime; }
            set { _ime = value; }
        }

        public String Prezime
        {
            get { return _prezime; }
            set { _prezime = value; }
        }

        public DateTime DatRodj
        {
            get { return _datRodj; } 
            set { _datRodj = value; }
        }

        public DateTime DozvolaOd
        {
            get { return _dozvolaOd; }
            set { _dozvolaDo = value; }
        }

        public DateTime DozvolaDo
        {
            get { return _dozvolaDo; }
            set { _dozvolaDo = value; }
        }

        public int DozvolaID
        {
            get { return _dozvolaID; }
            set { _dozvolaID = value; }
        }

        public String MestoIzdavanja
        {
            get { return _mestoIzdavanja; }
            set { _mestoIzdavanja = value; }
        }

        public char Pol
        {
            get { return _pol; }
            set { _pol = value; }
        }

        public String Path
        {
            get { return _slikaPath; }
            set { _slikaPath = value; }
        }

        public List<Kategorija> Kategorije
        {
            get { return _kategorije; }
            set { _kategorije = value; }
        }

        public List<Zabrana> Zabrane
        {
            get { return _zabrane; }
            set { _zabrane = value; }
        }
        #endregion

        #region Constructors
        public Vozac()
        {
            _ime = _prezime = _mestoIzdavanja = _slikaPath = "";
            _dozvolaID = 0;
            _pol = 'M';
            _datRodj = _dozvolaOd = _dozvolaDo = DateTime.Now;
            _kategorije = new List<Kategorija>();
            _zabrane = new List<Zabrana>();
            _kola = new List<String>();
        }

        public Vozac(String ime, String prezime, DateTime datRodj, DateTime dozvolaOd,
            DateTime dozvolaDo, int ID, String mesto, char p, String path,
            List<Kategorija> kategorije, List<Zabrana> zabrane)
        {
            _ime = ime;
            _prezime = prezime;
            _datRodj = datRodj;
            _dozvolaOd = dozvolaOd;
            _dozvolaDo = dozvolaDo;
            _dozvolaID = ID;
            _mestoIzdavanja = mesto;
            _pol = p;
            _slikaPath = path;
            _kategorije = kategorije;
            _zabrane = zabrane;
            _kola = new List<String>();
        }

        public Vozac(String ime, String prezime, DateTime datRodj, DateTime dozvolaOd,
            DateTime dozvolaDo, int ID, String mesto, char p, String path)
        {
            _ime = ime;
            _prezime = prezime;
            _datRodj = datRodj;
            _dozvolaOd = dozvolaOd;
            _dozvolaDo = dozvolaDo;
            _dozvolaID = ID;
            _mestoIzdavanja = mesto;
            _pol = p;
            _slikaPath = path;
            _kola = new List<String>();
        }
        #endregion

        #region Methods

        public bool dodajKategoriju(Kategorija k)
        {
            foreach (var kat in _kategorije){
                if (kat.Tip == k.Tip && kat.DatumDo > k.DatumOd && kat.DatumOd < k.DatumOd)
                    return false;
            }
            _kategorije.Add(k);
            return true;
        }

        public bool dodajZabranu(Zabrana z)
        {
            foreach (var zab in _zabrane)
            {
                if (zab.Tip == z.Tip && zab.DatumDo > zab.DatumOd && zab.DatumOd < zab.DatumOd)
                    return false;
            }
            _zabrane.Add(z);
            return true;
        }

        public void obrisiKategoriju(String tip)
        {
            foreach (Kategorija k in _kategorije)
            {
                if (k.Tip == tip)
                {
                    _kategorije.Remove(k);
                    return;
                }
            }
        }
        public void obrisiZabranu(String tip)
        {
            foreach (Zabrana k in _zabrane)
            {
                if (k.Tip == tip)
                {
                    _zabrane.Remove(k);
                    return;
                }
            }
        }
        #endregion

        #region StaticCompareMethods
        public static int CompareByName(Vozac A, Vozac B)
        {
            return A.Ime.CompareTo(B.Ime);
        }

        public static int CompareByLastName(Vozac A, Vozac B)
        {
            return A.Prezime.CompareTo(B.Prezime);
        }

        public static int CompareByID(Vozac A, Vozac B)
        {
            return A.DozvolaID.CompareTo(B.DozvolaID);
        }
        #endregion
    }
}
