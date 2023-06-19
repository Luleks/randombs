#pragma once
#include "GraphEdge.h"
#include <iostream>
using namespace std;

class GraphEdge;

class GraphNode {
public:
	int key;
	GraphNode* next;
	GraphEdge* adj;
	bool jeStanica;

	GraphNode* prev;
	int distance;
	int status;
public:
	GraphNode();
	GraphNode(int key);
	GraphNode(int key, GraphNode* next, GraphEdge* adj, int status, bool jeStanica);
	void visit();
};

