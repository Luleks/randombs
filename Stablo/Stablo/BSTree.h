#pragma once
#include "BSTNode.h"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class BSTree {
private:
	BSTNode* root;

	void deleteTree(BSTNode* root) {
		if (root == 0)
			return;
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
	}

	void recursiveInorder(BSTNode* node) {
		if (node == 0)
			return;
		recursiveInorder(node->left);
		node->visit();
		recursiveInorder(node->right);
	}
	void recursivePreorder(BSTNode* node) {
		if (node == 0)
			return;
		node->visit();
		recursivePreorder(node->left);
		recursivePreorder(node->right);
	}
	void recursivePostorder(BSTNode* node) {
		if (node == 0)
			return;
		recursivePostorder(node->left);
		recursivePostorder(node->right);
		node->visit();
	}

public:
	BSTree() {
		root = 0;
	}
	~BSTree() {
		deleteTree(root);
	}

	void insert(int val, double val1 = 0.0);
	BSTNode* find(int val);
	void deleteByCopying(int val);

	void recursiveInorder() {
		cout << "Recursive inorder" << endl;
		recursiveInorder(root);
		cout << endl;
	}
	void recursivePreorder() {
		cout << "Recursive preorder" << endl;
		recursivePreorder(root);
		cout << endl;
	}
	void recursivePostorder() {
		cout << "Recursive postorder" << endl;
		recursivePostorder(root);
		cout << endl;
	}

	void iterativePreorder();
	void iterativeInorder();
	void iterativePostorder();
	void breadthFirst();

	// RANDOM ZADACI ZA VEZBANJE
	int countWeight() {
		return countWeight(root);
	}
	int countWeight(BSTNode* root) {
		if (root == 0)
			return 0;
		if (isLeaf(root))
			return 1;
		return countWeight(root->left) + countWeight(root->right);
	}

	int findLevelWidth(int dubina) {
		return findLevelWidth(root, dubina);
	}
	int findLevelWidth(BSTNode* root, int dubina) {
		if (root == 0)
			return 0;
		else if (dubina == 0)
			return 1;
		return findLevelWidth(root->left, dubina - 1) + findLevelWidth(root->right, dubina - 1);
	}

	int countGreater(int value) {
		return countGreater(root, value);
	}
	int countGreater(BSTNode* root, int value) {
		if (root == 0)
			return 0;
		if (root->key > value)
			return 1 + countGreater(root->left, value) + countGreater(root->right, value);
		return countGreater(root->right, value);
	}

	int deleteRightLeaves() {
		return deleteRightLeaves(root);
	}
	int deleteRightLeaves(BSTNode* root) {
		if (root == 0)
			return 0;
		if (root->right != 0 and isLeaf(root->right)) {
			delete root->right;
			root->right = 0;
			return 1 + deleteRightLeaves(root->left);
		}
		return deleteRightLeaves(root->left) + deleteRightLeaves(root->right);
	}

	int findMaxNodesLevel() {
		return findMaxNodesLevel(root);
	}
	int findMaxNodesLevel(BSTNode* root) {
		if (root == 0)
			return 0;
		BSTNode* temp = root;
		queue<BSTNode*>* parents = new queue<BSTNode*>();
		queue<BSTNode*>* children = new queue<BSTNode*>();
		parents->push(temp);
		int curCount = 0;
		int maxCount = 0;
		while (not parents->empty()) {
			curCount = 0;
			while (not parents->empty()) {
				temp = parents->front();
				parents->pop();
				curCount += 1;
				if (temp->left != 0)
					children->push(temp->left);
				if (temp->right != 0)
					children->push(temp->right);
			}
			if (curCount > maxCount)
				maxCount = curCount;
			delete parents;
			parents = children;
			children = new queue<BSTNode*>();
		}
		return maxCount;
	}

	int getDeepest(BSTNode** deepest) {
		return getDeepest(root, deepest);
	}
	int getDeepest(BSTNode* root, BSTNode** deepest) {
		if (root == 0) {
			return 0;
			*deepest = 0;
		}
		if (root->left == 0 and root->right == 0) {
			*deepest = root;
			return 1;
		}
		BSTNode* node1, * node2;
		int left, right;
		left = getDeepest(root->left, &node1);
		right = getDeepest(root->right, &node2);
		if (left > right) {
			*deepest = node1;
			return 1 + left;
		}
		else {
			*deepest = node2;
			return 1 + right;
		}
	}

	// DECEMBAR 2021.
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

	// OKTOBAR II 2021.
	BSTNode* getNNode() {
		return getNNode(root);
	}
	BSTNode* getNNode(BSTNode* root) {
		if (root == 0)
			return 0;
		int countLeft = countUnordered(root->left);
		int countRight = countUnordered(root->right);
		if (countRight == countLeft + 2)
			return root;
		BSTNode* left = getNNode(root->left);
		BSTNode* right = getNNode(root->right);
		return (left != 0) ? left : right;
	}
	int countUnordered(BSTNode* root) {
		if (root == 0)
			return 0;
		return 1 + countUnordered(root->left) + countUnordered(root->right);
	}

	// OKTOBAR 2021.
	int countSpecificNodes() {
		return countSpecificNodes(root);
	}
	int countSpecificNodes(BSTNode* root) {
		if (root == 0)
			return 0;
		int countLeft = countElementsInTree(root->left);
		int countRight = countElementsInTree(root->right);
		int count = 0;
		if (countRight > countLeft)
			count += 1;
		return count + countSpecificNodes(root->left) + countSpecificNodes(root->right);
	}
	int countElementsInTree(BSTNode* root) {
		if (root == 0)
			return 0;
		return 1 + countElementsInTree(root->left) + countElementsInTree(root->right);
	}

	// JUN II 2021.
	BSTNode* findNodeWithLargestRightSubtree() {
		return findNodeWithLargestRightSubtree(root);
	}
	BSTNode* findNodeWithLargestRightSubtree(BSTNode* root) {
		if (root == 0)
			return 0;
		BSTNode* max = findNodeWithLargestRightSubtree(root->left);
		if (max == 0)
			return root;
		int count = countNodes(root->right);
		int countLeft = countNodes(max->right);
		if (count > countLeft)
			return root;
		return max;
	}
	int countNodes(BSTNode* root) {
		if (root == 0)
			return 0;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}

	// SEPTEMBAR 2021.
	int countSingleLeavesNodes() {
		return countSingleLeavesNodes(root);
	}
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

	// JUN 2021.
	int countSL() {
		return countSL(root);
	}
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

	// KOLOKVIJUM II 2021.
	int deleteAllLeftLeafs() {
		return deleteAllLeftLeafs(root);
	}
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

	// JUN II 2022.
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

	// OKTOBAR II 2022.
	BSTNode* findSibling(BSTNode* node) {
		if (root == 0)
			return 0;
		queue<BSTNode*>* parents = new queue<BSTNode*>();
		queue<BSTNode*>* children = new queue<BSTNode*>();
		BSTNode* temp = root;
		bool nodeFound = false;
		parents->push(temp);
		while (not parents->empty() and not nodeFound) {
			while (not parents->empty()) {
				temp = parents->front();
				parents->pop();
				if (temp->left != 0) {
					children->push(temp->left);
					if (temp->left == node)
						nodeFound = true;
				}
				if (temp->right != 0) {
					children->push(temp->right);
					if (temp->right == node)
						nodeFound = true;
				}
			}
			parents = children;
			children = new queue<BSTNode*>();
		}
		if (not nodeFound)
			return 0;
		if (parents->front() == node)
			parents->pop();
		return parents->front();
	}

	// SEPTEMBAR 2022.
	int countNodesInRange(int min, int max) {
		return countNodesInRange(root, min, max);
	}
	int countNodesInRange(BSTNode* root, int min, int max) {
		if (root == 0)
			return 0;
		int count = 0;
		if (root->key >= min and root->key <= max)
			count += 1 + countNodesInRange(root->left, min, max) + countNodesInRange(root->right, min, max);
		else if (root->key < min)
			count += countNodesInRange(root->right, min, max);
		else if (root->key > max)
			count += countNodesInRange(root->left, min, max);
		return count;
	}

	// JUN 2022.
	int countMoment() {
		return countMoment(root);
	}
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

	// OKTOBAR 2022.
	int countCloseSiblings() {
		return countCloseSiblings(root);
	}
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
};

