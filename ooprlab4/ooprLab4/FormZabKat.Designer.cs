namespace ooprLab4
{
    partial class FormZabKat
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
            this.btnZatvori = new System.Windows.Forms.Button();
            this.btnProsledi = new System.Windows.Forms.Button();
            this.cbxKategorija = new System.Windows.Forms.ComboBox();
            this.dtpDo = new System.Windows.Forms.DateTimePicker();
            this.dtpOd = new System.Windows.Forms.DateTimePicker();
            this.lblDatDo = new System.Windows.Forms.Label();
            this.lblDatOd = new System.Windows.Forms.Label();
            this.lblZabrana = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btnZatvori
            // 
            this.btnZatvori.Location = new System.Drawing.Point(128, 123);
            this.btnZatvori.Name = "btnZatvori";
            this.btnZatvori.Size = new System.Drawing.Size(75, 23);
            this.btnZatvori.TabIndex = 33;
            this.btnZatvori.Text = "Zatvori";
            this.btnZatvori.UseVisualStyleBackColor = true;
            this.btnZatvori.Click += new System.EventHandler(this.btnZatvori_Click);
            // 
            // btnProsledi
            // 
            this.btnProsledi.Location = new System.Drawing.Point(47, 123);
            this.btnProsledi.Name = "btnProsledi";
            this.btnProsledi.Size = new System.Drawing.Size(75, 23);
            this.btnProsledi.TabIndex = 32;
            this.btnProsledi.Text = "Prosledi";
            this.btnProsledi.UseVisualStyleBackColor = true;
            this.btnProsledi.Click += new System.EventHandler(this.btnProsledi_Click);
            // 
            // cbxKategorija
            // 
            this.cbxKategorija.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxKategorija.FormattingEnabled = true;
            this.cbxKategorija.Location = new System.Drawing.Point(94, 20);
            this.cbxKategorija.Name = "cbxKategorija";
            this.cbxKategorija.Size = new System.Drawing.Size(109, 21);
            this.cbxKategorija.TabIndex = 31;
            // 
            // dtpDo
            // 
            this.dtpDo.CustomFormat = "dd.MM.yyyy";
            this.dtpDo.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpDo.Location = new System.Drawing.Point(94, 84);
            this.dtpDo.Name = "dtpDo";
            this.dtpDo.Size = new System.Drawing.Size(109, 20);
            this.dtpDo.TabIndex = 30;
            // 
            // dtpOd
            // 
            this.dtpOd.CustomFormat = "dd.MM.yyyy";
            this.dtpOd.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpOd.Location = new System.Drawing.Point(94, 52);
            this.dtpOd.Name = "dtpOd";
            this.dtpOd.Size = new System.Drawing.Size(109, 20);
            this.dtpOd.TabIndex = 29;
            // 
            // lblDatDo
            // 
            this.lblDatDo.AutoSize = true;
            this.lblDatDo.Location = new System.Drawing.Point(33, 88);
            this.lblDatDo.Name = "lblDatDo";
            this.lblDatDo.Size = new System.Drawing.Size(56, 13);
            this.lblDatDo.TabIndex = 28;
            this.lblDatDo.Text = "Datum do:";
            // 
            // lblDatOd
            // 
            this.lblDatOd.AutoSize = true;
            this.lblDatOd.Location = new System.Drawing.Point(33, 56);
            this.lblDatOd.Name = "lblDatOd";
            this.lblDatOd.Size = new System.Drawing.Size(56, 13);
            this.lblDatOd.TabIndex = 27;
            this.lblDatOd.Text = "Datum od:";
            // 
            // lblZabrana
            // 
            this.lblZabrana.AutoSize = true;
            this.lblZabrana.Location = new System.Drawing.Point(39, 24);
            this.lblZabrana.Name = "lblZabrana";
            this.lblZabrana.Size = new System.Drawing.Size(57, 13);
            this.lblZabrana.TabIndex = 26;
            this.lblZabrana.Text = "Kategorija:";
            // 
            // FormZabKat
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(278, 175);
            this.ControlBox = false;
            this.Controls.Add(this.btnZatvori);
            this.Controls.Add(this.btnProsledi);
            this.Controls.Add(this.cbxKategorija);
            this.Controls.Add(this.dtpDo);
            this.Controls.Add(this.dtpOd);
            this.Controls.Add(this.lblDatDo);
            this.Controls.Add(this.lblDatOd);
            this.Controls.Add(this.lblZabrana);
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(294, 191);
            this.MinimizeBox = false;
            this.MinimumSize = new System.Drawing.Size(294, 191);
            this.Name = "FormZabKat";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnZatvori;
        private System.Windows.Forms.Button btnProsledi;
        private System.Windows.Forms.ComboBox cbxKategorija;
        private System.Windows.Forms.DateTimePicker dtpDo;
        private System.Windows.Forms.DateTimePicker dtpOd;
        private System.Windows.Forms.Label lblDatDo;
        private System.Windows.Forms.Label lblDatOd;
        private System.Windows.Forms.Label lblZabrana;
    }
}