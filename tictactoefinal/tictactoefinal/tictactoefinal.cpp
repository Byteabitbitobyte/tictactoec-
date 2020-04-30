#include <iostream>
#include <conio.h>

// board
//display board
//play game
// handle turn
//check win
// check rows, columns, diagonals
// check for tie
// flip player

using namespace std;

void printInputboard();
void printGameboard();
int addTurn();
int checkWinners();

char board[3][3] = { ' ', ' ', ' ',
					 ' ', ' ', ' ',
					 ' ', ' ', ' ' };

int turn = 1;
char mark = 'O';
int input;

int main()
{
	int won = 0;
	int validInput = 0;


	for (int i = 0; i < 9; i++) {
		system("cls");
		printGameboard();

		if (turn) cout << "O's turn" << endl;
		else cout << " X's turn " << endl;
		printInputboard();
		cout << "Enter input";
		cin >> input;

		while (input < 0 || input > 9)
		{
			cout << "Invalid input.";
			cin >> input;
		}

		if (turn) mark = 'O';

		else mark = 'X';

		validInput = addTurn();
		if (!validInput) {
			i--;
			continue;
		}
		won = checkWinners();
		if (won) {
			
			printGameboard();
			if (turn) cout << "X has won" << endl;
			else cout << "O has won" << endl;
			break;
		}
		if (i == 8) {
			
			printGameboard();
			cout << "Cats game, tie game.";
		}
		turn = !turn;
	}

	return 0;
}
void printInputboard() {
	cout << "Input Matrix" << endl;
	cout << " 1 | 2 | 3 " << endl;
	cout << "------------" << endl;
	cout << " 4 | 5 | 6 " << endl;
	cout << "------------" << endl;
	cout << " 7 | 8 | 9 " << endl;
}

void printGameboard() {
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " " << endl;
	cout << "------------" << endl;
	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " " << endl;
	cout << "------------" << endl;
	cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " " << endl;

}
int addTurn() {
	for (int i = 0, k = 1; i < 3; i++) {
		for (int j = 0; j < 3; j++, k++) {
			if (k == input)
				if (board[i][j] == ' ') {
					board[i][j] = mark;
					return 1;
				}
				else {
					cout << "invalid Input, spot taken.";
					return 0;
				}
		}
	}
}
// Checking winners off rows
int checkWinners() {
	if (board[0][0] == mark && board[0][1] == mark && board[0][2] == mark)
		return 1;
	if (board[1][0] == mark && board[1][1] == mark && board[1][2] == mark)
		return 1;
	if (board[2][0] == mark && board[2][1] == mark && board[2][2] == mark)
		return 1;
	// Checking winners off columns 
	if (board[0][0] == mark && board[1][0] == mark && board[2][0] == mark)
		return 1;
	if (board[0][1] == mark && board[1][1] == mark && board[2][1] == mark)
		return 1;
	if (board[0][2] == mark && board[1][2] == mark && board[2][2] == mark)
		return 1;
	// Checking winners off crosses
	if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark)
		return 1;
	if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)
		return 1;

	return 0;
}