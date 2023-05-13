using DateTimeExtensions;
using Podaci;
using System.Text.RegularExpressions;
namespace Lab3
{
    public partial class FormGlavna : Form
    {
        public FormGlavna()
        {
            InitializeComponent();
            dtpDatRodj.Value = new DateTime(DateTime.Now.Year, DateTime.Now.Month,
                DateTime.Now.Day, 0, 0, 0, 0);
        }

        #region Methods
        private bool validacijaKontrola()
        {
            if (String.IsNullOrEmpty(txtIme.Text))
            {
                MessageBox.Show("Ime ne sme biti prazno polje", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                return false;
            }
            if (String.IsNullOrEmpty(txtPrezime.Text))
            {
                MessageBox.Show("Prezime ne sme biti prazno polje", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                return false;
            }
            if (String.IsNullOrEmpty(txtAdresa.Text))
            {
                MessageBox.Show("Adresa ne sme biti prazno polje", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                return false;
            }
            String numberFormat = @"^\+381 \d{2} \d{7}$";
            if (!Regex.IsMatch(txtTelefon.Text, numberFormat))
            {
                MessageBox.Show("Telefon mora biti u formatu +381 11 1234567", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                return false;
            }

            if (String.IsNullOrEmpty(txtIndex.Text))
            {
                MessageBox.Show("Indeks ne sme biti prazno polje", "Obavestenje",
                   MessageBoxButtons.OK, MessageBoxIcon.Information);
                return false;
            }
            return true;
        }

        private void ucitajListBox()
        {
            lbxListOsoba.DisplayMember = "zaPrikaz";
            lbxListOsoba.ValueMember = "zaUporedjivanje";

            lbxListOsoba.DataSource = ListaOsoba.Instance.ListOsobaValues.ToList();
            lbxListOsoba.ClearSelected();
        }

        private void uspesnoDodato()
        {
            txtIme.Focus();
            txtIme.Text = "";
            txtPrezime.Text = "";
            txtAdresa.Text = "";
            txtTelefon.Text = "";
            txtIndex.Text = "";
            dtpDatRodj.Value = new DateTime(DateTime.Now.Year, DateTime.Now.Month, DateTime.Now.Day, 0, 0, 0, 0);
            ListaOsoba.Instance.SortType = new ListaOsoba.SortTypeDelegate(Osoba.CompareByLastName);
        }

        #endregion

        #region EventHandling
        private void FormGlavna_Load(object sender, EventArgs e)
        {
            cbxSort.Items.Add("PO IMENU");
            cbxSort.Items.Add("PO PREZIMENU");
            cbxSort.Items.Add("PO DAT RODJ");
            cbxSort.SelectedIndex = 1;
        }

        private void FormGlavna_DoubleClick(object sender, EventArgs e)
        {
            var tacnoVreme = DateTime.Now.ToFormattedString();
            MessageBox.Show(tacnoVreme, "Tacno vreme",
                MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void btnZapamti_Click(object sender, EventArgs e)
        {
            if (!validacijaKontrola())
                return;
            String ucitano_ime = txtIme.Text.Trim().ToLower();
            String ime = ucitano_ime.Substring(0, 1).ToUpper() + ucitano_ime.Substring(1);
            String ucitano_prezime = txtPrezime.Text.Trim().ToLower();
            String prezime = ucitano_prezime.Substring(0, 1).ToUpper() + ucitano_prezime.Substring(1);
            String adresa = txtAdresa.Text.Trim();
            String telefon = txtTelefon.Text.Trim();
            String datRodj = dtpDatRodj.Text;
            String index = txtIndex.Text;

            if (lbxListOsoba.SelectedValue == null)
            {
                Osoba o = new Osoba(ime, prezime, telefon, adresa, datRodj, index);

                bool result = ListaOsoba.Instance.dodajOsobu(o);
                if (!result)
                {
                    MessageBox.Show("Osoba vec postoji u listi osoba", "Obavestenje",
                        MessageBoxButtons.OK, MessageBoxIcon.Information);
                    return;
                }
                MessageBox.Show("Osoba je uspesno dodata u listu osoba", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);

            }
            else
            {
                Osoba o = ListaOsoba.Instance.ListOsobaValues[lbxListOsoba.SelectedIndex];
                o.Adresa = adresa;
                o.Ime = ime;
                o.Prezime = prezime;
                o.Adresa = adresa;
                o.DatumRodjenja = datRodj;
                o.BrIndeksa = index;
                MessageBox.Show("Osoba je uspesno modifikovana", "Obavestenje",
                   MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            ucitajListBox();
            uspesnoDodato();
            lbxListOsoba.SelectedIndex = -1;
        }

        private void btnPonisti_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Polja su obrisana", "Obavestenje",
                MessageBoxButtons.OK, MessageBoxIcon.Information);

            txtIme.Focus();
            txtIme.Text = "";
            txtPrezime.Text = "";
            txtAdresa.Text = "";
            txtTelefon.Text = "";
            txtIndex.Text = "";
            txtIndex.Text = "";
            dtpDatRodj.Value = new DateTime(DateTime.Now.Year, DateTime.Now.Month, DateTime.Now.Day, 0, 0, 0, 0);
            lbxListOsoba.ClearSelected();
        }

        private void btnObrisiJednu_Click(object sender, EventArgs e)
        {
            if (lbxListOsoba.SelectedValue == null)
            {
                MessageBox.Show("Potrebno je izabrati osobu", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            else if (ListaOsoba.Instance.ListOsobaValues.Count == 0)
            {
                MessageBox.Show("Lista osoba je prazna", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            String zaObrisati = lbxListOsoba.SelectedValue as String;
            bool result = ListaOsoba.Instance.obrisiOsobu(zaObrisati);

            if (!result)
            {
                MessageBox.Show("Brisanje nije izvrseno", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            MessageBox.Show("Osoba uspesno obrisana", "Obavestenje",
                MessageBoxButtons.OK, MessageBoxIcon.Information);
            ucitajListBox();

            if (ListaOsoba.Instance.ListOsobaValues.Count == 0)
            {
                btnObrisiJednu.Enabled = false;
                btnSort.Enabled = false;
                btnObrisiSve.Enabled = false;
                cbxSort.Enabled = false;
            }
            lbxListOsoba.ClearSelected();
        }

        private void btnObrisiSve_Click(object sender, EventArgs e)
        {
            if (ListaOsoba.Instance.ListOsobaValues.Count == 0)
            {
                MessageBox.Show("Lista osoba je vec prazna", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }

            ListaOsoba.Instance.obrisiSve();

            MessageBox.Show("Lista osoba je obrisana", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);

            ucitajListBox();
            btnObrisiJednu.Enabled = false;
            btnSort.Enabled = false;
            btnObrisiSve.Enabled = false;
            cbxSort.Enabled = false;
        }

        private void FormGlavna_FormClosing(object sender, FormClosingEventArgs e)
        {
            DialogResult dr = MessageBox.Show("Zatvori aplikaciju", "Obavestenje",
                MessageBoxButtons.YesNo, MessageBoxIcon.Question);

            if (dr == DialogResult.No)
                e.Cancel = true;
        }

        private void txtIme_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsControl(e.KeyChar) && !Char.IsLetter(e.KeyChar))
                e.Handled = true;
        }

        private void txtPrezime_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsControl(e.KeyChar) && !Char.IsLetter(e.KeyChar))
                e.Handled = true;
        }

        private void txtTelefon_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((e.KeyChar == '+' && txtTelefon.Text.Length == 0) || e.KeyChar == ' ')
            {

            }
            else if (!Char.IsControl(e.KeyChar) && !Char.IsDigit(e.KeyChar))
                e.Handled = true;
        }
        private void txtTelefon_Leave(object sender, EventArgs e)
        {
            String numberFormat = @"^\+381 \d{2} \d{7}$";
            if (!Regex.IsMatch(txtTelefon.Text, numberFormat))
            {
                MessageBox.Show("Telefon mora biti u formatu +381 11 1234567", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void lbxListOsoba_DoubleClick(object sender, EventArgs e)
        {
            if (lbxListOsoba.SelectedValue == null)
                return;
            Osoba o = ListaOsoba.Instance.ListOsobaValues[lbxListOsoba.SelectedIndex];
            txtIme.Text = o.Ime;
            txtPrezime.Text = o.Prezime;
            txtTelefon.Text = o.BrojTelefona;
            txtAdresa.Text = o.Adresa;
            txtIndex.Text = o.BrIndeksa;
            String datumRodj = o.DatumRodjenja.Substring(3, 3) + o.DatumRodjenja.Substring(0, 3) +
                o.DatumRodjenja.Substring(6);
            dtpDatRodj.Text = datumRodj;
        }

        private void btnSort_Click(object sender, EventArgs e)
        {
            if (ListaOsoba.Instance.ListOsobaValues.Count == 0)
            {
                MessageBox.Show("Lista osoba je prazna", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            ListaOsoba.Instance.SortListValue();
            MessageBox.Show("Lista osoba je sortirana", "Obavestenje",
                MessageBoxButtons.OK, MessageBoxIcon.Information);
            ucitajListBox();
        }

        private void cbxSort_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (cbxSort.SelectedIndex == 1)
                ListaOsoba.Instance.SortType = new ListaOsoba.SortTypeDelegate(Osoba.CompareByName);
            else if (cbxSort.SelectedIndex == 0)
                ListaOsoba.Instance.SortType = new ListaOsoba.SortTypeDelegate(Osoba.CompareByLastName);
            else if (cbxSort.SelectedIndex == 2)
                ListaOsoba.Instance.SortType = new ListaOsoba.SortTypeDelegate(Osoba.CompareByBirthDay);
        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsControl(e.KeyChar) && !Char.IsDigit(e.KeyChar))
                e.Handled = true;
        }

        #endregion



    }
}