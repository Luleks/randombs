#include "Fakultet.h"

Fakultet* Fakultet::fakultet = 0;

Fakultet::Fakultet(const char* ime, Datum dat_osn, const char* dekan) {
	naziv = new char[strlen(ime) + 1];
	strcpy(naziv, ime);
	datum_osnivanja = dat_osn;
	this->dekan = new char[strlen(dekan) + 1];
	strcpy(this->dekan, dekan);
	br_odseka = 0;
	odseci = 0;
}

Fakultet::~Fakultet() {
	if (naziv != 0)
		delete[] naziv;
	if (dekan != 0)
		delete[] dekan;
	if (odseci != 0) {
		for (int i = 0; i < br_odseka; i++)
			delete odseci[i];
		delete[] odseci;
	}
	naziv = 0;
	odseci = 0;
}

void Fakultet::setFakultet(const char* ime, Datum dat_osn, const char* dekan) {
	if (fakultet == 0)
		fakultet = new Fakultet(ime, dat_osn, dekan);
}

Fakultet* Fakultet::getFakultet() {
	return fakultet;
}

void Fakultet::dodajOdsek(const char* ime, const char* katedra, int br_predmeta, const char* predmeti[]) {
	if (br_odseka == 0) {
		odseci = new Odsek * [1];
		odseci[br_odseka] = new Odsek(ime, katedra, br_predmeta, predmeti, this);
	}
	else {
		Odsek** pom_odseci = new Odsek * [br_odseka + 1];
		for (int i = 0; i < br_odseka; i++)
			pom_odseci[i] = odseci[i];
		pom_odseci[br_odseka] = new Odsek(ime, katedra, br_predmeta, predmeti, this);
		delete[] odseci;
		odseci = pom_odseci;
	}
	br_odseka += 1;
}

void Fakultet::prikazi(ostream& out) {
	out << naziv << " since ";
	datum_osnivanja.prikaziDatum(out);
	out << "Dekan: " << dekan << endl;
	out << "------------------------------" << endl;
	for (int i = 0; i < br_odseka; i++) {
		out << i + 1 << ". ";
		odseci[i]->prikaziOdsek(out);
		out << "------------------------------" << endl;
	}
}

void Fakultet::upisiStudenta(Student* student, const char* ime_odseka) {
	int i = 0;
	while (i < br_odseka and strcmp(ime_odseka, odseci[i]->getNaziv()) != 0)
		i += 1;
	if (i == br_odseka)
		throw exception("Unet pogresan naziv odseka");
	Odsek* odsek = odseci[i];
	odsek->dodajStudenta(student);
	student->postaviOdsek(odsek);
}