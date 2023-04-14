#pragma once
#include "SLinkedList.h"
#include <iostream>
#include <exception>
using namespace std;

template<typename T>
class DStack {
private:
	SLinkedList<T> stack;
public:
	DStack() {
		stack = SLinkedList<T>();
	}
	~DStack() {}
	void push(T info);
	T pop();
	T top_();
	bool isEmpty() {
		return stack.getHead() == 0;
	}
};

template<typename T>
void DStack<T>::push(T info) {
	stack.addToHead(info);
}

template<typename T>
T DStack<T>::pop() {
	if (stack.getHead() == 0)
		throw exception("Stack underflow");
	return stack.deleteFromHead();
}

template<typename T>
T DStack<T>::top_() {
	if (stack.getHead() == 0)
		throw exception("Stack underflow");
	return stack.getHead()->info;
}
