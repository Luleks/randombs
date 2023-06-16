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