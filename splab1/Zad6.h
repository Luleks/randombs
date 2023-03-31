#pragma once
#include <iostream>
using namespace std;

class Node1 {
public:
	int next;
	int info;
	Node1() {
		info = next = 0;
	}
	Node1(int i) {
		info = i;
		next = 0;
	}
	Node1(int i, int n) {
		info = i;
		next = n;
	}
};

class CStaticSortList {
protected:
	int lrmp;
	int head;
	int n;
	Node1* data;
public:
	CStaticSortList(int maxNo) {
		n = maxNo;
		head = 0;
		lrmp = 1;
		data = new Node1[n + 1];
		int i;
		for (i = 1; i < n; i++)
			data[i].next = i + 1;
		data[n].next = 0;
	}
	~CStaticSortList() {
		if (data != 0)
			delete[] data;
		data = 0;
	}
	void addToHead(int info) {
		if (lrmp == 0)
			return;
		int temp = lrmp;
		lrmp = data[temp].next;
		data[temp].info = info;
		data[temp].next = head;
		head = temp;
	}
	void print() {
		for (int temp = head; temp != 0; temp = data[temp].next)
			cout << data[temp].info << " ";
		cout << endl;
	}
	int get_tail() {
		int temp = head;
		while (data[temp].next != 0)
			temp = data[temp].next;
		return temp;
	}
	void swapNeighbors(int temp, int prev) {
		if (temp == head) {
			head = data[temp].next;
			data[temp].next = data[data[temp].next].next;
			data[head].next = temp;
		}
		else {
			data[prev].next = data[temp].next;
			data[temp].next = data[data[temp].next].next;
			data[data[prev].next].next = temp;
		}
	}
	void sort(bool rastuci) {
		int temp1, temp2, prev2;
		for (temp1 = get_tail(); temp1 != head; temp1 = prev2) {
			prev2 = 0;
			for (temp2 = head; data[temp2].next != temp1; ) {
				if ((rastuci == true and data[temp2].info > data[data[temp2].next].info) or 
					(rastuci == false and data[temp2].info < data[data[temp2].next].info)) {
					swapNeighbors(temp2, prev2);
					if (prev2 == 0)
						prev2 = head;
					else
						prev2 = data[prev2].next;
				}
				else {
					prev2 = temp2;
					temp2 = data[temp2].next;
				}
			}
			if ((rastuci == true and data[temp2].info > data[data[temp2].next].info) or
				(rastuci == false and data[temp2].info < data[data[temp2].next].info)) {
				swapNeighbors(temp2, prev2);
				if (prev2 == 0)
					prev2 = head;
				else
					prev2 = data[prev2].next;
			}
			else {
				prev2 = temp2;
			}
		}
	}
};

