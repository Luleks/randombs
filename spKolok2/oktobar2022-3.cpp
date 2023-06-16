int countCloseSiblings(BSTNode* root) {
	if (root == 0)
		return 0;
	int count = 0;
	if (root->left != 0 and root->key - root->left->key == 1)
		count += 1;
	if (root->right != 0 and root->key - root->right->key == -1)
		count += 1;
	return count + countCloseSiblings(root->left) + countCloseSiblings(root->right);
}