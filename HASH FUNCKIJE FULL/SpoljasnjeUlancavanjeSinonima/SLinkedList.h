#pragma once
#include "HashObject.h"
#include <iostream>
#include <exception>
using namespace std;

class SLLNode {
public:
	SLLNode* next;
	HashObject info;
	SLLNode() {
		next = 0;
		info = HashObject();
	}
	SLLNode(HashObject info) {
		next = 0;
		this->info = info;
	}
	SLLNode(HashObject info, SLLNode* next) {
		this->info = info;
		this->next = next;
	}
	~SLLNode() {}
};


class SLinkedList {
private:
	SLLNode* head;
public:
	SLinkedList() {
		head = 0;
	}
	~SLinkedList() {
		while (not isEmpty())
			deleteFromHead();
	}
	bool isEmpty() {
		return head == 0;
	}
	void addToHead(HashObject info) {
		head = new SLLNode(info, head);
	}
	bool deleteFromHead() {
		if (head == 0)
			return false;
		SLLNode* temp = head;
		head = head->next;
		delete temp;
		return true;
	}
	bool deleteVal(HashObject val) {
		if (head == 0)
			return false;
		else if (head->info == val)
			return deleteFromHead();
		SLLNode* prev = head, * cur = head->next;
		while (cur != 0 and not (cur->info == val)) {
			prev = cur;
			cur = cur->next;
		}
		if (cur == 0)
			return false;
		prev->next = cur->next;
		delete cur;
		return true;
	}
	void print() {
		SLLNode* temp = head;
		while (temp != 0) {
			temp->info.print();
			cout << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	SLLNode* getHead() {
		return head;
	}
};

