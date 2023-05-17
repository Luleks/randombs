using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
	internal class Program
	{
		static void Main(string[] args)
		{
			Literatura diplomski = new Literatura();
			Stavka s1 = new Knjiga("Zlocin i kazna", 1866, "Rusija", "Fjodor Dostojevski");
			Stavka s2 = new Knjiga("Ana Karenjina", 1878, "Rusija", "Lav Tolstoj");
			Stavka s3 = new Clanak("De nomine cristianorum deleto", 300, "Rim", "Dioklecijan", "Maximian");
			Stavka s4 = new Clanak("Clanak2", 2020, "Nis", "Luka Velickovic", "Petar Petrovic");
			Stavka s5 = new WebStranica("anticliterature.com", 2020);
			Stavka s6 = new WebStranica("novokomponovanaliteratura.com", 2017);

			diplomski.DodajStavku(s1);
			diplomski.DodajStavku(s2);
			diplomski.DodajStavku(s3);
			diplomski.DodajStavku(s4);
			diplomski.DodajStavku(s5);
			diplomski.DodajStavku(s6);

			diplomski.SortByGodina(false);
			diplomski.Print();
			diplomski.PisiBin("test.txt");

			Literatura l2 = new Literatura();
			l2.CitajBin("test.txt");
			l2.Print();
		}
	}
}
