int countCloseSiblings(BSTNode* root) {
	if (root == 0 or (root->left == 0 and root->right == 0))
		return 0;
	int count = 0;
	if (root->left != 0 and root->key == root->left->key + 1)
		count += 1;
	if (root->right != 0 and root->key == root->right->key - 1)
		count += 1;
	count += countCloseSiblings(root->left);
	count += countCloseSiblings(root->right);
	return count;
}