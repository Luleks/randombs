int countNodesInRange(BSTNode* root, int min, int max) {
	if (root == 0)
		return 0;
	int count = 0;
	if (root->key >= min and root->key <= max)
		count += 1 + countNodesInRange(root->left, min, max) + countNodesInRange(root->right, min, max);
	else if (root->key < min)
		count += countNodesInRange(root->right, min, max);
	else if (root->key > max)
		count += countNodesInRange(root->left, min, max);
	return count;
}