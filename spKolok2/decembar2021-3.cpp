BSTNode* biggestDifference(int* difference) {
	int curDifference = 0;
	return biggestDifference(root, difference, &curDifference);
}
BSTNode* biggestDifference(BSTNode* root, int* maxDifference, int* curDifference) {
	if (root == 0) {
		*curDifference = 0;
		return 0;
	}
	BSTNode* max = root;
	int countLeft = countMoment(root->left);
	int countRight = countMoment(root->right);
	int absDifference = abs(countLeft - countRight);
	BSTNode* leftMax = biggestDifference(root->left, maxDifference, curDifference);
	if (absDifference < *curDifference) {
		max = leftMax;
		absDifference = *curDifference;
	}
	BSTNode* rightMax = biggestDifference(root->right, maxDifference, curDifference);
	if (absDifference < *curDifference) {
		max = rightMax;
		absDifference = *curDifference;
	}
	*maxDifference = absDifference;
	*curDifference = absDifference;
	return max;
}