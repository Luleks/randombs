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
