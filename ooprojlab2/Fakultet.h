#pragma once
#include "Datum.h"
#include "Odsek.h"
#include "Student.h"
#include <string.h>
#include <iostream>
#include <exception>
using namespace std;

class Student;
class Odsek;

class Fakultet {
private:
	char* naziv;
	char* dekan;
	Datum datum_osnivanja;
	static Fakultet* fakultet;
	Odsek** odseci;
	int br_odseka;

	Fakultet(const char* ime, Datum dat_osn, const char* dekan);

public:
	~Fakultet();

	static Fakultet* getFakultet();
	static void setFakultet(const char* ime, Datum dat_osn, const char* dekan);

	void upisiStudenta(Student* student, const char* ime_odseka);
	void dodajOdsek(const char* ime, const char* katedra, int br_predmeta, const char* predmeti[]);

	void prikazi(ostream& out);
};

