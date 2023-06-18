int numberOfConnections(int startAero, int endAero) {
	GraphNode* temp = start;
	GraphNode* pStart = 0, * pEnd = 0;
	while (temp != 0) {
		temp->status = 1;
		temp->prev = 0;
		temp->distance = 0;
		if (temp->key == startAero)
			pStart = temp;
		if (temp->key == endAero)
			pEnd = temp;
		temp = temp->next;
	}
	if (startAero == 0 or endAero == 0)
		return 0;
	temp = pStart;
	queue<GraphNode*> qju;
	qju.push(temp);
	temp->status = 2;
	while (not qju.empty()) {
		temp = qju.front();
		qju.pop();
		temp->status = 3;
		GraphEdge* edge = temp->adj;
		while (edge != 0) {
			if (edge->dest->status == 1) {
				edge->dest->distance = temp->distance + edge->weight;
				edge->dest->status = 2;
				edge->dest->prev = temp;
				qju.push(edge->dest);
			}
			edge = edge->next;
		}
	}
	return pEnd->distance;
}