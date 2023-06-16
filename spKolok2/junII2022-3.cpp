int brojCvorova(int keyMin, double valueMin) {
	return brojCvorova(root, keyMin, valueMin, false);
}
int brojCvorova(BSTNode* root, int keyMin, double valueMin, bool ancestorExists) {
	if (root == 0)
		return 0;
	int count = 0;
	if (root->key > keyMin and ancestorExists)
		count += 1 + brojCvorova(root->left, keyMin, valueMin, true) + brojCvorova(root->right, keyMin, valueMin, true);
	else if (not ancestorExists and root->value > valueMin)
		count += brojCvorova(root->left, keyMin, valueMin, true) + brojCvorova(root->right, keyMin, valueMin, true);
	else
		count += brojCvorova(root->left, keyMin, valueMin, false) + brojCvorova(root->right, keyMin, valueMin, false);
	return count;
}