#pragma once
#include "GraphEdge.h"
#include "GraphNode.h"
#include "PriorityQueue.h"
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

class GraphNode;
class GraphEdge;

class Graph {
public:
	GraphNode* start;
	int numOfElements;

	void deleteEdgesToNode(GraphNode* node);
	int recursiveDepthTrav(GraphNode* node);
	int findPath(GraphNode* node, GraphNode* end, int* arPath, int* lPath);
public:
	Graph();
	~Graph();

	GraphNode* findNode(int val);
	GraphEdge* findEdge(int val1, int val2);
	bool insertNode(int val, bool jeStanica = true);
	bool insertEdge(int val1, int val2, int weight = 0);
	bool deleteNode(int val);
	bool deleteEdge(int val1, int val2);
	void print();

	int breadthTrav(int val);
	int iterativeDepthTrav(int val);
	int recursiveDepthTrav(int val);
	int topologicalTrav();
	int findPath(int val1, int val2, int* arPath, int* lPath);
	int dijkstra(int val);

	// DECEMBAR 2021.
	void countIns() {
		GraphNode* temp = start;
		while (temp != 0) {
			temp->status = 1;
			temp = temp->next;
		}
		temp = start;
		while (temp != 0) {
			GraphEdge* edge = temp->adj;
			while (edge != 0) {
				edge->dest->distance += 1;
				edge = edge->next;
			}
			temp = temp->next;
		}
	}
	void obidjiSveMoguce(int start) {
		countIns();
		GraphNode* temp = this->start;
		while (temp != 0 and temp->key != start) {
			temp = temp->next;
		}
		if (temp == 0)
			return;
		stack<GraphNode*> stek;
		stek.push(temp);
		temp->status == 2;
		while (not stek.empty()) {
			temp = stek.top();
			stek.pop();
			temp->status = 3;
			temp->visit();
			GraphEdge* edge = temp->adj;
			while (edge != 0) {
				edge->dest->distance -= 1;
				if (edge->dest->distance == 0 && edge->dest->status == 1)
					stek.push(edge->dest);
				edge = edge->next;
			}
		}
	}

	// OKTOBAR II 2021.
	int numberOfConnections(int startAero, int endAero) {
		GraphNode* temp = start;
		GraphNode* pStart = 0, * pEnd = 0;
		while (temp != 0) {
			temp->status = 1;
			temp->prev = 0;
			temp->distance = 0;
			if (temp->key == startAero)
				pStart = temp;
			if (temp->key == endAero)
				pEnd = temp;
			temp = temp->next;
		}
		if (startAero == 0 or endAero == 0)
			return 0;
		temp = pStart;
		queue<GraphNode*> qju;
		qju.push(temp);
		temp->status = 2;
		while (not qju.empty()) {
			temp = qju.front();
			qju.pop();
			temp->status = 3;
			GraphEdge* edge = temp->adj;
			while (edge != 0) {
				if (edge->dest->status == 1) {
					edge->dest->distance = temp->distance + edge->weight;
					edge->dest->status = 2;
					edge->dest->prev = temp;
					qju.push(edge->dest);
				}
				edge = edge->next;
			}
		}
		return pEnd->distance;
	}

	// OKTOBAR 2021.
	int breadthTrav(GraphNode* node) {
		GraphNode* temp = start;
		while (temp != 0) {
			temp->status = 1;
			temp = temp->next;
		}
		temp = node;
		int count = 0;
		queue<GraphNode*> qju;
		qju.push(temp);
		temp->status = 2;
		while (not qju.empty()) {
			temp = qju.front();
			qju.pop();
			count += 1;
			temp->status = 3;
			GraphEdge* edge = temp->adj;
			while (edge != 0) {
				if (edge->dest->status == 1) {
					edge->dest->status = 2;
					qju.push(edge->dest);
				}
				edge = edge->next;
			}
		}
		return count;
	}
	bool canReachMoreWithUndirrected(GraphNode* a) {
		int countUndirrected = breadthTrav(a);
		makeDirected();
		int countDirected = breadthTrav(a);
		return countUndirrected > countDirected;
	}
	void makeDirected() {
		GraphNode* temp = start;
		while (temp != 0) {
			GraphEdge* edge = temp->adj;
			while (edge != 0) {
				if (not edgeExistsInGraph(edge->dest, temp))
					edge->dest->adj = new GraphEdge(temp, edge->dest->adj);
				edge = edge->next;
			}
			temp = temp->next;
		}
	}
	bool edgeExistsInGraph(GraphNode* nodeA, GraphNode* nodeB) {
		GraphEdge* edge = nodeA->adj;
		while (edge != 0 and edge->dest != nodeB)
			edge = edge->next;
		return edge != 0;
	}

