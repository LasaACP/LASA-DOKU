#include "iostream"
#include "random"
#include <bits/stdc++.h>

using namespace std;

class sudoku {
private:
  int randomGenerator(int num);
  void swapRows(int n1, int n2);
  void swapCols(int c1, int c2);
  void swapSubMatRows(int r1, int r2);
  void swapSubMatCols(int c1, int c2);

public:
  int r;
  int c;
  int **matrix;
  void shuffleSubMatCols();
  void shuffleSubMatRows();
  void shuffleRows();
  void shuffleCols();
  void fill(string difficulty);
  void printSudoku();

  sudoku(int rows, int columns, string difficulty) {
    r = rows;
    c = columns;
    matrix = new int *[rows];
    for (int i = 0; i < rows; i++) {
      matrix[i] = new int[columns];
    }
    int easyNumbers[] = {3, 4, 5, 9, 2, 6, 7, 8, 1, 8, 9, 1, 4, 7, 3, 5, 2,
                         6, 7, 2, 6, 8, 5, 1, 4, 3, 9, 2, 5, 4, 1, 9, 7, 8,
                         6, 3, 9, 1, 3, 5, 6, 8, 2, 4, 7, 6, 8, 7, 3, 4, 2,
                         1, 9, 5, 4, 7, 9, 6, 8, 5, 3, 1, 2, 1, 6, 2, 7, 3,
                         4, 9, 5, 8, 5, 3, 8, 2, 1, 9, 6, 7, 4};
    int count = 0;
    int mediumNumbers[] = {6, 1, 3, 8, 2, 7, 5, 4, 9, 2, 5, 7, 6, 4, 9, 8, 3,
                           1, 9, 8, 4, 5, 3, 1, 6, 7, 2, 1, 9, 6, 7, 5, 3, 2,
                           8, 4, 8, 3, 2, 4, 9, 6, 1, 5, 7, 7, 4, 5, 2, 1, 8,
                           3, 9, 6, 3, 7, 8, 9, 6, 2, 4, 1, 5, 4, 2, 9, 1, 8,
                           5, 7, 6, 3, 5, 6, 1, 3, 7, 4, 9, 2, 8};
    count = 0;
    int hardNumbers[] = {7, 9, 5, 2, 6, 1, 4, 8, 3, 4, 2, 6, 8, 7, 3, 5, 1,
                         9, 8, 1, 3, 4, 5, 9, 2, 6, 7, 5, 7, 2, 1, 9, 8, 6,
                         3, 4, 9, 3, 8, 6, 4, 5, 7, 2, 1, 6, 4, 1, 3, 2, 7,
                         9, 5, 8, 3, 5, 9, 7, 1, 6, 8, 4, 2, 1, 6, 4, 9, 8,
                         2, 3, 7, 5, 2, 8, 7, 5, 3, 4, 1, 9, 6};

    if (difficulty == "easy") {
      count = 0;
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          matrix[i][j] = easyNumbers[count];
          count++;
        }
      }
    } else if (difficulty == "medium") {
      count = 0;
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          matrix[i][j] = mediumNumbers[count];
          count++;
        }
      }
    } else {
      count = 0;
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          matrix[i][j] = hardNumbers[count];
          count++;
        }
      }
    }
    printSudoku();
    cout << endl;
    fill(difficulty);
  }
};