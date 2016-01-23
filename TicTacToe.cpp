/*
	name : Phenomenon
	github : phen0menon
	language : cpp
*/

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>

int main() {
	srand(time(nullptr));
	setlocale(LC_ALL, "Russian");
	int row = 0; // just statement
	int col = 0; // just statement
	const int rows = 3; // for matrix
	const int cols = 3; // for matrix
	bool playerOne = true; // ' x '
	bool playerTwo = false; // ' 0 ' 

	/* * * * * * * * * * * * * * * * * * * * * * * *
	* * * * * * initialize char *matrix * * * * * */
	
	char **matrix = new char*[rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new char[cols];
	}
	for (int i = 0; i < rows; i++) {
		std::cout << " | ";
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = 'n';
			std::cout << matrix[i][j] << " ";
		}
		std::cout << " | " << std::endl;
	}

	/* * * * * * * * * * * * * * * * * * * * * * * *
	* * * * * * player's choice to moving * * * * * */
	while (true) {
		if (playerOne) {
			std::cout << std::endl << std::setw(4) << " PLAYER 1 IS MOVING " << std::endl;
			do {
				std::cout << "enter your move: "; // 0, 0 to 3, 3
				std::cin >> row;
				std::cin >> col;
				if (!(row >= 0 && row <= 3 && col >= 0 && col <= 3)) {
					std::cout << "enter legal move!" << std::endl;
				}
			} while (!(row >= 0 && row <= 3 && col >= 0 && col <= 3));
			matrix[row - 1][col - 1] = 'x';

			if (matrix[0][0] && matrix[0][1] && matrix[0][2] == 'n') { // 00 01 02
				std::cout << "\n----PLAYER 1 WINS----" << std::endl;
				break;
			}
			if (matrix[0][0] && matrix[1][0] && matrix[2][0] == 'n') { // 00 10 20
				std::cout << "\n----PLAYER 1 WINS----" << std::endl;
				break;
			}
			if (matrix[0][0] && matrix[1][1] && matrix[2][2] == 'n') { // 00 11 22
				std::cout << "\n----PLAYER 1 WINS----" << std::endl;
				break;
			}
			if (matrix[1][0] && matrix[1][1] && matrix[1][2] == 'n') { // 10 11 12
				std::cout << "\n----PLAYER 1 WINS----" << std::endl;
				break;
			}
			if (matrix[0][1] && matrix[1][1] && matrix[2][1] == 'n') { // 01 11 21
				std::cout << "\n----PLAYER 1 WINS----" << std::endl;
				break;
			}
			if (matrix[2][0] && matrix[1][1] && matrix[0][2] == 'n') { // 20 11 02
				std::cout << "\n----PLAYER 1 WINS----" << std::endl;
				break;
			}
			if (matrix[0][2] && matrix[1][2] && matrix[2][2] == 'n') { // 02 12 22
				std::cout << "\n----PLAYER 1 WINS----" << std::endl;
				break;
			}
			playerOne = false;
			playerTwo = true;
			for (int i = 0; i < rows; i++) {
				std::cout << " | ";
				for (int j = 0; j < cols; j++) {
					std::cout << matrix[i][j] << " ";
				}
				std::cout << " | " << std::endl;
			}
		}
		if (playerTwo) {
			std::cout << std::endl << std::setw(4) << " PLAYER 2 IS MOVING " << std::endl;
			do {
				std::cout << "enter your move: "; // 0, 0 to 3, 3
				std::cin >> row;
				std::cin >> col;
				if (!(row >= 0 && row <= 3 && col >= 0 && col <= 3)) {
					std::cout << "enter legal move!" << std::endl;
				}
			} while (!(row >= 0 && row <= 3 && col >= 0 && col <= 3));
			matrix[row - 1][col - 1] = '0';

			if (matrix[0][0] && matrix[0][1] && matrix[0][2] == '0') { // 00 01 02
				std::cout << "\n----PLAYER 2 WINS----" << std::endl;
				break;
			} 
			if (matrix[0][0] && matrix[1][0] && matrix[2][0] == '0') { // 00 10 20
				std::cout << "\n----PLAYER 2 WINS----" << std::endl;
				break;
			}
			if (matrix[0][0] && matrix[1][1] && matrix[2][2] == '0') { // 00 11 22
				std::cout << "\n----PLAYER 2 WINS----" << std::endl;
				break;
			}
			if (matrix[1][0] && matrix[1][1] && matrix[1][2] == '0') { // 10 11 12
				std::cout << "\n----PLAYER 2 WINS----" << std::endl;
				break;
			}
			if (matrix[0][1] && matrix[1][1] && matrix[2][1] == '0') { // 01 11 21
				std::cout << "\n----PLAYER 2 WINS----" << std::endl;
				break;
			}
			if (matrix[2][0] && matrix[1][1] && matrix[0][2] == '0') { // 20 11 02
				std::cout << "\n----PLAYER 2 WINS----" << std::endl;
				break;
			}
			if (matrix[0][2] && matrix[1][2] && matrix[2][2] == '0') { // 02 12 22
				std::cout << "\n----PLAYER 2 WINS----" << std::endl;
				break;
			}
			
			playerOne = false;
			playerOne = true;
			for (int i = 0; i < rows; i++) {
				std::cout << " | ";
				for (int j = 0; j < cols; j++) {
					std::cout << matrix[i][j] << " ";
				}
				std::cout << " | " << std::endl;
			}
		}
		std::cout << std::endl;
	}

	/* --------------------- E X A M P L E S ---------------------- 
	* if(matrix[0][0] && matrix[0][1] && matrix[0][2]) win 00 01 02
	* if(matrix[0][0] && matrix[1][0] && matrix[2][0]) win 00 10 20
	* if(matrix[0][0] && matrix[1][1] && matrix[2][2]) win 00 11 22
	* if(matrix[1][0] && matrix[1][1] && matrix[1][2]) win 10 11 12
	* if(matrix[0][1] && matrix[1][1] && matrix[2][1]) win 01 11 21
	* if(matrix[2][0] && matrix[1][1] && matrix[0][2]) win 20 11 02
	* if(matrix[0][2] && matrix[1][2] && matrix[2][2]) win 02 12 22
	* row 1, col 1
	* matrix[row-1][col-1] = 'x'; 
	--------------------------------------------------------------*/


	for (int i = 0; i < rows; i++) {
		std::cout << " | ";
		for (int j = 0; j < cols; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << " | " << std::endl;
	}

	/* * * * * * * * * * * * * * * * * * * * * * * * */
	delete [] matrix;
	_getch();
}

