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