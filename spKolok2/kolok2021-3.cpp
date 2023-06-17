int deleteAllLeftLeafs(BSTNode* root) {
	if (root == 0)
		return 0;
	if (root->left != 0 and isLeaf(root->left)) {
		delete root->left;
		root->left = 0;
		return 1 + deleteAllLeftLeafs(root->right);
	}
	return deleteAllLeftLeafs(root->left) + deleteAllLeftLeafs(root->right);
}
bool isLeaf(BSTNode* node) {
	return node->left == 0 and node->right == 0;
}