int countNodesInRange(BSTNode* root, int min, int max) {
	if (root == 0)
		return 0;
	return (min <= root->key and root->key <= max ? 1 : 0) + 
		countNodesInRange(root->left, min, max)
		+ countNodesInRange(root->right, min, max);
}