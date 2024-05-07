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
    swapRows(i, blockNumber * 3 + (ranNum - 1));
  }
}

void sudoku::swapRows(int r1, int r2) {
  int rowVal;
  for (int i = 0; i < 9; i++) {
    rowVal = matrix[r1][i];
    matrix[r1][i] = matrix[r2][i];
    matrix[r2][i] = rowVal;
  }
}

void sudoku::shuffleCols() {
  int blockNumber;

  for (int i = 0; i < 9; i++) {
    int ranNum = randomGenerator(3);
    blockNumber = i / 3;
    swapCols(i, blockNumber * 3 + (ranNum - 1));
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
    swapSubMatRows(i, (ranNum - 1));
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
    swapSubMatCols(i, (ranNum-1));
  }
}
void sudoku::swapSubMatCols(int c1, int c2) {
  for (int i = 0; i < 3; i++) {
    swapCols(c1 * 3 + i, c2 * 3 + i);
  }
}

void sudoku::removeElement(string Difficulty){
  int randX;
  int randY;
  int amtToRemove;
  if(Difficulty == "easy"){
    amtToRemove = randomGenerator(8);
  } else if(Difficulty == "medium"){
    amtToRemove = randomGenerator(14);
  } else {
    amtToRemove = randomGenerator(20);
  }
  for(int i = 0; i < amtToRemove; i++){
    randX = randomGenerator(9-1);
    randY = randomGenerator(9-1);
    matrix[randX][randY] = 0;
  }
}

void sudoku::fill(string difficulty) {
  shuffleCols();
  shuffleRows();
  shuffleSubMatRows();
  shuffleSubMatCols();
  removeElement(difficulty);
}

void sudoku::printSudoku() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}