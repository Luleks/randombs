#include "Matrica.h"

int main() {
	ifstream in1("matrix1.txt");
	ofstream out1("omatrix1.txt");
	if (not in1.good() or not out1.good())
		return 0;
	int n, m, k, l, p, q;
	cin >> n >> m;
	Matrica* m1 = new Matrica(m, n);
	in1 >> *m1;
	cin >> k >> l >> p >> q;

	Tacka suma_k = m1->suma_kolone(k);
	Tacka suma_kolona = m1->suma_kolone(l) + suma_k;
	Tacka suma_p = m1->suma_reda(p);
	Tacka suma_redova = m1->suma_reda(q) + suma_p;
	cout << "Suma kolona k i l je " << suma_kolona << endl;
	cout << "Suma redova p i q je " << suma_redova << endl;

	out1 << *m1;
	m1->povecaj();
	m1->normalizuj(0, 2, 0, 3, 0, 4);
	Matrica* m2 = new Matrica(2, 5);
	*m2 = *m1;
	m2->tacka_na(0, 0) = Tacka(10, 10, 10);
	cout << *m1;
	cout << *m2;

	delete m1;
	delete m2;
}