#pragma once
#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std;

typedef const char* cc;
typedef unsigned int uint;

class HashObject {
protected:
	char* key;
	char* record;
public:
	HashObject() {
		key = record = 0;
	}
	HashObject(cc k, cc r) {
		key = new char[strlen(k) + 1];
		strcpy(key, k);
		record = new char[strlen(r) + 1];
		strcpy(record, r);
	}
	HashObject(const HashObject& object) {
		key = new char[strlen(object.key) + 1];
		strcpy(key, object.key);
		record = new char[strlen(object.record) + 1];
		strcpy(record, object.record);
	}
	virtual ~HashObject() {
		if (key != 0)
			delete[] key;
		if (record != 0)
			delete[] record;
		key = record = 0;
	}
	HashObject& operator=(const HashObject& object) {
		if (this != &object) {
			if (key != 0)
				delete[] key;
			key = new char[strlen(object.key) + 1];
			strcpy(key, object.key);
			if (record != 0)
				delete[] record;
			record = new char[strlen(object.record) + 1];
			strcpy(record, object.record);
		}
		return *this;
	}
	bool operator==(const HashObject& obj) {
		return (strcmp(key, obj.key) == 0) and (strcmp(record, obj.record) == 0);
	}
	char* getKey() {
		return key;
	}
	char* getRecord() {
		return record;
	}
};

class ScatterObject : public HashObject {
public:
	int status; //0 - slobodan, 1 - obrisan, 2 - zauzet
public:
	ScatterObject() : HashObject() {
		status = 0;
	}
	ScatterObject(cc k, cc r) : HashObject(k, r) {
		status = 0;
	}
	ScatterObject(const ScatterObject& obj) : HashObject(obj) {
		status = obj.status;
	}
	virtual ~ScatterObject() {}
	ScatterObject& operator=(const ScatterObject& obj) {
		if (this != &obj) {
			(HashObject&)(*this) = obj;
			status = obj.status;
		}
		return *this;
	}
};

class ChainedScatterObject : public ScatterObject {
public:
	uint next;
public:
	ChainedScatterObject() : ScatterObject() {
		next = -1;
	}
	ChainedScatterObject(cc k, cc r) : ScatterObject(k, r) {
		next = -1;
	}
	ChainedScatterObject(cc k, cc r, uint n) : ScatterObject(k, r) {
		next = n;
	}
	ChainedScatterObject(const ChainedScatterObject& obj) : ScatterObject(obj) {
		next = obj.next;
	}
	~ChainedScatterObject() {}
	ChainedScatterObject& operator=(const ChainedScatterObject& obj) {
		if (this != &obj) {
			(ScatterObject&)(*this) = obj;
			next = obj.next;
		}
		return *this;
	}
	void print(uint i) {
		long n;
		if (next == -1)
			n = -1;
		else
			n = next;
		if (key == 0)
			cout << "|" << i << "| " << setw(8) << " " << " | " << n << endl;
		else if (next == -1)
			cout << "|" << i << "| " << setw(8) << key << " | " << -1 << endl;
		else
			cout << "|" << i << "| " << setw(8) << key << " | " << n << endl;
	}
};

