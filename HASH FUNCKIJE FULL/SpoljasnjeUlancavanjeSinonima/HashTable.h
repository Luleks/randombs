#pragma once
#include "SLinkedList.h"
#include <cmath>
#include <iomanip>

typedef unsigned int uint;
typedef unsigned long long ull;

class HashTable {
private:
	SLinkedList* list;
	uint length;
	uint count;

	uint h(const char* key) {
		uint res = 0;
		int i = 0, n = 5;
		const int a = 7;
		while (key[i] != '\0' and i < n) {
			res = res << 7 ^ key[i];
			i += 1;
		}
		return h(res);
	}
	uint h(uint key) {
		uint a = 2654435769;
		ull ak = a * key;
		return ak >> (32 - (int)log2(length));
	}
	uint h(double key) {
		if (key == 0)
			return 0U;
		int exponent;
		double mantissa = frexp(key, &exponent);
		return (uint)((2 * mantissa - 1) * ~0U);
	}
public:
	HashTable(uint len) {
		count = 0;
		length = len;
		list = new SLinkedList[length];
	}
	~HashTable() {
		if (list != 0)
			delete[] list;
		list = 0;
	}
	void insert(HashObject obj) {
		uint ind = h(obj.getKey());
		list[ind].addToHead(obj);
		count += 1;
	}
	HashObject find(const char* key) {
		uint ind = h(key);
		SLLNode* temp = list[ind].getHead();
		while (temp != 0 and strcmp(temp->info.getKey(), key) != 0)
			temp = temp->next;
		if (temp != 0)
			return temp->info;
		return HashObject();
	}
	void withdraw(const char* key) {
		HashObject obj = find(key);
		if (obj.getKey() != 0)
			withdraw(obj);
	}
	void withdraw(HashObject obj) {
		uint ind = h(obj.getKey());
		list[ind].deleteVal(obj);
		count -= 1;
	}
	void print() {
		for (uint i = 0; i < length; i++) {
			cout << "|" << setw(3) << i << "| ";
			list[i].print();
		}
	}
};

