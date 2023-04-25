namespace Podaci
{
    public class Osoba
    {
        #region Attributes
        String _ime;
        String _prezime;
        String _brojTelefona;
        String _adresa;
        String _datumRodjenja;
        #endregion

        #region Properties
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
        public String BrojTelefona
        {
            get { return _brojTelefona;}
            set { _brojTelefona = value; } 
        }
        public String DatumRodjenja
        {
            get { return _datumRodjenja; }
            set { _datumRodjenja = value; }
        }
        public String Adresa
        {
            get { return _adresa; }
            set { _adresa = value; }
        }

        public String zaPrikaz
        {
            get 
            {
                return Ime + " " + Prezime + " BrTel: " + BrojTelefona + " " +
                    "DatRodj: " + DatumRodjenja + " Adresa: " + Adresa;
            }
        }

        public String zaUporedjivanje
        {
            get
            {
                return Ime + Prezime + BrojTelefona + DatumRodjenja + Adresa;
            }
        }
        #endregion

        #region Constructors

        public Osoba()
        {
            _ime = "";
            _prezime = "";
            _brojTelefona = "";
            _adresa = "";
            _datumRodjenja = "";
        }

        public Osoba(String ime, String prezime, String brTel, String adresa, String datRodj)
        {
            _ime = ime;
            _prezime = prezime;
            _brojTelefona = brTel;
            _adresa = adresa;
            _datumRodjenja = datRodj;
        }
        #endregion

        #region Methods
        public static int CompareByName(Osoba a, Osoba b)
        {
            return a.Ime[0].CompareTo(b.Ime[0]);
        }

        public static int CompareByLastName(Osoba a, Osoba b)
        {
            return a.Prezime[0].CompareTo(b.Prezime[0]);
        }

        public static int CompareByBirthDay(Osoba a, Osoba b)
        {
            String[] rodjA = a.DatumRodjenja.Split(".");
            String[] rodjB = b.DatumRodjenja.Split(".");
            DateOnly date1 = new DateOnly(Int32.Parse(rodjA[2]), Int32.Parse(rodjA[1]), Int32.Parse(rodjA[0]));
            DateOnly date2 = new DateOnly(Int32.Parse(rodjB[2]), Int32.Parse(rodjB[1]), Int32.Parse(rodjB[0]));

            return date1.CompareTo(date2);
        }
        #endregion
    }
}