	// JUN II 2021.
	int reachableInNHoops(GraphNode* a, int n) {
		GraphNode* temp = start;
		while (temp != 0) {
			temp->status = 1;
			temp->distance = 0;
			temp = temp->next;
		}
		int count = 0;
		temp = a;
		queue<GraphNode*> qju;
		qju.push(temp);
		temp->status = 2;
		while (not qju.empty()) {
			temp = qju.front();
			qju.pop();
			temp->status = 3;
			GraphEdge* edge = temp->adj;
			while (edge != 0) {
				if (edge->dest->status == 1) {
					edge->dest->status = 2;
					qju.push(edge->dest);
				}
				if (edge->dest->distance != n) {
					bool modifiable = edge->dest->distance != 0;
					edge->dest->distance = temp->distance + 1;
					if (edge->dest->distance == n and edge->dest->status != 4) {
						count += 1;
						cout << edge->dest->key << endl;
						edge->dest->status = 4;
						if (modifiable)
							edge->dest->distance -= 1;
					}
					else if (edge->dest->distance == n and edge->dest->status == 4)
						edge->dest->distance -= 1;
				}
				edge = edge->next;
			}
		}
		return count;
	}

	// SEPTEMBAR 2021.
	int getTownName() {
		GraphNode* temp = start;
		while (temp != 0) {
			temp->status = 1;
			temp = temp->next;
		}
		int citiesOnMaxIsland = 0, citiesOnCurIsland = 0;
		int townName = -1;
		int maxConnection = 0;
		temp = start;
		GraphNode* nextNode = temp;
		queue<GraphNode*> qju;
		while (temp != 0) {
			qju.push(temp);
			temp->status = 2;
			citiesOnCurIsland = 0;
			int curCityConnections = 0;
			int maxCityConnection = 0;
			int maxCityName = -1;
			while (not qju.empty()) {
				temp = qju.front();
				qju.pop();
				temp->status = 3;
				citiesOnCurIsland += 1;
				curCityConnections = 0;
				GraphEdge* edge = temp->adj;
				while (edge != 0) {
					curCityConnections += 1;
					if (edge->dest->status == 1) {
						edge->dest->status = 2;
						qju.push(edge->dest);
					}
					edge = edge->next;
				}
				if (curCityConnections > maxCityConnection) {
					maxCityConnection = curCityConnections;
					maxCityName = temp->key;
				}
			}
			if (citiesOnCurIsland > citiesOnMaxIsland) {
				citiesOnMaxIsland = citiesOnCurIsland;
				townName = maxCityName;
			}
			while (nextNode != 0 and nextNode->status != 1)
				nextNode = nextNode->next;
			temp = nextNode;
		}
		return townName;
	}

	// JUN 2021.
	void breadthVariant(GraphNode* node1, int maxH) {
		GraphNode* temp = start;
		while (temp != 0) {
			temp->status = 1;
			temp->prev = 0;
			temp = temp->next;
		}
		temp = node1;
		queue<GraphNode*> qju;
		qju.push(temp);
		temp->status = 2;
		while (not qju.empty()) {
			temp = qju.front();
			qju.pop();
			temp->status = 3;
			GraphEdge* edge = temp->adj;
			while (edge != 0) {
				if (edge->dest->status == 1 and edge->weight < maxH) {
					qju.push(edge->dest);
					edge->dest->status = 2;
					edge->dest->prev = temp;
				}
				edge = edge->next;
			}
		}
	}
	GraphNode* boljiPut(GraphNode* nodeA, GraphNode* nodeB, GraphNode* nodeC, int maxH, int* brPresedanja) {
		breadthVariant(nodeA, maxH);
		int presedanjaB = 0, presedanjaC = 0;
		bool existsPathToB = false, existsPathToC = false;
		GraphNode* temp = nodeB;
		while (temp != 0 and temp != nodeA) {
			presedanjaB += 1;
			temp = temp->prev;
		}
		if (temp == nodeA)
			existsPathToB = true;
		temp = nodeC;
		while (temp != 0 and temp != nodeA) {
			presedanjaC += 1;
			temp = temp->prev;
		}
		if (temp == nodeA)
			existsPathToC = true;
		if (existsPathToB and existsPathToC) {
			if (presedanjaB < presedanjaC) {
				*brPresedanja = presedanjaB;
				return nodeB;
			}
			else {
				*brPresedanja = presedanjaC;
				return nodeC;
			}
		}
		else if (existsPathToB) {
			*brPresedanja = presedanjaB;
			return nodeB;
		}
		else if (existsPathToC) {
			*brPresedanja = presedanjaC;
			return nodeC;
		}
		else {
			*brPresedanja = -1;
			return nodeA;
		}
	}

