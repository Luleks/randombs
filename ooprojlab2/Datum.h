#pragma once
#include <iostream>
using namespace std;

class Datum {
private:
    int dan;
    int mesec;
    int godina;
public:
    Datum(int day = 1, int month = 1, int year = 1970);
    ~Datum() {}

    int getDan() const;
    int getMesec() const;
    int getGodina() const;

    void setDan(int day);
    void setMesec(int month);
    void setGodina(int year);

    void prikaziDatum(ostream& out) const;
};

inline int Datum::getDan() const {
    return dan;
}

inline int Datum::getMesec() const {
    return mesec;
}

inline int Datum::getGodina() const {
    return godina;
}

inline void Datum::setDan(int day) {
    dan = day;
}

inline void Datum::setMesec(int month) {
    mesec = month;
}

inline void Datum::setGodina(int year) {
    godina = year;
}