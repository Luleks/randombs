#pragma once
#include "Fakultet.h"
#include "Student.h"
#include "Predmet.h"
#include <string.h>
#include <iostream>
using namespace std;

class Fakultet;
class Student;
class Predmet;

class Odsek {
private:
	char* naziv;
	char* katedra;

	Student** studenti;
	int br_studenata;
	int size;

	Predmet** predmeti;
	int br_predmeta;

	Fakultet* fakultet;
	
	Odsek();
	Odsek(const char* ime, const char* katedra, int br_predmeta, const char* predmet_pod[], Fakultet* fakultet);
	~Odsek();

	void prikaziOdsek(ostream& out);
	void dodajStudenta(Student* student);

	friend class Fakultet;

public:
	char* getNaziv();
	Predmet* getPredmet(const char* naziv);
};

inline char* Odsek::getNaziv() {
	return naziv;
}

