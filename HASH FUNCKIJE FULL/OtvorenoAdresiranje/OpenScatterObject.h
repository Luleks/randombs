#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class OpenScatterObject {
	char* key;
	char* record;
public:
	int status; //0 slobodno, 1 obrisano, 2 zauzeto
	OpenScatterObject() {
		key = record = 0;
		status = 0;
	}
	OpenScatterObject(const char* key, const char* record) {
		this->key = new char[strlen(key) + 1];
		strcpy(this->key, key);
		this->record = new char[strlen(record) + 1];
		strcpy(this->record, record);
		status = 0;
	}
	OpenScatterObject(const OpenScatterObject& obj) {
		this->key = new char[strlen(obj.key) + 1];
		strcpy(this->key, obj.key);
		this->record = new char[strlen(obj.record) + 1];
		strcpy(this->record, obj.record);
		status = obj.status;
	}
	~OpenScatterObject() {
		if (key != 0)
			delete[] key;
		if (record != 0)
			delete[] record;
		key = record = 0;
	}
	OpenScatterObject& operator=(const OpenScatterObject& obj) {
		if (this != &obj) {
			if (key != 0)
				delete[] key;
			this->key = new char[strlen(obj.key) + 1];
			strcpy(this->key, obj.key);
			if (record != 0)
				delete[] record;
			this->record = new char[strlen(obj.record) + 1];
			strcpy(this->record, obj.record);
			status = obj.status;
		}
		return *this;
	}
	bool operator==(const OpenScatterObject& obj) {
		return strcmp(key, obj.key) == 0 and strcmp(record, obj.record) == 0;
	}
	char* getKey() {
		return key;
	}
	void print() {
		cout << status << " ";
		if (key != 0)
			cout << "{" << key << ", " << record << "}";
	}
};

