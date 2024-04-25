namespace test_1
{
    partial class Form1
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
            this.adaugaAngajat = new System.Windows.Forms.Button();
            this.lista = new System.Windows.Forms.TextBox();
            this.arataTotiAngajatii = new System.Windows.Forms.Button();
            this.text_nume = new System.Windows.Forms.TextBox();
            this.text_salariuOrar = new System.Windows.Forms.TextBox();
            this.text_oreLucrate = new System.Windows.Forms.TextBox();
            this.label_nume = new System.Windows.Forms.Label();
            this.label_oreLucrate = new System.Windows.Forms.Label();
            this.label_salariuOrar = new System.Windows.Forms.Label();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.optiuniToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.salveazaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.restaureazaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // adaugaAngajat
            // 
            this.adaugaAngajat.AccessibleName = "adaugaAngajat";
            this.adaugaAngajat.Location = new System.Drawing.Point(111, 223);
            this.adaugaAngajat.Name = "adaugaAngajat";
            this.adaugaAngajat.Size = new System.Drawing.Size(178, 56);
            this.adaugaAngajat.TabIndex = 0;
            this.adaugaAngajat.Text = "Adauga Angajat";
            this.adaugaAngajat.UseVisualStyleBackColor = true;
            this.adaugaAngajat.Click += new System.EventHandler(this.adaugaAngajat_click);
            // 
            // lista
            // 
            this.lista.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lista.Location = new System.Drawing.Point(432, 32);
            this.lista.Multiline = true;
            this.lista.Name = "lista";
            this.lista.ReadOnly = true;
            this.lista.Size = new System.Drawing.Size(339, 393);
            this.lista.TabIndex = 1;
            // 
            // arataTotiAngajatii
            // 
            this.arataTotiAngajatii.AccessibleName = "afisareAngajati";
            this.arataTotiAngajatii.Location = new System.Drawing.Point(30, 366);
            this.arataTotiAngajatii.Name = "arataTotiAngajatii";
            this.arataTotiAngajatii.Size = new System.Drawing.Size(347, 59);
            this.arataTotiAngajatii.TabIndex = 2;
            this.arataTotiAngajatii.Text = "Arata toti angajatii";
            this.arataTotiAngajatii.UseVisualStyleBackColor = true;
            this.arataTotiAngajatii.Click += new System.EventHandler(this.afiseazaAngaajtii);
            // 
            // text_nume
            // 
            this.text_nume.Location = new System.Drawing.Point(155, 78);
            this.text_nume.Name = "text_nume";
            this.text_nume.Size = new System.Drawing.Size(222, 22);
            this.text_nume.TabIndex = 3;
            // 
            // text_salariuOrar
            // 
            this.text_salariuOrar.Location = new System.Drawing.Point(155, 165);
            this.text_salariuOrar.Name = "text_salariuOrar";
            this.text_salariuOrar.Size = new System.Drawing.Size(222, 22);
            this.text_salariuOrar.TabIndex = 4;
            // 
            // text_oreLucrate
            // 
            this.text_oreLucrate.Location = new System.Drawing.Point(155, 121);
            this.text_oreLucrate.Name = "text_oreLucrate";
            this.text_oreLucrate.Size = new System.Drawing.Size(222, 22);
            this.text_oreLucrate.TabIndex = 5;
            // 
            // label_nume
            // 
            this.label_nume.AutoSize = true;
            this.label_nume.Location = new System.Drawing.Point(45, 81);
            this.label_nume.Name = "label_nume";
            this.label_nume.Size = new System.Drawing.Size(43, 16);
            this.label_nume.TabIndex = 6;
            this.label_nume.Text = "Nume";
            // 
            // label_oreLucrate
            // 
            this.label_oreLucrate.AutoSize = true;
            this.label_oreLucrate.Location = new System.Drawing.Point(45, 124);
            this.label_oreLucrate.Name = "label_oreLucrate";
            this.label_oreLucrate.Size = new System.Drawing.Size(72, 16);
            this.label_oreLucrate.TabIndex = 7;
            this.label_oreLucrate.Text = "Ore lucrate";
            // 
            // label_salariuOrar
            // 
            this.label_salariuOrar.AutoSize = true;
            this.label_salariuOrar.Location = new System.Drawing.Point(45, 171);
            this.label_salariuOrar.Name = "label_salariuOrar";
            this.label_salariuOrar.Size = new System.Drawing.Size(76, 16);
            this.label_salariuOrar.TabIndex = 8;
            this.label_salariuOrar.Text = "Salariu orar";
            // 
            // menuStrip1
            // 
            this.menuStrip1.AccessibleName = "OPTIUNI";
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.optiuniToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(800, 28);
            this.menuStrip1.TabIndex = 9;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // optiuniToolStripMenuItem
            // 
            this.optiuniToolStripMenuItem.AccessibleName = "OPTIUNI";
            this.optiuniToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.salveazaToolStripMenuItem,
            this.restaureazaToolStripMenuItem});
            this.optiuniToolStripMenuItem.Name = "optiuniToolStripMenuItem";
            this.optiuniToolStripMenuItem.Size = new System.Drawing.Size(72, 24);
            this.optiuniToolStripMenuItem.Text = "Optiuni";
            // 
            // salveazaToolStripMenuItem
            // 
            this.salveazaToolStripMenuItem.Tag = "S";
            this.salveazaToolStripMenuItem.Name = "salveazaToolStripMenuItem";
            this.salveazaToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.salveazaToolStripMenuItem.Text = "Salveaza";
            this.salveazaToolStripMenuItem.Click += new System.EventHandler(this.salveaza_click);
            // 
            // restaureazaToolStripMenuItem
            // 
            this.restaureazaToolStripMenuItem.Name = "restaureazaToolStripMenuItem";
            this.restaureazaToolStripMenuItem.Tag = "R";
            this.restaureazaToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.restaureazaToolStripMenuItem.Text = "Restaureaza";
            this.restaureazaToolStripMenuItem.Click += new System.EventHandler(this.salveaza_click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label_salariuOrar);
            this.Controls.Add(this.label_oreLucrate);
            this.Controls.Add(this.label_nume);
            this.Controls.Add(this.text_oreLucrate);
            this.Controls.Add(this.text_salariuOrar);
            this.Controls.Add(this.text_nume);
            this.Controls.Add(this.arataTotiAngajatii);
            this.Controls.Add(this.lista);
            this.Controls.Add(this.adaugaAngajat);
            this.Controls.Add(this.menuStrip1);
            this.ImeMode = System.Windows.Forms.ImeMode.Off;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button adaugaAngajat;
        private System.Windows.Forms.TextBox lista;
        private System.Windows.Forms.Button arataTotiAngajatii;
        private System.Windows.Forms.TextBox text_nume;
        private System.Windows.Forms.TextBox text_salariuOrar;
        private System.Windows.Forms.TextBox text_oreLucrate;
        private System.Windows.Forms.Label label_nume;
        private System.Windows.Forms.Label label_oreLucrate;
        private System.Windows.Forms.Label label_salariuOrar;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem optiuniToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem salveazaToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem restaureazaToolStripMenuItem;
    }
}
