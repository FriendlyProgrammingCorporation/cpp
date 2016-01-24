/*
name : Phenomenon
github : phen0menon
language : cpp
*/

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <ctime>

/* * * V A R I A B L E S * * */
char matrix[3][3];
int row = 0; // just var
int col = 0; // just var
const int rows = 3; // for matrix
const int cols = 3; // for matrix
bool playerOne = true; // ' x '
bool playerTwo = false; // ' 0 ' 
bool isPlay = true; 
char* alph = "1234567890-=qwert'yuiop[]asdfghjkl;zxcvbnm,./éöóêåíãøùçõúôûâàïðîëäæýÿ÷ñìèòüþ.!¹;:?*()_+"; // buffer for getch

void ReadME() { // show instructions
	char choice = 0;
	do {
		std::cout << ".............. Welcome to TicTacToe game! ............." << std::endl;
		std::cout << ".................. Rules are simple ..................." << std::endl;
		std::cout << "|1| You can move only (1, 1) to (3, 3), same as in geometry" << std::endl;
		std::cout << "|2| You can't move to point that already used" << std::endl;
		std::cout << "|3| Mercy me for my English :D :D :D" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "                  TO START PRESS ANY KEY                 " << std::endl;
		choice = _getch();

	} while (!strchr (alph, choice)); // until users any key
	system("cls"); // clear screen
}

void win() { // if win-combination are exists
	isPlay = false; 
	playerOne = false;
	playerTwo = false;
}

void fillMatrix() { // fill in matrix
	for (int i(0); i < 3; i++) {
		for (int j(0); j < 3; j++) {
			matrix[i][j] = '-'; // all elements of matrix have '-' values
		}
	}
}

void showMatrix() { // show full matrix (rows and cols)
	for (int i(0); i < 3; i++) {
		std::cout << " | "; 
		for (int j(0); j < 3; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << " | " << std::endl;
	}
}
void play() { // TicTacToe game function
	while (isPlay) { 
		if (playerOne) {
			bool problems = false;
			bool fill = false;
			std::cout << " ------------------------------ ";
			std::cout << std::endl << std::setw(4) << " PLAYER 1 IS MOVING " << std::endl;
			do {
				problems = false;
				fill = false;
				std::cout << "enter your move: "; // 0, 0 to 3, 3
				std::cin >> row;
				std::cin >> col;
				if (!(row >= 0 && row <= 3 && col >= 0 && col <= 3)) {
					std::cout << "enter legal move!" << std::endl;
				}
				if ((matrix[row - 1][col - 1] == 'x') || (matrix[row - 1][col - 1] == '0')) {
					std::cout << "OOPS! " << row << "." << col << " already taken. " << std::endl;
					problems = true;
				}
					
				
				if (problems == false) {
					matrix[row - 1][col - 1] = 'x'; // fill ' x '
					fill = true;
				} 
			} while (!((row >= 0 && row <= 3 && col >= 0 && col <= 3) && (fill)));
			
			//while (!(((row >= 0 && row <= 3 && col >= 0 && col <= 3))
			//	&& ((matrix[row - 1][col - 1] == 'x'))));

			//matrix[row - 1][col - 1] = 'x'; // fill ' X '

			showMatrix();

			for (int i = 0; i < rows; i++) {
				if (((matrix[i][0] == 'x') && (matrix[i][1] == 'x') && (matrix[i][2] == 'x'))) {
					std::cout << " ... PLAYER 1 WINS ... " << std::endl;
					win();
				}
				else
					if (((matrix[0][i] == 'x') && (matrix[1][i] == 'x') && (matrix[2][i] == 'x'))) {
						std::cout << " ... PLAYER 1 WINS ... " << std::endl;
						win();
					}
					else if (((matrix[i][i] == 'x') && (matrix[i + 1][i + 1] == 'x') && (matrix[i + 2][i + 2] == 'x'))
						|| ((matrix[i][2] == 'x') && (matrix[i + 1][1] == 'x') && (matrix[i + 2][0] == 'x'))) {
						std::cout << " ... PLAYER 1 WINS ... " << std::endl;
						win();
					}
			}
			playerOne = !playerOne;
			playerTwo = !playerTwo;
		}
		if (playerTwo) {
			bool problems = false;
			bool fill = false;
			std::cout << " ------------------------------ ";
			std::cout << std::endl << " PLAYER 2 IS MOVING " << std::endl;
			do {
				problems = false;
				fill = false;
				std::cout << "enter your move: "; // 0, 0 to 3, 3
				std::cin >> row;
				std::cin >> col;
				if (!(row >= 0 && row <= 3 && col >= 0 && col <= 3)) {
					std::cout << "enter legal move!" << std::endl;
				}
				if ((matrix[row - 1][col - 1] == 'x') || (matrix[row - 1][col - 1] == '0')) {
					std::cout << "OOPS! " << row << "." << col << " already taken. " << std::endl;
					problems = true;
				}


				if (problems == false) {
					matrix[row - 1][col - 1] = '0'; // fill ' x '
					fill = true;
				}
			} while (!((row >= 0 && row <= 3 && col >= 0 && col <= 3) && (fill)));

			//matrix[row - 1][col - 1] = '0'; // fill ' 0 '

			showMatrix();

			for (int i = 0; i < rows; i++) {
				if (((matrix[i][0] == '0') && (matrix[i][1] == '0') && (matrix[i][2] == '0'))) {
					std::cout << " ... PLAYER 2 WINS ... " << std::endl;
					win();
				}
				else
					if (((matrix[0][i] ==  '0') && (matrix[1][i] == '0') && (matrix[2][i] == '0'))) {
						std::cout << " ... PLAYER 2 WINS ... " << std::endl;
						win();
					}
					else if (((matrix[i][i] == '0') && (matrix[i + 1][i + 1] == '0') && (matrix[i + 2][i + 2] == '0'))
						|| ((matrix[i][2] == '0') && (matrix[i + 1][1] == '0') && (matrix[i + 2][0] == '0'))) {
						std::cout << " ... PLAYER 1 WINS ... " << std::endl;
						win();
					}
			}
			playerTwo = !playerTwo;
			playerOne = !playerOne;
		}
	}
}

int main() {
	srand(time(nullptr)); // randomizer (just in case :D :D :D)
	setlocale(LC_ALL, "Russian"); // rus localization
	ReadME(); // instruction
	fillMatrix(); // fill in matrix
	showMatrix(); // show full matrix
	play(); // play function
	_getch();
}
