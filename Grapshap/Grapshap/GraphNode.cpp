#include "GraphNode.h"

GraphNode::GraphNode() {
	key = status = distance = 0;
	next = 0;
	adj = 0;
	prev = 0;
}

GraphNode::GraphNode(int key) {
	this->key = key;
	next = prev = 0;
	adj = 0;
	status = distance = 0;
}

GraphNode::GraphNode(int key, GraphNode* next, GraphEdge* adj, int status, bool jeStanica) {
	this->key = key;
	this->next = next;
	this->adj = adj;
	this->status = status;
	this->prev = 0;
	this->distance = 0;
	this->jeStanica = jeStanica;
}

void GraphNode::visit() {
	cout << this->key << " ";
}
