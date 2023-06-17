int getTownName() {
	GraphNode* temp = start;
	while (temp != 0) {
		temp->status = 1;
		temp = temp->next;
	}
	int citiesOnMaxIsland = 0, citiesOnCurIsland = 0;
	int townName = -1;
	int maxConnection = 0;
	temp = start;
	GraphNode* nextNode = temp;
	queue<GraphNode*> qju;
	while (temp != 0) {
		qju.push(temp);
		temp->status = 2;
		citiesOnCurIsland = 0;
		int curCityConnections = 0;
		int maxCityConnection = 0;
		int maxCityName = -1;
		while (not qju.empty()) {
			temp = qju.front();
			qju.pop();
			temp->status = 3;
			citiesOnCurIsland += 1;
			curCityConnections = 0;
			GraphEdge* edge = temp->adj;
			while (edge != 0) {
				curCityConnections += 1;
				if (edge->dest->status == 1) {
					edge->dest->status = 2;
					qju.push(edge->dest);
				}
				edge = edge->next;
			}
			if (curCityConnections > maxCityConnection) {
				maxCityConnection = curCityConnections;
				maxCityName = temp->key;
			}
		}
		if (citiesOnCurIsland > citiesOnMaxIsland) {
			citiesOnMaxIsland = citiesOnCurIsland;
			townName = maxCityName;
		}
		while (nextNode != 0 and nextNode->status != 1)
			nextNode = nextNode->next;
		temp = nextNode;
	}
	return townName;
}