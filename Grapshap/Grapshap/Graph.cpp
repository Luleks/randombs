#include "Graph.h"

Graph::Graph() {
	start = 0;
	numOfElements = 0;
}

Graph::~Graph() {
	while (start != 0)
		deleteNode(start->key);
}

void Graph::print() {
	GraphNode* temp = start;
	while (temp != 0) {
		cout << temp->key << "->";
		GraphEdge* edge = temp->adj;
		while (edge != 0) {
			cout << edge->dest->key << "|";
			edge = edge->next;
		}
		cout << endl;
		temp = temp->next;
	}
}

GraphNode* Graph::findNode(int val) {
	GraphNode* temp = start;
	while (temp != 0 and temp->key != val)
		temp = temp->next;
	return temp;
}

GraphEdge* Graph::findEdge(int val1, int val2) {
	GraphNode* node1 = findNode(val1);
	if (node1 == 0)
		return 0;
	GraphEdge* edge = node1->adj;
	while (edge != 0 and edge->dest->key != val2)
		edge = edge->next;
	return edge;
}

bool Graph::insertNode(int val, bool jeStanica) {
	if (findNode(val) != 0)
		return false;
	start = new GraphNode(val, start, 0, 0, jeStanica);
	numOfElements += 1;
	return true;
}

bool Graph::insertEdge(int val1, int val2, int weight) {
	GraphNode* temp = start, * node1 = 0, * node2 = 0;
	while (temp != 0 and (node1 == 0 or node2 == 0)) {
		if (temp->key == val1)
			node1 = temp;
		if (temp->key == val2)
			node2 = temp;
		temp = temp->next;
	}
	if (node1 == 0 or node2 == 0 or findEdge(val1, val2) != 0)
		return false;
	node1->adj = new GraphEdge(node2, node1->adj, weight);
}

bool Graph::deleteEdge(int val1, int val2) {
	GraphNode* node1 = findNode(val1);
	if (node1 == 0)
		return false;
	GraphEdge* prev = 0, * edge = node1->adj;
	while (edge != 0 and edge->dest->key != val2) {
		prev = edge;
		edge = edge->next;
	}
	if (edge == 0)
		return false;
	else if (prev == 0)
		node1->adj = edge->next;
	else
		prev->next = edge->next;
	delete edge;
	return true;
}

void Graph::deleteEdgesToNode(GraphNode* node) {
	GraphNode* temp = start;
	while (temp != 0) {
		if (temp != node) {
			GraphEdge* prev = 0, * edge = temp->adj;
			while (edge != 0 and edge->dest != node) {
				prev = edge;
				edge = edge->next;
			}
			if (edge != 0) {
				if (prev == 0)
					temp->adj = edge->next;
				else
					prev->next = edge->next;
				delete edge;
			}
		}
		temp = temp->next;
	}
}

bool Graph::deleteNode(int val) {
	GraphNode* prev = 0, * temp = start;
	while (temp != 0 and temp->key != val) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == 0)
		return false;
	deleteEdgesToNode(temp);
	GraphEdge* edge = temp->adj;
	while (edge != 0) {
		GraphEdge* temp = edge->next;
		delete edge;
		edge = temp;
	}
	if (prev == 0)
		start = temp->next;
	else
		prev->next = temp->next;
	delete temp;
	numOfElements -= 1;
	return true;
}

int Graph::breadthTrav(int val) {
	GraphNode* temp = start;
	while (temp != 0) {
		temp->status = 1;
		temp = temp->next;
	}
	temp = findNode(val);
	if (temp == 0)
		return 0;
	int count = 0;
	queue<GraphNode*> qju;
	qju.push(temp);
	temp->status = 2;
	while (not qju.empty()) {
		temp = qju.front();
		qju.pop();
		temp->status = 3;
		temp->visit();
		count += 1;
		GraphEdge* edge = temp->adj;
		while (edge != 0) {
			if (edge->dest->status == 1) {
				qju.push(edge->dest);
				edge->dest->status = 2;
			}
			edge = edge->next;
		}
	}
	return count;
}

