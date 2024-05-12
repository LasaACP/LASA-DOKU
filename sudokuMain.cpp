#include <iostream>
#include <random>
#include "sudoku.h"

using namespace std;

int main() {
	// Rows and columns for the sudoku board
	int rows = 9;
	int columns = 9;

	// Takes the parameters: int rows, int columns, string difficulty
	// Since difficulty isn't "easy" or "medium" it defaults to hard
	sudoku* Sudoku = new sudoku(rows, columns, "sdfgerg");
	// Sudoku->printSudoku(); --> Can print the sudoku board if it is run without html
	return 0;
}