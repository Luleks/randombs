void countIns() {
	GraphNode* temp = start;
	while (temp != 0) {
		temp->status = 1;
		temp = temp->next;
	}
	temp = start;
	while (temp != 0) {
		GraphEdge* edge = temp->adj;
		while (edge != 0) {
			edge->dest->distance += 1;
			edge = edge->next;
		}
		temp = temp->next;
	}
}
void obidjiSveMoguce(int start) {
	countIns();
	GraphNode* temp = this->start;
	while (temp != 0 and temp->key != start) {
		temp = temp->next;
	}
	if (temp == 0)
		return;
	stack<GraphNode*> stek;
	stek.push(temp);
	temp->status == 2;
	while (not stek.empty()) {
		temp = stek.top();
		stek.pop();
		temp->status = 3;
		temp->visit();
		GraphEdge* edge = temp->adj;
		while (edge != 0) {
			edge->dest->distance -= 1;
			if (edge->dest->distance == 0 && edge->dest->status == 1)
				stek.push(edge->dest);
			edge = edge->next;
		}
	}
}