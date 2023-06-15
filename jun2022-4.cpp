int getMaxConnectionsDisjointSubgraph() {
	if (start == 0)
		return 0;
	GraphNode* temp = start;
	while (temp != 0) {
		temp->status = 0;
		temp = temp->next;
	}
	temp = start;
	GraphNode* nextNode = temp;
	int maxCount = 0, curCount;
	queue<GraphNode*> qju;
	while (temp != 0) {
		qju.push(temp);
		temp->status = 1;
		curCount = 0;
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
				if (edge->dest->status != 2)
					curCount += 1;
				edge = edge->next;
			}
		}
		if (curCount > maxCount)
			maxCount = curCount;
		while (nextNode != 0 and nextNode->status != 0)
			nextNode = nextNode->next;
		temp = nextNode;
	}
	return maxCount;
}