#include "Datum.h"

Datum::Datum(int day, int month, int year) {
	dan = day;
	mesec = month;
	godina = year;
}

void Datum::prikaziDatum(ostream& out) const {
	out << dan << "." << mesec << "." << godina << endl;
}
