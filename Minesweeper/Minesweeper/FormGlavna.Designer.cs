namespace Minesweeper
{
	partial class FormGlavna
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.lblTimer = new System.Windows.Forms.Label();
			this.tmrTimer = new System.Windows.Forms.Timer(this.components);
			this.lblVreme = new System.Windows.Forms.Label();
			this.label1 = new System.Windows.Forms.Label();
			this.menuStrip1 = new System.Windows.Forms.MenuStrip();
			this.newToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.settingsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.startGameToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.menuStrip1.SuspendLayout();
			this.SuspendLayout();
			// 
			// lblTimer
			// 
			this.lblTimer.AutoSize = true;
			this.lblTimer.Font = new System.Drawing.Font("Comic Sans MS", 12F);
			this.lblTimer.Location = new System.Drawing.Point(546, 70);
			this.lblTimer.Name = "lblTimer";
			this.lblTimer.Size = new System.Drawing.Size(119, 23);
			this.lblTimer.TabIndex = 1;
			this.lblTimer.Text = "Proteklo vreme";
			// 
			// tmrTimer
			// 
			this.tmrTimer.Interval = 1000;
			this.tmrTimer.Tick += new System.EventHandler(this.tmrTimer_Tick);
			// 
			// lblVreme
			// 
			this.lblVreme.AutoSize = true;
			this.lblVreme.Font = new System.Drawing.Font("Comic Sans MS", 11F);
			this.lblVreme.Location = new System.Drawing.Point(596, 93);
			this.lblVreme.Name = "lblVreme";
			this.lblVreme.Size = new System.Drawing.Size(18, 20);
			this.lblVreme.TabIndex = 2;
			this.lblVreme.Text = "0";
			this.lblVreme.TextChanged += new System.EventHandler(this.lblVreme_TextChanged);
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(570, 27);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(0, 13);
			this.label1.TabIndex = 0;
			// 
			// menuStrip1
			// 
			this.menuStrip1.Font = new System.Drawing.Font("Comic Sans MS", 11F);
			this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newToolStripMenuItem,
            this.openToolStripMenuItem,
            this.settingsToolStripMenuItem,
            this.startGameToolStripMenuItem});
			this.menuStrip1.Location = new System.Drawing.Point(0, 0);
			this.menuStrip1.Name = "menuStrip1";
			this.menuStrip1.Size = new System.Drawing.Size(674, 28);
			this.menuStrip1.TabIndex = 7;
			this.menuStrip1.Text = "menuStrip1";
			// 
			// newToolStripMenuItem
			// 
			this.newToolStripMenuItem.Name = "newToolStripMenuItem";
			this.newToolStripMenuItem.Size = new System.Drawing.Size(54, 24);
			this.newToolStripMenuItem.Text = "Save";
			this.newToolStripMenuItem.Click += new System.EventHandler(this.newToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this.openToolStripMenuItem.Name = "openToolStripMenuItem";
			this.openToolStripMenuItem.Size = new System.Drawing.Size(57, 24);
			this.openToolStripMenuItem.Text = "Open";
			this.openToolStripMenuItem.Click += new System.EventHandler(this.openToolStripMenuItem_Click);
			// 
			// settingsToolStripMenuItem
			// 
			this.settingsToolStripMenuItem.Name = "settingsToolStripMenuItem";
			this.settingsToolStripMenuItem.Size = new System.Drawing.Size(80, 24);
			this.settingsToolStripMenuItem.Text = "Settings";
			this.settingsToolStripMenuItem.Click += new System.EventHandler(this.settingsToolStripMenuItem_Click);
			// 
			// startGameToolStripMenuItem
			// 
			this.startGameToolStripMenuItem.Name = "startGameToolStripMenuItem";
			this.startGameToolStripMenuItem.Size = new System.Drawing.Size(99, 24);
			this.startGameToolStripMenuItem.Text = "Start game";
			this.startGameToolStripMenuItem.Click += new System.EventHandler(this.startGameToolStripMenuItem_Click);
			// 
			// FormGlavna
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(674, 571);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.lblVreme);
			this.Controls.Add(this.lblTimer);
			this.Controls.Add(this.menuStrip1);
			this.MaximizeBox = false;
			this.MaximumSize = new System.Drawing.Size(690, 610);
			this.MinimizeBox = false;
			this.MinimumSize = new System.Drawing.Size(690, 610);
			this.Name = "FormGlavna";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Minesweeper";
			this.Load += new System.EventHandler(this.FormGlavna_Load);
			this.menuStrip1.ResumeLayout(false);
			this.menuStrip1.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Label lblTimer;
		private System.Windows.Forms.Timer tmrTimer;
		private System.Windows.Forms.Label lblVreme;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.MenuStrip menuStrip1;
		private System.Windows.Forms.ToolStripMenuItem newToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem settingsToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem startGameToolStripMenuItem;
	}
}

