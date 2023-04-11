#pragma once
#include <string.h>
#include "Student.h"
#include "Odsek.h"
#include <iostream>
using namespace std;

class Student;
class Odsek;

class Predmet {
private:
	char* naziv;
	int espb;
	char* sifra;
	Student** studenti;
	int br_studenata;
	Odsek* odsek;

	Predmet();
	Predmet(const char* ime, const char* espb, const char* sifra, Odsek* odsek);
	~Predmet();

	friend class Odsek;

public:
	char* getNaziv();
};

inline char* Predmet::getNaziv() {
	return naziv;
}

