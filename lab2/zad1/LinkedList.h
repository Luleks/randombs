#pragma once
#include "HashObject.h"
#include <exception>
using namespace std;

class Node {
public:
	HashObject info;
	Node* next;
	Node() {
		next = 0;
	}
	Node(HashObject i) {
		info = i;
		next = 0;
	}
	Node(HashObject i, Node* l) {
		info = i;
		next = l;
	}
};

class LinkedList {
protected:
	Node* head;
public:
	LinkedList() {
		head = 0;
	}
	~LinkedList() {
		while (head != 0)
			deleteFromHead();
	}
	void addToHead(HashObject info) {
		head = new Node(info, head);
	}
	HashObject deleteFromHead() {
		if (head == 0)
			throw exception("Deleting from empty list");
		Node* temp = head;
		HashObject toReturn = temp->info;
		head = head->next;
		delete temp;
		return toReturn;
	}
	bool deleteVal(HashObject val) {
		Node* prev = 0, * cur = head;
		while (cur != 0 and not (cur->info == val)) {
			prev = cur;
			cur = cur->next;
		}
		if (cur == 0)
			return false;
		else if (cur == head)
			head = head->next;
		else
			prev->next = cur->next;
		delete cur;
		return true;
	}
	bool isEmpty() {
		return head == 0;
	}
	Node* get_head() {
		return head;
	}
	void print(int i) {
		cout << "|" << i << "| ";
		Node* temp = head;
		while (temp != 0) {
			temp->info.print();
			cout << " ";
			temp = temp->next;
		}
		cout << endl;
	}

};

