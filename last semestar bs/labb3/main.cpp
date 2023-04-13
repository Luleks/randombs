#include "Laptop.h"
#include "Torba.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
	Artikal** niz = new Artikal * [2018];
	ofstream izlaz("izlaz.txt");
	if (not izlaz.good())
		return 0;

	// rad funkcija klasa laptop i torba;
	char* imelaptopa = new char[30];
	strcpy(imelaptopa, "LaptopTest1");
	char* opislaptopa = new char[300];
	strcpy(opislaptopa, "Laptop sa 8gb rama i intel i5 sedmom generacijom");
	Laptop* laptop1 = new Laptop(imelaptopa, 55000, opislaptopa, false);
	delete[] imelaptopa; delete[] opislaptopa;
	char* imetorbe = new char[30];
	strcpy(imetorbe, "Torba za laptop1");
	Torba* torba1 = new Torba(imetorbe, 3000, 0);
	laptop1->turnOn();
	laptop1->turnOff();
	torba1->put(*laptop1);
	torba1->showDescription(cout);
	torba1->remove();
	torba1->showDescription(cout);

	for (int i = 0; i < 1009; i++) {
		double cena = 10000 + rand() % 100000;
		char* ime = new char[30];
		char* broj = new char[5];
		itoa(i, broj, 10);
		strcpy(ime, "Laptop");
		strcat(ime, broj);
		char* opis = new char[200];
		strcpy(opis, "Genericki opis");
		niz[i] = new Laptop(ime, cena * 2, opis, false);
		delete[] ime;
		delete[] opis;
	}
	for (int i = 1009; i < 2018; i++) {
		double cena = 2000 + rand() % 3000;
		char* ime = new char[30];
		char* broj = new char[5];
		itoa(i, broj, 10);
		strcpy(ime, "Torba");
		strcat(ime, broj);
		if (i % 2 == 0)
			niz[i] = new Torba(ime, cena, 0);
		else
			niz[i] = new Torba(ime, cena, niz[i - 1009]);
		delete[] ime;
	}

	for (int i = 1; i < 2018; i++) {
		int j = i - 1;
		Artikal* pom = niz[i];
		while (j >= 0 and pom->getPrice() < niz[j]->getPrice()) {
			niz[j+1] = niz[j];
			niz[j] = pom;
			pom = niz[j];
			j -= 1;
		}
	}

	for (int i = 0; i < 2018; i++) {
		izlaz << *niz[i];
	}

}