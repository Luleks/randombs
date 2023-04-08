#pragma once
#include <string.h>
#include <iostream>
using namespace std;

class HashObject {
protected:
	char* key;
	char* record;
public:
	HashObject() {
		key = record = 0;
	}
	HashObject(const char* k, const char* r) {
		key = new char[strlen(k) + 1];
		strcpy(key, k);
		record = new char[strlen(r) + 1];
		strcpy(record, r);
	}
	HashObject(const HashObject& obj) {
		key = new char[strlen(obj.key) + 1];
		strcpy(key, obj.key);
		record = new char[strlen(obj.record) + 1];
		strcpy(record, obj.record);
	}
	~HashObject() {
		if (key != 0 and record != 0) {
			delete[] key;
			delete[] record;
		}
		key = 0;
		record = 0;
	}
	char* getKey() {
		return key;
	}
	char* getRecord() {
		return record;
	}
	bool operator==(const HashObject& obj) {
		return (strcmp(key, obj.key) == 0) and (strcmp(record, obj.record) == 0);
	}
	HashObject& operator=(const HashObject& obj) {
		if (this != &obj) {
			if (key != 0)
				delete[] key;
			key = new char[strlen(obj.key) + 1];
			strcpy(key, obj.key);
			if (record != 0)
				delete[] record;
			record = new char[strlen(obj.record) + 1];
			strcpy(record, obj.record);
		}
		return *this;
	}
	void print() {
		if (key != 0 and record != 0)
			cout << "{" << key << ", " << record << "}";
	}
};

