int breadthTrav(GraphNode* node) {
	GraphNode* temp = start;
	while (temp != 0) {
		temp->status = 1;
		temp = temp->next;
	}
	temp = node;
	int count = 0;
	queue<GraphNode*> qju;
	qju.push(temp);
	temp->status = 2;
	while (not qju.empty()) {
		temp = qju.front();
		qju.pop();
		count += 1;
		temp->status = 3;
		GraphEdge* edge = temp->adj;
		while (edge != 0) {
			if (edge->dest->status == 1) {
				edge->dest->status = 2;
				qju.push(edge->dest);
			}
			edge = edge->next;
		}
	}
	return count;
}
bool canReachMoreWithUndirrected(GraphNode* a) {
	int countUndirrected = breadthTrav(a);
	makeDirected();
	int countDirected = breadthTrav(a);
	return countUndirrected > countDirected;
}
void makeDirected() {
	GraphNode* temp = start;
	while (temp != 0) {
		GraphEdge* edge = temp->adj;
		while (edge != 0) {
			if (not edgeExistsInGraph(edge->dest, temp))
				edge->dest->adj = new GraphEdge(temp, edge->dest->adj);
			edge = edge->next;
		}
		temp = temp->next;
	}
}
bool edgeExistsInGraph(GraphNode* nodeA, GraphNode* nodeB) {
	GraphEdge* edge = nodeA->adj;
	while (edge != 0 and edge->dest != nodeB)
		edge = edge->next;
	return edge != 0;
}