#include "Matrica.h"
#include <iostream>
using namespace std;

int main() {
	Matrica m1(3, 1);
	m1.unesi();
	cout << "Suma vrednosti elemenata 1. i 3. kolone je " << m1.suma_kolone(1) << " i " << m1.suma_kolone(3) << endl;
	cout << "Suma vrednosti elemenata 2. i 3. vrste je " << m1.suma_reda(2) << " i " << m1.suma_reda(3) << endl;
	m1.prikazi();
}