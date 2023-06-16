BSTNode* findSibling(BSTNode* node) {
	if (root == 0)
		return 0;
	queue<BSTNode*>* parents = new queue<BSTNode*>();
	queue<BSTNode*>* children = new queue<BSTNode*>();
	BSTNode* temp = root;
	bool nodeFound = false;
	parents->push(temp);
	while (not parents->empty() and not nodeFound) {
		while (not parents->empty()) {
			temp = parents->front();
			parents->pop();
			if (temp->left != 0) {
				children->push(temp->left);
				if (temp->left == node)
					nodeFound = true;
			}
			if (temp->right != 0) {
				children->push(temp->right);
				if (temp->right == node)
					nodeFound = true;
			}
		}
		parents = children;
		children = new queue<BSTNode*>();
	}
	if (not nodeFound)
		return 0;
	if (parents->front() == node)
		parents->pop();
	return parents->front();
}