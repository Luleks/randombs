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