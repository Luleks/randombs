#pragma once
#include "Radnik.h"

class Menager : public Radnik {
private:
	char* tip;
public:
	Menager(int, char*, int, int, double, char*);
	~Menager();

	double odredi_platu() const;
	void prikazi(ostream&) const;

	friend istream& operator>>(istream&, Menager&);
};