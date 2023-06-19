#pragma once
#include <exception>
using namespace std;

class MinHeap {
private:
	int* items;
	int n;
	int cur;
public:
	MinHeap(int max) {
		n = max;
		cur = 1;
		items = new int[n + 1];
	}
	~MinHeap() {
		if (items != 0)
			delete[] items;
		items = 0;
	}
	void insert(int el) {
		if (cur == n + 1)
			throw exception("Heap overflow");
		int i = cur;
		cur += 1;
		while (i > 1 and items[i / 2] > el) {
			items[i] = items[i / 2];
			i /= 2;
		}
		items[i] = el;
	}
	int deleteRoot() {
		if (cur == 1)
			throw exception("Heap underflow");
		int ret = items[1];
		cur -= 1;
		int last = items[cur];
		int i = 1;
		while (2 * i < cur) {
			int child = 2 * i;
			if (child + 1 < cur and items[child + 1] < items[child])
				child += 1;
			if (items[child] >= last)
				break;
			items[i] = items[child];
			i = child;
		}
		items[i] = last;
		return ret;
	}
	void updateEl(int el, int val) {
		int i = 1;
		while (items[i] != el)
			i += 1;
		if (items[i] != el)
			throw exception("Not found");
		items[i] += val;
		if (val > 0) {
			int temp = items[i];
			while (2 * i < cur) {
				int child = 2 * i;
				if (child + 1 < cur and items[child + 1] < items[child])
					child += 1;
				if (items[child] >= temp)
					break;
				items[i] = items[child];
				i = child;
			}
			items[i] = temp;
		}
		else if (val < 0) {
			while (i > 1 and items[i / 2] > items[i]) {
				int temp = items[i];
				items[i] = items[i / 2];
				items[i / 2] = temp;
				i /= 2;
			}
		}
	}

	void printHeap() {
		for (int i = 1; i < cur; i++) {
			cout << items[i] << " ";
		}
	}

	static void HeapSort(int* a, int n) {
		MinHeap mh(n);
		for (int i = 0; i < n; i++)
			mh.insert(a[i]);
		for (int i = 0; i < n; i++)
			a[i] = mh.deleteRoot();
	}
};

