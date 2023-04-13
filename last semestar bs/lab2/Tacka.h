#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Tacka {
private:
	double x;
	double y;
	double z;
public:
	Tacka();
	Tacka(double, double, double);
	double get_x();
	double get_y();
	double get_z();
	void set_x(double);
	void set_y(double);
	void set_z(double);
	friend istream& operator>>(istream&, Tacka&);
	friend ostream& operator<<(ostream&, Tacka&);
	friend ifstream& operator>>(ifstream&, Tacka&);
	friend ofstream& operator<<(ofstream&, Tacka&);
	Tacka operator+(Tacka&);
	Tacka operator-(Tacka&);
	Tacka& operator=(Tacka);
	Tacka operator++(int);
	Tacka operator*(Tacka&);
	Tacka& operator+=(Tacka);
};

inline double Tacka::get_x() {
	return x;
}

inline double Tacka::get_y() {
	return y;
}

inline double Tacka::get_z() {
	return z;
}

inline void Tacka::set_x(double x1) {
	x = x1;
}

inline void Tacka::set_y(double y1) {
	y = y1;
}

inline void Tacka::set_z(double z1) {
	z = z1;
}