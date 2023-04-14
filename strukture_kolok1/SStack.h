#pragma once
#include <iostream>
#include <exception>
using namespace std;

template<typename T>
class SStack {
private:
	int top;
	int N;
	T* data;
public:
	SStack(int capacity) {
		top = -1;
		N = capacity;
		data = new T[N];
	}
	~SStack();
	void push(T info);
	T pop();
	T top_();
	int size() {
		return top + 1;
	}
	bool isEmpty() {
		return top == -1;
	}
	bool isFull() {
		return top == N - 1;
	}
};

template<typename T>
void SStack<T>::push(T info) {
	if (isFull())
		throw exception("Stack overflow");
	top += 1;
	data[top] = info;
}

template<typename T>
T SStack<T>::pop() {
	if (isEmpty())
		throw exception("Stack underflow");
	top -= 1;
	return data[top + 1];
}

template<typename T>
T SStack<T>::top_() {
	if (isEmpty())
		throw exception("Stack underflow");
	return data[top];
}

template<typename T>
SStack<T>::~SStack() {
	if (data != 0)
		delete[] data;
	data = 0;
}

