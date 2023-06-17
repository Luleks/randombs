int countSingleLeavesNodes(BSTNode* root) {
	if (root == 0)
		return 0;
	else if (leaf(root->right) and not leaf(root->left))
		return 1 + countSingleLeavesNodes(root->left);
	else if (leaf(root->left) and not leaf(root->right))
		return 1 + leaf(root->right);
	return countSingleLeavesNodes(root->left) + countSingleLeavesNodes(root->right);
}
bool leaf(BSTNode* root) {
	return root != 0 and root->left == 0 and root->right == 0;
}