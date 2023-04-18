#pragma once
#include "ChainedScatterObject.h"
#include <iomanip>

class ChainedScatterTable {
	ChainedScatterObject* table;
	uint length;
	uint count;

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
public:
	ChainedScatterTable(uint max) {
		length = max;
		count = 0;
		table = new ChainedScatterObject[length];
	}
	~ChainedScatterTable() {
		if (table != 0)
			delete[] table;
		table = 0;
	}
	void insert(ChainedScatterObject obj) {
		if (count == length)
			throw exception("Tablica je puna");
		uint index = h(obj.getKey());
		if (table[index].status != 2) {
			table[index] = obj;
			table[index].status = 2;
			return;
		}
		else if (h(table[index].getKey()) == index) {
			while (table[index].next != -1)
				index = table[index].next;
			uint probe = index + 1;
			while (table[probe].status == 2)
				probe += 1;
			table[probe] = obj;
			table[probe].status = 2;
			table[index].next = probe;
		}
		else {
			uint index1 = h(table[index].getKey());
			while (table[index1].next != index)
				index1 = table[index1].next;
			uint probe = index + 1;
			while (table[probe].status == 2)
				probe += 1;
			table[probe] = table[index];
			table[probe].status = 2;
			table[index1].next = probe;
			table[index] = obj;
			table[index].status = 2;
		}
		count += 1;
	}
	ChainedScatterObject find(const char* key) {
		uint index = h(key);
		while (index != -1 and strcmp(table[index].getKey(), key) != 0)
			index = table[index].next;
		if (index == -1)
			return ChainedScatterObject();
		return table[index];
	}
	void withdraw(const char* key) {
		uint index = h(key);
		uint prev = -1;
		while (index != -1 and strcmp(table[index].getKey(), key) != 0) {
			prev = index;
			index = table[index].next;
		}
		if (index == -1)
			return;
		if (prev == -1 and table[index].next == -1) {
			table[index].status = 1;
		}
		else if (prev == -1 and table[index].next != -1) {
			prev = index;
			index = table[index].next;
			table[prev] = table[index];
			table[index].status = 1;
		}
		else {
			table[prev].next = table[index].next;
			table[index].status = 1;
		}
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

