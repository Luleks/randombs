#include "Matrica.h"
#include <string.h>
#include <iostream>
using namespace std;

Matrica::Matrica() {
	br_vrsta = 20;
	br_kolona = 20;
	ime = new char[30];
	strcpy(ime, "Default ime");
	matrica = new double* [20];
	for (int i = 0; i < 20; i++)
		matrica[i] = new double[20];
}

Matrica::Matrica(int n, int m) {
	br_vrsta = n;
	br_kolona = m;
	ime = new char[30];
	strcpy(ime, "Default ime");
	matrica = new double*[br_vrsta];
	for (int i = 0; i < br_vrsta; i++)
		matrica[i] = new double[br_kolona];
}

Matrica::~Matrica() {
	if (matrica != 0) {
		for (int i = 0; i < br_vrsta; i++)
			delete[] matrica[i];
		delete[] matrica;
	}
	if (ime != 0) {
		delete[] ime;
	}
	ime = 0;
	matrica = 0;
}

double Matrica::suma_reda(int n) {
	if (n < 0 or n > br_vrsta - 1)
		return -1;
	double s = 0;
	for (int i = 0; i < br_kolona; i++)
		s += matrica[n][i];
	return s;
}

double Matrica::suma_kolone(int m) {
	if (m < 0 or m > br_kolona - 1)
		return -1;
	double s = 0;
	for (int i = 0; i < br_vrsta; i++)
		s += matrica[i][m];
	return s;
}

void Matrica::unesi() {
	cout << "Unesite ime matrice: ";
	cin >> ime;
	cout << "Unesite elemente matrice: " << endl;
	for (int i = 0; i < br_vrsta; i++)
		for (int j = 0; j < br_kolona; j++)
			cin >> matrica[i][j];
}

void Matrica::prikazi() {
	cout << "Matrica: " << ime << endl;
	for (int i = 0; i < br_vrsta; i++) {
		for (int j = 0; j < br_kolona; j++)
			cout << matrica[i][j] << " ";
		cout << endl;
	}
}

Matrica* Matrica::proizvod(const Matrica& mat2) {
	if (br_kolona != mat2.br_vrsta) {
		Matrica* p = new Matrica;
		return p;
	}
	Matrica* m = new Matrica(br_vrsta, mat2.br_kolona);
	for (int i = 0; i < br_vrsta; i++) {
		for (int j = 0; j < mat2.br_kolona; j++) {
			m->matrica[i][j] = 0;
			for (int k = 0; k < br_kolona; k++)
				m->matrica[i][j] += matrica[i][k] * mat2.matrica[k][j];
		}
	}
	return m;
}

Matrica* Matrica::kronekerov_proizvod(const Matrica& mat2) {
	Matrica* m = new Matrica(br_vrsta * mat2.br_vrsta, br_kolona * mat2.br_kolona);
	int blok_i = 0, blok_j = 0;
	for (int i = 0; i < br_vrsta; i++) {
		if (i > 0) {
			blok_i += mat2.br_vrsta;
			blok_j = 0;
		}
		for (int j = 0; j < br_kolona; j++) {
			if (j > 0)
				blok_j += mat2.br_kolona;
			double coef = matrica[i][j];
			for (int k = 0; k < mat2.br_vrsta; k++) {
				for (int l = 0; l < mat2.br_kolona; l++) {
					double element_za_upis = mat2.matrica[k][l] * coef;
					m->matrica[blok_i + k][blok_j + l] = element_za_upis;
				}
			}
		}
	}
	return m;
}