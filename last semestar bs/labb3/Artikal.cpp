#include "Artikal.h"

Artikal::Artikal() {
	naziv = 0;
	cena = 0;
}

Artikal::Artikal(char* ime, double kosta) {
	naziv = new char[30];
	strcpy(naziv, ime);
	cena = kosta;
}

Artikal::Artikal(const Artikal& art1) {
	naziv = new char[30];
	strcpy(naziv, art1.naziv);
	cena = art1.cena;
}

Artikal::~Artikal() {
	if (naziv != 0)
		delete[] naziv;
	naziv = 0;
}

void Artikal::showDescription(ostream& izlaz) {
	izlaz << "Ime proizvoda: " << naziv << ", cena: " << cena << " ";
}

ostream& operator<<(ostream& izlaz, Artikal& a) {
	a.showDescription(izlaz);
	return izlaz;
}