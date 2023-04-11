#include "Odsek.h"

Odsek::Odsek() {
	naziv = 0;
	katedra = 0;
	studenti = 0;
	br_studenata = 0;
	size = 0;
	br_predmeta = 0;
	predmeti = 0;
	fakultet = 0;
}

Odsek::Odsek(const char* ime, const char* katedra, int br_predmeta, const char* predmet_pod[], Fakultet* fakultet) {
	naziv = new char[strlen(ime) + 1];
	strcpy(naziv, ime);
	this->katedra = new char[strlen(katedra) + 1];
	strcpy(this->katedra, katedra);
	studenti = 0;
	br_studenata = 0;
	size = 0;
	this->br_predmeta = br_predmeta;
	predmeti = new Predmet * [this->br_predmeta];
	for (int i = 0; i < this->br_predmeta; i++) {
		predmeti[i] = new Predmet(predmet_pod[3 * i], predmet_pod[3 * i + 1], predmet_pod[3 * i + 2], this);
	}
	this->fakultet = fakultet;
}

Odsek::~Odsek() {
	if (naziv != 0)
		delete[] naziv;
	if (katedra != 0)
		delete[] katedra;
	naziv = katedra = 0;
}

void Odsek::prikaziOdsek(ostream& out) {
	out << "Odsek: " << naziv << ", katedra " << katedra << endl;
	out << "Broj studenata: " << br_studenata << endl << endl;
	for (int i = 0; i < br_studenata; i++) {
		studenti[i]->prikaziStudenta(out);
	}
	out << endl << "Spisak predmeta: " << endl;
	for (int i = 0; i < br_predmeta; i++) {
		out << "	" << i + 1 << ") ";
		out << predmeti[i]->sifra << " " << predmeti[i]->naziv << " " << predmeti[i]->espb << " " << 
			predmeti[i]->br_studenata << endl;
	}
}

void Odsek::dodajStudenta(Student* student) {
	if (br_studenata == 0) {
		studenti = new Student * [1];
		studenti[br_studenata] = student;
	}
	else {
		Student** pom_studenti = new Student * [br_studenata + 1];
		for (int i = 0; i < br_studenata; i++)
			pom_studenti[i] = studenti[i];
		pom_studenti[br_studenata] = student;
		delete[] studenti;
		studenti = pom_studenti;
	}
	br_studenata += 1;
}

Predmet* Odsek::getPredmet(const char* naziv) {
	int i = 0;
	while (i < br_predmeta and strcmp(naziv, predmeti[i]->getNaziv()) != 0)
		i += 1;
	if (i == br_predmeta)
		throw exception("Nepostojeci predmet");
	return predmeti[i];
}