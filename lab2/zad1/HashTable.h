#pragma once
#include "LinkedList.h"
#include <cmath>

typedef unsigned int uint;

class HashTable {
protected:
	uint length;
	uint count;

	uint h(const char* key) {
		uint res = 0;
		int n = 5, i = 0;
		while (key[i] != '\0' and i < n) {
			res = res << 7 ^ key[i];
			i += 1;
		}
		return h(res);
	}

	uint h(uint key) {
		uint const a = 2654435769;
		unsigned long long ak = a * key;
		return ak >> (32 - (int)log2(length));
	}
};

class ChainedHashTable : public HashTable {
private:
	LinkedList* table;
public:
	ChainedHashTable(int len) {
		length = len;
		count = 0;
		table = new LinkedList[length];
	}
	~ChainedHashTable() {
		for (int i = 0; i < length; i++) {
			while (not table[i].isEmpty())
				table[i].deleteFromHead();
		}
		delete[] table;
		table = 0;
	}
	void insert(HashObject obj) {
		uint index = h(obj.getKey());
		table[index].addToHead(obj);
		count += 1;
	}
	void print() {
		for (int i = 0; i < length; i++)
			table[i].print(i);
	}
	void withdraw(const char* key) {
		HashObject obj = find(key);
		if (obj.getKey() == 0)
			return;
		withdraw(obj);
	}
	void withdraw(HashObject obj) {
		if (table[h(obj.getKey())].deleteVal(obj))
			count -= 1;
	}
	HashObject find(const char* key) {
		uint index = h(key);
		Node* node = table[index].get_head();
		while (node != 0 and strcmp(node->info.getKey(), key) != 0)
			node = node->next;
		if (node != 0)
			return node->info;
		return HashObject();
	}
};