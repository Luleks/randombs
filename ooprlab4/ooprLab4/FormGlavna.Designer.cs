namespace ooprLab4
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormGlavna));
            this.lblTime = new System.Windows.Forms.Label();
            this.tmrVreme = new System.Windows.Forms.Timer(this.components);
            this.btnSort = new System.Windows.Forms.Button();
            this.cbxSort = new System.Windows.Forms.ComboBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnObrisi = new System.Windows.Forms.Button();
            this.btnIzmeni = new System.Windows.Forms.Button();
            this.btnDodaj = new System.Windows.Forms.Button();
            this.dgwLista = new System.Windows.Forms.DataGridView();
            this.Ime = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Prezime = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Vozacka = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgwLista)).BeginInit();
            this.SuspendLayout();
            // 
            // lblTime
            // 
            this.lblTime.AutoSize = true;
            this.lblTime.Font = new System.Drawing.Font("Consolas", 10F);
            this.lblTime.Location = new System.Drawing.Point(10, 10);
            this.lblTime.Name = "lblTime";
            this.lblTime.Size = new System.Drawing.Size(168, 17);
            this.lblTime.TabIndex = 0;
            this.lblTime.Text = "HH:mm:ss dd.MM.yyyy.";
            // 
            // tmrVreme
            // 
            this.tmrVreme.Interval = 1000;
            this.tmrVreme.Tick += new System.EventHandler(this.tmrVreme_Tick);
            // 
            // btnSort
            // 
            this.btnSort.Location = new System.Drawing.Point(366, 7);
            this.btnSort.Name = "btnSort";
            this.btnSort.Size = new System.Drawing.Size(75, 23);
            this.btnSort.TabIndex = 1;
            this.btnSort.Text = "Sortiraj";
            this.btnSort.UseVisualStyleBackColor = true;
            this.btnSort.Click += new System.EventHandler(this.btnSort_Click);
            // 
            // cbxSort
            // 
            this.cbxSort.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxSort.FormattingEnabled = true;
            this.cbxSort.Items.AddRange(new object[] {
            "Broj vozacke dozvole",
            "Ime",
            "Prezime"});
            this.cbxSort.Location = new System.Drawing.Point(447, 8);
            this.cbxSort.Name = "cbxSort";
            this.cbxSort.Size = new System.Drawing.Size(125, 21);
            this.cbxSort.TabIndex = 2;
            this.cbxSort.SelectedIndexChanged += new System.EventHandler(this.cbxSort_SelectedIndexChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnObrisi);
            this.groupBox1.Controls.Add(this.btnIzmeni);
            this.groupBox1.Controls.Add(this.btnDodaj);
            this.groupBox1.Controls.Add(this.dgwLista);
            this.groupBox1.Location = new System.Drawing.Point(13, 43);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(559, 256);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Lista vozaca";
            // 
            // btnObrisi
            // 
            this.btnObrisi.Image = ((System.Drawing.Image)(resources.GetObject("btnObrisi.Image")));
            this.btnObrisi.Location = new System.Drawing.Point(468, 212);
            this.btnObrisi.Name = "btnObrisi";
            this.btnObrisi.Size = new System.Drawing.Size(85, 38);
            this.btnObrisi.TabIndex = 3;
            this.btnObrisi.Text = "Obrisi vozaca";
            this.btnObrisi.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.btnObrisi.UseVisualStyleBackColor = true;
            this.btnObrisi.Click += new System.EventHandler(this.btnObrisi_Click);
            // 
            // btnIzmeni
            // 
            this.btnIzmeni.Image = ((System.Drawing.Image)(resources.GetObject("btnIzmeni.Image")));
            this.btnIzmeni.Location = new System.Drawing.Point(98, 212);
            this.btnIzmeni.Name = "btnIzmeni";
            this.btnIzmeni.Size = new System.Drawing.Size(85, 38);
            this.btnIzmeni.TabIndex = 2;
            this.btnIzmeni.Text = "Izmeni vozaca";
            this.btnIzmeni.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.btnIzmeni.UseVisualStyleBackColor = true;
            this.btnIzmeni.Click += new System.EventHandler(this.btnIzmeni_Click);
            // 
            // btnDodaj
            // 
            this.btnDodaj.Image = ((System.Drawing.Image)(resources.GetObject("btnDodaj.Image")));
            this.btnDodaj.Location = new System.Drawing.Point(7, 212);
            this.btnDodaj.Name = "btnDodaj";
            this.btnDodaj.Size = new System.Drawing.Size(85, 38);
            this.btnDodaj.TabIndex = 1;
            this.btnDodaj.Text = "Dodaj vozaca";
            this.btnDodaj.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.btnDodaj.UseVisualStyleBackColor = true;
            this.btnDodaj.Click += new System.EventHandler(this.btnDodaj_Click);
            // 
            // dgwLista
            // 
            this.dgwLista.AllowUserToAddRows = false;
            this.dgwLista.AllowUserToDeleteRows = false;
            this.dgwLista.AllowUserToResizeColumns = false;
            this.dgwLista.AllowUserToResizeRows = false;
            this.dgwLista.BackgroundColor = System.Drawing.SystemColors.Control;
            this.dgwLista.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgwLista.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Ime,
            this.Prezime,
            this.Vozacka});
            this.dgwLista.Location = new System.Drawing.Point(7, 20);
            this.dgwLista.MultiSelect = false;
            this.dgwLista.Name = "dgwLista";
            this.dgwLista.ReadOnly = true;
            this.dgwLista.RowHeadersVisible = false;
            this.dgwLista.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgwLista.Size = new System.Drawing.Size(546, 186);
            this.dgwLista.TabIndex = 0;
            // 
            // Ime
            // 
            this.Ime.DataPropertyName = "Ime";
            this.Ime.HeaderText = "Ime";
            this.Ime.Name = "Ime";
            this.Ime.ReadOnly = true;
            // 
            // Prezime
            // 
            this.Prezime.DataPropertyName = "Prezime";
            this.Prezime.HeaderText = "Prezime";
            this.Prezime.Name = "Prezime";
            this.Prezime.ReadOnly = true;
            // 
            // Vozacka
            // 
            this.Vozacka.DataPropertyName = "DozvolaID";
            this.Vozacka.HeaderText = "Br. vozacke dozvole";
            this.Vozacka.Name = "Vozacka";
            this.Vozacka.ReadOnly = true;
            // 
            // FormGlavna
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(584, 311);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.cbxSort);
            this.Controls.Add(this.btnSort);
            this.Controls.Add(this.lblTime);
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(600, 350);
            this.MinimizeBox = false;
            this.MinimumSize = new System.Drawing.Size(600, 350);
            this.Name = "FormGlavna";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Lista vozaca";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.FormGlavna_FormClosing);
            this.Load += new System.EventHandler(this.FormGlavna_Load);
            this.groupBox1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgwLista)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblTime;
        private System.Windows.Forms.Timer tmrVreme;
        private System.Windows.Forms.Button btnSort;
        private System.Windows.Forms.ComboBox cbxSort;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.DataGridView dgwLista;
        private System.Windows.Forms.Button btnObrisi;
        private System.Windows.Forms.Button btnIzmeni;
        private System.Windows.Forms.Button btnDodaj;
        private System.Windows.Forms.DataGridViewTextBoxColumn Ime;
        private System.Windows.Forms.DataGridViewTextBoxColumn Prezime;
        private System.Windows.Forms.DataGridViewTextBoxColumn Vozacka;
    }
}

