#include "Fakultet.h"

int main() {
	Fakultet::setFakultet("Elektronski fakultet", Datum(10, 11, 1968));
	Fakultet* fakultet = Fakultet::getFakultet();

	const char* predmetiRI[] = { "Aip", "7", "R1", "OOP", "6", "R2", "SP", "6", "R3", "OS", "6", "R4"};
	fakultet->dodajOdsek("Racunarstvo i informatika", "Racunarstvo i informatika", 4, predmetiRI);

	const char* predmetiMIKRO[] = {"Elektronske komponente", "6", "M1", "Materijali", "5", "M2", "Stampane ploce",
	"5", "M3"};
	fakultet->dodajOdsek("Mikroelektronika", "Mikroelektronika", 3, predmetiMIKRO);

	Student* student1 = new Student(18587, "0311002730052", "Luka Velickovic", Datum(17, 9, 2021));
	fakultet->upisiStudenta(student1, "Racunarstvo i informatika");

	fakultet->prikazi(cout);
}