#pragma once
#include "GraphNode.h"
#include <map>
#include <exception>
using namespace std;

class PriorityQueue
{
private:
	GraphNode** items;
	int max;
	int count;
	map<GraphNode*, int> indexes;
public:
	PriorityQueue(int n) {
		max = n;
		count = 0;
		items = new GraphNode * [max];
	}
	~PriorityQueue() {
		if (items != 0)
			delete[] items;
		items = 0;
	}
	bool isEmpty() {
		return count == 0;
	}
	void insert(GraphNode* element) {
		if (max == count)
			throw exception("PriorityQueue is full");
		count += 1;
		int i = count;
		while (i > 1 and element->distance < items[i / 2]->distance) {
			items[i] = items[i / 2];
			indexes[items[i]] = i;
			i /= 2;
		}
		items[i] = element;
		indexes[items[i]] = i;
	}
	GraphNode* removeFirst() {
		if (count == 0)
			throw exception("Empty PriorityQueue");
		GraphNode* toReturn = items[1];
		GraphNode* last = items[count];
		int i = 1;
		count -= 1;
		while (2 * i < count + 1) {
			int child = 2 * i;
			if (child + 1 < count + 1 and items[child + 1]->distance < items[child]->distance)
				child += 1;
			if (items[child]->distance >= last->distance)
				break;
			items[i] = items[child];
			indexes[items[i]] = i;
			i = child;
		}
		items[i] = last;
		indexes[items[i]] = i;
		indexes.erase(toReturn);
		return toReturn;
	}
	void update(GraphNode* node, int newDist) {
		int index = indexes[node];
		node->distance = newDist;

		while (index > 1 and newDist < items[index / 2]->distance) {
			items[index] = items[index / 2];
			indexes[items[index]] = index;
			index /= 2;
		}
		items[index] = node;
		indexes[node] = index;
	}

};