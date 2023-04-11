#include "Fakultet.h"

int main() {
	Fakultet::setFakultet("Elektronski fakultet", Datum(10, 11, 1968));
	Fakultet* fakultet = Fakultet::getFakultet();

	const char* predmetiRI[] = { "Aip", "7", "R1", "OOP", "6", "R2", "SP", "6", "R3", "OS", "6", "R4"};
	fakultet->dodajOdsek("Racunarstvo i informatika", "Racunarstvo i informatika", 4, predmetiRI);

	const char* predmetiMIKRO[] = {"Elektronske komponente", "6", "M1", "Materijali", "5", "M2", "Stampane ploce",
	"5", "M3"};
	fakultet->dodajOdsek("Mikroelektronika", "Mikroelektronika", 3, predmetiMIKRO);

	const char* predmetiAUTO[] = { "Sau", "6", "A1", "Mehanika", "7", "A2"};
	fakultet->dodajOdsek("Automatika", "Automatika", 2, predmetiAUTO);

	try {

		Student* student1 = new Student(18587, "0311002730052", "Luka Velickovic", Datum(17, 9, 2021));
		const char* predmeti1[] = { "Aip", "OOP", "SP" };
		fakultet->upisiStudenta(student1, "Racunarstvo i informatika", predmeti1, 3);

		Student* student2 = new Student(18645, "1721002735486", "Veljko Zivkovic", Datum(17, 9, 2020));
		const char* predmeti2[] = { "Aip", "OOP", "SP", "OS" };
		fakultet->upisiStudenta(student2, "Racunarstvo i informatika", predmeti2, 4);

		Student* student3 = new Student(19256, "1821003734589", "Petar Petrovic", Datum(21, 10, 2022));
		const char* predmeti3[] = { "Aip" };
		fakultet->upisiStudenta(student3, "Racunarstvo i informatika", predmeti3, 1);

		Student* student4 = new Student(18598, "1920003734851", "Dusan Gligorijevic", Datum(17, 9, 2021));
		const char* predmeti4[] = { "Elektronske komponente", "Materijali" };
		fakultet->upisiStudenta(student4, "Mikroelektronika", predmeti4, 2);

		Student* student5 = new Student(18255, "2810000745824", "Stariji student", Datum(15, 8, 2019));
		const char* predmeti5[] = { "Elektronske komponente", "Materijali", "Stampane ploce" };
		fakultet->upisiStudenta(student5, "Mikroelektronika", predmeti5, 3);

		Student* student6 = new Student(20000, "2001000730002", "Los student", Datum());
		const char* predmeti[] = { "Nepostojeci predmet1", "Nepostojeci predmet2" };
		fakultet->upisiStudenta(student6, "Nepostojeci smer", predmeti, 2);
	}
	catch (exception e) {
		cerr << e.what() << endl;
	}
	fakultet->prikazi(cout);
}