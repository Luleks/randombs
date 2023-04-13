#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Field {
private:
	char chr;
	int i;
	int j;
	int diri;
	int dirj;
	int alt_diri;
	int alt_dirj;
	char mode;
public:
	Field() {
		i = j = diri = dirj = alt_diri = alt_dirj = 0;
		chr = 0;
	}
	Field(int i, int j) {
		this->i = i;
		this->j = j;
		chr = 0;
		diri = dirj = alt_diri = alt_dirj = 0;
	}
	~Field() {}
	char get_char() {
		return chr;
	}
	int get_i() {
		return i;
	}
	int get_j() {
		return j;
	}
	int get_diri() {
		return diri;
	}
	int get_dirj() {
		return dirj;
	}
	int get_alt_diri() {
		return alt_diri;
	}
	int get_alt_dirj() {
		return alt_dirj;
	}
	void set_diri(int dir) {
		diri = dir;
		dirj = 0;
	}
	void set_dirj(int dir) {
		dirj = dir;
		diri = 0;
	}
	void set_alt_diri(int dir) {
		alt_diri = dir;
		alt_dirj = 0;
	}
	void set_alt_dirj(int dir) {
		alt_dirj = dir;
		alt_diri = 0;
	}
	void set_char(char c) {
		chr = c;
	}

	friend istream& operator>>(istream& in, Field& f);
};