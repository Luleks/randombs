#include "Student.h"

Student::Student() {
	ime = prezime = "";
	br_ind = 0;
	prosecna_ocena = 0;
}

Student::Student(string ime, string prezime, int index, double prosek) {
	this->ime = ime;
	this->prezime = prezime;
	br_ind = index;
	prosecna_ocena = prosek;
}

Student::Student(const Student& s1) {
	ime = s1.ime;
	prezime = s1.prezime;
	br_ind = s1.br_ind;
	prosecna_ocena = s1.prosecna_ocena;
}

Student::~Student() {

}

Student& Student::operator=(Student& s1) {
	if (this != &s1) {
		ime = s1.ime;
		prezime = s1.prezime;
		br_ind = s1.br_ind;
		prosecna_ocena = s1.prosecna_ocena;
	}
	return *this;
}

ostream& operator<<(ostream& out, Student& s1) {
	out << s1.br_ind << " " << s1.ime << " " << s1.prezime << "(" << s1.prosecna_ocena << ")";
	return out;
}

istream& operator>>(istream& in, Student& s1) {
	in >> s1.br_ind >> s1.ime >> s1.prezime >> s1.prosecna_ocena;
	return in;
}