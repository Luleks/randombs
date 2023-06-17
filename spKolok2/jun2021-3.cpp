int countSL(BSTNode* root) {
	if (root == 0)
		return 0;
	int countLeft = countKeys(root->left);
	int countRight = countKeys(root->right);
	int count = 0;
	if (countLeft > countRight)
		count += 1;
	return count + countSL(root->left) + countSL(root->right);
}
int countKeys(BSTNode* root) {
	if (root == 0)
		return 0;
	return root->key + countKeys(root->left) + countKeys(root->right);
}