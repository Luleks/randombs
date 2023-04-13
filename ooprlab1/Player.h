#pragma once
#include "Board.h"

class Board;

class Player {
private:
	int i, j, i0, j0;
	int laps;
	int h, x;
	bool right;
	bool right_off;
	Board* board;
public:
	Player(int i, int j, Board* tabla) {
		this->i = i;
		this->j = j;
		i0 = i;
		j0 = j;
		laps = 0;
		h = 0;
		x = 0;
		right = false;
		right_off = false;
		board = tabla;
	}
	~Player() {}
	
	bool move(int number);
	bool game_end();
	void apply_effects();
};