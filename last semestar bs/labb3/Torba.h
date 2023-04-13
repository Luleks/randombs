#pragma once
#include "Artikal.h"

class Torba : public Artikal {
private:
	Artikal* sadrzaj;
public:
	Torba();
	Torba(char*, double, Artikal*);
	Torba(const Torba&);
	~Torba();
	void showDescription(ostream&);
	void put(Artikal&);
	void remove();
};

