#pragma once
#include "Radnik.h"

class Developer : public Radnik {
private:
	char* tip;
	int prekovremeni_sati;
public:
	Developer(int, char*, int, int, double, char*, int);
	~Developer();

	double odredi_platu() const;
	void prikazi(ostream&) const;

	friend istream& operator>>(istream&, Developer&);
};