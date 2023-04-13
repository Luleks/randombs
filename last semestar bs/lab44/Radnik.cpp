#include "Radnik.h"
#include <string.h>

Radnik::Radnik(int jmbg, char* puno_ime, int god_z, int god_s, double osnovica) {
	this->jmbg = jmbg;
	godina_zaposljenja = god_z;
	godine_starosti = god_s;
	this->osnovica = osnovica;
	ime_i_prezime = new char[strlen(puno_ime) + 1];
	strcpy(ime_i_prezime, puno_ime);
}

Radnik::~Radnik() {
	if (ime_i_prezime != 0)
		delete[] ime_i_prezime;
	ime_i_prezime = 0;
}

Radnik& Radnik::operator++() {
	osnovica = 1.1 * osnovica;
	return *this;
}

Radnik& Radnik::operator--() {
	osnovica = 0.9 * osnovica;
	return *this;
}

bool Radnik::operator>(const Radnik& rad1) const {
	return godine_starosti > rad1.godine_starosti;
}

ostream& operator<<(ostream& out, const Radnik& radnik) {
	radnik.prikazi(out);
	return out;
}