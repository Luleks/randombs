using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Game;

namespace Minesweeper
{
	public partial class FormSettings : Form
	{
		private Settings settings;

		public Settings set
		{
			get { return settings; }
		}
		public FormSettings()
		{
			InitializeComponent();
			settings = new Settings();
		}

		public FormSettings(Settings settings)
		{
			InitializeComponent();
			this.settings = settings;
		}


		private void loadToolStripMenuItem_Click(object sender, EventArgs e)
		{
			OpenFileDialog ofd = new OpenFileDialog();
			ofd.Filter = "XML Files (*.xml)|*.xml";

			if (ofd.ShowDialog() == DialogResult.OK)
			{
				settings = Settings.Load(ofd.FileName);
				nudBrMina.Value = settings.BrMina;
				nudBrPolja.Value = settings.BrPolja;
			}
		}

		private void saveToolStripMenuItem_Click(object sender, EventArgs e)
		{
			SaveFileDialog sfd = new SaveFileDialog();
			sfd.Filter = "XML Files (*.xml)|*.xml";

			if (sfd.ShowDialog() == DialogResult.OK)
			{
				settings.BrMina = (int)nudBrMina.Value;
				settings.BrPolja = (int)nudBrPolja.Value;
				settings.Save(sfd.FileName);
				Close();
			}
		}

		private void btnLoadBombImage_Click(object sender, EventArgs e)
		{
			OpenFileDialog ofd = new OpenFileDialog();
			ofd.Filter = "PNG Files (*.png)|*.png|JPEG Files (*.jpg, *.jpeg)|*.jpg;*.jpeg";

			if (ofd.ShowDialog() == DialogResult.OK)
			{
				string newPath = ofd.FileName;
				settings.BombImagePath = newPath;
			}
		}

		private void btnSacuvaj_Click(object sender, EventArgs e)
		{
			settings.BrMina = (int)nudBrMina.Value;
			settings.BrPolja = (int)nudBrPolja.Value;
			this.DialogResult = DialogResult.OK;
			Close();
		}

		private void btnOdustani_Click(object sender, EventArgs e)
		{
			this.Close();
		}
	}
}
