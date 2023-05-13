using Podaci;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ooprLab4
{
    public partial class FormGlavna : Form
    {
        public FormGlavna()
        {
            InitializeComponent();
            dgwLista.AutoGenerateColumns = false;
        }
        #region EventHandling
        private void tmrVreme_Tick(object sender, EventArgs e)
        {
            String tacno_vreme = DateTime.Now.ToString("HH:mm:ss dd.MM.yyyy.");
            lblTime.Text = tacno_vreme;
        }

        private void FormGlavna_Load(object sender, EventArgs e)
        {
            tmrVreme.Enabled = true;
            cbxSort.SelectedIndex = 0;
        }

        private void btnDodaj_Click(object sender, EventArgs e)
        {
            var formaVozac = new FormVozac();
            DialogResult dlg = formaVozac.ShowDialog();
            if (dlg == DialogResult.OK)
            {
                dgwLista.DataSource = Vozaci.Instance.ListaVozaca.ToList();
            }
        }

        private void FormGlavna_FormClosing(object sender, FormClosingEventArgs e)
        {
            DialogResult dr = MessageBox.Show("Zatvori prozor?", "Pitanje",
                                MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (dr == DialogResult.No)
            {
                e.Cancel = true;
            }
        }

        private void btnObrisi_Click(object sender, EventArgs e)
        {
            if (dgwLista.Rows.Count == 0)
            {
                MessageBox.Show("Lista vozaca je prazna.", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }
            if (dgwLista.SelectedRows.Count == 0)
            {
                MessageBox.Show("Nije izabrana zabrana.", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }
            int selectedIndex = dgwLista.SelectedRows[0].Index;
            Vozaci.Instance.obrisiVozaca(Int32.Parse(dgwLista.Rows[selectedIndex].Cells[2].Value.ToString()));
            MessageBox.Show("Vozac uspesno obrisan.", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
            dgwLista.DataSource = Vozaci.Instance.ListaVozaca.ToList();
            return;
        }

        private void btnIzmeni_Click(object sender, EventArgs e)
        {
            if (dgwLista.Rows.Count == 0)
            {
                MessageBox.Show("Lista vozaca je prazna", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }
            int selectedIndex = dgwLista.SelectedRows[0].Index;
            if (selectedIndex == -1)
            {
                MessageBox.Show("Potrebno je izabrati vozaca", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }
            int id = Int32.Parse(dgwLista.Rows[selectedIndex].Cells[2].Value.ToString());
            var formaVozac = new FormVozac(Vozaci.Instance.getVozac(id));
            DialogResult dlg = formaVozac.ShowDialog();
            if (dlg == DialogResult.OK)
            {
                dgwLista.DataSource = Vozaci.Instance.ListaVozaca.ToList();
            }
        }

        private void cbxSort_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (cbxSort.SelectedIndex == 1)
                Vozaci.Instance.SortType = new Vozaci.SortTypeDelegate(Vozac.CompareByName);
            else if (cbxSort.SelectedIndex == 0)
                Vozaci.Instance.SortType = new Vozaci.SortTypeDelegate(Vozac.CompareByID);
            else if (cbxSort.SelectedIndex == 2)
                Vozaci.Instance.SortType = new Vozaci.SortTypeDelegate(Vozac.CompareByLastName);
        }

        private void btnSort_Click(object sender, EventArgs e)
        {
            if (dgwLista.Rows.Count == 0)
            {
                MessageBox.Show("Lista vozaca je prazna.", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }
            Vozaci.Instance.Sort();
            MessageBox.Show("Lista je uspesno sortirana", "Obavestenje",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
            dgwLista.DataSource = Vozaci.Instance.ListaVozaca.ToList();
        }
#endregion
    }
}