	// KOLOKVIJUM II 2021.
	int brStanica(GraphNode* node1, GraphNode* node2, int maxKm) {
		GraphNode* temp = start;
		while (temp != 0) {
			temp->status = 1;
			temp->prev = 0;
			temp = temp->next;
		}
		temp = node1;
		queue<GraphNode*> qju;
		qju.push(temp);
		temp->status = 2;
		while (not qju.empty()) {
			temp = qju.front();
			qju.pop();
			temp->status = 3;
			GraphEdge* edge = temp->adj;
			while (edge != 0) {
				if (edge->dest->jeStanica and edge->dest->status == 1 and edge->weight < maxKm) {
					qju.push(edge->dest);
					edge->dest->status = 2;
					edge->dest->prev = temp;
				}
				edge = edge->next;
			}
		}
		temp = node2;
		int count = 0;
		while (temp != 0 and temp != node1) {
			count += 1;
			temp = temp->prev;
		}
		return (temp == node1) ? count : 0;
	}

	// JUN II 2022.
	void bfs(GraphNode* node) {
		GraphNode* temp = node;
		queue<GraphNode*> qju;
		qju.push(temp);
		temp->status = 2;
		while (not qju.empty()) {
			temp = qju.front();
			qju.pop();
			temp->status = 3;
			GraphEdge* edge = temp->adj;
			while (edge != 0) {
				if (edge->dest->status == 1) {
					qju.push(edge->dest);
					edge->dest->status = 2;
					edge->dest->prev = temp;
				}
				edge = edge->next;
			}
		}
	}
	int BridgeCount(int a, int b) {
		GraphNode* temp = start;
		GraphNode* A = 0, * B = 0;
		while (temp != 0) {
			temp->status = 1;
			temp->prev = 0;
			if (temp->key == a)
				A = temp;
			if (temp->key == b)
				B = temp;
			temp = temp->next;
		}
		if (A == 0 or B == 0)
			return -1;
		bfs(A);
		int count = 0;
		temp = B;
		while (temp != 0 and temp != A) {
			count += 1;
			temp = temp->prev;
		}
		return (temp == A) ? count : -1;
	}

	// OKTOBAR II 2022.
	void setStatusForNodes() {
		GraphNode* temp = start;
		while (temp != 0) {
			temp->status = 0;
			temp = temp->next;
		}
	}
	bool pathExists(GraphNode* a, GraphNode* b, GraphNode* c, GraphNode* d) {
		if (a == 0 or b == 0 or c == 0 or d == 0)
			return false;
		setStatusForNodes();
		bool pathACexists = false;
		pathExists(a, c, &pathACexists);
		setStatusForNodes();
		bool pathDBexists = false;
		pathExists(d, b, &pathDBexists);
		return pathACexists and pathDBexists;
	}
	void pathExists(GraphNode* start, GraphNode* end, bool* found) {
		if (start == end) {
			*found = true;
			return;
		}
		if (start->status != 1) {
			start->status = 1;
			GraphEdge* edge = start->adj;
			while (edge != 0 and not(*found)) {
				pathExists(edge->dest, end, found);
				edge = edge->next;
			}
		}
	}

