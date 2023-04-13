#pragma once
#include "Field.h"
#include "Player.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <iomanip>
using namespace std;

class Player;

class Board {
private:
	static Board* singleton;
	int laps;

	Field*** board;
	int o[2];
	int size;

	Player* player;

	string board_rep;
	int row_len;
	
	void load_board(const char* file);
	void set_field_directions();
	void format_board();

	bool outside(int i, int j) {
		if (i > 19 or i < 0 or j > 19 or j < 0)
			return true;
		else if (board[i][j]->get_char() == '-')
			return true;
		return false;
	}

	Board(const char* file, int laps);

public:
	~Board();
	
	static void set_board(const char* file, int laps) {
		if (singleton == 0)
			singleton = new Board(file, laps);
	}

	static Board* get_board() {
		return singleton;
	}

	int* get_dirs(int i, int j, int i0, int j0, bool right);

	int get_laps() {
		return laps;
	}

	int* get_o() {
		return o;
	}

	char get_field_char(int i, int j) {
		return board[i][j]->get_char();
	}

	Field* get_field(int i, int j) {
		return board[i][j];
	}

	int* find_next_p(int i, int j);

	bool board_action(int number);
	void clear_player_position(int i, int j);
	void set_player_position(int i, int j);

	friend ostream& operator<<(ostream& out, const Board& b);
};