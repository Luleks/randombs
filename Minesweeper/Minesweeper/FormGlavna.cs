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
	public partial class FormGlavna : Form
	{
		#region Attributes
		private int elapsedSeconds = 0;
		private Polje polje;
		private Button[,] buttons;
		private Settings settings;
		private readonly static int buttonSize = 30;
		private bool run = false;
		#endregion

		#region Constructors
		public FormGlavna()
		{
			InitializeComponent();
			settings = new Settings();
		}
		#endregion

		#region Methods
		private void GameChanged()
		{
			elapsedSeconds = 0;
			tmrTimer.Enabled = !tmrTimer.Enabled;
			lblVreme.Enabled = !lblVreme.Enabled;
			lblVreme.Visible = !lblVreme.Visible;
			lblTimer.Enabled = !lblTimer.Visible;
			lblTimer.Visible = !lblTimer.Visible;
			run = !run;
		}

		private void ChangeButtonSettings()
		{
			foreach (Button b in buttons)
			{
				b.Visible = !b.Visible;
				b.Enabled = !b.Enabled;
			}
		}

		private void RemoveButtons()
		{
			foreach (Button b in buttons)
			{
				this.Controls.Remove(b);
			}
		}

		private int RefreshButtons()
		{
			int open = 0;
			for (int i = 0; i < settings.BrPolja; i++)
			{
				for (int j = 0; j < settings.BrPolja; j++)
				{
					int[] color = polje[i, j].RGBButtonColor;
					if (polje[i, j] is PraznoPolje)
					{
						buttons[i, j].BackColor = Color.FromArgb(color[0], color[1], color[2]);
					}
					else if (polje[i, j] is PoljeSaBrojem)
					{
						buttons[i, j].BackColor = Color.FromArgb(color[0], color[1], color[2]);
						buttons[i, j].Text = polje[i, j].BrOkolnihMina.ToString();
						if (polje[i, j].BrOkolnihMina == 2)
							buttons[i, j].ForeColor = Color.Green;
						else if (polje[i, j].BrOkolnihMina == 3)
							buttons[i, j].ForeColor = Color.Red;
						else
							buttons[i, j].ForeColor = Color.Blue;
					}
					else if (polje[i, j] is PoljeSaBombom && !run)
					{
						buttons[i, j].Image = Image.FromFile(settings.BombImagePath);
						buttons[i, j].ForeColor = Color.Red;
					}
					else if (polje[i, j] is NeotkrivenoPolje && polje[i, j].Zastava)
						buttons[i, j].Image = Image.FromFile(settings.FlagImagePath);
				}
			}
			return open;
		}

		private void Init(bool initPolje = true)
		{
			if (initPolje)
				polje = new Polje(settings);
			buttons = new Button[settings.BrPolja, settings.BrPolja];
			int Y = 30 + (540 - settings.BrPolja * buttonSize) / 2;
			for (int i = 0; i < settings.BrPolja; i++)
			{
				int X = (540 - settings.BrPolja * buttonSize) / 2;
				for (int j = 0; j < settings.BrPolja; j++)
				{
					int[] color = polje[i, j].RGBButtonColor;
					Button b = new Button
					{
						Location = new Point(X, Y),
						Width = buttonSize,
						Height = buttonSize,
						BackColor = Color.FromArgb(color[0], color[1], color[2]),
						Name = (i * settings.BrPolja + j).ToString(),
						FlatStyle = FlatStyle.Flat,
						TabStop = false,
						Enabled = false,
						Visible = false
					};
					b.MouseDown += btn_LeftClick;
					X += buttonSize;
					this.Controls.Add(b);
					buttons[i, j] = b;
				}
				Y += buttonSize;
			}
		}

		#endregion

		#region EventHandling
		private void FormGlavna_Load(object sender, EventArgs e)
		{
			Init();
			tmrTimer.Enabled = true;
			GameChanged();
			label1.Focus();
		}
		private void tmrTimer_Tick(object sender, EventArgs e)
		{
			elapsedSeconds += 1;
			lblVreme.Text = elapsedSeconds.ToString();

		}

		private void lblVreme_TextChanged(object sender, EventArgs e)
		{
			lblVreme.Location = new Point(lblTimer.Location.X + (lblTimer.Width - lblVreme.Width) / 2,
				lblVreme.Location.Y);
		}

		private void startGameToolStripMenuItem_Click(object sender, EventArgs e)
		{
			startGameToolStripMenuItem.Text = startGameToolStripMenuItem.Text == "Start game" ? "End game" : "Start game";
			if (startGameToolStripMenuItem.Text == "Start game")
			{
				run = false;
				polje.OtvoriSve();
				RefreshButtons();
				tmrTimer.Enabled = false;
				GameEnd("Izgubili ste", "Nema dalje");
			}
			else
			{
				GameChanged();
				ChangeButtonSettings();
			}
		}

		private void settingsToolStripMenuItem_Click(object sender, EventArgs e)
		{
			if (tmrTimer.Enabled)
			{
				MessageBox.Show("Igra je u toku", "Obavestenje",
					MessageBoxButtons.OK, MessageBoxIcon.Information);
				return;
			}
			var SettingsForm = new FormSettings();
			if (SettingsForm.ShowDialog() == DialogResult.OK)
			{
				this.settings = SettingsForm.set;
				Init();
			}
		}

		private void GameEnd(string message, string title)
		{
			DialogResult dlg = MessageBox.Show(message, title, MessageBoxButtons.RetryCancel, MessageBoxIcon.Information);
			if (dlg == DialogResult.Retry)
			{
				RemoveButtons();
				Init();
				elapsedSeconds = 0;
				tmrTimer.Enabled = true;
				ChangeButtonSettings();
				label1.Focus();
				startGameToolStripMenuItem.Text = "End game";
			}
			else
			{
				RemoveButtons();
				Init();
				tmrTimer.Enabled = true;
				GameChanged();
				label1.Focus();
				startGameToolStripMenuItem.Text = "Start game";
			}
		}

		private void btn_LeftClick(object sender, EventArgs e)
		{
			if (((MouseEventArgs)e).Button == MouseButtons.Left)
			{
				label1.Focus();
				Button clicked = sender as Button;
				int position = Int32.Parse(clicked.Name);
				int i = position / settings.BrPolja;
				int j = position - i * settings.BrPolja;
				if (polje[i, j].Zastava)
					return;

				int res = polje.KliknutoPolje(i, j);
				if (res == 1) 
				{
					RefreshButtons();
					if (settings.BrMina == polje.GetNeotvrena())
					{
						GameEnd("Pobedili ste", "Ima dalje");
					}
				}
				else if (res == 2)
				{
					run = false;
					polje.OtvoriSve();
					RefreshButtons();
					tmrTimer.Enabled = false;
					GameEnd("Izgubili ste", "Nema dalje");
				}
			}
			else if (((MouseEventArgs)e).Button == MouseButtons.Right)
			{
				label1.Focus();
				Button clicked = sender as Button;
				int position = Int32.Parse(clicked.Name);
				int i = position / settings.BrPolja;
				int j = position - i * settings.BrPolja;

				if (polje[i, j] is NeotkrivenoPolje)
				{
					polje[i, j].Zastava = !polje[i, j].Zastava;
					if (buttons[i, j].Image is null)
						buttons[i, j].Image = Image.FromFile(settings.FlagImagePath);
					else
						buttons[i, j].Image = null;
				}
			}
		}
		#endregion

		private void newToolStripMenuItem_Click(object sender, EventArgs e)
		{
			if (!tmrTimer.Enabled)
			{
				MessageBox.Show("Partija nije u toku", "Obavestenje",
					MessageBoxButtons.OK, MessageBoxIcon.Information);
				return;
			}
			tmrTimer.Enabled = false;
			SaveFileDialog sfd = new SaveFileDialog();
			sfd.Filter = "XML Files (*.xml)|*.xml";

			if (sfd.ShowDialog() == DialogResult.OK)
			{
				polje.Seconds = elapsedSeconds;
				polje.Save(sfd.FileName);
			}
			tmrTimer.Enabled = true;
		}

		private void openToolStripMenuItem_Click(object sender, EventArgs e)
		{
			if (tmrTimer.Enabled)
			{
				MessageBox.Show("Partija je u toku", "Obavestenje",
					MessageBoxButtons.OK, MessageBoxIcon.Information);
				return;
			}
			OpenFileDialog ofd = new OpenFileDialog();
			ofd.Filter = "XML Files (*.xml)|*.xml";

			if (ofd.ShowDialog() == DialogResult.OK)
			{
				polje = Polje.Load(ofd.FileName);
				GameChanged();
				this.settings = polje.SettingsSet;
				this.elapsedSeconds = polje.Seconds;
				Init(false);
				ChangeButtonSettings();
				RefreshButtons();
				label1.Focus();
			}
		}
	}
}
