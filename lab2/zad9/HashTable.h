#include "HashObject.h"
#include <cmath>
#include <exception>
using namespace std;

typedef unsigned int uint;

class HashTable {
protected:
	uint length;
	uint count;
	
	uint f(const char* s) {
		uint res = 0;
		int i = 0, n = 5;
		while (s[i] != '\0' and i < n) {
			res = res << 7 ^ s[i];
			i += 1;
		}
		return f(res);
	}

	uint f(uint k) {
		uint const a = 2654435769;
		unsigned long long ak = a * k;
		return ak >> (32 - (int)log2(length));
	}
};

class OpenScatterTable : public HashTable {
protected:
	ScatterObject* table;
public:
	OpenScatterTable(uint leng) {
		length = leng;
		count = 0;
		table = new ScatterObject[length];
	}
	~OpenScatterTable() {
		if (table != 0)
			delete[] table;
		table = 0;
	}
	uint c(uint i) {
		return (i * i);
	}
	void insert(ScatterObject obj) {
		if (count == length)
			throw exception("list is full");
		uint hash = f(obj.getKey());
		uint probe = hash;
		if (table[hash].status != 2) {
			table[hash] = obj;
			table[hash].status = 2;
			count += 1;
			return;
		}
		int i = 1;
		do {
			probe = (hash + c(i)) % length;
			if (table[probe].status != 2) {
				table[hash] = obj;
				table[hash].status = 2;
				count += 1;
				return;
			}
			i += 1;
		} while (probe != hash and i < length);
		throw exception("List full or poor second transform");
	}
	uint findIndex(const char* key) {
		uint hash = f(key);
		for (uint i = 0; i < length; i++) {
			uint probe = (hash + c(i)) % length;
			if (table[probe].status == 0)
				return ~0U;
			if (strcmp(table[probe].getKey(), key) == 0)
				return probe;
		}
		return ~0U;
	}
	ScatterObject find(const char* key) {
		uint ind = findIndex(key);
		if (ind == ~0U)
			return ScatterObject();
		return table[ind];
	}
	bool withdraw(const char* key) {
		uint ind = findIndex(key);
		if (ind == ~0U)
			return false;
		table[ind].status = 1;
		count -= 1;
		return true;
	}
	void print() {
		for (int i = 0; i < length; i++) {
			cout << "|" << i << "| ";
			table[i].print();
			cout << endl;
		}
	}
};