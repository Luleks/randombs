#pragma once
#include <iostream>
using namespace std;

template <class Type, int size>
class Bafer {
private:
	Type* niz;
	int tren;
public:
	Bafer() {
		tren = 0;
		niz = new Type[size];
	}
	~Bafer() {
		if (niz != 0)
			delete[] niz;
		niz = 0;
	}
	Type& getItem(int index) {
		if (index < 0 || index >= size)
			return niz[0];
		return niz[index];
	}
	Type& getFirst() {
		return niz[0];
	}
	Type& getLast() {
		return niz[tren - 1];
	}
	void add(Type& item) {
		if (tren + 1 <= size)
			niz[tren++] = item;
	}
	friend ostream& operator<< <>(ostream& out, Bafer<Type, size>& b);
};

template <class Type, int size>
ostream& operator<<(ostream& out, Bafer<Type, size>& b) {
	for (int i = 0; i < b.tren; i++)
		out << b.niz[i] << endl;
	return out;
}

