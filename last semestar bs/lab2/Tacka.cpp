#include "Tacka.h"

Tacka::Tacka() {
	x = y = z = 0;
}

Tacka::Tacka(double k1, double k2, double k3) 
		:x(k1), y(k2), z(k3) {
}

istream& operator>>(istream& ulaz, Tacka& t) {
	ulaz >> t.x >> t.y >> t.z;
	return ulaz;
}

ostream& operator<<(ostream& izlaz, Tacka& t) {
	izlaz << t.x << ' ' << t.y << ' ' << t.z;
	return izlaz;
}

ifstream& operator>>(ifstream& ulaz, Tacka& t) {
	ulaz >> t.x >> t.y >> t.z;
	return ulaz;
}

ofstream& operator<<(ofstream& izlaz, Tacka& t) {
	izlaz << t.x << ' ' << t.y << ' ' << t.z;
	return izlaz;
}

Tacka Tacka::operator-(Tacka& t1) {
	return Tacka(x - t1.x, y - t1.y, z - t1.z);
}

Tacka Tacka::operator+(Tacka& t1) {
	return Tacka(x + t1.x, y + t1.y, z + t1.z);
}

Tacka& Tacka::operator=(Tacka t1) {
	if (this != &t1) {
		x = t1.x;
		y = t1.y;
		z = t1.z;
	}
	return *this;
}

Tacka Tacka::operator++(int n) {
	x += 1;
	y += 1;
	z += 1;
	return Tacka(x + 1, y + 1, z + 1);
}

Tacka Tacka::operator*(Tacka& t1) {
	return Tacka(x * t1.x, y * t1.y, z * t1.z);
}

Tacka& Tacka::operator+=(Tacka t1) {
	x += t1.x;
	y += t1.y;
	z += t1.z;
	return *this;
}