#pragma once
#include "GraphNode.h"
#include <iostream>
using namespace std;

class GraphNode;

class GraphEdge {
public:
	GraphNode* dest;
	GraphEdge* next;

	int weight;
public:
	GraphEdge();
	GraphEdge(GraphNode* dest, GraphEdge* edge, int weight = 0);
};

