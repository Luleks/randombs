#pragma once
#include <iostream>
#include <exception>
#include <string.h>
#include <cmath>
using namespace std;

typedef unsigned int uint;

class ChainedScatterObject {
	char* key;
	char* record;
public:
	uint next;
	int status;
	ChainedScatterObject() {
		key = record = 0;
		next = -1;
		status = 0;
	}
	ChainedScatterObject(const char* key, const char* record) {
		this->key = new char[strlen(key) + 1];
		strcpy(this->key, key);
		this->record = new char[strlen(record) + 1];
		strcpy(this->record, record);
		next = -1;
		status = 0;
	}
	ChainedScatterObject(const ChainedScatterObject& obj) {
		this->key = new char[strlen(obj.key) + 1];
		strcpy(this->key, obj.key);
		this->record = new char[strlen(obj.record) + 1];
		strcpy(this->record, obj.record);
		next = obj.next;
		status = obj.status;
	}
	~ChainedScatterObject() {
		if (key != 0)
			delete[] key;
		if (record != 0)
			delete[] record;
		key = record = 0;
	}
	ChainedScatterObject& operator=(const ChainedScatterObject& obj) {
		if (this != &obj) {
			if (key != 0)
				delete[] key;
			this->key = new char[strlen(obj.key) + 1];
			strcpy(this->key, obj.key);
			if (record != 0)
				delete[] record;
			this->record = new char[strlen(obj.record) + 1];
			strcpy(this->record, obj.record);
			next = obj.next;
			status = obj.status;
		}
		return *this;
	}
	bool operator==(const ChainedScatterObject& obj) {
		return strcmp(key, obj.key) == 0 and strcmp(record, obj.record) == 0;
	}
	char* getKey() {
		return key;
	}
	void print() {
		cout << status << " ";
		if (key != 0)
			cout << "{" << key << ", " << record << "} ";
		if (next == -1)
			cout << "-1";
		else
			cout << next;
	}
	
};

