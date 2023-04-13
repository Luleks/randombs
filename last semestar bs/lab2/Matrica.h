#pragma once
#include "Tacka.h"

class Matrica {
private:
	Tacka** matrica;
	int br_kolona;
	int br_vrsta;
	char* ime;
public:
	Matrica();
	Matrica(int, int);
	Matrica(const Matrica&);
	~Matrica();
	int vrati_br_kolona();
	int vrati_br_vrsta();
	Tacka suma_reda(int);
	Tacka suma_kolone(int);
	void unesi();
	void prikazi();
	Matrica* kronekerov_proizvod(const Matrica&);
	Matrica* proizvod(const Matrica&);

	void povecaj();
	void normalizuj(double, double, double, double, double, double);
	Matrica& operator=(Matrica&);
	Tacka& tacka_na(int, int);
	friend istream& operator>>(istream&, Matrica&);
	friend ostream& operator<<(ostream&, Matrica&);
	friend ifstream& operator>>(ifstream&, Matrica&);
	friend ofstream& operator<<(ofstream&, Matrica&);
};

inline int Matrica::vrati_br_kolona() {
	return br_kolona;
}
inline int Matrica::vrati_br_vrsta() {
	return br_vrsta;
}