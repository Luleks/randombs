#pragma once
#include <iostream>
#include <exception>
using namespace std;

template<typename T>
class SLLNode {
public:
	T info;
	SLLNode<T>* next;

	SLLNode() {
		next = 0;
	}
	SLLNode(T info) {
		this->info = info;
		next = 0;
	}
	SLLNode(T info, SLLNode<T>* next) {
		this->info = info;
		this->next = next;
	}
	~SLLNode() {}
};

template<typename T>
class SLinkedList {
private:
	SLLNode<T>* head;
public:
	SLinkedList() { head = 0; }
	~SLinkedList();
	void addToHead(T val);
	void addToTail(T val);
	T deleteFromHead();
	T deleteFromTail();
	void deleteVal(T val);
	SLLNode<T>* getHead() { return head; }
	SLLNode<T>* getTail();
	void print();

	void swapNeighbors(SLLNode<T>* node, SLLNode<T>* prev);
	void swap(SLLNode<T>* node1, SLLNode<T>* prev1, SLLNode<T>* node2, SLLNode<T>* prev2);

	void bubbleSort();
	void insertionSort();
	void selectionSort();

	// Jun 2022.
	void GroupElements() {
		SLLNode<T>* temp = head;
		while (temp->next != 0) {
			SLLNode<T>* node = temp->next, *prev = temp;
			while (node != 0 and node->info != temp->info) {
				prev = node;
				node = node->next;
			}

			if (node == 0 or temp->next == node)
				temp = temp->next;
			else {
				prev->next = node->next;
				node->next = temp->next;
				temp->next = node;
				temp = node;
			}
		}
	}

	// Oktobar 2022.
	int MoveHigher(int value) {
		if (head == 0)
			return 0;
		SLLNode<T>* prev;
		if (head->info > value)
			prev = head;
		else
			prev = 0;
		SLLNode<T>* prev1 = head, *temp = head->next;
		while (temp != 0) {
			if (temp->info > value) {
				if (prev == 0) {
					prev1->next = temp->next;
					temp->next = head;
					head = temp;
					prev = head;
					temp = prev1->next;
				}
				else if (prev->next != temp) {
					prev1->next = temp->next;
					temp->next = prev->next;
					prev->next = temp;
					prev = temp;
					temp = prev1->next;
				}
				else {
					prev = prev->next;
					prev1 = temp;
					temp = temp->next;
				}
			}
			else {
				prev1 = temp;
				temp = temp->next;
			}
		}
		return 0;
	}

	// Oktobar 2 2022.
	void MoveMinToHead(SLLNode<T>* start) {
		SLLNode<T>* prev;
		if (start == head)
			prev = 0;
		else {
			prev = head;
			while (prev->next != start)
				prev = prev->next;
		}
		SLLNode<T>* min = start, *min_prev = prev;
		SLLNode<T>* temp = start->next, * prev_temp = start;
		while (temp != 0) {
			if (temp->info < min->info) {
				min_prev = prev_temp;
				min = temp;
			}
			prev_temp = temp;
			temp = temp->next;
		}
		if (min_prev != prev) {
			min_prev->next = min->next;
			if (prev == 0) {
				min->next = head;
				head = min;
			}
			else {
				min->next = prev->next;
				prev->next = min;
			}
		}
	}
	void SortList() {
		SLLNode<T>* prev = 0;
		for (SLLNode<T>* temp = head; temp->next != 0; ) {
			MoveMinToHead(temp);
			if ((prev == 0 and head == temp) or (prev != 0 and prev->next == temp)) {
				prev = temp;
				temp = temp->next;
			}
			else {
				if (prev == 0)
					prev = head;
				else
					prev = prev->next;
			}
		}
	}

	// Jun 2 2022
	SLinkedList<T>* SplitOrMove() {
		if (head == 0)
			return new SLinkedList();
		SLLNode<T>* new_head = 0, * new_temp = 0;
		SLLNode<T>* prev = 0, * cur = head;
		SLLNode<T>* prev1, *temp1;
		SLLNode<T>* to_be_izlancan = 0, *to_be_izlancan_prev = 0;
		while (cur != 0) {
			prev1 = cur;
			temp1 = cur->next;
			while (temp1 != 0 and temp1->info != cur->info) {
				prev1 = temp1;
				temp1 = temp1->next;
			}
			if (temp1 == 0) {
				to_be_izlancan = cur;
				to_be_izlancan_prev = prev;
				cur = cur->next;
			}
			else {
				to_be_izlancan = temp1;
				to_be_izlancan_prev = prev1;
				prev = cur;
				cur = cur->next;
			}
			if (to_be_izlancan_prev == 0)
				head = to_be_izlancan->next;
			else
				to_be_izlancan_prev->next = to_be_izlancan->next;
			if (new_head == 0) {
				new_head = to_be_izlancan;
				to_be_izlancan->next = 0;
				new_temp = new_head;
			}
			else {
				to_be_izlancan->next = 0;
				new_temp->next = to_be_izlancan;
				new_temp = new_temp->next;
			}
		}
		SLinkedList<T>* nova = new SLinkedList<T>();
		nova->head = new_head;
		return nova;
	}
};

