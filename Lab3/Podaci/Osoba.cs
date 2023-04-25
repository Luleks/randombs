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
    }
}