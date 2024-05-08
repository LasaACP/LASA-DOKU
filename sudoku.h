#pragma once
#include <iostream>
#include <random>

using namespace std;

class sudoku {
private:
	int randomGenerator(int num);
	void swapRows(int r1, int r2);
	void swapCols(int c1, int c2);
	void swapSubMatRows(int r1, int r2);
	void swapSubMatCols(int c1, int c2);
	void removeElement(string difficulty);

public:
	int r;
	int c;
	int** matrix;
	int** solutionMatrix;
	void shuffleSubMatCols();
	void getSolution();
	bool getBoard();
	void shuffleSubMatRows();
	void shuffleRows();
	void shuffleCols();
	void fill(string difficulty);
	void printSudoku();

	sudoku(int rows, int columns, string difficulty);

};
