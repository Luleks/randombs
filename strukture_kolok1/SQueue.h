#pragma once
#include <exception>
#include <iostream>
using namespace std;

template<typename T>
class SQueue {
	int f;
	int r;
	int N;
	T* queue;
public:
	SQueue(int max) {
		f = r = 0;
		N = max;
		queue = new T[N];
	}
	~SQueue() {
		if (queue != 0)
			delete[] queue;
		queue = 0;
	}
	void enqueue(T info);
	T dequeue();
	bool isEmpty() {
		return f == r;
	}
	bool isFull() {
		return (r + 1) % N == f;
	}
	bool size() {
		return N - f + r;
	}
};

template<typename T>
void SQueue<T>::enqueue(T info) {
	if (isFull())
		throw exception("Queue overflow");
	queue[r] = info;
	r = (r + 1) % N;
}

template<typename T>
T SQueue<T>::dequeue() {
	if (isEmpty())
		throw exception("Queue underflow");
	T info = queue[f];
	f = (f + 1) % N;
	return info;
}

