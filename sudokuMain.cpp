#include <iostream>
#include <random>
#include "sudoku.h"

using namespace std;

int main() {
	int rows = 9;
	int columns = 9;
	sudoku* Sudoku = new sudoku(rows, columns, "sdfgerg");
	//Sudoku->printSudoku();
	return 0;
}