int Graph::iterativeDepthTrav(int val) {
	GraphNode* temp = start;
	while (temp != 0) {
		temp->status = 1;
		temp = temp->next;
	}
	temp = findNode(val);
	if (temp == 0)
		return 0;
	int count = 0;
	stack<GraphNode*> stek;
	stek.push(temp);
	temp->status = 2;
	while (not stek.empty()) {
		temp = stek.top();
		stek.pop();
		temp->status = 3;
		temp->visit();
		count += 1;
		GraphEdge* edge = temp->adj;
		while (edge != 0) {
			if (edge->dest->status == 1) {
				stek.push(edge->dest);
				edge->dest->status = 2;
			}
			edge = edge->next;
		}
	}
	return count;
}

int Graph::recursiveDepthTrav(int val) {
	GraphNode* temp = start, * node = 0;
	while (temp != 0) {
		temp->status = 0;
		if (temp->key == val)
			node = temp;
		temp = temp->next;
	}
	if (node == 0)
		return 0;
	return recursiveDepthTrav(node);
}

int Graph::recursiveDepthTrav(GraphNode* node) {
	if (node->status == 1)
		return 0;
	int count = 0;
	node->visit();
	node->status = 1;
	count += 1;
	GraphEdge* edge = node->adj;
	while (edge != 0) {
		count += recursiveDepthTrav(edge->dest);
		edge = edge->next;
	}
	return count;
}

int Graph::topologicalTrav() {
	if (start == 0)
		return 0;
	GraphNode* temp = start;
	while (temp != 0) {
		temp->status = 0;
		temp = temp->next;
	}
	temp = start;
	while (temp != 0) {
		GraphEdge* edge = temp->adj;
		while (edge != 0) {
			edge->dest->status += 1;
			edge = edge->next;
		}
		temp = temp->next;
	}
	int count = 0;
	queue<GraphNode*> qju;
	temp = start;
	while (temp != 0) {
		if (temp->status == 0)
			qju.push(temp);
		temp = temp->next;
	}
	while (not qju.empty()) {
		temp = qju.front();
		qju.pop();
		count += 1;
		temp->visit();
		GraphEdge* edge = temp->adj;
		while (edge != 0) {
			edge->dest->status -= 1;
			if (edge->dest->status == 0)
				qju.push(edge->dest);
			edge = edge->next;
		}
	}
	return count;
}

int Graph::findPath(int val1, int val2, int* arPath, int* lPath) {
	GraphNode* temp = start, * pFirst = 0, * pLast = 0;
	while (temp != 0) {
		temp->status = 0;
		if (temp->key == val1)
			pFirst = temp;
		if (temp->key == val2)
			pLast = temp;
		temp = temp->next;
	}
	if (pFirst == 0 or pLast == 0)
		return 0;
	return findPath(pFirst, pLast, arPath, lPath);
}

int Graph::findPath(GraphNode* node, GraphNode* end, int* arPath, int* lPath) {
	if (node->key == end->key) {
		if (arPath != 0)
			arPath[(*lPath)++] = node->key;
		return 0;
	}
	int count = 0;
	if (node->status == 0) {
		node->status = 1;
		count += 1;
		GraphEdge* edge = node->adj;
		while (edge != 0 and arPath != 0 and *lPath == 0) {
			count += findPath(edge->dest, end, arPath, lPath);
			edge = edge->next;
		}
		if (arPath != 0 and lPath != 0 and *lPath != 0)
			arPath[(*lPath)++] = node->key;
	}
	return count;
}

int Graph::dijkstra(int val) {
	GraphNode* temp = start, *node = 0;
	while (temp != 0) {
		temp->status = 1;
		temp->prev = 0;
		temp->distance = INT_MAX;
		if (temp->key == val)
			node = temp;
		temp = temp->next;
	}
	if (node == 0)
		return 0;
	temp = node;
	int count = 0;
	PriorityQueue pq(numOfElements);
	pq.insert(temp);
	temp->distance = 0;
	temp->status = 2;
	while (not pq.isEmpty()) {
		temp = pq.removeFirst();
		count += 1;
		temp->status = 3;
		GraphEdge* edge = temp->adj;
		while (edge != 0) {
			if (edge->dest->status == 1) {
				edge->dest->distance = temp->distance + edge->weight;
				edge->dest->prev = temp;
				pq.insert(edge->dest);
				edge->dest->status = 2;
			}
			else if (edge->dest->status == 2) {
				if (edge->dest->distance > temp->distance + edge->weight) {
					pq.update(edge->dest, temp->distance + edge->weight);
					edge->dest->prev = temp;
				}
			}
			edge = edge->next;
		}
	}
	return count;
}