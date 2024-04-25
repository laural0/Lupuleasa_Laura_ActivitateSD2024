using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test_1
{
    public class Angajat
    {
        private string nume;
        private int oreLucrate;
        private int salariuOrar;

        public Angajat()
        {
        }

        public Angajat(string nume, int oreLucrate, int salariuOrar)
        {
            this.nume = nume;
            this.oreLucrate = oreLucrate;
            this.salariuOrar = salariuOrar;
        }

        public string Nume
        {
            get => nume;
            set => nume = value;
        }

        public int OreLucrate
        {
            get => oreLucrate;
            set => oreLucrate = value;
        }

        public int SalariuOrar
        {
            get => salariuOrar;
            set => salariuOrar = value;
        }

        public override string ToString() =>
            $"{Nume}\t{OreLucrate}\t{SalariuOrar}\t{SalariuOrar * OreLucrate}";
    }

    public class Firma : ITotalSalariu
    {
        private List<Angajat> listaAngajati = new List<Angajat>();

        private string numeFirma;

        public Firma(string numeFirma)
        {
            this.numeFirma = numeFirma;
        }

        public List<Angajat> ListaAngajati
        {
            get => listaAngajati;
            set => listaAngajati = value;
        }

        public string NumeFirma
        {
            get => numeFirma;
            set => numeFirma = value;
        }

        public override string ToString()
        {
            StringBuilder stringBuilder = new StringBuilder();

            stringBuilder.Append("Numele firmei: ").Append(numeFirma);

            foreach (Angajat angajat in listaAngajati)
            {
                stringBuilder.Append(angajat);
            }

            return stringBuilder.ToString();
        }

        public float calculeazaTotalSalarii()
        {
            float sum = 0;

            foreach (var angajat in listaAngajati)
            {
                sum += angajat.OreLucrate * angajat.SalariuOrar;
            }

            return sum;
        }

        public static Firma operator +(Firma firma, Angajat angajat)
        {
            firma.ListaAngajati.Add(angajat);

            return firma;
        }

        public void SalvareInFisier(string numeFisier)
        {
            using (FileStream file = new FileStream(numeFisier, FileMode.Create))
            {
                using (StreamWriter writer = new StreamWriter(file))
                {
                    writer.WriteLine(numeFirma);

                    foreach (var angajat in ListaAngajati)
                    {
                        Console.WriteLine(angajat);
                        writer.WriteLine(angajat);
                    }

                    writer.WriteLine(calculeazaTotalSalarii());
                }
            }

            Console.WriteLine("Date salvate");
        }

        public void citireDinFisier(string numeFisier)
        {
            if (File.Exists(numeFisier))
                using (StreamReader reader = new StreamReader(numeFisier))
                {
                    string line = reader.ReadLine();
                    numeFirma = line;

                    while (!reader.EndOfStream)
                    {
                        line = reader.ReadLine();

                        if (reader.Peek() != -1)

                        {
                            string[] columns = line.Split('\t');

                            Angajat angajat = new Angajat(
                                columns[0],
                                int.Parse(columns[1]),
                                int.Parse(columns[2]));

                            listaAngajati.Add(angajat);
                        }
                    }
                }
        }
    }
}