int reachableInNHoops(GraphNode* a, int n) {
	GraphNode* temp = start;
	while (temp != 0) {
		temp->status = 1;
		temp->distance = 0;
		temp = temp->next;
	}
	int count = 0;
	temp = a;
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
				edge->dest->status = 2;
				qju.push(edge->dest);
			}
			if (edge->dest->distance != n) {
				bool modifiable = edge->dest->distance != 0;
				edge->dest->distance = temp->distance + 1;
				if (edge->dest->distance == n and edge->dest->status != 4) {
					count += 1;
					cout << edge->dest->key << endl;
					edge->dest->status = 4;
					if (modifiable)
						edge->dest->distance -= 1;
				}
				else if (edge->dest->distance == n and edge->dest->status == 4)
					edge->dest->distance -= 1;
			}
			edge = edge->next;
		}
	}
	return count;
}