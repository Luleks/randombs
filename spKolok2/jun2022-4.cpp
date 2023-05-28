int getMaxConnectionsDisjointSubgraph() {
	if (start == 0)
		return 0;
	GraphNode* temp = start;
	while (temp != 0) {
		temp->status = 1;
		temp = temp->next;
	}
	int maxCount = 0, curCount = 0;
	temp = start;
	GraphNode* toStartSearchFrom = temp;
	stack<GraphNode*> stek;
	while (temp != 0) {
		stek.push(temp);
		temp->status = 2;
		while (not stek.empty()) {
			temp = stek.top();
			stek.pop();
			GraphEdge* edge = temp->adj;
			while (edge != 0) {
				if (edge->dest->status != 3) {
					curCount += 1;
					stek.push(edge->dest);
					edge->dest->status = 2;
				}
				edge = edge->next;;
			}
			temp->status = 3;
		}
		if (curCount > maxCount)
			maxCount = curCount;
		curCount = 0;
		while (toStartSearchFrom != 0 and toStartSearchFrom->status != 1)
			toStartSearchFrom = toStartSearchFrom->next;
		temp = toStartSearchFrom;
	}	
	return maxCount;
}