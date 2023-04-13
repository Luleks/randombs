#include "Laptop.h"

Laptop::Laptop()
	: Artikal() {
	opis = 0;
	stanje = 0;
}

Laptop::Laptop(char* ime, double kosta, char* desc, bool s)
	: Artikal(ime, kosta) {
	opis = new char[200];
	strcpy(opis, desc);
	stanje = s;
}

Laptop::Laptop(const Laptop& l1)
	: Artikal(l1) {
	opis = new char[200];
	strcpy(opis, l1.opis);
	stanje = l1.stanje;
}

Laptop::~Laptop() {
	if (opis != 0)
		delete[] opis;
	opis = 0;
}

void Laptop::turnOn() {
	stanje = 1;
	cout << "Laptop je ukljucen" << endl;
}

void Laptop::turnOff() {
	stanje = 0;
	cout << "Laptop je sada iskljucen" << endl;
}

void Laptop::showDescription(ostream& izlaz) {
	Artikal::showDescription(izlaz);
	izlaz << opis << endl;
}
