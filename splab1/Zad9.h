#pragma once
#include <iostream>
using namespace std;

struct Node_ {
	int key;
};

class Node9 {
public:
	struct Node_ info;
	Node9* next;
	
	Node9() {
		info.key = 0;
		next = 0;
	}
	Node9(int key) {
		info.key = key;
		next = 0;
	}
	Node9(struct Node_ info, Node9* next) {
		this->info = info;
		this->next = next;
	}
	Node9(int key, Node9* next) {
		info.key = key;
		this->next = next;
	}
	~Node9() {}
};

class CReorgList {
	Node9* head;
public:
	CReorgList() {
		head = 0;
	}
	void addToTail(Node9 n) {
		if (head == 0)
			head = new Node9(n.info, head);
		Node9* npok = head;
		while (npok->next != 0)
			npok = npok->next;
		npok->next = new Node9(n.info, 0);
	}
	void print() {
		Node9* temp = head;
		while (temp != 0) {
			cout << temp->info.key << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	struct Node_* getToStart(int key) {
		Node9* temp = head, *prev = 0;
		while (temp != 0 and temp->info.key != key) {
			prev = temp;
			temp = temp->next;
		}
		if (temp == 0)
			throw exception("Not found");
		else if (temp == head)
			return &temp->info;
		prev->next = temp->next;
		temp->next = head;
		head = temp;
		return &temp->info;
	}
	struct Node_* getTransp(int key) {
		Node9* prev1 = 0, *prev2 = head, * temp = head->next;
		while (temp != 0 and temp->info.key != key) {
			prev2 = prev1;
			prev1 = temp;
			temp = temp->next;
		}
		if (temp == 0)
			throw exception("Not found");
		else if (head->info.key == key)
			return &head->info;
		prev2->next = temp;
		prev1->next = temp->next;
		temp->next = prev1;
	}
};

