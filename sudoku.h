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
	int seed;
	int** matrix;
	int** solutionMatrix;
	void shuffleSubMatCols();
	void getSolution(int** matrix);
	bool solve(int** matrix);
	bool getBoard();
	void shuffleSubMatRows();
	void shuffleRows();
	void shuffleCols();
	void fill(string difficulty);
	void printSudoku();
	bool isValid(int** matrix, int num, int rows, int cols);
	pair<int, int> findempty(int** matrix);

	sudoku(int rows, int columns, string difficulty);

};