	// OKTOBAR 2022.
	bool edgeExists(GraphNode* node1, GraphNode* node2) {
		if (node1 == 0 or node2 == 0)
			return false;
		GraphEdge* edge = node1->adj;
		while (edge != 0 and edge->dest != node2)
			edge = edge->next;
		return edge != 0;
	}
	bool isConnected() {
		if (start == 0)
			return true;
		GraphNode* temp = start;
		while (temp != 0) {
			temp->status = 1;
			temp = temp->next;
		}
		queue<GraphNode*> qju;
		int count = 0;
		temp = start;
		qju.push(temp);
		temp->status = 2;
		while (not qju.empty()) {
			temp = qju.front();
			qju.pop();
			temp->status = 3;
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
		return count == numOfElements;
	}
	void connectGraph() {
		GraphNode* temp = start;
		while (not isConnected()) {
			if (not edgeExists(start, temp)) {
				start->adj = new GraphEdge(temp, start->adj);
				temp->adj = new GraphEdge(start, temp->adj);
			}
			temp = temp->next;
		}
	}
	void connectGraphOptimal() {
		if (start == 0)
			return;
		GraphNode* temp = start;
		while (temp != 0) {
			temp->status = 0;
			temp = temp->next;
		}
		temp = start;
		queue<GraphNode*> qju;
		GraphNode* nextNode = temp;

		while (temp != 0) {
			qju.push(temp);
			temp->status = 1;
			while (not qju.empty()) {
				temp = qju.front();
				qju.pop();
				temp->status = 2;
				GraphEdge* edge = temp->adj;
				while (edge != 0) {
					if (edge->dest->status == 0) {
						qju.push(edge->dest);
						edge->dest->status = 1;
					}
					edge = edge->next;
				}
			}
			nextNode->status = 3;
			while (nextNode != 0 and nextNode->status != 0) {
				nextNode = nextNode->next;
			}
			temp = nextNode;
		}
		temp = start->next;
		while (temp != 0) {
			if (temp->status == 3) {
				temp->adj = new GraphEdge(start, temp->adj);
				start->adj = new GraphEdge(temp, start->adj);
			}
			temp = temp->next;
		}
	}

	// SEPTEMBAR 2022.
	void setStatus(int stat) {
		GraphNode* temp = start;
		while (temp != 0) {
			temp->status = stat;
			temp->prev = 0;
			temp->distance = 0;
			temp = temp->next;
		}
	}
	void breadthFirstVariant(GraphNode* node) {
		setStatus(0);
		queue<GraphNode*> qju;
		GraphNode* temp = node;
		qju.push(temp);
		temp->status = 1;
		while (not qju.empty()) {
			temp = qju.front();
			qju.pop();
			temp->status = 2;
			GraphEdge* edge = temp->adj;
			while (edge != 0) {
				if (edge->dest->status == 0) {
					edge->dest->prev = temp;
					edge->dest->status = 1;
					qju.push(edge->dest);
				}
				edge = edge->next;
			}
		}
	}
	int numOfSameFlights(GraphNode* node1, GraphNode* node2, GraphNode* end) {
		if (start == 0)
			return 0;
		int* flights1 = new int[numOfElements];
		int* flights2 = new int[numOfElements];
		int len1 = 0, len2 = 0;
		
		breadthFirstVariant(node1);
		GraphNode* temp = end;
		while (temp->prev != 0 and temp != node1) {
			flights1[len1++] = temp->key;
			temp = temp->prev;
		}
		flights1[len1++] = node1->key;

		breadthFirstVariant(node2);
		temp = end;
		while (temp->prev != 0 and temp != node2) {
			flights2[len2++] = temp->key;
			temp = temp->prev;
		}
		flights2[len2++] = node2->key;
		
		int sameFlights = 0;
		for (int i = len1 - 1; i > 0; i--) {
			for (int j = len2 - 1; j > 0; j--) {
				if (flights1[i] == flights2[j] and flights1[i - 1] == flights2[j - 1])
					sameFlights += 1;
			}
		}
		return sameFlights;
	}

	// JUN 2022.
	int getMaxConnectionsDisjointSubgraph() {
		if (start == 0)
			return 0;
		GraphNode* temp = start;
		while (temp != 0) {
			temp->status = 0;
			temp = temp->next;
		}
		temp = start;
		GraphNode* nextNode = temp;
		int maxCount = 0, curCount;
		queue<GraphNode*> qju;
		while (temp != 0) {
			qju.push(temp);
			temp->status = 1;
			curCount = 0;
			while (not qju.empty()) {
				temp = qju.front();
				qju.pop();
				temp->status = 2;
				GraphEdge* edge = temp->adj;
				while (edge != 0) {
					if (edge->dest->status == 0) {
						qju.push(edge->dest);
						edge->dest->status = 1;
					}
					if (edge->dest->status != 2)
						curCount += 1;
					edge = edge->next;
				}
			}
			if (curCount > maxCount)
				maxCount = curCount;
			while (nextNode != 0 and nextNode->status != 0)
				nextNode = nextNode->next;
			temp = nextNode;
		}
		return maxCount;
	}
};

