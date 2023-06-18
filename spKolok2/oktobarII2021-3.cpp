BSTNode* getNNode() {
	return getNNode(root);
}
BSTNode* getNNode(BSTNode* root) {
	if (root == 0)
		return 0;
	int countLeft = countUnordered(root->left);
	int countRight = countUnordered(root->right);
	if (countRight == countLeft + 2)
		return root;
	BSTNode* left = getNNode(root->left);
	BSTNode* right = getNNode(root->right);
	return (left != 0) ? left : right;
}
int countUnordered(BSTNode* root) {
	if (root == 0)
		return 0;
	return 1 + countUnordered(root->left) + countUnordered(root->right);
}