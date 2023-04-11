#include "Fakultet.h"

int main() {
	Fakultet::setFakultet("Elektronski fakultet", Datum(10, 11, 1968), "Dekan fakulteta");
	Fakultet* fakultet = Fakultet::getFakultet();

	const char* predmetiRI[] = {"UUR", "6", "R0", "Aip", "7", "R1", "OOP", "6", "R2", "SP", "6", "R3", "OS", "6", "R4"};
	fakultet->dodajOdsek("Racunarstvo i informatika", "Racunarstvo i informatika", 5, predmetiRI);

	const char* predmetiMIKRO[] = {"Fizika", "6", "M0", "Elektronske komponente", "6", "M1", "Materijali", "5", "M2", "Stampane ploce",
	"5", "M3"};
	fakultet->dodajOdsek("Mikroelektronika", "Mikroelektronika", 4, predmetiMIKRO);

	const char* predmetiAUTO[] = { "Sau", "6", "A1", "Mehanika", "7", "A2"};
	fakultet->dodajOdsek("Automatika", "Automatika", 2, predmetiAUTO);


	Student* student1 = new Student(18587, "0311002730052", "Luka Velickovic", Datum(17, 9, 2021));
	fakultet->upisiStudenta(student1, "Racunarstvo i informatika");
	student1->izaberiPredmet("Aip");
	student1->izaberiPredmet("OOP");
	student1->izaberiPredmet("SP");

	Student* student2 = new Student(18645, "1721002735486", "Veljko Zivkovic", Datum(17, 9, 2020));
	fakultet->upisiStudenta(student2, "Racunarstvo i informatika");
	student2->izaberiPredmet("Aip");
	student2->izaberiPredmet("OOP");
	student2->izaberiPredmet("SP");
	student2->izaberiPredmet("OS");

	Student* student3 = new Student(19256, "1821003734589", "Petar Petrovic", Datum(21, 10, 2022));
	fakultet->upisiStudenta(student3, "Racunarstvo i informatika");
	student3->izaberiPredmet("Aip");

	Student* student4 = new Student(18598, "1920003734851", "Dusan Gligorijevic", Datum(17, 9, 2021));
	fakultet->upisiStudenta(student4, "Mikroelektronika");
	student4->izaberiPredmet("Elektronske komponente");
	student4->izaberiPredmet("Materijali");

	Student* student5 = new Student(18255, "2810000745824", "Stariji student", Datum(15, 8, 2019));
	fakultet->upisiStudenta(student5, "Mikroelektronika");
	student5->izaberiPredmet("Elektronske komponente");
	student5->izaberiPredmet("Materijali");
	student5->izaberiPredmet("Stampane ploce");

	fakultet->prikazi(cout);
	cout << "==============================" << endl;
	student1->zameniPredmet("Aip", "UUR");
	student4->zameniPredmet("Elektronske komponente", "Fizika");
	fakultet->prikazi(cout);

	cout << endl;
	cout << student1->izracunajESPB() << endl;
	cout << student5->izracunajESPB() << endl;
}