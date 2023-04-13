#include "Torba.h"

Torba::Torba()
	: Artikal() {
	sadrzaj = 0;
}

Torba::Torba(char* ime, double kosta, Artikal* a)
	: Artikal(ime, kosta) {
	sadrzaj = a;
}

Torba::Torba(const Torba& t1)
	: Artikal(t1) {
	sadrzaj = 0;
}

Torba::~Torba() {
	if (sadrzaj != 0)
		delete sadrzaj;
	sadrzaj = 0;
}

void Torba::showDescription(ostream& izlaz) {
	izlaz << "Torba za laptop racunar ";
	Artikal::showDescription(izlaz);
	if (sadrzaj != 0)
		sadrzaj->showDescription(izlaz);
	else
		izlaz << endl;
}

void Torba::put(Artikal& a) {
	if (sadrzaj == 0) {
		sadrzaj = &a;
		cout << "Artikal smesten u torbu" << endl;
	}
	else
		cout << "Torba je trenutno zauzeta" << endl;
}

void Torba::remove() {
	if (sadrzaj == 0)
		cout << "Torba je vec prazna" << endl;
	else {
		sadrzaj = 0;
		cout << "Torba je sada prazna" << endl;
	}
}