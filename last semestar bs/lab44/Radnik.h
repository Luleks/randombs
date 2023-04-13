#pragma once
#include <iostream>
using namespace std;

class Radnik {
protected:
	int jmbg;
	char* ime_i_prezime;
	int godina_zaposljenja;
	int godine_starosti;
	double osnovica;
public:
	Radnik(int, char*, int, int, double);
	virtual ~Radnik();

	int get_jmbg() const;
	char* get_iip() const;
	int get_godina_zaposljenja() const;
	void set_godina_zaposlenja(int);

	Radnik& operator++();
	Radnik& operator--();
	bool operator>(const Radnik&) const;

	virtual double odredi_platu() const = 0;
	virtual void prikazi(ostream&) const = 0;

	friend ostream& operator<<(ostream&, const Radnik&);
};

inline int Radnik::get_jmbg() const {
	return jmbg;
}

inline char* Radnik::get_iip() const {
	return ime_i_prezime;
}

inline int Radnik::get_godina_zaposljenja() const {
	return godina_zaposljenja;
}

inline void Radnik::set_godina_zaposlenja(int god) {
	godina_zaposljenja = god;
}