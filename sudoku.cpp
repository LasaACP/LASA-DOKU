#include "sudoku.h"
#include "iostream"
#include "random"
#include <bits/stdc++.h>

using namespace std;

int sudoku::randomGenerator(int num) {
  random_device rd;

  mt19937 gen(rd());

  uniform_int_distribution<int> dis(1, num);

  int random_number = dis(gen);

  return random_number;
}

void sudoku::shuffleRows() {
  int blockNumber;

  for (int i = 0; i < 9; i++) {
    int ranNum = randomGenerator(3);
    blockNumber = i / 3;
    swapRows(i, blockNumber * 3 + ranNum);
  }
}

void sudoku::swapRows(int r1, int r2) {
  int row[9];
  for (int i = 0; i < 9; i++) {
    row[i] = matrix[r1][i];
  }
  matrix[r1] = matrix[r2];
  matrix[r2] = row;
}

void sudoku::shuffleCols() {
  int blockNumber;

  for (int i = 0; i < 9; i++) {
    int ranNum = randomGenerator(3);
    blockNumber = i / 3;
    swapCols(i, blockNumber * 3 + ranNum);
  }
}
void sudoku::swapCols(int c1, int c2) {
  int colVal;
  for (int i = 0; i < 9; i++) {
    colVal = matrix[i][c1];
    matrix[i][c1] = matrix[i][c2];
    matrix[i][c2] = colVal;
  }
}

void sudoku::shuffleSubMatRows() {

  for (int i = 0; i < 3; i++) {
    int ranNum = randomGenerator(3);
    swapSubMatRows(i, ranNum);
  }
}

void sudoku::swapSubMatRows(int r1, int r2) {
  for (int i = 0; i < 3; i++) {
    swapRows(r1 * 3 + i, r2 * 3 + i);
  }
}

void sudoku::shuffleSubMatCols() {

  for (int i = 0; i < 3; i++) {
    int ranNum = randomGenerator(3);
    swapSubMatCols(i, ranNum);
  }
}
void sudoku::swapSubMatCols(int c1, int c2) {
  for (int i = 0; i < 3; i++) {
    swapCols(c1 * 3 + i, c2 * 3 + i);
  }
}

void sudoku::fill(string difficuty) {
  shuffleCols();
  // shuffleRows();
  // shuffleSubMatRows();
  // shuffleSubMatCols();
}

void sudoku::printSudoku() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}