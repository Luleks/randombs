int countMoment() {
	return countMoment(root);
}
int countMoment(BSTNode* start) {
	if (start == 0)
		return 0;
	return 1 + countMoment(start->left) + countMoment(start->right);
}
bool isPerfect() {
	return isPerfect(root);
}
bool isPerfect(BSTNode* root) {
	if (root->left == 0 or root->right == 0)
		return true;
	int count1 = countMoment(root->left);
	int count2 = countMoment(root->right);
	if (abs(count1 - count2) > 1)
		return false;
	return isPerfect(root->left) and isPerfect(root->right);
}