#pragma once
#include "HashObject.h"
#include <cmath>
#include <exception>

class HashTable {
protected:
	uint length;
	uint count;

	uint h(cc s) {
		uint res = 0;
		int i = 0, n = 5;
		while (s[i] != '\0' and i < n) {
			res = res << 7 ^ s[i];
			i += 1;
		}
		return h(res);
	}

	uint h(uint key) {
		uint const a = 2654435769;
		unsigned long long ak = key * a;
		return ak >> (32 - (int)log2(length));
	}
};

class ChainedScatterTable : public HashTable {
protected:
	ChainedScatterObject* table;
	uint lrmp;
public:
	ChainedScatterTable(uint len) {
		length = len;
		count = 0;
		lrmp = length;
		table = new ChainedScatterObject[2 * length];
		for (int i = lrmp; i < 2 * length - 1; i++)
			table[i].next = i + 1;
		table[2 * length - 1].next = 0;
	}
	~ChainedScatterTable() {
		if (table != 0)
			delete[] table;
		table = 0;
	}
	void print() {
		for (int i = 0; i < 2 * length; i++) {
			table[i].print(i);
		}
	}
	void insert(ChainedScatterObject obj) {
		if (count == 2 * length)
			throw exception("Error");
		uint probe = h(obj.getKey());
		if (table[probe].status == 2) {
			while (table[probe].status == 2 and table[probe].next != -1 and table[probe].next != 0)
				probe = table[probe].next;
			if (table[probe].next == 0)
				throw exception("Prostor za sin je prazan");
			table[probe].next = lrmp;
			probe = lrmp;
			lrmp = table[probe].next;
		}
		table[probe] = obj;
		table[probe].status = 2;
		table[probe].next = -1;
		count += 1;
	}
	ChainedScatterObject find(cc key) {
		uint probe = h(key);
		while (probe != -1) {
			if (strcmp(key, table[probe].getKey()) == 0)
				return table[probe];
			probe = table[probe].next;
		}
		return ChainedScatterObject();
	}

};

