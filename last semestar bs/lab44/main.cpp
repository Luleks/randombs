#include "Preduzece.h"
#include "Developer.h"
#include "Menager.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
	Preduzece* pred = new Preduzece("firma", 18000000, 2020);
	srand(time(0));
	ofstream izlaz("izlaz.txt");
	if (!izlaz.good())
		return 0;

	for (int i = 0; i < 1009; i++) {
		int jmbg = 25000 + rand();

		char* ime = new char[30];
		strcpy(ime, "Developer_");
		char* br_dev = new char[5];
		itoa(i, br_dev, 10);
		strcat(ime, br_dev);

		int godina_z = 2000 + rand() % 23;
		int godina_s = 18 + rand() % 48;
		double osnovica = (30 - 15) * ((double)rand() / (double)RAND_MAX) + 15;
		int prek_sati = rand() % 20;

		char* tip = new char[11];
		if (i % 3 == 0)
			strcpy(tip, "programer");
		else if (i % 3 == 1)
			strcpy(tip, "tester");
		else
			strcpy(tip, "projektant");

		Radnik* r = new Developer(jmbg, ime, 0, godina_s, osnovica, tip, prek_sati);
		pred->dodaj_radnika(r, godina_z);
	}

	for (int i = 1009; i < 2018; i++) {
		int jmbg = 25000 + rand();

		char* ime = new char[30];
		strcpy(ime, "Menager_");
		char* br_dev = new char[5];
		itoa(i, br_dev, 10);
		strcat(ime, br_dev);

		int godina_z = 2000 + rand() % 23;
		int godina_s = 18 + rand() % 48;
		double osnovica = (30 - 15) * ((double)rand() / (double)RAND_MAX) + 15;

		char* tip = new char[18];
		if (i % 3 == 0)
			strcpy(tip, "tehnicki");
		else if (i % 3 == 1)
			strcpy(tip, "marketinski");
		else
			strcpy(tip, "finansijski");

		Radnik* r = new Menager(jmbg, ime, 0, godina_s, osnovica, tip);
		pred->dodaj_radnika(r, godina_z);
	}
	cout << pred->ukupno_plata() << endl;
	if (pred->je_rentabilno()) {
		++(*pred);
		cout << "r" << endl;
	}
	else {
		--(*pred);
		cout << "nr" << endl;
	}
	cout << pred->ukupno_plata() << endl;
	izlaz << *pred;
	
	return 0;
}