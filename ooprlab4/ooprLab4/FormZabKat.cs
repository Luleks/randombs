using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ooprLab4
{
    public partial class FormZabKat : Form
    {
        #region Properties
        public String kategorija
        {
            get;
            set;
        }
        public DateTime datumOd
        {
            get;
            set;
        }
        public DateTime datumDo
        {
            get;
            set;
        }
        #endregion

        #region Constructors
        public FormZabKat()
        {
            InitializeComponent();
        }

        public FormZabKat(String naslov, String[] kategorije)
        {
            InitializeComponent();
            this.Text = naslov;
            foreach (String s in kategorije)
            {
                cbxKategorija.Items.Add(s);
            }
        }
        #endregion

        #region Methods
        private bool validacija()
        {
            if (cbxKategorija.SelectedIndex == -1)
            {
                MessageBox.Show("Potrebno je izabrati kategoriju.", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            if (dtpOd.Value > dtpDo.Value)
            {
                MessageBox.Show("Datum Od mora biti veci od datuma Do.", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            return true;
        }
        #endregion

        #region EventHandling

        private void btnZatvori_Click(object sender, EventArgs e)
        {
            DialogResult dr = MessageBox.Show("Zatvori prozor?", "Pitanje",
                    MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (dr == DialogResult.Yes)
            {

                this.Close();
                this.DialogResult = DialogResult.Cancel;
            }
        }
        private void btnProsledi_Click(object sender, EventArgs e)
        {
            if (!validacija())
                return;
            kategorija = cbxKategorija.Text;
            datumDo = dtpDo.Value;
            datumOd = dtpOd.Value;

            DialogResult dr = MessageBox.Show("Prosledi?", "Pitanje",
                    MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (dr == DialogResult.Yes)
            {
                this.Close();
                this.DialogResult = DialogResult.OK;
            }
        }
        #endregion
    }
}
