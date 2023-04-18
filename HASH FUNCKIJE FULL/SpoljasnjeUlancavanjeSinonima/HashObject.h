#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class HashObject {
protected:
	char* key;
	char* record;
public:
	HashObject() {
		key = record = 0;
	}
	HashObject(const char* key, const char* record) {
		this->key = new char[strlen(key) + 1];
		strcpy(this->key, key);
		this->record = new char[strlen(record) + 1];
		strcpy(this->record, record);
	}
	HashObject(const HashObject& obj) {
		this->key = new char[strlen(obj.key) + 1];
		strcpy(this->key, obj.key);
		this->record = new char[strlen(obj.record) + 1];
		strcpy(this->record, obj.record);
	}
	~HashObject() {
		if (key != 0)
			delete[] key;
		if (record != 0)
			delete[] record;
		key = record = 0;
	}
	HashObject& operator=(const HashObject& obj) {
		if (this != &obj) {
			this->key = new char[strlen(obj.key) + 1];
			strcpy(this->key, obj.key);
			this->record = new char[strlen(obj.record) + 1];
			strcpy(this->record, obj.record);
		}
		return *this;
	}
	bool operator==(const HashObject& obj) {
		return strcmp(key, obj.key) == 0 and strcmp(record, obj.record) == 0;
	}
	void print() {
		if (key != 0) {
			cout << "{" << key << ", " << record << "}";
		}
	}
	char* getKey() {
		return key;
	}
};

