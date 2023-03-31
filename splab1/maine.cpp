#include "Zad345.h"
#include "Zad6.h"
#include "Zad8.h"
#include "Zad9.h"
#include "Zad12.h"

int main() {
	/* DRIVER CODE FOR Zad345
	CSortList<int> csl1;
	CSortList<int> csl2;
	CSortList<int> csl3;
	for (int i = 0; i < 10; i++) {
		csl1.addToHead(10 + rand() % 90);
		csl2.addToHead(10 + rand() % 90);
		csl3.addToHead(10 + rand() % 90);
	}
	cout << "------- Selection sorted -------" << endl;
	csl1.print();
	csl1.selectionSort(false);
	csl1.print();
	csl1.selectionSort(true);
	csl1.print();
	cout << endl;
	cout << "------- Bubble sorted -------" << endl;
	csl2.print();
	csl2.bubbleSort(false);
	csl2.print();
	csl2.bubbleSort(true);
	csl2.print();
	cout << endl;
	cout << "------- Insertion sorted -------" << endl;
	csl3.print();
	csl3.insertionSort(false);
	csl3.print();
	csl3.insertionSort(true);
	csl3.print();
	*/

	/* DRIVER CODE FOR Zad6
	CStaticSortList ssl(10);
	for (int i = 0; i < 10; i++)
		ssl.addToHead(10 + rand() % 90);
	ssl.print();
	ssl.sort(true);
	ssl.print();
	ssl.sort(false);
	ssl.print();
	*/

	/* DRIVER CODE FOR Zad12
	CPolynomLL pol, pol2;
	pol.Coef(4, 18.6);
	pol.Coef(5, 25.24);
	pol.Coef(0, -18);
	pol.Coef(3, -22);
	pol.Coef(1, 1);
	pol.print();

	pol2.Coef(3, 10);
	pol2.Coef(1, 1.5);
	pol2.Coef(0, -0.05);
	pol2.print();

	CPolynomLL* p3 = pol.add(&pol2);
	p3->print();
	CPolynomLL* p4 = pol.mul(&pol2);
	p4->print();
	*/

	/* DRIVER CODE FOR Zad9
	CReorgList crl;
	for (int i = 0; i < 10; i++)
		crl.addToTail(10 + rand() % 90);
	crl.print();
	cout << crl.getToStart(74)->key << " " << crl.getToStart(74)->key << endl;
	crl.print();
	cout << crl.getTransp(44)->key << " " << crl.getTransp(84)->key << endl;
	crl.print();
	*/


	/* DRIVER CODE FOR Zad8
	CSparseMatrix csm(4, 5);
	int c = 0;
	for (int i = 0; i < 4; i+=2) {
		for (int j = 0; j < 5; j+=2) {
			csm.setAt(c++, i, j);
		}
	}
	csm.print();
	cout << csm.getAt(1, 3) << " " << csm.getAt(0, 2);
	*/
	return 0;
}