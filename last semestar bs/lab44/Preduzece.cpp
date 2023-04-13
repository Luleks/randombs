#include "Preduzece.h"

Preduzece::Preduzece(const char* ime, int budg, int max_rad) {
	naziv = new char[strlen(ime) + 1];
	strcpy(naziv, ime);
	budzet = budg;
	br_radnika = 0;
	max_radnika = max_rad;
	radnici = new Radnik * [max_radnika] {0};
}

Preduzece::~Preduzece() {
	if (naziv != 0)
		delete[] naziv;
	naziv = 0;
	if (radnici != 0) {
		for (int i = 0; i < max_radnika; i++)
			delete radnici[i];
		delete[] radnici;
	}
	radnici = 0;
}

void Preduzece::dodaj_radnika(Radnik* radnik, int god_zap) {
	if (br_radnika + 1 <= max_radnika) {
		radnik->set_godina_zaposlenja(god_zap);
		radnici[br_radnika++] = radnik;
	}
}

void Preduzece::ukloni_radnika(int jmb) {
	int i = 0;
	if (br_radnika == 0)
		return;
	while (i < br_radnika && radnici[i]->get_jmbg() != jmb)
		i += 1;
	Radnik& to_remove = *radnici[i];
	to_remove.set_godina_zaposlenja(0);
	for (int j = i; j < br_radnika - 1; j++)
		radnici[i] = radnici[i + 1];
	br_radnika -= 1;
}

double Preduzece::ukupno_plata() {
	double s = 0;
	for (int i = 0; i < br_radnika; i++)
		s += radnici[i]->odredi_platu();
	return s;
}

bool Preduzece::je_rentabilno() {
	return budzet > ukupno_plata();
}

Preduzece& Preduzece::operator++() {
	for (int i = 0; i < br_radnika; i++)
		++(*radnici[i]);
	return *this;
}

Preduzece& Preduzece::operator--() {
	for (int i = 0; i < br_radnika; i++)
		-- (*radnici[i]);
	return *this;
}

void Preduzece::sortiraj() {
	for (int i = 1; i < br_radnika; i++) {
		int j = i - 1;
		Radnik* pom = radnici[i];
		while (j >= 0 && *radnici[j] > *pom) {
			radnici[j + 1] = radnici[j];
			radnici[j] = pom;
			j -= 1;
		}
	}
}

ostream& operator<<(ostream& out, Preduzece& pred) {
	pred.sortiraj();
	for (int i = 0; i < pred.br_radnika; i++)
		out << *pred.radnici[i];
	out << endl;
	return out;
}