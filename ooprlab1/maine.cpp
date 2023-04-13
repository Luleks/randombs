#include "Board.h"
#include <Windows.h>

void display_number(int number);

int roll_dice(Board* b) {
	for (int i = 0; i < 10; i++) {
		cout << *b;
		display_number(1 + rand() % 6);
		Sleep(200);
		system("cls");
	}

	return 1+ rand() % 6;
}

int main() {
	srand(time(0));

	int k = 0;
	do {
		cout << "Broj prolazaka preko starta (>= 1): ";
		cin >> k;
		system("cls");
	} while (k < 1);

	Board::set_board("tabla.txt", k);
	Board * b = Board::get_board();
	bool run = true;
	char temp;
	int number = 1;

	while (run) {
		cout << *b;
		display_number(number);
		cout << endl << "r/R - roll the dice, x/X - terminate: ";
		cin >> temp;

		if (temp == 'r' || temp == 'R') {
			number = roll_dice(b);
			system("cls");
			cout << *b;
			display_number(number);
			Sleep(2000);
			run = b->board_action(number);
		}
		else if (temp == 'x' || temp == 'X')
			run = false;
		system("cls");
	}

	if (temp == 'x' or temp == 'X') {
		cout << "Terminated" << endl;
	}
	else {
		cout << *b << endl;
		cout << "Player has crossed start line " << k << " times. Game over";
	}

	delete b;
	return 0;
}

void display_number(int number) {
	if (number == 1) {
		cout << " _____ " << endl;
		cout << "|     |" << endl;
		cout << "|  *  |" << endl;
		cout << "|_____|" << endl;
	}
	else if (number == 2) {
		cout << " _____ " << endl;
		cout << "|  *  |" << endl;
		cout << "|     |" << endl;
		cout << "|__*__|" << endl;
	}
	else if (number == 3) {
		cout << " _____ " << endl;
		cout << "|  *  |" << endl;
		cout << "|  *  |" << endl;
		cout << "|__*__|" << endl;
	}
	else if (number == 4) {
		cout << " _____ " << endl;
		cout << "|*   *|" << endl;
		cout << "|     |" << endl;
		cout << "|*___*|" << endl;
	}
	else if (number == 5) {
		cout << " _____ " << endl;
		cout << "|*   *|" << endl;
		cout << "|  *  |" << endl;
		cout << "|*___*|" << endl;
	}
	else if (number == 6) {
		cout << " _____ " << endl;
		cout << "|*   *|" << endl;
		cout << "|*   *|" << endl;
		cout << "|*___*|" << endl;
	}
}