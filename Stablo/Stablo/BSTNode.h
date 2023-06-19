#pragma once
#include <iostream>
using namespace std;

class BSTNode
{
public:
	int key;
	double value;
	BSTNode* left, * right;
public:
	BSTNode() {
		key = 0;
		value = 0;
		left = right = 0;
	}
	BSTNode(int key, double value = 0.0) {
		this->key = key;
		this->value = value;
		left = right = 0;
	}
	BSTNode(int key, BSTNode* left, BSTNode* right, double value = 0.0) {
		this->key = key;
		this->left = left;
		this->right = right;
		this->value = value;
	}
	void visit() {
		cout << key << " ";
	}
};

