BSTNode* findNodeWithLargestRightSubtree() {
	return findNodeWithLargestRightSubtree(root);
}
BSTNode* findNodeWithLargestRightSubtree(BSTNode* root) {
	if (root == 0)
		return 0;
	BSTNode* max = findNodeWithLargestRightSubtree(root->left);
	if (max == 0)
		return root;
	int count = countNodes(root->right);
	int countLeft = countNodes(max->right);
	if (count > countLeft)
		return root;
	return max;
}
int countNodes(BSTNode* root) {
	if (root == 0)
		return 0;
	return 1 + countNodes(root->left) + countNodes(root->right);
}