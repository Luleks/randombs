#include "SLinkedList.h"
#include "SDLinkedList.h"
#include "SStack.h"
#include "DStack.h"
#include "SQueue.h"

bool isOperation(char c) {
	return (c == '+' or c == '-' or c == '*' or c == '/');
}

double calc(char op, double op1, double op2) {
	if (op == '+')
		return op1 + op2;
	else if (op == '-')
		return op1 - op2;
	else if (op == '*')
		return op1 * op2;
	else if (op == '/')
		return op1 / op2;
}
// Septembar 2022.
double calcPrefix(const char* exp) {
	DStack<char> operations;
	DStack<double> operands;
	bool operation = false;
	for (int i = 0; exp[i] != '\0'; i++) {
		if (isOperation(exp[i])) {
			operations.push(exp[i]);
			operation = true;
		}
		else if (operands.isEmpty() or operation) {
			operands.push(exp[i] - 48);
			operation = false;
		}
		else {
			char op = operations.pop();
			double op1 = operands.pop();
			double op2 = exp[i] - 48;
			operands.push(calc(op, op1, op2));
			operation = false;
		}
	}
	if (not operations.isEmpty()) {
		double op2 = operands.pop();
		double op1 = operands.pop();
		return calc(operations.pop(), op1, op2);
	}
	return operands.pop();
}

int main() {
	// singly linked list
	SLinkedList<int> sll;
	for (int i = 0; i < 5; i++) {
		sll.addToHead(i + 1);
		sll.addToTail(5 - i);
	}
	sll.print();
	sll.deleteFromHead();
	sll.deleteFromTail();
	sll.deleteVal(3);
	sll.print();
	//sll.bubbleSort();
	//sll.selectionSort();
	//sll.insertionSort();
	//sll.print();
	//sll.GroupElements();
	//sll.print();
	//sll.MoveHigher(0);
	//sll.print();
	//sll.SortList();
	//sll.print();
	SLinkedList<int>* l = sll.SplitOrMove();
	sll.print();
	l->print();
	

	/* Static doubly linked list
	SDLinkedList<int> sdll(10);
	for (int i = 0; i < 5; i++) {
		sdll.addToHead(i);
		sdll.addToTail(5 - i);
	}
	sdll.print();
	sdll.deleteFromHead();
	sdll.deleteFromTail();
	sdll.deleteVal(0);
	sdll.addToHead(8);
	sdll.addToTail(8);
	sdll.print();
	sdll.bubbleSort();
	sdll.print();
	*/

	/* Static/ Dynamic stack
	DStack<int> stek;
	// SStack<int> stek(10);
	for (int i = 0; i < 7; i++) {
		stek.push(i);
	}
	for (int i = 0; i < 4; i++) {
		cout << stek.pop() << " ";
	}
	cout << endl;
	for (int i = 10; i < 13; i++)
		stek.push(i);
	while (not stek.isEmpty())
		cout << stek.pop() << " ";
	*/

	/* Static queue
	SQueue<int> qju(7);
	for (int i = 0; i < 3; i++)
		qju.enqueue(i);
	for (int i = 0; i < 3; i++)
		cout << qju.dequeue() << " ";
	cout << endl;
	for (int i = 0; i < 6; i++)
		qju.enqueue(i);
	for (int i = 0; i < 6; i++)
		cout << qju.dequeue() << " ";
	*/

	// cout << calcPrefix("-*+342/84");

	return 0;
}