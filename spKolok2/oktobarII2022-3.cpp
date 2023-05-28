BSTNode* findSibling(BSTNode* p) {
	if (root == p)
		return 0;
	
	queue<BSTNode*>* parents = new queue<BSTNode*>();
	queue<BSTNode*>* children = new queue<BSTNode*>();
	BSTNode* temp = root;
	bool found = false;
	
	parents->push(temp);

	while (not parents->empty() and not found) {
		while (not parents->empty()) {
			temp = parents->front();
			parents->pop();
			if (temp->right != 0) {
				children->push(temp->right);
				if (temp->right == p)
					found = true;
			}
			if (temp->left != 0) {
				children->push(temp->left);
				if (temp->left == p)
					found = true;
			}
		}
		parents = children;
		children = new queue<BSTNode*>();	
	}
	if (not found or parents->empty())
		return 0;
	if (parents->front() == p) {
		parents->pop();
	}
	return parents->front();
}