void BSTree::insert(int val, double val1) {
	BSTNode* temp = root, * prev = 0;
	while (temp != 0) {
		prev = temp;
		if (val < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if (prev == 0)
		root = new BSTNode(val, val1);
	else if (val < prev->key)
		prev->left = new BSTNode(val, val1);
	else
		prev->right = new BSTNode(val, val1);
}

BSTNode* BSTree::find(int val) {
	BSTNode* temp = root;
	while (temp != 0 and temp->key != val) {
		if (val < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return temp;
}

void BSTree::iterativePreorder() {
	if (root == 0)
		return;
	cout << "Iterative preorder" << endl;
	BSTNode* temp = root;
	stack<BSTNode*> stek;
	stek.push(temp);
	while (not stek.empty()) {
		temp = stek.top();
		stek.pop();
		temp->visit();
		if (temp->right != 0)
			stek.push(temp->right);
		if (temp->left != 0)
			stek.push(temp->left);
	}
	cout << endl;
	return;
}

void BSTree::iterativeInorder() {
	cout << "Iterative inorder" << endl;
	BSTNode* temp = root;
	stack<BSTNode*> stek;
	while (temp != 0) {
		while (temp != 0) {
			if (temp->right != 0)
				stek.push(temp->right);
			stek.push(temp);
			temp = temp->left;
		}
		temp = stek.top();
		stek.pop();
		while (not stek.empty() and temp->right == 0) {
			temp->visit();
			temp = stek.top();
			stek.pop();
		}
		temp->visit();
		if (not stek.empty()) {
			temp = stek.top();
			stek.pop();
		}
		else
			temp = 0;
	}
	cout << endl;
}

void BSTree::iterativePostorder() {
	cout << "Iterative postorder" << endl;
	BSTNode* temp = root, *help = root;
	stack<BSTNode*> stek;
	while (temp != 0) {
		for (; temp->left != 0; temp = temp->left)
			stek.push(temp);
		while (temp->right == 0 or temp->right == help) {
			temp->visit();
			help = temp;
			if (stek.empty()) {
				cout << endl;
				return;
			}
			temp = stek.top();
			stek.pop();
		}
		if (temp->right != 0) {
			stek.push(temp);
			temp = temp->right;
		}
	}
	cout << endl;
}

void BSTree::breadthFirst() {
	cout << "Breadth first" << endl;
	BSTNode* temp = root;
	queue<BSTNode*> qju;
	qju.push(temp);
	while (not qju.empty()) {
		temp = qju.front();
		qju.pop();
		temp->visit();
		if (temp->left != 0)
			qju.push(temp->left);
		if (temp->right != 0)
			qju.push(temp->right);
	}
	cout << endl;
}

void BSTree::deleteByCopying(int val) {
	if (root == 0)
		return;
	BSTNode* prev = 0, * temp = root;
	while (temp != 0 and temp->key != val) {
		prev = temp;
		if (val < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if (temp == 0)
		return;
	BSTNode* node = temp;
	if (temp->left == 0)
		node = temp->right;
	else if (temp->right == 0)
		node = temp->left;
	else {
		BSTNode* prv = temp, * tmp = temp->left;
		while (tmp->right != 0) {
			prv = tmp;
			tmp = tmp->right;
		}
		node->key = tmp->key;
		if (prv == node)
			prv->left = tmp->left;
		else
			prv->right = tmp->left;
		delete tmp;
		return;
	}
	if (temp == root)
		root = node;
	else if (prev->left == temp)
		prev->left = node;
	else
		prev->right = node;
	delete temp;
}