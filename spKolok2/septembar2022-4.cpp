void shortestPath(GraphNode* node1, GraphNode* node2) {
	GraphNode* temp = start;
	while (temp != 0) {
		temp->status = 1;
		temp->distance = INT_MAX;
		temp->prev = 0;
		temp = temp->next;
	}
	temp = node1;
	temp->distance = 0;
	PriorityQueue pqju(numOfElements);
	pqju.insert(temp);
	temp->status = 2;
	while (not pqju.isEmpty()) {
		temp = pqju.removeFirst();
		temp->status = 3;
		GraphEdge* edge = temp->adj;
		while (edge != 0) {
			if (edge->dest->status == 1) {
				edge->dest->distance = temp->distance + edge->weight;
				edge->dest->prev = temp;
				pqju.insert(edge->dest);
				edge->dest->status = 2;
			}
			else if (edge->dest->status == 2) {
				if (edge->dest->distance > temp->distance + edge->weight) {
					pqju.update(edge->dest, temp->distance + edge->weight);
					edge->dest->prev = temp;
				}
			}
			edge = edge->next;
		}
	}
}

int numOfSameFlights(GraphNode* airport1, GraphNode* airport2, GraphNode* airportEnd) {
	int* airports1 = new int[numOfElements];
	int l1 = 0;
	shortestPath(airport1, airportEnd);
	GraphNode* temp = airportEnd->prev;
	while (temp != airport1) {
		airports1[l1++] = temp->key;
		temp = temp->prev;
	}

	int* airports2 = new int[numOfElements];
	int l2 = 0;
	shortestPath(airport2, airportEnd);
	temp = airportEnd->prev;
	while (temp != airport2) {
		airports2[l2++] = temp->key;
		temp = temp->prev;
	}

	int count = 0;
	map<int, bool> zajednicki;
	for (int i = 0; i < l1; i++) {
		zajednicki[airports1[i]] = true;
	}
	for (int i = 0; i < l2; i++) {
		if (zajednicki[airports2[i]])
			count += 1;
	}
	return count;
}