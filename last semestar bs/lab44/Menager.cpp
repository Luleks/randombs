#include "Menager.h"

Menager::Menager(int jmbg, char* puno_ime, int god_z, int god_s, double osnovica, char* tip)
	: Radnik(jmbg, puno_ime, god_z, god_s, osnovica) {
	this->tip = new char[strlen(tip) + 1];
	strcpy(this->tip, tip);
}

Menager::~Menager() {
	if (tip != 0)
		delete[] tip;
	tip = 0;
}

double Menager::odredi_platu() const {
	return 30 * osnovica + 1.5 * godina_zaposljenja;
}

void Menager::prikazi(ostream& out) const {
	out << "Ime i prezime: " << ime_i_prezime << ", " << godine_starosti << ", " << tip << ". Plata: " << odredi_platu() << endl;
}

istream& operator>>(istream& in, Menager& men) {
	in >> men.jmbg >> men.ime_i_prezime >> men.godina_zaposljenja >> men.godine_starosti >> men.osnovica;
	in >> men.tip;
	if (!strcmp("finansijski", men.tip) && !strcmp("tehnicki", men.tip) && !strcmp("marketinski", men.tip))
		strcpy(men.tip, "tehnicki");
	return in;
}