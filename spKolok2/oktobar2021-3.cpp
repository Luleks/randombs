int countSpecificNodes() {
	return countSpecificNodes(root);
}
int countSpecificNodes(BSTNode* root) {
	if (root == 0)
		return 0;
	int countLeft = countElementsInTree(root->left);
	int countRight = countElementsInTree(root->right);
	int count = 0;
	if (countRight > countLeft)
		count += 1;
	return count + countSpecificNodes(root->left) + countSpecificNodes(root->right);
}
int countElementsInTree(BSTNode* root) {
	if (root == 0)
		return 0;
	return 1 + countElementsInTree(root->left) + countElementsInTree(root->right);
}