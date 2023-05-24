namespace Minesweeper
{
	partial class FormSettings
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
			this.lblBrPolja = new System.Windows.Forms.Label();
			this.lblBombImage = new System.Windows.Forms.Label();
			this.lblBrojMina = new System.Windows.Forms.Label();
			this.nudBrPolja = new System.Windows.Forms.NumericUpDown();
			this.nudBrMina = new System.Windows.Forms.NumericUpDown();
			this.btnLoadBombImage = new System.Windows.Forms.Button();
			this.menuStrip1 = new System.Windows.Forms.MenuStrip();
			this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.loadToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.btnSacuvaj = new System.Windows.Forms.Button();
			this.btnOdustani = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.nudBrPolja)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.nudBrMina)).BeginInit();
			this.menuStrip1.SuspendLayout();
			this.SuspendLayout();
			// 
			// lblBrPolja
			// 
			this.lblBrPolja.AutoSize = true;
			this.lblBrPolja.Font = new System.Drawing.Font("Comic Sans MS", 11F);
			this.lblBrPolja.Location = new System.Drawing.Point(31, 41);
			this.lblBrPolja.Name = "lblBrPolja";
			this.lblBrPolja.Size = new System.Drawing.Size(117, 20);
			this.lblBrPolja.TabIndex = 0;
			this.lblBrPolja.Text = "Dimenzija table";
			// 
			// lblBombImage
			// 
			this.lblBombImage.AutoSize = true;
			this.lblBombImage.Font = new System.Drawing.Font("Comic Sans MS", 11F);
			this.lblBombImage.Location = new System.Drawing.Point(59, 113);
			this.lblBombImage.Name = "lblBombImage";
			this.lblBombImage.Size = new System.Drawing.Size(89, 20);
			this.lblBombImage.TabIndex = 1;
			this.lblBombImage.Text = "Bomb image";
			// 
			// lblBrojMina
			// 
			this.lblBrojMina.AutoSize = true;
			this.lblBrojMina.Font = new System.Drawing.Font("Comic Sans MS", 11F);
			this.lblBrojMina.Location = new System.Drawing.Point(74, 78);
			this.lblBrojMina.Name = "lblBrojMina";
			this.lblBrojMina.Size = new System.Drawing.Size(74, 20);
			this.lblBrojMina.TabIndex = 2;
			this.lblBrojMina.Text = "Broj mina";
			// 
			// nudBrPolja
			// 
			this.nudBrPolja.Font = new System.Drawing.Font("Comic Sans MS", 11F);
			this.nudBrPolja.Location = new System.Drawing.Point(170, 39);
			this.nudBrPolja.Maximum = new decimal(new int[] {
            17,
            0,
            0,
            0});
			this.nudBrPolja.Minimum = new decimal(new int[] {
            9,
            0,
            0,
            0});
			this.nudBrPolja.Name = "nudBrPolja";
			this.nudBrPolja.Size = new System.Drawing.Size(120, 28);
			this.nudBrPolja.TabIndex = 3;
			this.nudBrPolja.Value = new decimal(new int[] {
            9,
            0,
            0,
            0});
			// 
			// nudBrMina
			// 
			this.nudBrMina.Font = new System.Drawing.Font("Comic Sans MS", 11F);
			this.nudBrMina.Location = new System.Drawing.Point(170, 74);
			this.nudBrMina.Maximum = new decimal(new int[] {
            30,
            0,
            0,
            0});
			this.nudBrMina.Minimum = new decimal(new int[] {
            10,
            0,
            0,
            0});
			this.nudBrMina.Name = "nudBrMina";
			this.nudBrMina.Size = new System.Drawing.Size(120, 28);
			this.nudBrMina.TabIndex = 4;
			this.nudBrMina.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
			// 
			// btnLoadBombImage
			// 
			this.btnLoadBombImage.Font = new System.Drawing.Font("Comic Sans MS", 10F);
			this.btnLoadBombImage.Location = new System.Drawing.Point(170, 109);
			this.btnLoadBombImage.Name = "btnLoadBombImage";
			this.btnLoadBombImage.Size = new System.Drawing.Size(120, 28);
			this.btnLoadBombImage.TabIndex = 5;
			this.btnLoadBombImage.Text = "Open";
			this.btnLoadBombImage.UseVisualStyleBackColor = true;
			this.btnLoadBombImage.Click += new System.EventHandler(this.btnLoadBombImage_Click);
			// 
			// menuStrip1
			// 
			this.menuStrip1.Font = new System.Drawing.Font("Comic Sans MS", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.saveToolStripMenuItem,
            this.loadToolStripMenuItem});
			this.menuStrip1.Location = new System.Drawing.Point(0, 0);
			this.menuStrip1.Name = "menuStrip1";
			this.menuStrip1.Size = new System.Drawing.Size(334, 26);
			this.menuStrip1.TabIndex = 6;
			this.menuStrip1.Text = "menuStrip1";
			// 
			// saveToolStripMenuItem
			// 
			this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
			this.saveToolStripMenuItem.Size = new System.Drawing.Size(49, 22);
			this.saveToolStripMenuItem.Text = "Save";
			this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
			// 
			// loadToolStripMenuItem
			// 
			this.loadToolStripMenuItem.Name = "loadToolStripMenuItem";
			this.loadToolStripMenuItem.Size = new System.Drawing.Size(49, 22);
			this.loadToolStripMenuItem.Text = "Load";
			this.loadToolStripMenuItem.Click += new System.EventHandler(this.loadToolStripMenuItem_Click);
			// 
			// btnSacuvaj
			// 
			this.btnSacuvaj.Font = new System.Drawing.Font("Comic Sans MS", 10F);
			this.btnSacuvaj.Location = new System.Drawing.Point(28, 143);
			this.btnSacuvaj.Name = "btnSacuvaj";
			this.btnSacuvaj.Size = new System.Drawing.Size(120, 28);
			this.btnSacuvaj.TabIndex = 8;
			this.btnSacuvaj.Text = "Primeni";
			this.btnSacuvaj.UseVisualStyleBackColor = true;
			this.btnSacuvaj.Click += new System.EventHandler(this.btnSacuvaj_Click);
			// 
			// btnOdustani
			// 
			this.btnOdustani.Font = new System.Drawing.Font("Comic Sans MS", 10F);
			this.btnOdustani.Location = new System.Drawing.Point(170, 143);
			this.btnOdustani.Name = "btnOdustani";
			this.btnOdustani.Size = new System.Drawing.Size(120, 28);
			this.btnOdustani.TabIndex = 9;
			this.btnOdustani.Text = "Odustani";
			this.btnOdustani.UseVisualStyleBackColor = true;
			this.btnOdustani.Click += new System.EventHandler(this.btnOdustani_Click);
			// 
			// FormSettings
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(334, 182);
			this.Controls.Add(this.btnOdustani);
			this.Controls.Add(this.btnSacuvaj);
			this.Controls.Add(this.btnLoadBombImage);
			this.Controls.Add(this.nudBrMina);
			this.Controls.Add(this.nudBrPolja);
			this.Controls.Add(this.lblBrojMina);
			this.Controls.Add(this.lblBombImage);
			this.Controls.Add(this.lblBrPolja);
			this.Controls.Add(this.menuStrip1);
			this.MainMenuStrip = this.menuStrip1;
			this.MaximizeBox = false;
			this.MinimizeBox = false;
			this.Name = "FormSettings";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Settings";
			((System.ComponentModel.ISupportInitialize)(this.nudBrPolja)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.nudBrMina)).EndInit();
			this.menuStrip1.ResumeLayout(false);
			this.menuStrip1.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Label lblBrPolja;
		private System.Windows.Forms.Label lblBombImage;
		private System.Windows.Forms.Label lblBrojMina;
		private System.Windows.Forms.NumericUpDown nudBrPolja;
		private System.Windows.Forms.NumericUpDown nudBrMina;
		private System.Windows.Forms.Button btnLoadBombImage;
		private System.Windows.Forms.MenuStrip menuStrip1;
		private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem loadToolStripMenuItem;
		private System.Windows.Forms.Button btnSacuvaj;
		private System.Windows.Forms.Button btnOdustani;
	}
}