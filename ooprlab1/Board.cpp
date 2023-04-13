#include "Board.h"

Board* Board::singleton = 0;

Board::Board(const char* file, int laps) {
	this->laps = laps;
	size = 20;
	board = new Field * *[size];
	for (int i = 0; i < size; i++) {
		board[i] = new Field * [size];
		for (int j = 0; j < size; j++)
			board[i][j] = new Field(i, j);
	}
	load_board(file);
	player = new Player(o[0], o[1], this);
	row_len = size * 4 + 2;
	format_board();
	
	/*
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << "(" << setw(2) << board[i][j]->get_diri() << "," << setw(2) << board[i][j]->get_dirj() << ") ";
		cout << endl;
	}
	cout << "--------------------------------------------------------" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j]->get_alt_diri() == 0 and board[i][j]->get_alt_dirj() == 0)
				cout << "(" << setw(2) << board[i][j]->get_diri() << "," << setw(2) << board[i][j]->get_dirj() << ") ";
			else
				cout << "(" << setw(2) << board[i][j]->get_alt_diri() << "," << setw(2) << board[i][j]->get_alt_dirj() << ") ";
		}
		cout << endl;
	}
	
	system("pause");
	*/
	
}

void Board::load_board(const char* file) {
	ifstream in(file);
	if (!in.good())
		throw exception("Cannot open file");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			in >> *board[i][j];
			if (board[i][j]->get_char() == 'O') {
				o[0] = i;
				o[1] = j;
			}
		}
	}
	set_field_directions();
	in.close();
}

void Board::set_field_directions() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == 0 and j != 19)
				board[i][j]->set_dirj(1);
			else if (j == 19 and i != 19)
				board[i][j]->set_diri(1);
			else if (i == 19 and j != 0)
				board[i][j]->set_dirj(-1);
			else if (j == 0 and i != 0)
				board[i][j]->set_diri(-1);
			else {
				if (j > i and board[i][j]->get_char() != '-') {
					if (not outside(i + 1, j)) {
						board[i][j]->set_diri(1);
						board[i][j]->set_alt_diri(-1);
					}
					else if (not outside(i, j + 1)) {
						board[i][j]->set_dirj(1);
						board[i][j]->set_alt_dirj(-1);
					}
				}
				else if (i > j and board[i][j]->get_char() != '-') {
					if (not outside(i - 1, j)) {
						board[i][j]->set_diri(-1);
						board[i][j]->set_alt_diri(1);
					}
					else if (not outside(i, j - 1)) {
						board[i][j]->set_dirj(-1);
						board[i][j]->set_alt_dirj(1);
					}
				}
			}
		}
	}
	board[0][12]->set_alt_diri(1);
	board[19][7]->set_alt_diri(-1);
	board[11][0]->set_alt_dirj(1);
	board[7][19]->set_alt_dirj(-1);
	board[7][12]->set_dirj(1);
	board[7][12]->set_alt_diri(-1);
	board[11][7]->set_dirj(-1);
	board[11][7]->set_alt_diri(1);
}

void Board::format_board() {
	for (int i = 0; i < size; i++)
		board_rep += " ___";
	board_rep += "\n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j]->get_char() != '-')
				board_rep += "|   ";
			else {
				if (j != 0 && board[i][j - 1]->get_char() != '-')
					board_rep += "|   ";
				else
					board_rep += "    ";
			}
		}
		board_rep += "|\n";

		for (int j = 0; j < size; j++) {
			if (board[i][j]->get_char() != '-')
				board_rep += "|___";
			else {
				if (i != 19 && board[i + 1][j]->get_char() != '-' && j != 0 && board[i][j - 1]->get_char() != '-')
					board_rep += "|___";
				else if (i != 19 && board[i + 1][j]->get_char() != '-') {
					board_rep += " ___";
				}
				else if (j != 0 && board[i][j - 1]->get_char() != '-') {
					board_rep += "|   ";
				}
				else
					board_rep += "    ";
			}
		}
		board_rep += "|\n";
	}
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (board[i][j]->get_char() != '-' && board[i][j]->get_char() != 'D')
				board_rep[(1 + 2 * i) * row_len + (1 + 4 * j)] = board[i][j]->get_char();
	set_player_position(o[0], o[1]);
}

Board::~Board() {
	if (board != 0) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				delete board[i][j];
				board[i][j] = 0;
			}
			delete[] board[i];
			board[i] = 0;
		}
		delete[] board;
	}
	board = 0;
	if (player != 0)
		delete player;
	player = 0;
}

ostream& operator<<(ostream& out, const Board& b) {
	out << b.board_rep;
	return out;
}

void Board::clear_player_position(int i, int j) {
	int player_pos = (2 + 2 * i) * row_len + (1 + 4 * j);
	board_rep[player_pos] = '_';
}

void Board::set_player_position(int i, int j) {
	int player_pos = (2 + 2 * i) * row_len + (1 + 4 * j);
	board_rep[player_pos] = 'i';
}

bool Board::board_action(int number) {
	if (not player->move(number))
		return false;
	player->apply_effects();
	return true;
}

int* Board::find_next_p(int i, int j) {
	int p[2];
	for (int k = 0; k < size; k++)
		for (int l = 0; l < size; l++)
			if (board[k][l]->get_char() == 'P' and k != i and l != j) {
				p[0] = k;
				p[1] = l;
			}
	return p;
}

int* Board::get_dirs(int i, int j, int i0, int j0, bool right) {
	int dirs[2];
	if ((i == i0 and j == j0) or not right) {
		dirs[0] = board[i][j]->get_diri();
		dirs[1] = board[i][j]->get_dirj();
	}
	else {
		if (i + board[i][j]->get_alt_diri() == i0 and j + board[i][j]->get_alt_dirj() == j0) {
			dirs[0] = board[i][j]->get_diri();
			dirs[1] = board[i][j]->get_dirj();
		}
		else if (board[i][j]->get_alt_diri() == 0 and board[i][j]->get_alt_dirj() == 0) {
			dirs[0] = board[i][j]->get_diri();
			dirs[1] = board[i][j]->get_dirj();
		}
		else {
			dirs[0] = board[i][j]->get_alt_diri();
			dirs[1] = board[i][j]->get_alt_dirj();
		}
	}
	return dirs;
}