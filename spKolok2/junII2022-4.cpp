int bridgeCount(int a, int b) {
	if (start == 0)
		return -1;
	GraphNode* temp = start;
	GraphNode* pFirst = 0, * pLast = 0;
	while (temp != 0) {
		temp->status = 1;
		temp->distance = INT_MAX;
		temp->prev = 0;
		if (temp->key == a)
			pFirst = temp;
		if (temp->key == b)
			pLast = temp;
		temp = temp->next;
	}
	if (pFirst == 0 or pLast == 0)
		return -1;
	return bridgeCount(pFirst, pLast);
}
int bridgeCount(GraphNode* first, GraphNode* last) {
	GraphNode* temp = first;
	PriorityQueue pqju(numOfElements);
	pqju.insert(temp);
	temp->status = 2;
	temp->distance = 0;
	while (not pqju.isEmpty()) {
		temp = pqju.removeFirst();
		temp->status = 3;
		GraphEdge* edge = temp->adj;
		while (edge != 0) {
			if (edge->dest->status == 1) {
				edge->dest->status = 2;
				edge->dest->prev = temp;
				edge->dest->distance = temp->distance + edge->weight;
				pqju.insert(edge->dest);
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
	int count = 1;
	temp = last->prev;
	while (temp != 0 and temp != first) {
		count += 1;
		temp = temp->prev;
	}
	return temp == 0 ? -1 : count;
}