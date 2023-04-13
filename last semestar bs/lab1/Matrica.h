#pragma once

/*Zadatak 7. Na programskom jeziku C++ kreirati klasu Matrica koja kao privatne
članove ima matricu, dimenzije matrice i naziv matrice (char*). Svaki element
matrice je tipa double. Klasa sadrži sledeće javne funkcije članice:
• konstruktor bez parametara koji postavlja dimenziju matrice na 20x20,
• konstruktor za postavljanje dimenzija matrice,
• destruktor,
• inline funkcije koje vraćaju dimenzije matrice,
• funkciju koja vraća sumu vrednosti elemenata traženog reda,
• funkciju koja vraća sumu vrednosti elemenata tražene kolone,
• funkciju za unos elementa matrice sa standardnog ulaza,
• funkciju za prikaz matrice na standardni izlaz,
• funkciju za računanje Kronekerovog proizvoda dve matrice,
• funkciju za računanje proizvoda dve matrice.
U funkciji main kreirati objekat klase Matrica, učitati vrednosti elemenata matrice
sa standardnog ulaza. Zatim sumirati vrednosti 1 i 3. kolone, kao i 2 i 3. reda, a
potom prikazati matricu.*/

class Matrica {
private:
	double** matrica;
	int br_kolona;
	int br_vrsta;
	char* ime;
public:
	Matrica();
	Matrica(int, int);
	~Matrica();
	int vrati_br_kolona();
	int vrati_br_vrsta();
	double suma_reda(int);
	double suma_kolone(int);
	void unesi();
	void prikazi();
	Matrica* kronekerov_proizvod(const Matrica&);
	Matrica* proizvod(const Matrica&);
};

inline int Matrica::vrati_br_kolona() {
	return br_kolona;
}
inline int Matrica::vrati_br_vrsta() {
	return br_vrsta;
}