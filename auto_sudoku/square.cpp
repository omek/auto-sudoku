#include "square.h"
#include <vector>
#include <iostream>
#include <fstream>


square::square():baseSquare(9, std::vector<int>(9)) {
	std::ifstream file("sudoku.txt");
	int c, z = 0, i = 0;
	int can;
	if (file.is_open()) {
		while (!file.eof()) {
			c = file.get();
			if (c != 10) {
				if (z < baseSquare.size() && i < baseSquare.size()) {
					baseSquare[z][i] = c - '0';
					i++;
				}
			}
			else {
				z++;
				i = 0;
			}
		}
		file.close();
	}
}



bool square::check(std::vector<std::vector<int>>&baseSquare, int Height, int Width, int Num) {
	
	
	for (int i = 0; i < 9; i++) {
		if (baseSquare[Height][i] == Num && Width != i) 
			return false;
	}
	for (int i = 0; i < 9; i++) {
		if (baseSquare[i][Width] == Num && Height != i) 
			return false;
	}

	int y_Height = Width / 3;
	int x_Width = Height / 3;

	for (int i = x_Width * 3; i < x_Width * 3 + 3; i++) {
		for (int j = y_Height * 3; j < y_Height * 3 + 3; j++) {
			if (baseSquare[i][j] == Num && i != Width && j != Height) {
				return false;
			}
		}
	}
	
	return true;
}


bool square::isSolved(std::vector<std::vector<int>>&baseSquare) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (baseSquare[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}



bool square::solve(std::vector<std::vector<int>>&baseSquare, int H, int W) {

	if (isSolved(baseSquare)) {
		return true;
	}

	if (W == 9) {
		W = 0;
		H++;
	}

	if (baseSquare[H][W] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (check(baseSquare, H, W, i)) {
				baseSquare[H][W] = i;
				if (solve(baseSquare, H, W + 1)) {
					return true;
				}
				baseSquare[H][W] = 0;
			}

		}
	}
	else {
		return solve(baseSquare, H, W + 1);

	}
	return false;
}

void square::tryToSolve() {
	
	if (!solve(baseSquare, 0, 0)) {
		std::cout << "Cannot solve this sudoku!" << std::endl;
	} 
	for (int i = 0; i < baseSquare.size(); i++) {
		for (int j = 0; j < baseSquare[i].size(); j++)
			std::cout << baseSquare[i][j];
		std::cout << std::endl;
	}
}