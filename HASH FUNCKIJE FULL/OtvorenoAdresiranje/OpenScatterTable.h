#pragma once
#include "OpenScatterObject.h"
#include <cmath>
#include <iomanip>

typedef unsigned int uint;

class OpenScatterTable {
	uint length;
	uint count;
	OpenScatterObject* table;
	
	uint h(const char* key) {
		uint res = 0;
		int i = 0, n = 5;
		while (key[i] != '\0' and i < n) {
			res = res << 7 ^ key[i];
			i += 1;
		}
		return h(res);
	}
	uint h(uint key) {
		const uint a = 2654435769;
		unsigned long long ak = a * key;
		return ak >> (32 - (int)log2(length));
	}
	uint c(uint i) {
		return i * i;
	}
public:
	OpenScatterTable(uint max) {
		length = max;
		count = 0;
		table = new OpenScatterObject[length];
	}
	~OpenScatterTable() {
		if (table != 0)
			delete[] table;
		table = 0;
	}
	uint findUnoccupied(OpenScatterObject obj) {
		uint probe = h(obj.getKey());
		if (table[probe].status != 2)
			return probe;
		uint i = 1;
		uint st = c(i);
		uint index = (probe + st) % length;
		while (probe != index and i < length) {
			if (table[index].status != 2)
				return index;
			i += 1;
			st = c(i);
			index = (probe + st) % length;
		}
		throw exception("Tablica je puna");
	}
	void insert(OpenScatterObject obj) {
		if (count == length)
			throw exception("Tablica je puna");
		uint index = findUnoccupied(obj);
		table[index] = obj;
		table[index].status = 2;
		count += 1;
	}
	uint findMatch(const char* key) {
		uint hash = h(key);
		for (uint i = 0; i < length; i++) {
			uint probe = (hash + c(i)) % length;
			if (table[probe].status == 0)
				return -1;
			else if (strcmp(table[probe].getKey(), key) == 0)
				return probe;
		}
		return -1;
	}
	OpenScatterObject find(const char* key) {
		uint ind = findMatch(key);
		if (ind == -1)
			return OpenScatterObject();
		return table[ind];
	}
	void withdraw(const char* key) {
		if (count == 0)
			throw exception("mpty list");
		uint ind = findMatch(key);
		if (ind == -1)
			throw exception("element not in list");
		table[ind].status = 1;
		count -= 1;
	}
	void print() {
		for (uint i = 0; i < length; i++) {
			cout << "|" << setw(3) << i << "| ";
			table[i].print();
			cout << endl;
		}
	}
};

