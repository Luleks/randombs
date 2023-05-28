int brojCvorova(int keyMin, double valueMin) {
	return brojCvorova(root, keyMin, valueMin, false);
}

int brojCvorova(BSTNode* node, int keyMin, double valueMin, bool hasAncestor) {
	if (node == 0 or node->key <= keyMin)
		return 0;
	if (hasAncestor and node->key > keyMin)
		return 1 + brojCvorova(node->left, keyMin, valueMin, true)
					+ brojCvorova(node->right, keyMin, valueMin, true);
	else if ((hasAncestor and node->key <= keyMin) or (node->value > valueMin))
		return brojCvorova(node->left, keyMin, valueMin, true)
				+ brojCvorova(node->right, keyMin, valueMin, true);

	return brojCvorova(node->left, keyMin, valueMin, false) 
			+ brojCvorova(node->right, keyMin, valueMin, false);
}