using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace test_1
{
    public partial class Form1 : Form
    {
        private Firma firma;
        private Angajat angajat = new Angajat();

        public Form1()
        {
            InitializeComponent();
            firma = new Firma("Borotalco");
        }

        private void afiseazaAngaajtii(object sender, EventArgs e)
        {
            lista.Text = "";

            foreach (var angajat in firma.ListaAngajati)
            {
                lista.AppendText(angajat.ToString());
                lista.AppendText(Environment.NewLine);
            }
        }

        private void adaugaAngajat_click(object sender, EventArgs e)
        {
            try
            {
                angajat.Nume = text_nume.Text;

                if (Int32.TryParse(text_oreLucrate.Text, out int oreLucrate))
                {
                    angajat.OreLucrate = oreLucrate;
                }
                else
                {
                    MessageBox.Show("Vă rugăm să introduceți un număr valid pentru orele lucrate.", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }

                if (Int32.TryParse(text_salariuOrar.Text, out int salariuOrar))
                {
                    angajat.SalariuOrar = salariuOrar;
                }
                else
                {
                    MessageBox.Show("Vă rugăm să introduceți un număr valid pentru salariul orar.", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }

                firma.ListaAngajati.Add(new Angajat(angajat.Nume, angajat.OreLucrate, angajat.SalariuOrar));
                MessageBox.Show("Angajat introdus cu succes!");
            }
            catch (ArgumentNullException argumentNull)
            {
                MessageBox.Show(argumentNull.Message, "Eroare - nu există valoare.", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch (FormatException format)
            {
                MessageBox.Show(format.Message, "Eroare - format incorect", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch (OverflowException overflow)
            {
                MessageBox.Show(overflow.Message, "Eroare - overflow", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            text_nume.Text = angajat.Nume;
            text_oreLucrate.Text = angajat.OreLucrate.ToString();
            text_salariuOrar.Text = angajat.SalariuOrar.ToString();
        }

        private void salveaza_click(object sender, EventArgs e)
        {
            ToolStripMenuItem item = sender as ToolStripMenuItem;

            if (item.Tag.ToString() == "S")
            {
                SaveFileDialog fd = new SaveFileDialog();

                string path = System.IO.Path.Combine(Directory.GetCurrentDirectory(), "..\\..");

                fd.InitialDirectory = System.IO.Path.GetFullPath(path);
                fd.Filter = "Date(*.txt)|*.txt|All files (*.*)|*.*";
                fd.FilterIndex = 1;
                fd.DefaultExt = "txt";

                if (DialogResult.OK == fd.ShowDialog())
                {
                    firma.SalvareInFisier(fd.FileName);
                }
            }

            if (item.Tag.ToString() == "R")
            {
                OpenFileDialog fd = new OpenFileDialog();

                string path = System.IO.Path.Combine(Directory.GetCurrentDirectory(), "..\\..");
                fd.InitialDirectory = System.IO.Path.GetFullPath(path);

                fd.Filter = "Date(*.txt)|*.txt|All files (*.*)|*.*";
                fd.FilterIndex = 1;
                fd.Multiselect = false;

                if (DialogResult.OK == fd.ShowDialog()) { firma.citireDinFisier(fd.FileName); }
            }
        }
    }
}