bool edgeExists(GraphNode* a, GraphNode* b) {
	if (a == 0 or b == 0)
		return false;
	else if (a == b)
		return true;
	GraphEdge* edge = a->adj;
	while (edge != 0 and edge->dest != b)
		edge = edge->next;
	return edge != 0;
}

bool isConnected() {
	if (start == 0)
		return false;
	GraphNode* temp = start;
	while (temp != 0) {
		temp->status = 1;
		temp = temp->next;
	}
	int count = 0;
	temp = start;
	queue<GraphNode*> qju;
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
	while (not isConnected() or temp == 0) {
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
		temp->status = 1;
		temp = temp->next;
	}
	temp = start;
	GraphNode* toStartSearchFrom = temp;
	stack<GraphNode*> stek;
	while (temp != 0) {
		stek.push(temp);
		temp->status = 2;
		while (not stek.empty()) {
			temp = stek.top();
			stek.pop();
			temp->status = 3;
			GraphEdge* edge = temp->adj;
			while (edge != 0) {
				if (edge->dest->status == 1) {
					stek.push(edge->dest);
					edge->dest->status = 2;
				}
				edge = edge->next;
			}
		}
		toStartSearchFrom->status = 4;
		while (toStartSearchFrom != 0 and toStartSearchFrom->status != 1)
			toStartSearchFrom = toStartSearchFrom->next;
		temp = toStartSearchFrom;
	}
	temp = start->next;
	while (temp != 0) {
		if (temp->status == 4) {
			temp->adj = new GraphEdge(start, temp->adj);
			start->adj = new GraphEdge(temp, start->adj);
		}
		temp = temp->next;
	}
}