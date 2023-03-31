#pragma once
#include <iostream>
using namespace std;

class SparseMatrixNode {
public:
	int info;
	int i, j;
	SparseMatrixNode* vrs, * kol;
public:
	SparseMatrixNode() {
		info = i = j = 0;
		vrs = kol = 0;
	}
	SparseMatrixNode(int infic, int ii, int jj) {
		info = infic;
		i = ii;
		j = jj;
		vrs = kol = 0;
	}
	SparseMatrixNode(int infic, int ii, int jj, SparseMatrixNode* vrs, SparseMatrixNode* kol) {
		info = infic;
		i = ii;
		j = jj;
		this->vrs = vrs;
		this->kol = kol;
	}
};

class CSparseMatrix {
protected:
	SparseMatrixNode** row_heads;
	SparseMatrixNode** col_heads;
	int n, m;
public:
	CSparseMatrix(int nn, int mm) {
		n = nn;
		m = mm;
		row_heads = new SparseMatrixNode * [n];
		for (int i = 0; i < n; i++)
			row_heads[i] = 0;
		col_heads = new SparseMatrixNode * [m];
		for (int i = 0; i < m; i++)
			col_heads[i] = 0;
	}
	~CSparseMatrix() {
		SparseMatrixNode* temp;
		for (int i = 0; i < n; i++) {
			temp = row_heads[i];
			while (temp != 0) {
				row_heads[i] = temp->vrs;
				delete temp;
				temp = row_heads[i];
			}
		}
		delete[] row_heads;
		delete[] col_heads;
	}
	void print() {
		for (int i = 0; i < n; i++) {
			SparseMatrixNode* temp = row_heads[i];
			if (temp == 0) {
				for (int j = 0; j < m; j++)
					cout << "0 ";
			}
			else {
				for (int j = 0; j < temp->j; j++)
					cout << "0 ";
				while (temp != 0 and temp->vrs != 0) {
					cout << temp->info << " ";
					for (int i = temp->j; i < temp->vrs->j - 1; i++)
						cout << "0 ";
					temp = temp->vrs;
				}
				if (temp != 0) {
					cout << temp->info << " ";
					for (int j = temp->j + 1; j < m; j++)
						cout << "0 ";
				}
			}
			cout << endl;
		}
	}
	void setAt(int el, int i, int j) {
		SparseMatrixNode* temp = new SparseMatrixNode(el, i, j);
		if (row_heads[i] == 0 or row_heads[i]->j > temp->j) {
			temp->vrs = row_heads[i];
			row_heads[i] = temp;
		}
		else {
			SparseMatrixNode* temp1 = row_heads[i];
			SparseMatrixNode* prev1 = 0;
			while (temp1 != 0 and row_heads[i]->j < j) {
				prev1 = temp1;
				temp1 = temp1->vrs;
			}
			if (temp1 == 0)
				prev1->vrs = temp;
			else if (temp1->j == j) {
				temp1->info = el;
			}
			else {
				prev1->vrs = temp;
				temp->vrs = row_heads[i];
			}
		}

		if (col_heads[j] == 0)
			col_heads[j] = temp;
		else {
			SparseMatrixNode* temp1 = col_heads[j];
			SparseMatrixNode* prev1= 0;
			while (temp1 != 0 and temp1->i < i) {
				prev1 = temp1;
				temp1 = temp1->kol;
			}
			if (temp1 == 0)
				prev1->kol = temp;
			else if (temp1 != 0) {
				prev1->kol = temp;
				temp->kol = temp1;
			}
		}
	}
	int getAt(int i, int j) {
		if (row_heads[i] == 0)
			return 0;
		SparseMatrixNode* temp = row_heads[i];
		while (temp != 0 and temp->j != j)
			temp = temp->vrs;
		if (temp != 0)
			return temp->info;
		return 0;
	}
};


