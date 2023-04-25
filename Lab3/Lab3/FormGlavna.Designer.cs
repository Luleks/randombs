namespace Lab3
{
    partial class FormGlavna
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormGlavna));
            groupBox1 = new GroupBox();
            btnPonisti = new Button();
            txtAdresa = new TextBox();
            lblAdresa = new Label();
            dtpDatRodj = new DateTimePicker();
            lblDatRodj = new Label();
            btnZapamti = new Button();
            txtTelefon = new TextBox();
            txtPrezime = new TextBox();
            txtIme = new TextBox();
            lblTelefon = new Label();
            lblPrezime = new Label();
            lblIme = new Label();
            lbxListOsoba = new ListBox();
            lblListaOsoba = new Label();
            btnObrisiJednu = new Button();
            btnObrisiSve = new Button();
            btnSort = new Button();
            cbxSort = new ComboBox();
            groupBox1.SuspendLayout();
            SuspendLayout();
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(btnPonisti);
            groupBox1.Controls.Add(txtAdresa);
            groupBox1.Controls.Add(lblAdresa);
            groupBox1.Controls.Add(dtpDatRodj);
            groupBox1.Controls.Add(lblDatRodj);
            groupBox1.Controls.Add(btnZapamti);
            groupBox1.Controls.Add(txtTelefon);
            groupBox1.Controls.Add(txtPrezime);
            groupBox1.Controls.Add(txtIme);
            groupBox1.Controls.Add(lblTelefon);
            groupBox1.Controls.Add(lblPrezime);
            groupBox1.Controls.Add(lblIme);
            groupBox1.Location = new Point(12, 12);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(460, 180);
            groupBox1.TabIndex = 0;
            groupBox1.TabStop = false;
            groupBox1.Text = "Podaci o osobi";
            // 
            // btnPonisti
            // 
            btnPonisti.Image = (Image)resources.GetObject("btnPonisti.Image");
            btnPonisti.Location = new Point(249, 132);
            btnPonisti.Name = "btnPonisti";
            btnPonisti.Size = new Size(119, 39);
            btnPonisti.TabIndex = 6;
            btnPonisti.Text = "Ponisti";
            btnPonisti.TextImageRelation = TextImageRelation.ImageBeforeText;
            btnPonisti.UseVisualStyleBackColor = true;
            btnPonisti.Click += btnPonisti_Click;
            // 
            // txtAdresa
            // 
            txtAdresa.Location = new Point(247, 85);
            txtAdresa.MaxLength = 60;
            txtAdresa.Multiline = true;
            txtAdresa.Name = "txtAdresa";
            txtAdresa.ScrollBars = ScrollBars.Vertical;
            txtAdresa.Size = new Size(205, 38);
            txtAdresa.TabIndex = 4;
            // 
            // lblAdresa
            // 
            lblAdresa.AutoSize = true;
            lblAdresa.Location = new Point(247, 67);
            lblAdresa.Name = "lblAdresa";
            lblAdresa.Size = new Size(106, 15);
            lblAdresa.TabIndex = 9;
            lblAdresa.Text = "Adresa stanovanja:";
            // 
            // dtpDatRodj
            // 
            dtpDatRodj.CustomFormat = "dd.MM.yyyy";
            dtpDatRodj.Format = DateTimePickerFormat.Custom;
            dtpDatRodj.Location = new Point(343, 34);
            dtpDatRodj.Name = "dtpDatRodj";
            dtpDatRodj.Size = new Size(109, 23);
            dtpDatRodj.TabIndex = 3;
            dtpDatRodj.Value = new DateTime(2023, 4, 25, 0, 0, 0, 0);
            // 
            // lblDatRodj
            // 
            lblDatRodj.AutoSize = true;
            lblDatRodj.Location = new Point(247, 38);
            lblDatRodj.Name = "lblDatRodj";
            lblDatRodj.Size = new Size(92, 15);
            lblDatRodj.TabIndex = 7;
            lblDatRodj.Text = "Datum rodjenja:";
            // 
            // btnZapamti
            // 
            btnZapamti.Image = (Image)resources.GetObject("btnZapamti.Image");
            btnZapamti.Location = new Point(108, 132);
            btnZapamti.Name = "btnZapamti";
            btnZapamti.Size = new Size(119, 39);
            btnZapamti.TabIndex = 5;
            btnZapamti.Text = "Zapamti";
            btnZapamti.TextImageRelation = TextImageRelation.ImageBeforeText;
            btnZapamti.UseVisualStyleBackColor = true;
            btnZapamti.Click += btnZapamti_Click;
            // 
            // txtTelefon
            // 
            txtTelefon.Location = new Point(64, 100);
            txtTelefon.MaxLength = 15;
            txtTelefon.Name = "txtTelefon";
            txtTelefon.Size = new Size(163, 23);
            txtTelefon.TabIndex = 2;
            txtTelefon.KeyPress += txtTelefon_KeyPress;
            txtTelefon.Leave += txtTelefon_Leave;
            // 
            // txtPrezime
            // 
            txtPrezime.Location = new Point(64, 67);
            txtPrezime.MaxLength = 20;
            txtPrezime.Name = "txtPrezime";
            txtPrezime.Size = new Size(163, 23);
            txtPrezime.TabIndex = 1;
            txtPrezime.KeyPress += txtPrezime_KeyPress;
            // 
            // txtIme
            // 
            txtIme.Location = new Point(64, 34);
            txtIme.MaxLength = 20;
            txtIme.Name = "txtIme";
            txtIme.Size = new Size(163, 23);
            txtIme.TabIndex = 0;
            txtIme.KeyPress += txtIme_KeyPress;
            // 
            // lblTelefon
            // 
            lblTelefon.AutoSize = true;
            lblTelefon.Location = new Point(6, 104);
            lblTelefon.Name = "lblTelefon";
            lblTelefon.Size = new Size(48, 15);
            lblTelefon.TabIndex = 2;
            lblTelefon.Text = "Telefon:";
            // 
            // lblPrezime
            // 
            lblPrezime.AutoSize = true;
            lblPrezime.Location = new Point(6, 71);
            lblPrezime.Name = "lblPrezime";
            lblPrezime.Size = new Size(52, 15);
            lblPrezime.TabIndex = 1;
            lblPrezime.Text = "Prezime:";
            // 
            // lblIme
            // 
            lblIme.AutoSize = true;
            lblIme.Location = new Point(6, 38);
            lblIme.Name = "lblIme";
            lblIme.Size = new Size(30, 15);
            lblIme.TabIndex = 0;
            lblIme.Text = "Ime:";
            // 
            // lbxListOsoba
            // 
            lbxListOsoba.FormattingEnabled = true;
            lbxListOsoba.HorizontalScrollbar = true;
            lbxListOsoba.ItemHeight = 15;
            lbxListOsoba.Location = new Point(12, 235);
            lbxListOsoba.Name = "lbxListOsoba";
            lbxListOsoba.RightToLeft = RightToLeft.No;
            lbxListOsoba.ScrollAlwaysVisible = true;
            lbxListOsoba.Size = new Size(460, 199);
            lbxListOsoba.TabIndex = 0;
            lbxListOsoba.DoubleClick += lbxListOsoba_DoubleClick;
            // 
            // lblListaOsoba
            // 
            lblListaOsoba.AutoSize = true;
            lblListaOsoba.Font = new Font("Segoe UI", 15F, FontStyle.Bold, GraphicsUnit.Point);
            lblListaOsoba.Location = new Point(180, 204);
            lblListaOsoba.Name = "lblListaOsoba";
            lblListaOsoba.Size = new Size(118, 28);
            lblListaOsoba.TabIndex = 2;
            lblListaOsoba.Text = "Lista osoba";
            // 
            // btnObrisiJednu
            // 
            btnObrisiJednu.Image = (Image)resources.GetObject("btnObrisiJednu.Image");
            btnObrisiJednu.Location = new Point(12, 440);
            btnObrisiJednu.Name = "btnObrisiJednu";
            btnObrisiJednu.Size = new Size(133, 39);
            btnObrisiJednu.TabIndex = 1;
            btnObrisiJednu.Text = "Obrisi izabranu osobu";
            btnObrisiJednu.TextImageRelation = TextImageRelation.ImageBeforeText;
            btnObrisiJednu.UseVisualStyleBackColor = true;
            btnObrisiJednu.Click += btnObrisiJednu_Click;
            // 
            // btnObrisiSve
            // 
            btnObrisiSve.Image = (Image)resources.GetObject("btnObrisiSve.Image");
            btnObrisiSve.Location = new Point(151, 440);
            btnObrisiSve.Name = "btnObrisiSve";
            btnObrisiSve.Size = new Size(109, 39);
            btnObrisiSve.TabIndex = 2;
            btnObrisiSve.Text = "Obrisi listu osoba";
            btnObrisiSve.TextImageRelation = TextImageRelation.ImageBeforeText;
            btnObrisiSve.UseVisualStyleBackColor = true;
            btnObrisiSve.Click += btnObrisiSve_Click;
            // 
            // btnSort
            // 
            btnSort.Image = (Image)resources.GetObject("btnSort.Image");
            btnSort.Location = new Point(280, 440);
            btnSort.Name = "btnSort";
            btnSort.Size = new Size(85, 39);
            btnSort.TabIndex = 3;
            btnSort.Text = "Sortiraj listu";
            btnSort.TextImageRelation = TextImageRelation.ImageBeforeText;
            btnSort.UseVisualStyleBackColor = true;
            btnSort.Click += btnSort_Click;
            // 
            // cbxSort
            // 
            cbxSort.DropDownStyle = ComboBoxStyle.DropDownList;
            cbxSort.FormattingEnabled = true;
            cbxSort.Items.AddRange(new object[] { "PO IMENU", "PO PREZIMENU", "PO DAT RODJ" });
            cbxSort.Location = new Point(371, 448);
            cbxSort.Name = "cbxSort";
            cbxSort.Size = new Size(101, 23);
            cbxSort.TabIndex = 4;
            cbxSort.SelectedIndexChanged += cbxSort_SelectedIndexChanged;
            // 
            // FormGlavna
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(484, 496);
            Controls.Add(cbxSort);
            Controls.Add(btnSort);
            Controls.Add(btnObrisiSve);
            Controls.Add(btnObrisiJednu);
            Controls.Add(lblListaOsoba);
            Controls.Add(lbxListOsoba);
            Controls.Add(groupBox1);
            MaximizeBox = false;
            MaximumSize = new Size(500, 535);
            MinimizeBox = false;
            MinimumSize = new Size(500, 535);
            Name = "FormGlavna";
            ShowIcon = false;
            StartPosition = FormStartPosition.CenterScreen;
            Text = "OOProjektovanje lab. vezba 1";
            FormClosing += FormGlavna_FormClosing;
            Load += FormGlavna_Load;
            DoubleClick += FormGlavna_DoubleClick;
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private GroupBox groupBox1;
        private Label lblDatRodj;
        private Button btnZapamti;
        private TextBox txtTelefon;
        private TextBox txtPrezime;
        private TextBox txtIme;
        private Label lblTelefon;
        private Label lblPrezime;
        private Label lblIme;
        private Button btnPonisti;
        private TextBox txtAdresa;
        private Label lblAdresa;
        private DateTimePicker dtpDatRodj;
        private ListBox lbxListOsoba;
        private Label lblListaOsoba;
        private Button btnObrisiJednu;
        private Button btnObrisiSve;
        private Button btnSort;
        private ComboBox cbxSort;
    }
}