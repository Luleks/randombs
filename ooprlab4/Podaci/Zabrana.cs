using Extensions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Podaci
{
    public class Zabrana
    {
        #region Attributes
        private String _tip;
        private DateTime _datumOd;
        private DateTime _datumDo;
        #endregion

        #region Properties
        public String Tip
        {
            get { return _tip; }
            set { _tip = value; }
        }

        public DateTime DatumOd
        {
            get { return _datumOd; }
            set { _datumOd = value; }
        }

        public DateTime DatumDo
        {
            get { return _datumDo; }
            set { _datumDo = value; }
        }
        public String DatumDoValue
        {
            get { return _datumDo.ToFormattedString(); }
        }

        public String DatumOdValue
        {
            get { return _datumOd.ToFormattedString(); }
        }
        #endregion

        #region Constructors
        public Zabrana()
        {
            _tip = "";
            _datumOd = _datumDo = DateTime.Now;
        }

        public Zabrana(String tip, DateTime datumOd, DateTime datumDo)
        {
            _tip = tip;
            _datumOd = datumOd;
            _datumDo = datumDo;
        }
        #endregion
    }
}
