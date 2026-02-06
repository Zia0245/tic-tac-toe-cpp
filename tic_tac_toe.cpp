#include<iostream>
using namespace std;

bool win(char arr[3][3]) {

	for (int i = 0; i < 3; i++) {
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ') {
			return true;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ') {
			return true;
		}
	}

	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ') {
		return true;
	}

	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != ' ') {
		return true;
	}

	return false;
}

bool draw(char arr[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}

bool mark(char arr[3][3], int a) {
	int row, col;

	while (true) {
		cout << "Enter Row (1-3): ";
		cin >> row;
		cout << "Enter Column (1-3): ";
		cin >> col;

		if (row < 1 || row > 3 || col < 1 || col > 3) {
			cout << "\n*********************" << endl;
			cout << "Invalid input... Enter 1-3 only" << endl;
			cout << "*********************\n" << endl;
			continue;
		}

		if (arr[row - 1][col - 1] == ' ') {
			if (a == 1) {
				arr[row - 1][col - 1] = 'X';
			}
			else if (a == 2) {
				arr[row - 1][col - 1] = 'O';
			}
			return true;
		}
		else {
			cout << endl;
			cout << "*********************" << endl;
			cout << "Cell already occupied..." << endl;
			cout << "Try again..." << endl;
			cout << "*********************\n" << endl;
		}
	}
}

void index(char arr[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arr[i][j] = ' ';
		}
	}
}

void board(char arr[3][3]) {
	cout << endl;
	cout << "   ------------ " << endl;
	for (int i = 0; i < 3; i++) {
		cout << "  | ";
		for (int j = 0; j < 3; j++) {
			cout << " " << arr[i][j] << " |";
		}
		cout << endl;
	}
	cout << "   ------------\n" << endl;
}

void warning() {
	cout << "****************************\n";
	cout << "Enter valid positions only..." << endl;
	cout << "****************************\n\n";
}

int main() {
	char arr[3][3];
	index(arr);
	board(arr);
	warning();

	while (true) {
		cout << "Player 1's turn (X)" << endl << endl;
		mark(arr, 1);
		system("CLS");
		board(arr);

		if (win(arr)) {
			cout << "Player 1 (X) Wins!" << endl;
			cout << "\n**************\n";
			cout << "   Winner (X)";
			cout << "\n**************\n";
			break;
		}

		if (draw(arr)) {
			cout << "Draw Match!" << endl << endl;
			break;
		}

		cout << "Player 2's turn (O)" << endl << endl;
		mark(arr, 2);
		system("CLS");
		board(arr);

		if (win(arr)) {
			cout << "Player 2 (O) Wins!" << endl;
			cout << "\n**************\n";
			cout << "   Winner (O)";
			cout << "\n**************\n";
			break;
		}

		if (draw(arr)) {
			cout << "Draw Match!" << endl << endl;
			break;
		}
	}

	system("pause");
	return 0;
}
