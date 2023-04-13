#include "Field.h"

istream& operator>>(istream& in, Field& f) {
	in >> f.chr;
	return in;
}