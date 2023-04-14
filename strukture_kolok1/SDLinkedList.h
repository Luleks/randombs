#pragma once
#pragma once
#include <iostream>
#include <exception>
using namespace std;

template<typename T>
class SDLLNode {
public:
	int prev;
	int next;
	T info;

	SDLLNode() {
		prev = next = 0;
	}
	SDLLNode(T info, int prev) {
		this->info = info;
		this->prev = prev;
		next = 0;
	}
	SDLLNode(T info, int prev, int next) {
		this->info = info;
		this->prev = prev;
		this->next = next;
	}
	~SDLLNode() {}
};

template<typename T>
class SDLinkedList {
private:
	int head;
	int lrmp;
	int size;
	SDLLNode<T>* data;
public:
	SDLinkedList(int max);
	~SDLinkedList();
	void addToHead(T info);
	void addToTail(T info);
	T deleteFromHead();
	T deleteFromTail();
	void deleteVal(T val);
	void print();
	int getTail();

	void swapNeigbors(int ind, int prev);
	void bubbleSort();
};

template<typename T>
SDLinkedList<T>::SDLinkedList(int max) {
	head = 0;
	lrmp = 1;
	size = max;
	data = new SDLLNode<T>[size + 1];
	for (int i = 1; i < size; i++)
		data[i].next = i + 1;
	data[size].next = 0;
}

template<typename T>
SDLinkedList<T>::~SDLinkedList() {
	if (data != 0)
		delete[] data;
	data = 0;
}

template<typename T>
void SDLinkedList<T>::addToHead(T info) {
	if (lrmp == 0)
		throw exception("List is full");
	int temp = lrmp;
	lrmp = data[temp].next;
	data[temp].info = info;
	data[temp].prev = 0;
	data[temp].next = head;
	if (head != 0)
		data[head].prev = temp;
	head = temp;
}

template<typename T>
int SDLinkedList<T>::getTail() {
	int temp = head;
	while (data[temp].next != 0)
		temp = data[temp].next;
	return temp;
}

template<typename T>
void SDLinkedList<T>::addToTail(T info) {
	if (lrmp == 0)
		throw exception("List is full");
	if (head == 0) {
		addToHead(info);
		return;
	}
	int temp = head;
	while (data[temp].next != 0)
		temp = data[temp].next;
	int temp1 = lrmp;
	lrmp = data[temp1].next;
	data[temp1].info = info;
	data[temp1].next = 0;
	data[temp1].prev = temp;
	data[temp].next = temp1;
}

template<typename T>
T SDLinkedList<T>::deleteFromHead() {
	if (head == 0)
		throw exception("Deleting from mpty list");
	int temp = head;
	T toReturn = data[temp].info;
	head = data[temp].next;
	data[head].prev = 0;
	data[temp].prev = 0;
	data[temp].next = lrmp;
	lrmp = temp;
	return toReturn;
}

template<typename T>
void SDLinkedList<T>::print() {
	for (int temp = head; temp != 0; temp = data[temp].next)
		cout << data[temp].info << " ";
	cout << endl;
}

template<typename T>
T SDLinkedList<T>::deleteFromTail() {
	if (head == 0)
		throw exception("Deleting from mpty list");
	if (data[head].next == 0) 
		return deleteFromHead();
	int temp = head;
	while (data[temp].next != 0)
		temp = data[temp].next;
	T toReturn = data[temp].info;
	data[data[temp].prev].next = 0;
	data[temp].prev = 0;
	data[temp].next = lrmp;
	lrmp = temp;
	return toReturn;
}

template<typename T>
void SDLinkedList<T>::deleteVal(T val) {
	if (head == 0)
		throw exception("Deleting from mpty list");
	if (data[head].info == val) {
		deleteFromHead();
		return;
	}
	int temp = head;
	while (temp != 0 and data[temp].info != val)
		temp = data[temp].next;
	if (temp != 0) {
		data[data[temp].prev].next = data[temp].next;
		data[data[temp].next].prev = data[temp].prev;
		data[temp].prev = 0;
		data[temp].next = lrmp;
		lrmp = temp;
	}
}

template<typename T>
void SDLinkedList<T>::swapNeigbors(int ind, int prev) {
	if (ind == head) {
		head = data[head].next;
		data[ind].next = data[head].next;
		data[ind].prev = head;
		data[head].next = ind;
		data[head].prev = 0;
		data[data[ind].next].prev = ind;
	}
	else {
		data[prev].next = data[ind].next;
		data[ind].next = data[data[ind].next].next;
		data[ind].prev = data[prev].next;
		data[data[prev].next].next = ind;
		data[data[prev].next].prev = prev;
		if (data[data[ind].next].prev != 0)
			data[data[ind].next].prev = ind;
	}
}

template<typename T>
void SDLinkedList<T>::bubbleSort() {
	int ind1, ind2, prev2;
	for (ind1 = getTail(); ind1 != head; ind1 = prev2) {
		prev2 = 0;
		for (ind2 = head; data[ind2].next != ind1; ) {
			if (data[ind2].info > data[data[ind2].next].info) {
				swapNeigbors(ind2, prev2);
				if (prev2 == 0)
					prev2 = head;
				else
					prev2 = data[prev2].next;
			}
			else {
				prev2 = ind2;
				ind2 = data[ind2].next;
			}
		}
		if (data[ind2].info > data[data[ind2].next].info) {
			swapNeigbors(ind2, prev2);
			if (prev2 == 0)
				prev2 = head;
			else
				prev2 = data[prev2].next;
		}
		else
			prev2 = ind2;
	}
}