#pragma once
#include "Radnik.h"

class Preduzece {
private:
	char* naziv;
	int budzet;
	Radnik** radnici;
	int max_radnika;
	int br_radnika;
public:
	Preduzece(const char*, int, int);
	~Preduzece();

	void dodaj_radnika(Radnik*, int);
	void ukloni_radnika(int);
	double ukupno_plata();
	bool je_rentabilno();
	void sortiraj();

	Preduzece& operator++();
	Preduzece& operator--();

	friend ostream& operator<<(ostream&, Preduzece&);
};

