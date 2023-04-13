#include "Developer.h"

Developer::Developer(int jmbg, char* puno_ime, int god_z, int god_s, double osnovica, char* tip, int prek_sati) 
	: Radnik(jmbg, puno_ime, god_z, god_s, osnovica) {
	prekovremeni_sati = prek_sati;
	this->tip = new char[strlen(tip) + 1];
	strcpy(this->tip, tip);
}

Developer::~Developer() {
	if (tip != 0)
		delete[] tip;
	tip = 0;
}

double Developer::odredi_platu() const {
	return 25 * osnovica + 1.5 * godina_zaposljenja + 1 * prekovremeni_sati;
}

void Developer::prikazi(ostream& out) const {
	out << "Ime i prezime: " << ime_i_prezime << ", " << godine_starosti << ", " << tip << ". Plata: " << odredi_platu() << endl;
}

istream& operator>>(istream& in, Developer& dev) {
	in >> dev.jmbg >> dev.ime_i_prezime >> dev.godina_zaposljenja >> dev.godine_starosti >> dev.osnovica;
	in >> dev.prekovremeni_sati >> dev.tip;
	if (!strcmp("programer", dev.tip) && !strcmp("projektant", dev.tip) && !strcmp("tester", dev.tip))
		strcpy(dev.tip, "programer");
	return in;
}