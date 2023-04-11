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
