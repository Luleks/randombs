#pragma once
#include "Artikal.h"

class Laptop : public Artikal {
private:
	char* opis;
	bool stanje; // 1 - ukljuceno, 0 - iskljuceno
public:
	Laptop();
	Laptop(char*, double, char*, bool);
	Laptop(const Laptop&);
	~Laptop();
	void showDescription(ostream&);
	void turnOn();
	void turnOff();
};