template<typename T>
SLinkedList<T>::~SLinkedList() {
	while (head != 0)
		deleteFromHead();
}

template<typename T>
void SLinkedList<T>::addToHead(T val) {
	head = new SLLNode<T>(val, head);
}

template<typename T>
void SLinkedList<T>::addToTail(T val) {
	if (head == 0) {
		head = new SLLNode<T>(val, head);
		return;
	}
	SLLNode<T>* temp = head;
	while (temp->next != 0)
		temp = temp->next;
	temp->next = new SLLNode<T>(val);
}

template<typename T>
T SLinkedList<T>::deleteFromHead() {
	if (head == 0)
		throw exception("Empty list");
	SLLNode<T>* temp = head;
	T info = temp->info;
	head = head->next;
	delete temp;
	return info;
}

template<typename T>
T SLinkedList<T>::deleteFromTail() {
	if (head == 0)
		throw exception("Empty list");
	SLLNode<T>* prev = head, * cur = head->next;
	if (cur == 0) {
		T info = prev->info;
		head = head->next;
		delete prev;
		return info;
	}
	while (cur->next != 0) {
		prev = cur;
		cur = cur->next;
	}
	prev->next = 0;
	T info = cur->info;
	delete cur;
	return info;
}

template<typename T>
void SLinkedList<T>::deleteVal(T info) {
	if (head == 0)
		throw exception("Empty list");
	if (head->info == info) {
		SLLNode<T>* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	SLLNode<T>* prev = head, * cur = head->next;
	while (cur != 0 and cur->info != info) {
		prev = cur;
		cur = cur->next;
	}
	if (cur != 0) {
		prev->next = cur->next;
		delete cur;
	}
}

template<typename T>
SLLNode<T>* SLinkedList<T>::getTail() {
	if (head == 0)
		return 0;
	SLLNode<T>* temp = head;
	while (temp->next != 0)
		temp = temp->next;
	return temp;
}

template<typename T>
void SLinkedList<T>::print() {
	SLLNode<T>* temp = head;
	while (temp != 0) {
		cout << temp->info << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<typename T>
void SLinkedList<T>::swapNeighbors(SLLNode<T>* node, SLLNode<T>* prev) {
	if (node == head) {
		head = node->next;
		node->next = node->next->next;
		head->next = node;
	}
	else {
		prev->next = node->next;
		node->next = node->next->next;
		prev->next->next = node;
	}
}

template<typename T>
void SLinkedList<T>::swap(SLLNode<T>* node1, SLLNode<T>* prev1, SLLNode<T>* node2, SLLNode<T>* prev2) {
	if (node1 == node2)
		return;
	else if (node1->next == node2)
		swapNeighbors(node1, prev1);
	else if (node2->next == node1)
		swapNeighbors(node2, prev2);
	else {
		if (prev1 == 0)
			head = node2;
		else
			prev1->next = node2;
		if (prev2 == 0)
			head = node1;
		else
			prev2->next = node1;
		SLLNode<T>* temp = node1->next;
		node1->next = node2->next;
		node2->next = temp;
	}
}

template<typename T>
void SLinkedList<T>::bubbleSort() {
	SLLNode<T>* temp1, * temp2, * prev2;
	for (temp1 = getTail(); temp1 != head; temp1 = prev2) {
		prev2 = 0;
		for (temp2 = head; temp2->next != temp1; ) {
			if (temp2->info > temp2->next->info) {
				swapNeighbors(temp2, prev2);
				if (prev2 == 0)
					prev2 = head;
				else
					prev2 = prev2->next;
			}
			else {
				prev2 = temp2;
				temp2 = temp2->next;
			}
		}
		if (temp2->info > temp2->next->info) {
			swapNeighbors(temp2, prev2);
			if (prev2 == 0)
				prev2 = head;
			else
				prev2 = prev2->next;
		}
		else
			prev2 = temp2;
	}
}

template<typename T>
void SLinkedList<T>::selectionSort() {
	SLLNode<T>* node1, * prev1, * node2, * prev2, * node, * prev;
	prev1 = 0;
	for (node1 = head; node1 != 0; node1 = node1->next) {
		prev2 = node1;
		prev = prev1;
		node = node1;
		for (node2 = node1->next; node2 != 0; node2 = node2->next) {
			if (node2->info < node->info) {
				prev = prev2;
				node = node2;
			}
			prev2 = node2;
		}
		swap(node1, prev1, node, prev);
		node1 = node;
		prev1 = node1;
	}
}

template<typename T>
void SLinkedList<T>::insertionSort() {
	SLLNode<T>* node1, * prev1, * node2, * prev2;
	prev1 = head;
	for (node1 = head->next; node1 != 0; ) {
		prev2 = 0;
		node2 = head;
		while (node2 != node1 and node2->info < node1->info) {
			prev2 = node2;
			node2 = node2->next;
		}
		if (node1 == node2) {
			prev1 = node1;
			node1 = node1->next;
		}
		else {
			if (prev2 != 0) {
				prev1->next = node1->next;
				prev2->next = node1;
				node1->next = node2;
			}
			else {
				prev1->next = node1->next;
				head = node1;
				node1->next = node2;
			}
			node1 = prev1->next;
		}
	}
}