using Extensions;
using Podaci;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ooprLab4
{
    public partial class FormVozac : Form
    {
        #region Properties
        private bool exit;
        public Vozac vozac
        {
            get;
            set;
        }
        #endregion

        #region Constructors
        public FormVozac()
        {
            InitializeComponent();
            vozac = new Vozac();
            vozac.DozvolaID = -1;
            exit = true;
        }

        public FormVozac(Vozac v)
        {
            InitializeComponent();
            vozac = v;
            btnProsledi.Text = "Izmeni";
            txtID.Enabled = false;
            exit = true;
            ucitajPodatke();
        }
        #endregion

        #region Methods

        private bool validacija()
        {
            if (String.IsNullOrEmpty(txtIme.Text))
            {
                MessageBox.Show("Polje Ime ne sme biti prazno.",
                               "Obavestenje",
                               MessageBoxButtons.OK,
                               MessageBoxIcon.Information);
                return false;
            }
            if (String.IsNullOrEmpty(txtPrezime.Text))
            {
                MessageBox.Show("Polje Prezime ne sme biti prazno.",
                               "Obavestenje",
                               MessageBoxButtons.OK,
                               MessageBoxIcon.Information);
                return false;
            }
            if (String.IsNullOrEmpty(txtMesto.Text))
            {
                MessageBox.Show("Polje Mesto ne sme biti prazno.",
                               "Obavestenje",
                               MessageBoxButtons.OK,
                               MessageBoxIcon.Information);
                return false;
            }
            if (txtID.Text.Length == 0) 
            {
                MessageBox.Show("Polje ID ne sme biti prazno.",
                               "Obavestenje",
                               MessageBoxButtons.OK,
                               MessageBoxIcon.Information);
                return false;
            }
            if (DateTime.Now.Year - dtpDatRodj.Value.Year < 21)
            {
                MessageBox.Show("Vozac mora imati bar 21 godinu.",
                               "Obavestenje",
                               MessageBoxButtons.OK,
                               MessageBoxIcon.Information);
                return false;
            }
            if (dtpOd.Value > dtpDo.Value)
            {
                MessageBox.Show("Datum Od mora biti veci od datuma Do.", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                return false;
            }
            if (dgwKategorije.RowCount == 0)
            {
                MessageBox.Show("Potrbno je dodati bar jednu kategoriju.", "Obavestenje",
                                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                return false;
            }
            if (pbxSlika.Image == null)
            {
                MessageBox.Show("Potrebno je dodati sliku.", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                return false;
            }
            return true;
        }

        private void ucitajPodatke()
        {
            txtIme.Text = vozac.Ime;
            txtPrezime.Text = vozac.Prezime;
            txtMesto.Text = vozac.MestoIzdavanja;
            dtpDatRodj.Value = vozac.DatRodj;
            dtpOd.Value = vozac.DozvolaOd;
            dtpDo.Value = vozac.DozvolaDo;
            txtID.Text = vozac.DozvolaID.ToString();
            cbxPol.Text = vozac.Pol.ToString();
            dgwKategorije.DataSource = vozac.Kategorije;
            dgwZabrane.DataSource = vozac.Zabrane;
            pbxSlika.ImageLocation = vozac.Path;
            pbxSlika.Image = Image.FromFile(pbxSlika.ImageLocation);
        }

        private bool dodaj()
        {
            Vozac v = new Vozac(txtIme.Text, txtPrezime.Text, dtpDatRodj.Value, dtpOd.Value,
                dtpDo.Value, Int32.Parse(txtID.Text), txtMesto.Text, cbxPol.Text.ElementAt(0),
                pbxSlika.ImageLocation, vozac.Kategorije, vozac.Zabrane);
            v.Kola = vozac.Kola;
            return Vozaci.Instance.dodajVozaca(v);
        }

        private bool izmeni()
        {
            vozac.Ime = txtIme.Text;
            vozac.Prezime = txtPrezime.Text;
            vozac.MestoIzdavanja = txtMesto.Text;
            vozac.DozvolaOd = dtpOd.Value;
            vozac.DozvolaDo = dtpDo.Value;
            vozac.DozvolaID = Int32.Parse(txtID.Text);
            vozac.Pol = cbxPol.Text.ElementAt(0);
            vozac.Path = pbxSlika.ImageLocation;
            pbxSlika.Image = Image.FromFile(pbxSlika.ImageLocation);
            return Vozaci.Instance.izmeniVozaca(vozac);
        }

        #endregion

        #region EventHandling
        private void FormVozac_Load(object sender, EventArgs e)
        {
            cbxPol.SelectedIndex = 0;
            dgwKategorije.AutoGenerateColumns = false;
            dgwZabrane.AutoGenerateColumns = false;
        }

        private void txtIme_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsLetter(e.KeyChar) && !Char.IsControl(e.KeyChar))
                e.Handled = true;
        }

        private void txtPrezime_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsLetter(e.KeyChar) && !Char.IsControl(e.KeyChar))
                e.Handled = true;
        }

        private void txtID_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsDigit(e.KeyChar) && !Char.IsControl(e.KeyChar))
                e.Handled = true;
        }

        private void txtMesto_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsLetter(e.KeyChar) && !Char.IsControl(e.KeyChar))
                e.Handled = true;
        }

        private void txtIme_Leave(object sender, EventArgs e)
        {
            txtIme.Text = txtIme.Text.PostaviPrvoVelikoSlovo();
        }

        private void txtPrezime_Leave(object sender, EventArgs e)
        {
            txtPrezime.Text = txtPrezime.Text.PostaviPrvoVelikoSlovo();
        }

        private void txtMesto_Leave(object sender, EventArgs e)
        {
            txtMesto.Text = txtMesto.Text.PostaviPrvoVelikoSlovo();
        }
      
        private void btnDodajSliku_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png";
            
            if (ofd.ShowDialog() == DialogResult.OK)
            {
                pbxSlika.Image = Image.FromFile(ofd.FileName);
                pbxSlika.ImageLocation = ofd.FileName;
            }          
        }

        private void btnDodajKat_Click(object sender, EventArgs e)
        {
            String[] kategorije = new string[] {"AM", "A1", "A2", "A", "B1", "B",
            "BE", "C1", "C1E", "C", "CE", "D1", "D1E", "D", "DE", "F", "M" };
            var frmKategorija = new FormZabKat("Kategorija", kategorije);
            DialogResult dlg = frmKategorija.ShowDialog();
            if (dlg == DialogResult.OK)
            {
                vozac.dodajKategoriju(new Podaci.Kategorija(frmKategorija.kategorija,
                    frmKategorija.datumOd, frmKategorija.datumDo));
                dgwKategorije.DataSource = vozac.Kategorije.ToList();
            }
        }

        private void btnDodajZab_Click(object sender, EventArgs e)
        {
            String[] kategorije = new string[dgwKategorije.RowCount];
            for (int i = 0; i <  kategorije.Length; i++)
            {
                kategorije[i] = (string)dgwKategorije.Rows[i].Cells[0].Value;
            }
            
            var frmZabrana = new FormZabKat("Zabrana", kategorije);
            DialogResult dlg = frmZabrana.ShowDialog();
            if (dlg == DialogResult.OK)
            {
                vozac.dodajZabranu(new Podaci.Zabrana(frmZabrana.kategorija,
                     frmZabrana.datumOd, frmZabrana.datumDo));
                dgwZabrane.DataSource = vozac.Zabrane.ToList();
            }
        }

        private void btnObrisiKat_Click(object sender, EventArgs e)
        {
            if (dgwKategorije.SelectedRows.Count == 0)
            {
                MessageBox.Show("Nije izabrana kategorija.", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }
            int selectedIndex = dgwKategorije.SelectedRows[0].Index;
            vozac.obrisiKategoriju(dgwKategorije.Rows[selectedIndex].Cells[0].Value.ToString());
            MessageBox.Show("Kategorija uspesno obrisana.", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
            dgwKategorije.DataSource = vozac.Kategorije.ToList();
            return;
        }

        private void btnObrisiZab_Click(object sender, EventArgs e)
        {
            if (dgwZabrane.SelectedRows.Count == 0)
            {
                MessageBox.Show("Nije izabrana zabrana.", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }
            int selectedIndex = dgwZabrane.SelectedRows[0].Index;
            vozac.obrisiZabranu(dgwZabrane.Rows[selectedIndex].Cells[0].Value.ToString());
            MessageBox.Show("Zabrana uspesno obrisana.", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
            dgwZabrane.DataSource = vozac.Zabrane.ToList();
            return;
        }

        private void FormVozac_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (this.exit == true)
            {
                DialogResult = DialogResult.Cancel;
                DialogResult dr = MessageBox.Show("Zatvori prozor?", "Pitanje",
                MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (dr == DialogResult.No)
                {
                    e.Cancel = true;
                }
            }
            else
            {
                DialogResult = DialogResult.OK;
            }
        }
        private void btnZatvori_Click(object sender, EventArgs e)
        {
            exit = true;
            this.Close();
        }
        

        private void btnProsledi_Click(object sender, EventArgs e)
        {
            if (!validacija())
                return;

            if (vozac.DozvolaID == -1) 
            {
                if (!dodaj())
                {
                    MessageBox.Show("Neuspesno dodavanje. Pokusajte ponovo.",
                                    "Greska", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    txtIme.Focus();
                    return;
                }
                else
                {
                    MessageBox.Show("Vozac uspesno dodat.", "Obavestenje", 
                        MessageBoxButtons.OK, MessageBoxIcon.Information);
                    exit = false;
                    this.Close();
                }
            }
            else
            {
                if (!izmeni())
                {
                    MessageBox.Show("Neuspesna izmena. Pokusajte ponovo.",
                                    "Greska", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    txtIme.Focus();
                    return;
                }
                else
                {
                    MessageBox.Show("Vozac uspesno izmenjen", "Obavestenje",
                        MessageBoxButtons.OK, MessageBoxIcon.Information);
                    exit = false;
                    this.Close();
                }
            }
        }
        #endregion

        private void btnDodajKola_Click(object sender, EventArgs e)
        {
            if (String.IsNullOrEmpty(txtDodajAuto.Text))
            {
                MessageBox.Show("Potrbno je uneti naziv auta.", "Obavestenje",
                                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }
            vozac.Kola.Add(txtDodajAuto.Text);
            txtDodajAuto.Clear();
        }

        private void btnVidiKola_Click(object sender, EventArgs e)
        {
            var frm = new Form2();
            frm.listBox1.DataSource = vozac.Kola.ToList();
            frm.Show();
        }
    }
}
