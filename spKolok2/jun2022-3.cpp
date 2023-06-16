int countMoment(BSTNode* root) {
	if (root == 0)
		return 0;
	return 1 + countMoment(root->left) + countMoment(root->right);
}
bool isPerfect() {
	return isPerfect(root);
}
bool isPerfect(BSTNode* root) {
	if (root == 0)
		return true;
	int a = countMoment(root->left);
	int b = countMoment(root->right);
	if (abs(a - b) > 1)
		return false;
	return isPerfect(root->left) and isPerfect(root->right);
}