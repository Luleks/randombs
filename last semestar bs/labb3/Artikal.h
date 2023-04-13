#pragma once
#include <string.h>
#include <iostream>
using namespace std;

class Artikal {
private:
	char* naziv;
	double cena;
public:
	Artikal();
	Artikal(char*, double);
	Artikal(const Artikal&);
	virtual ~Artikal();
	virtual void showDescription(ostream&);
	double getPrice() const;
	friend ostream& operator<<(ostream&, Artikal&);
};

inline double Artikal::getPrice() const {
	return cena;
}

