#include "GraphEdge.h"

GraphEdge::GraphEdge() {
	dest = 0;
	next = 0;
	weight = 0;
}

GraphEdge::GraphEdge(GraphNode* node, GraphEdge* edge, int weight) {
	this->dest = node;
	this->next = edge;
	this->weight = weight;
}