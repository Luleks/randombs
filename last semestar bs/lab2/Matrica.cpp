#include "Matrica.h"
#include <string.h>

Matrica::Matrica() {
	br_vrsta = 20;
	br_kolona = 20;
	ime = new char[30];
	strcpy(ime, "Default ime");
	matrica = new Tacka* [20];
	for (int i = 0; i < 20; i++)
		matrica[i] = new Tacka[20];
}

Matrica::Matrica(int n, int m) {
	br_vrsta = n;
	br_kolona = m;
	ime = new char[30];
	strcpy(ime, "Default ime");
	matrica = new Tacka* [br_vrsta];
	for (int i = 0; i < br_vrsta; i++)
		matrica[i] = new Tacka[br_kolona];
}

Matrica::Matrica(const Matrica& m1) {
	br_vrsta = m1.br_vrsta;
	br_kolona = m1.br_kolona;
	ime = new char[30];
	strcpy(ime, m1.ime);
	matrica = new Tacka* [br_vrsta];
	for (int i = 0; i < br_vrsta; i++)
		matrica[i] = new Tacka[br_kolona];
	for (int i = 0; i < br_vrsta; i++)
		for (int j = 0; j < br_kolona; j++)
			matrica[i][j] = m1.matrica[i][j];
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
			cout << '(' << matrica[i][j] << ") ";
		cout << endl;
	}
}

Tacka Matrica::suma_reda(int n) {
	if (n < 0 || n > br_vrsta - 1)
		return Tacka();
	Tacka s;
	for (int i = 0; i < br_kolona; i++)
		s = s + matrica[n][i];
	return s;
}

Tacka Matrica::suma_kolone(int m) {
	if (m < 0 || m > br_kolona - 1)
		return Tacka();
	Tacka s;
	for (int i = 0; i < br_vrsta; i++)
		s = s + matrica[i][m];
	return s;
}

Matrica* Matrica::proizvod(const Matrica& mat2) {
	if (br_kolona != mat2.br_vrsta) {
		Matrica* p = new Matrica(1, 1);
		return p;
	}
	Matrica* m = new Matrica(br_vrsta, mat2.br_kolona);
	for (int i = 0; i < br_vrsta; i++) {
		for (int j = 0; j < mat2.br_kolona; j++) {
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
			for (int k = 0; k < mat2.br_vrsta; k++) {
				for (int l = 0; l < mat2.br_kolona; l++) {
					m->matrica[blok_i + k][blok_j + l] = mat2.matrica[k][l] * matrica[i][j];
				}
			}
		}
	}
	return m;
}

void Matrica::povecaj() {
	for (int i = 0; i < br_vrsta; i++)
		for (int j = 0; j < br_kolona; j++)
			matrica[i][j]++;
}

void Matrica::normalizuj(double minx, double maxx, double miny, double maxy, double minz, double maxz) {
	for (int i = 0; i < br_vrsta; i++)
		for (int j = 0; j < br_kolona; j++) {
			if (minx > matrica[i][j].get_x())
				matrica[i][j].set_x(minx);
			else if (maxx < matrica[i][j].get_x())
				matrica[i][j].set_x(maxx);
			if (miny > matrica[i][j].get_y())
				matrica[i][j].set_y(miny);
			else if (maxy < matrica[i][j].get_y())
				matrica[i][j].set_y(maxy);
			if (minz > matrica[i][j].get_z())
				matrica[i][j].set_z(minz);
			else if (maxz < matrica[i][j].get_z())
				matrica[i][j].set_z(maxz);
		}
}

Matrica& Matrica::operator=(Matrica& m1) {
	if (this != &m1) {
		delete[] ime;
		for (int i = 0; i < br_vrsta; i++)
			delete matrica[i];
		delete[] matrica;
		br_vrsta = m1.br_vrsta;
		br_kolona = m1.br_kolona;
		ime = new char[30];
		strcpy(ime, m1.ime);
		matrica = new Tacka*[br_vrsta];
		for (int i = 0; i < br_vrsta; i++)
			matrica[i] = new Tacka[br_kolona];
		for (int i = 0; i < br_vrsta; i++)
			for (int j = 0; j < br_kolona; j++)
				matrica[i][j] = m1.matrica[i][j];
	}
	return *this;
}

Tacka& Matrica::tacka_na(int x, int y) {
	if (x >= 0 && x < br_vrsta && y >= 0 && y < br_kolona)
		return matrica[x][y];
	return matrica[0][0];
}

istream& operator>>(istream& ulaz, Matrica& m1) {
	cout << "Unesite ime matrice: ";
	ulaz >> m1.ime;
	cout << "Unesite elemente matrice: " << endl;
	for (int i = 0; i < m1.br_vrsta; i++)
		for (int j = 0; j < m1.br_kolona; j++)
			ulaz >> m1.matrica[i][j];
	return ulaz;
}

ostream& operator<<(ostream& izlaz, Matrica& m1) {
	izlaz << "Matrica: " << m1.ime << endl;
	for (int i = 0; i < m1.br_vrsta; i++) {
		for (int j = 0; j < m1.br_kolona; j++)
			izlaz << '(' << m1.matrica[i][j] << ") ";
		izlaz << endl;
	}
	return izlaz;
}

ifstream& operator>>(ifstream& ulaz, Matrica& m1) {
	ulaz >> m1.ime;
	for (int i = 0; i < m1.br_vrsta; i++)
		for (int j = 0; j < m1.br_kolona; j++)
			ulaz >> m1.matrica[i][j];
	return ulaz;
}

ofstream& operator<<(ofstream& izlaz, Matrica& m1) {
	izlaz << "Matrica: " << m1.ime << endl;
	for (int i = 0; i < m1.br_vrsta; i++) {
		for (int j = 0; j < m1.br_kolona; j++)
			izlaz << '(' << m1.matrica[i][j] << ") ";
		izlaz << endl;
	}
	return izlaz;
}