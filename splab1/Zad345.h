#pragma once
#include <iostream>
using namespace std;

template<typename T>
class SLLNode {
public:
	T info;
	SLLNode<T>* link;
	
	SLLNode() {
		link = 0;
		info = (T)0;
	}
	SLLNode(T i) {
		info = i;
		link = 0;
	}
	SLLNode(T i, SLLNode<T>* next) {
		info = i;
		link = next;
	}
	~SLLNode() {}
};

template<typename T>
class CSortList {
protected:
	SLLNode<T>* head;
	SLLNode<T>* get_tail() {
		SLLNode<T>* temp = head;
		while (temp->link != 0)
			temp = temp->link;
		return temp;
	}
public:
	CSortList() {
		head = 0;
	}
	~CSortList() {
		SLLNode<T>* temp = head;
		while (temp != 0) {
			head = head->link;
			delete temp;
			temp = head;
		}
	}
	void addToHead(T info) {
		head = new SLLNode<T>(info, head);
	}
	void print() {
		SLLNode<T>* temp = head;
		while (temp != 0) {
			cout << temp->info << " ";
			temp = temp->link;
		}
		cout << endl;
	}
	void swapNeighbors(SLLNode<T>* node, SLLNode<T>* prev) {
		if (node == head) {
			head = node->link;
			node->link = node->link->link;
			head->link = node;
		}
		else {
			prev->link = node->link;
			node->link = node->link->link;
			prev->link->link = node;
		}
	}
	void swap(SLLNode<T>* node1, SLLNode<T>* prev1, SLLNode<T>* node2, SLLNode<T>* prev2) {
		if (node1 == node2)
			return;
		else if (node1->link == node2)
			swapNeighbors(node1, prev1);
		else if (node2->link == node1)
			swapNeighbors(node2, prev2);
		else {
			if (prev1 == 0)
				head = node2;
			else
				prev1->link = node2;
			if (prev2 == 0)
				head = node1;
			else
				prev2->link = node1;
			SLLNode<T>* temp = node1->link;
			node1->link = node2->link;
			node2->link = temp;
		}
	}
	// 3)
	void bubbleSort(bool rastuci) {
		SLLNode<T>* temp1, * prev2, * temp2;
		for (temp1 = get_tail(); temp1 != head; temp1 = prev2) {
			prev2 = 0;
			for (temp2 = head; temp2->link != temp1; ) {
				if ((rastuci == true and temp2->info > temp2->link->info) or 
					(rastuci == false and temp2->info < temp2->link->info)) {
					swapNeighbors(temp2, prev2);
					if (prev2 == 0)
						prev2 = head;
					else
						prev2 = prev2->link;
				}
				else {
					prev2 = temp2;
					temp2 = temp2->link;
				}
			}
			if ((rastuci == true and temp2->info > temp2->link->info) or
				(rastuci == false and temp2->info < temp2->link->info)) {
				swapNeighbors(temp2, prev2);
				if (prev2 == 0)
					prev2 = head;
				else
					prev2 = prev2->link;
			}
			else
				prev2 = temp2;
		}

	}
	// 4)
	void selectionSort(bool rastuci) {
		SLLNode<T>* prev1, * temp1, * prev2, * temp2, * prev, * temp;
		prev1 = 0;
		for (temp1 = head; temp1 != 0; temp1 = temp1->link) {
			prev = prev1;
			temp = temp1;
			prev2 = temp1;
			for (temp2 = temp1->link; temp2 != 0; temp2 = temp2->link) {
				if (rastuci == true and temp2->info < temp->info) {
					temp = temp2;
					prev = prev2;
				}
				else if (rastuci == false and temp2->info > temp->info) {
					temp = temp2;
					prev = prev2;
				}
				prev2 = temp2;
			}
			swap(temp1, prev1, temp, prev);
			temp1 = temp;
			prev1 = temp1;
		}
	}
	// 5)
	void insertionSort(bool rastuci) {
		SLLNode<T>* prev1, * temp1, * prev2, * temp2;
		prev1 = head;
		for (temp1 = head->link; temp1 != 0; ) {
			prev2 = 0;
			temp2 = head;
			while (temp1 != temp2 and ((rastuci == true and temp1->info > temp2->info) or
										rastuci == false and temp1->info < temp2->info)) {
				prev2 = temp2;
				temp2 = temp2->link;
			}
			if (temp1 == temp2) {
				prev1 = temp1;
				temp1 = temp1->link;
			}
			else {
				if (prev2 == 0) {
					prev1->link = temp1->link;
					head = temp1;
					head->link = temp2;
				}
				else {
					prev1->link = temp1->link;
					prev2->link = temp1;
					temp1->link = temp2;
				}
				temp1 = prev1->link;
			}
		}
	}
};

