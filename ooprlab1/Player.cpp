#include "Player.h"
#include <cmath>

bool Player::move(int number) {
	if (x == 1)
		number = (number / 2) + 1;
	else if (x == 2) {
		number = (number / 2 + 1) / 2 + 1;
		x = 0;
	}
	number = number * ((int)pow(2, h));
	if (h == 2)
		h = 0;
	for (int k = 0; k < number; k++) {
		int* dirs = board->get_dirs(i, j, i0, j0, right);
		i0 = i;
		j0 = j;
		i += dirs[0];
		j += dirs[1];
		board->clear_player_position(i0, j0);
		board->set_player_position(i, j);

		if (game_end())
			return false;

		system("cls");
		cout << *board;
		Sleep(300);
	}
	if ((i == 19 or i == 0 or j == 19 or j == 0) and right_off) {
		right = false;
		right_off = false;
	}
	if (board->get_field_char(i, j) == 'H' && h == 1) {
		h += 1;
		return move(number / 2);
	}
	return true;
}

bool Player::game_end() {
	if (i == board->get_o()[0] && j == board->get_o()[1]) {
		laps += 1;
		if (laps == board->get_laps())
			return true;
	}
	return false;
}

void Player::apply_effects() {
	if (board->get_field_char(i, j) == 'S') {
		right = true;
		h = x = 0;
	}
	else if (board->get_field_char(i, j) == 'T') {
		if (j >= 12 and j <= 18 and i >= 0 and i <= 18)
			right_off = true;
		else if (j >= 1 and j <= 7 and i >= 11 and i <= 18)
			right_off = true;
		else 
			right = false;
		h = x = 0;
	}
	else if (board->get_field_char(i, j) == 'P') {
		board->clear_player_position(i, j);
		int* dirs = board->find_next_p(i, j);
		i = dirs[0];
		j = dirs[1];
		board->set_player_position(i, j);
		h = x = 0;
	}
	else if (board->get_field_char(i, j) == 'H') {
		h += 1;
		x = 0;
	}
	else if (board->get_field_char(i, j) == 'X') {
		x += 1;
		h = 0;
	}
	else
		h = x = 0;
}