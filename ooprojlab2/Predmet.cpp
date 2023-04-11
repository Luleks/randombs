#include "Predmet.h"

Predmet::Predmet() {
	naziv = 0;
	sifra = 0;
	br_studenata = 0;
	studenti = 0;
	espb = 0;
	odsek = 0;
}

Predmet::Predmet(const char* ime, const char* espb, const char* sifra, Odsek* odsek) {
	naziv = new char[strlen(ime) + 1];
	strcpy(naziv, ime);
	this->espb = atoi(espb);
	this->sifra = new char[strlen(sifra) + 1];
	strcpy(this->sifra, sifra);
	br_studenata = 0;
	studenti = 0;
	this->odsek = odsek;
}

Predmet::~Predmet() {
	if (naziv != 0)
		delete[] naziv;
	if (sifra != 0)
		delete[] sifra;
	naziv = 0;
	sifra = 0;
}

void Predmet::dodajStudenta(Student* stud) {
	if (br_studenata == 0) {
		studenti = new Student * [1];
		studenti[br_studenata] = stud;
	}
	else {
		Student** pom_studenti = new Student * [br_studenata + 1];
		for (int i = 0; i < br_studenata; i++)
			pom_studenti[i] = studenti[i];
		pom_studenti[br_studenata] = stud;
		delete[] studenti;
		studenti = pom_studenti;
	}
	br_studenata += 1;
}

void Predmet::ukloniStudenta(Student* stud) {
	if (br_studenata == 0)
		throw exception("Nije moguce ukloniti studenta koji ne slusa predmet");
	int i = 0;
	while (i < br_studenata and stud->getIndex() != studenti[i]->getIndex())
		i += 1;
	if (i == br_studenata)
		throw exception("Student ne pohadja ovaj predmet");
	for (int j = i; j < br_studenata - 1; j++)
		studenti[j] = studenti[j + 1];
	br_studenata -= 1;
}