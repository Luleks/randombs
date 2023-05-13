namespace ooprLab4
{
    partial class FormVozac
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormVozac));
            this.gbxOsnovno = new System.Windows.Forms.GroupBox();
            this.btnVidiKola = new System.Windows.Forms.Button();
            this.txtDodajAuto = new System.Windows.Forms.TextBox();
            this.btnDodajKola = new System.Windows.Forms.Button();
            this.btnDodajSliku = new System.Windows.Forms.Button();
            this.pbxSlika = new System.Windows.Forms.PictureBox();
            this.cbxPol = new System.Windows.Forms.ComboBox();
            this.lblPol = new System.Windows.Forms.Label();
            this.lblMesto = new System.Windows.Forms.Label();
            this.txtMesto = new System.Windows.Forms.TextBox();
            this.txtID = new System.Windows.Forms.TextBox();
            this.lblID = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.lblOd = new System.Windows.Forms.Label();
            this.dtpDo = new System.Windows.Forms.DateTimePicker();
            this.dtpOd = new System.Windows.Forms.DateTimePicker();
            this.dtpDatRodj = new System.Windows.Forms.DateTimePicker();
            this.txtPrezime = new System.Windows.Forms.TextBox();
            this.lblDatRodj = new System.Windows.Forms.Label();
            this.lblPrezime = new System.Windows.Forms.Label();
            this.txtIme = new System.Windows.Forms.TextBox();
            this.lblIme = new System.Windows.Forms.Label();
            this.gbxKategorija = new System.Windows.Forms.GroupBox();
            this.btnObrisiKat = new System.Windows.Forms.Button();
            this.btnDodajKat = new System.Windows.Forms.Button();
            this.dgwKategorije = new System.Windows.Forms.DataGridView();
            this.Kategorija = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.DatumOd = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.DatumDo = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.gbxZabrane = new System.Windows.Forms.GroupBox();
            this.btnObrisiZab = new System.Windows.Forms.Button();
            this.btnDodajZab = new System.Windows.Forms.Button();
            this.dgwZabrane = new System.Windows.Forms.DataGridView();
            this.ZabKategorija = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ZabranaOd = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ZabranaDo = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.btnProsledi = new System.Windows.Forms.Button();
            this.btnZatvori = new System.Windows.Forms.Button();
            this.gbxOsnovno.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbxSlika)).BeginInit();
            this.gbxKategorija.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgwKategorije)).BeginInit();
            this.gbxZabrane.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgwZabrane)).BeginInit();
            this.SuspendLayout();
            // 
            // gbxOsnovno
            // 
            this.gbxOsnovno.Controls.Add(this.btnVidiKola);
            this.gbxOsnovno.Controls.Add(this.txtDodajAuto);
            this.gbxOsnovno.Controls.Add(this.btnDodajKola);
            this.gbxOsnovno.Controls.Add(this.btnDodajSliku);
            this.gbxOsnovno.Controls.Add(this.pbxSlika);
            this.gbxOsnovno.Controls.Add(this.cbxPol);
            this.gbxOsnovno.Controls.Add(this.lblPol);
            this.gbxOsnovno.Controls.Add(this.lblMesto);
            this.gbxOsnovno.Controls.Add(this.txtMesto);
            this.gbxOsnovno.Controls.Add(this.txtID);
            this.gbxOsnovno.Controls.Add(this.lblID);
            this.gbxOsnovno.Controls.Add(this.label2);
            this.gbxOsnovno.Controls.Add(this.lblOd);
            this.gbxOsnovno.Controls.Add(this.dtpDo);
            this.gbxOsnovno.Controls.Add(this.dtpOd);
            this.gbxOsnovno.Controls.Add(this.dtpDatRodj);
            this.gbxOsnovno.Controls.Add(this.txtPrezime);
            this.gbxOsnovno.Controls.Add(this.lblDatRodj);
            this.gbxOsnovno.Controls.Add(this.lblPrezime);
            this.gbxOsnovno.Controls.Add(this.txtIme);
            this.gbxOsnovno.Controls.Add(this.lblIme);
            this.gbxOsnovno.Location = new System.Drawing.Point(10, 10);
            this.gbxOsnovno.Name = "gbxOsnovno";
            this.gbxOsnovno.Size = new System.Drawing.Size(412, 242);
            this.gbxOsnovno.TabIndex = 0;
            this.gbxOsnovno.TabStop = false;
            this.gbxOsnovno.Text = "Osnovni podaci";
            // 
            // btnVidiKola
            // 
            this.btnVidiKola.Location = new System.Drawing.Point(329, 182);
            this.btnVidiKola.Name = "btnVidiKola";
            this.btnVidiKola.Size = new System.Drawing.Size(54, 54);
            this.btnVidiKola.TabIndex = 20;
            this.btnVidiKola.Text = "Vidi Spisak Auta";
            this.btnVidiKola.UseVisualStyleBackColor = true;
            this.btnVidiKola.Click += new System.EventHandler(this.btnVidiKola_Click);
            // 
            // txtDodajAuto
            // 
            this.txtDodajAuto.Location = new System.Drawing.Point(274, 156);
            this.txtDodajAuto.MaxLength = 20;
            this.txtDodajAuto.Name = "txtDodajAuto";
            this.txtDodajAuto.Size = new System.Drawing.Size(109, 20);
            this.txtDodajAuto.TabIndex = 19;
            // 
            // btnDodajKola
            // 
            this.btnDodajKola.Location = new System.Drawing.Point(274, 182);
            this.btnDodajKola.Name = "btnDodajKola";
            this.btnDodajKola.Size = new System.Drawing.Size(54, 54);
            this.btnDodajKola.TabIndex = 18;
            this.btnDodajKola.Text = "Dodaj Auto";
            this.btnDodajKola.UseVisualStyleBackColor = true;
            this.btnDodajKola.Click += new System.EventHandler(this.btnDodajKola_Click);
            // 
            // btnDodajSliku
            // 
            this.btnDodajSliku.Location = new System.Drawing.Point(293, 125);
            this.btnDodajSliku.Name = "btnDodajSliku";
            this.btnDodajSliku.Size = new System.Drawing.Size(70, 25);
            this.btnDodajSliku.TabIndex = 16;
            this.btnDodajSliku.Text = "Dodaj sliku";
            this.btnDodajSliku.UseVisualStyleBackColor = true;
            this.btnDodajSliku.Click += new System.EventHandler(this.btnDodajSliku_Click);
            // 
            // pbxSlika
            // 
            this.pbxSlika.Location = new System.Drawing.Point(278, 19);
            this.pbxSlika.Name = "pbxSlika";
            this.pbxSlika.Size = new System.Drawing.Size(100, 100);
            this.pbxSlika.TabIndex = 1;
            this.pbxSlika.TabStop = false;
            // 
            // cbxPol
            // 
            this.cbxPol.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxPol.FormattingEnabled = true;
            this.cbxPol.Items.AddRange(new object[] {
            "M",
            "Ž"});
            this.cbxPol.Location = new System.Drawing.Point(138, 203);
            this.cbxPol.Name = "cbxPol";
            this.cbxPol.Size = new System.Drawing.Size(109, 21);
            this.cbxPol.TabIndex = 15;
            // 
            // lblPol
            // 
            this.lblPol.AutoSize = true;
            this.lblPol.Location = new System.Drawing.Point(107, 207);
            this.lblPol.Name = "lblPol";
            this.lblPol.Size = new System.Drawing.Size(25, 13);
            this.lblPol.TabIndex = 14;
            this.lblPol.Text = "Pol:";
            // 
            // lblMesto
            // 
            this.lblMesto.AutoSize = true;
            this.lblMesto.Location = new System.Drawing.Point(45, 181);
            this.lblMesto.Name = "lblMesto";
            this.lblMesto.Size = new System.Drawing.Size(87, 13);
            this.lblMesto.TabIndex = 13;
            this.lblMesto.Text = "Mesto izdavanja:";
            // 
            // txtMesto
            // 
            this.txtMesto.Location = new System.Drawing.Point(138, 177);
            this.txtMesto.MaxLength = 20;
            this.txtMesto.Name = "txtMesto";
            this.txtMesto.Size = new System.Drawing.Size(109, 20);
            this.txtMesto.TabIndex = 12;
            this.txtMesto.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtMesto_KeyPress);
            this.txtMesto.Leave += new System.EventHandler(this.txtMesto_Leave);
            // 
            // txtID
            // 
            this.txtID.Location = new System.Drawing.Point(138, 151);
            this.txtID.MaxLength = 9;
            this.txtID.Name = "txtID";
            this.txtID.Size = new System.Drawing.Size(109, 20);
            this.txtID.TabIndex = 11;
            this.txtID.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtID_KeyPress);
            // 
            // lblID
            // 
            this.lblID.AutoSize = true;
            this.lblID.Location = new System.Drawing.Point(25, 155);
            this.lblID.Name = "lblID";
            this.lblID.Size = new System.Drawing.Size(107, 13);
            this.lblID.TabIndex = 10;
            this.lblID.Text = "Br. vozacke dozvole:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(110, 129);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(22, 13);
            this.label2.TabIndex = 9;
            this.label2.Text = "do:";
            // 
            // lblOd
            // 
            this.lblOd.AutoSize = true;
            this.lblOd.Location = new System.Drawing.Point(29, 103);
            this.lblOd.Name = "lblOd";
            this.lblOd.Size = new System.Drawing.Size(103, 13);
            this.lblOd.TabIndex = 8;
            this.lblOd.Text = "Vazenje dozvole od:";
            // 
            // dtpDo
            // 
            this.dtpDo.CustomFormat = "dd.MM.yyyy";
            this.dtpDo.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpDo.Location = new System.Drawing.Point(138, 125);
            this.dtpDo.Name = "dtpDo";
            this.dtpDo.Size = new System.Drawing.Size(109, 20);
            this.dtpDo.TabIndex = 7;
            // 
            // dtpOd
            // 
            this.dtpOd.CustomFormat = "dd.MM.yyyy";
            this.dtpOd.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpOd.Location = new System.Drawing.Point(138, 99);
            this.dtpOd.Name = "dtpOd";
            this.dtpOd.Size = new System.Drawing.Size(109, 20);
            this.dtpOd.TabIndex = 6;
            // 
            // dtpDatRodj
            // 
            this.dtpDatRodj.CustomFormat = "dd.MM.yyyy";
            this.dtpDatRodj.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpDatRodj.Location = new System.Drawing.Point(138, 73);
            this.dtpDatRodj.Name = "dtpDatRodj";
            this.dtpDatRodj.Size = new System.Drawing.Size(109, 20);
            this.dtpDatRodj.TabIndex = 5;
            // 
            // txtPrezime
            // 
            this.txtPrezime.Location = new System.Drawing.Point(138, 47);
            this.txtPrezime.MaxLength = 20;
            this.txtPrezime.Name = "txtPrezime";
            this.txtPrezime.Size = new System.Drawing.Size(109, 20);
            this.txtPrezime.TabIndex = 4;
            this.txtPrezime.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtPrezime_KeyPress);
            this.txtPrezime.Leave += new System.EventHandler(this.txtPrezime_Leave);
            // 
            // lblDatRodj
            // 
            this.lblDatRodj.AutoSize = true;
            this.lblDatRodj.Location = new System.Drawing.Point(51, 77);
            this.lblDatRodj.Name = "lblDatRodj";
            this.lblDatRodj.Size = new System.Drawing.Size(81, 13);
            this.lblDatRodj.TabIndex = 3;
            this.lblDatRodj.Text = "Datum rodjenja:";
            // 
            // lblPrezime
            // 
            this.lblPrezime.AutoSize = true;
            this.lblPrezime.Location = new System.Drawing.Point(85, 51);
            this.lblPrezime.Name = "lblPrezime";
            this.lblPrezime.Size = new System.Drawing.Size(47, 13);
            this.lblPrezime.TabIndex = 2;
            this.lblPrezime.Text = "Prezime:";
            // 
            // txtIme
            // 
            this.txtIme.Location = new System.Drawing.Point(138, 22);
            this.txtIme.MaxLength = 20;
            this.txtIme.Name = "txtIme";
            this.txtIme.Size = new System.Drawing.Size(109, 20);
            this.txtIme.TabIndex = 1;
            this.txtIme.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtIme_KeyPress);
            this.txtIme.Leave += new System.EventHandler(this.txtIme_Leave);
            // 
            // lblIme
            // 
            this.lblIme.AutoSize = true;
            this.lblIme.Location = new System.Drawing.Point(105, 26);
            this.lblIme.Name = "lblIme";
            this.lblIme.Size = new System.Drawing.Size(27, 13);
            this.lblIme.TabIndex = 0;
            this.lblIme.Text = "Ime:";
            // 
            // gbxKategorija
            // 
            this.gbxKategorija.Controls.Add(this.btnObrisiKat);
            this.gbxKategorija.Controls.Add(this.btnDodajKat);
            this.gbxKategorija.Controls.Add(this.dgwKategorije);
            this.gbxKategorija.Location = new System.Drawing.Point(10, 258);
            this.gbxKategorija.Name = "gbxKategorija";
            this.gbxKategorija.Size = new System.Drawing.Size(412, 185);
            this.gbxKategorija.TabIndex = 17;
            this.gbxKategorija.TabStop = false;
            this.gbxKategorija.Text = "Kategorija";
            // 
            // btnObrisiKat
            // 
            this.btnObrisiKat.Image = ((System.Drawing.Image)(resources.GetObject("btnObrisiKat.Image")));
            this.btnObrisiKat.Location = new System.Drawing.Point(315, 132);
            this.btnObrisiKat.Name = "btnObrisiKat";
            this.btnObrisiKat.Size = new System.Drawing.Size(91, 38);
            this.btnObrisiKat.TabIndex = 20;
            this.btnObrisiKat.Text = "Obrisi kategoriju";
            this.btnObrisiKat.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.btnObrisiKat.UseVisualStyleBackColor = true;
            this.btnObrisiKat.Click += new System.EventHandler(this.btnObrisiKat_Click);
            // 
            // btnDodajKat
            // 
            this.btnDodajKat.Image = ((System.Drawing.Image)(resources.GetObject("btnDodajKat.Image")));
            this.btnDodajKat.Location = new System.Drawing.Point(6, 132);
            this.btnDodajKat.Name = "btnDodajKat";
            this.btnDodajKat.Size = new System.Drawing.Size(117, 38);
            this.btnDodajKat.TabIndex = 19;
            this.btnDodajKat.Text = "Dodaj novu kategoriju";
            this.btnDodajKat.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.btnDodajKat.UseVisualStyleBackColor = true;
            this.btnDodajKat.Click += new System.EventHandler(this.btnDodajKat_Click);
            // 
            // dgwKategorije
            // 
            this.dgwKategorije.AllowUserToAddRows = false;
            this.dgwKategorije.AllowUserToDeleteRows = false;
            this.dgwKategorije.AllowUserToResizeColumns = false;
            this.dgwKategorije.AllowUserToResizeRows = false;
            this.dgwKategorije.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgwKategorije.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Kategorija,
            this.DatumOd,
            this.DatumDo});
            this.dgwKategorije.Location = new System.Drawing.Point(6, 19);
            this.dgwKategorije.MultiSelect = false;
            this.dgwKategorije.Name = "dgwKategorije";
            this.dgwKategorije.ReadOnly = true;
            this.dgwKategorije.RowHeadersVisible = false;
            this.dgwKategorije.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.dgwKategorije.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgwKategorije.Size = new System.Drawing.Size(400, 107);
            this.dgwKategorije.TabIndex = 18;
            // 
            // Kategorija
            // 
            this.Kategorija.DataPropertyName = "Tip";
            this.Kategorija.HeaderText = "KategorijaValue";
            this.Kategorija.Name = "Kategorija";
            this.Kategorija.ReadOnly = true;
            // 
            // DatumOd
            // 
            this.DatumOd.DataPropertyName = "DatumOdValue";
            this.DatumOd.HeaderText = "DatumOdValue";
            this.DatumOd.Name = "DatumOd";
            this.DatumOd.ReadOnly = true;
            // 
            // DatumDo
            // 
            this.DatumDo.DataPropertyName = "DatumDoValue";
            this.DatumDo.HeaderText = "DatumDoValue";
            this.DatumDo.Name = "DatumDo";
            this.DatumDo.ReadOnly = true;
            // 
            // gbxZabrane
            // 
            this.gbxZabrane.Controls.Add(this.btnObrisiZab);
            this.gbxZabrane.Controls.Add(this.btnDodajZab);
            this.gbxZabrane.Controls.Add(this.dgwZabrane);
            this.gbxZabrane.Location = new System.Drawing.Point(16, 449);
            this.gbxZabrane.Name = "gbxZabrane";
            this.gbxZabrane.Size = new System.Drawing.Size(412, 185);
            this.gbxZabrane.TabIndex = 21;
            this.gbxZabrane.TabStop = false;
            this.gbxZabrane.Text = "Zabrane";
            // 
            // btnObrisiZab
            // 
            this.btnObrisiZab.Image = ((System.Drawing.Image)(resources.GetObject("btnObrisiZab.Image")));
            this.btnObrisiZab.Location = new System.Drawing.Point(315, 132);
            this.btnObrisiZab.Name = "btnObrisiZab";
            this.btnObrisiZab.Size = new System.Drawing.Size(91, 38);
            this.btnObrisiZab.TabIndex = 20;
            this.btnObrisiZab.Text = "Obrisi zabranu";
            this.btnObrisiZab.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.btnObrisiZab.UseVisualStyleBackColor = true;
            this.btnObrisiZab.Click += new System.EventHandler(this.btnObrisiZab_Click);
            // 
            // btnDodajZab
            // 
            this.btnDodajZab.Image = ((System.Drawing.Image)(resources.GetObject("btnDodajZab.Image")));
            this.btnDodajZab.Location = new System.Drawing.Point(6, 132);
            this.btnDodajZab.Name = "btnDodajZab";
            this.btnDodajZab.Size = new System.Drawing.Size(117, 38);
            this.btnDodajZab.TabIndex = 19;
            this.btnDodajZab.Text = "Dodaj novu zabranu";
            this.btnDodajZab.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.btnDodajZab.UseVisualStyleBackColor = true;
            this.btnDodajZab.Click += new System.EventHandler(this.btnDodajZab_Click);
            // 
            // dgwZabrane
            // 
            this.dgwZabrane.AllowUserToAddRows = false;
            this.dgwZabrane.AllowUserToDeleteRows = false;
            this.dgwZabrane.AllowUserToResizeColumns = false;
            this.dgwZabrane.AllowUserToResizeRows = false;
            this.dgwZabrane.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgwZabrane.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.ZabKategorija,
            this.ZabranaOd,
            this.ZabranaDo});
            this.dgwZabrane.Location = new System.Drawing.Point(6, 19);
            this.dgwZabrane.MultiSelect = false;
            this.dgwZabrane.Name = "dgwZabrane";
            this.dgwZabrane.ReadOnly = true;
            this.dgwZabrane.RowHeadersVisible = false;
            this.dgwZabrane.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.dgwZabrane.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgwZabrane.Size = new System.Drawing.Size(400, 107);
            this.dgwZabrane.TabIndex = 18;
            // 
            // ZabKategorija
            // 
            this.ZabKategorija.DataPropertyName = "Tip";
            this.ZabKategorija.HeaderText = "KategorijaValue";
            this.ZabKategorija.Name = "ZabKategorija";
            this.ZabKategorija.ReadOnly = true;
            // 
            // ZabranaOd
            // 
            this.ZabranaOd.DataPropertyName = "DatumOdValue";
            this.ZabranaOd.HeaderText = "DatumOdValue";
            this.ZabranaOd.Name = "ZabranaOd";
            this.ZabranaOd.ReadOnly = true;
            // 
            // ZabranaDo
            // 
            this.ZabranaDo.DataPropertyName = "DatumDoValue";
            this.ZabranaDo.HeaderText = "DatumDoValue";
            this.ZabranaDo.Name = "ZabranaDo";
            this.ZabranaDo.ReadOnly = true;
            // 
            // btnProsledi
            // 
            this.btnProsledi.Location = new System.Drawing.Point(123, 646);
            this.btnProsledi.Name = "btnProsledi";
            this.btnProsledi.Size = new System.Drawing.Size(75, 23);
            this.btnProsledi.TabIndex = 22;
            this.btnProsledi.Text = "Prosledi";
            this.btnProsledi.UseVisualStyleBackColor = true;
            this.btnProsledi.Click += new System.EventHandler(this.btnProsledi_Click);
            // 
            // btnZatvori
            // 
            this.btnZatvori.Location = new System.Drawing.Point(237, 646);
            this.btnZatvori.Name = "btnZatvori";
            this.btnZatvori.Size = new System.Drawing.Size(75, 23);
            this.btnZatvori.TabIndex = 23;
            this.btnZatvori.Text = "Zatvori";
            this.btnZatvori.UseVisualStyleBackColor = true;
            this.btnZatvori.Click += new System.EventHandler(this.btnZatvori_Click);
            // 
            // FormVozac
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(434, 681);
            this.Controls.Add(this.btnZatvori);
            this.Controls.Add(this.btnProsledi);
            this.Controls.Add(this.gbxZabrane);
            this.Controls.Add(this.gbxKategorija);
            this.Controls.Add(this.gbxOsnovno);
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(450, 720);
            this.MinimizeBox = false;
            this.MinimumSize = new System.Drawing.Size(450, 720);
            this.Name = "FormVozac";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Vozac";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.FormVozac_FormClosing);
            this.Load += new System.EventHandler(this.FormVozac_Load);
            this.gbxOsnovno.ResumeLayout(false);
            this.gbxOsnovno.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbxSlika)).EndInit();
            this.gbxKategorija.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgwKategorije)).EndInit();
            this.gbxZabrane.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgwZabrane)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox gbxOsnovno;
        private System.Windows.Forms.ComboBox cbxPol;
        private System.Windows.Forms.Label lblPol;
        private System.Windows.Forms.Label lblMesto;
        private System.Windows.Forms.TextBox txtMesto;
        private System.Windows.Forms.TextBox txtID;
        private System.Windows.Forms.Label lblID;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label lblOd;
        private System.Windows.Forms.DateTimePicker dtpDo;
        private System.Windows.Forms.DateTimePicker dtpOd;
        private System.Windows.Forms.DateTimePicker dtpDatRodj;
        private System.Windows.Forms.TextBox txtPrezime;
        private System.Windows.Forms.Label lblDatRodj;
        private System.Windows.Forms.Label lblPrezime;
        private System.Windows.Forms.TextBox txtIme;
        private System.Windows.Forms.Label lblIme;
        private System.Windows.Forms.Button btnDodajSliku;
        private System.Windows.Forms.PictureBox pbxSlika;
        private System.Windows.Forms.GroupBox gbxKategorija;
        private System.Windows.Forms.DataGridView dgwKategorije;
        private System.Windows.Forms.Button btnDodajKat;
        private System.Windows.Forms.Button btnObrisiKat;
        private System.Windows.Forms.GroupBox gbxZabrane;
        private System.Windows.Forms.Button btnObrisiZab;
        private System.Windows.Forms.Button btnDodajZab;
        private System.Windows.Forms.DataGridView dgwZabrane;
        private System.Windows.Forms.Button btnProsledi;
        private System.Windows.Forms.Button btnZatvori;
        private System.Windows.Forms.DataGridViewTextBoxColumn Kategorija;
        private System.Windows.Forms.DataGridViewTextBoxColumn DatumOd;
        private System.Windows.Forms.DataGridViewTextBoxColumn DatumDo;
        private System.Windows.Forms.DataGridViewTextBoxColumn ZabKategorija;
        private System.Windows.Forms.DataGridViewTextBoxColumn ZabranaOd;
        private System.Windows.Forms.DataGridViewTextBoxColumn ZabranaDo;
        private System.Windows.Forms.Button btnVidiKola;
        private System.Windows.Forms.TextBox txtDodajAuto;
        private System.Windows.Forms.Button btnDodajKola;
    }
}