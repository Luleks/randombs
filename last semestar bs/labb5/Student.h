#pragma once
#include <string>
#include <iostream>
using namespace std;

class Student {
private:
	string ime;
	string prezime;
	int br_ind;
	double prosecna_ocena;
public:
	Student();
	Student(string ime, string prezime, int index, double prosek);
	Student(const Student& s1);
	~Student();
	Student& operator=(Student& s1);
	friend ostream& operator<<(ostream& out, Student& s1);
	friend istream& operator>>(istream& in, Student& s1);
};

