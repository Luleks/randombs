#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	double coef;
	int exp;
	Node* next;
public:
	Node() {
		coef = exp = 0;
		next = 0;
	}
	Node(double c, int e) {
		coef = c;
		exp = e;
		next = 0;
	}
	Node(double c, int e, Node* n) {
		coef = c;
		exp = e;
		next = n;
	}
	void print() {
		if (coef < 0)
			cout << "(" << coef << ")";
		else
			cout << coef;
		if (exp < 0)
			cout << "x^(" << exp << ")";
		else if (exp > 0)
			cout << "x^" << exp;
	}
};

class CPolynomLL {
protected:
	Node* lead;
public:
	CPolynomLL() {
		lead = 0;
	}
	void Coef(int exp, double coef) {
		if (lead == 0 or lead->exp < exp) {
			lead = new Node(coef, exp, lead);
			return;
		}
		Node* prev = lead;
		Node* cur = lead->next;
		while (cur != 0 and cur->exp > exp) {
			prev = cur;
			cur = cur->next;
		}
		if (cur != 0 and cur->exp == exp) {
			cur->coef += coef;
		}
		else {
			Node* temp = new Node(coef, exp, cur);
			prev->next = temp;
		}
	}
	void print() {
		Node* temp = lead;
		while (temp->next != 0) {
			temp->print();
			cout << " + ";
			temp = temp->next;
		}
		temp->print();
		cout << endl;
	}
	// 1)
	CPolynomLL* add(CPolynomLL* poly1) {
		CPolynomLL* new_poly = new CPolynomLL();
		Node* temp1 = poly1->lead;
		Node* temp2 = lead;
		while (temp1 != 0 and temp2 != 0) {
			if (temp1->exp > temp2->exp) {
				new_poly->Coef(temp1->exp, temp1->coef);
				temp1 = temp1->next;
			}
			else if (temp1->exp < temp2->exp) {
				new_poly->Coef(temp2->exp, temp2->coef);
				temp2 = temp2->next;
			}
			else {
				new_poly->Coef(temp1->exp, temp1->coef + temp2->coef);
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
		}
		while (temp1 != 0) {
			new_poly->Coef(temp1->exp, temp1->coef);
			temp1 = temp1->next;
		}
		while (temp2 != 0) {
			new_poly->Coef(temp2->exp, temp2->coef);
			temp2 = temp2->next;
		}
		return new_poly;
	}
	// 2)
	CPolynomLL* mul(CPolynomLL* poly2) {
		CPolynomLL* novi = new CPolynomLL();
		Node* temp1 = lead;
		while (temp1 != 0) {
			Node* temp2 = poly2->lead;
			while (temp2 != 0) {
				novi->Coef(temp1->exp + temp2->exp, temp1->coef * temp2->coef);
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
		}
		return novi;
	}
};

