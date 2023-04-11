#include "Student.h"

Student::Student() {
	index = 0;
	jmbg = 0;
	ime = 0;
	datum_upisa = Datum();
	odsek = 0;
	predmeti = 0;
	br_predmeta = 0;
}

Student::Student(int index, const char* jmbg, const char* ime, Datum datum_upisa) {
	this->index = index;
	this->jmbg = new char[strlen(jmbg) + 1];
	strcpy(this->jmbg, jmbg);
	this->ime = new char[strlen(ime) + 1];
	strcpy(this->ime, ime);
	this->datum_upisa = datum_upisa;
	br_predmeta = 0;
	predmeti = 0;
	this->odsek = 0;
}

Student::~Student() {
	if (jmbg != 0)
		delete[] jmbg;
	if (ime != 0)
		delete[] ime;
	jmbg = 0;
	ime = 0;
}

void Student::prikaziStudenta(ostream& out) {
	out << index << " " << ime << " " << jmbg << " Odsek: " << odsek->getNaziv() << endl;
	out << "Predmeti: [ ";
	for (int i = 0; i < br_predmeta; i++) {
		out << predmeti[i]->getNaziv() << ", ";
	}
	out << "]" << endl;
}

void Student::postaviOdsek(Odsek* odsek) {
	this->odsek = odsek;
}

void Student::dodajPredmet(Predmet* predmet) {
	if (br_predmeta == 0) {
		predmeti = new Predmet * [1];
		predmeti[br_predmeta] = predmet;
	}
	else {
		Predmet** pom_predmeti = new Predmet * [br_predmeta + 1];
		for (int i = 0; i < br_predmeta; i++)
			pom_predmeti[i] = predmeti[i];
		pom_predmeti[br_predmeta] = predmet;
		delete[] predmeti;
		predmeti = pom_predmeti;
	}
	br_predmeta += 1;
}

void Student::zameniPredmet(const char* stari, const char* novi) {
	Predmet* p1 = odsek->getPredmet(stari);
	Predmet* p2 = odsek->getPredmet(novi);
	int i = 0;
	while (i < br_predmeta and strcmp(p1->getNaziv(), predmeti[i]->getNaziv()) != 0)
		i += 1;
	if (i == br_predmeta)
		throw exception("Unet je predmet koji student ne pohadja");
	predmeti[i] = p2;
	p2->dodajStudenta(this);
	p1->ukloniStudenta(this);
}

void Student::izaberiPredmet(const char* predmet) {
	Predmet* p1 = odsek->getPredmet(predmet);
	p1->dodajStudenta(this);
	dodajPredmet(p1);
}

int Student::izracunajESPB() {
	int s = 0;
	for (int i = 0; i < br_predmeta; i++)
		s += predmeti[i]->getESPB();
	return s;
}
