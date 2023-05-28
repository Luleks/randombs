void pathExistsBetweenTwo(GraphNode* a, GraphNode* b, bool* found) {
	if (a == b) {
		*found = true;
		return;
	}
	if (a->status != 1) {
		a->status = 1;
		GraphEdge* edge = a->adj;
		while (edge != 0 and not(*found)) {
			pathExistsBetweenTwo(edge->dest, b, found);
			edge = edge->next;
		}
		if (*found) {
			return;
		}
	}
}

bool pathExists(GraphNode* a, GraphNode* b, GraphNode* c, GraphNode* d) {
	if (a == 0 or b == 0 or c == 0 or d == 0)
		return false;
	else if (a == b or not edgeExists(c, d))
		return false;
	GraphNode* temp = start;
	while (temp != 0) {
		temp->status = 0;
		temp = temp->next;
	}
	bool existsAC = false;
	pathExistsBetweenTwo(a, c, &existsAC);
	temp = start;				//
	while (temp != 0) {			//	Ukoliko nije dozvoljen visestruki prelaz preko cvorova
		temp->status = 0;		//	Ovaj deo ovde je visak
		temp = temp->next;		//
	}							//
	bool existsDB = false;
	pathExistsBetweenTwo(d, b, &existsDB);
	return existsAC and existsDB;
}