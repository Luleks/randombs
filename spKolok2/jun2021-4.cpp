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