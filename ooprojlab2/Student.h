#pragma once
#include "Odsek.h"
#include "Predmet.h"
#include "Datum.h"
#include <iostream>
#include <string.h>
using namespace std;

class Predmet;
class Odsek;

class Student {
private:
	int index;
	char* jmbg;
	char* ime;
	Datum datum_upisa;
	Odsek* odsek;
	Predmet** predmeti;
	int br_predmeta;

public:
	Student();
	Student(int index, const char* jmbg, const char* ime, Datum datum_upisa);
	~Student();

	void prikaziStudenta(ostream& out);
	void postaviOdsek(Odsek* odsek);
};
