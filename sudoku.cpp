#include "sudoku.h"
#include <iostream>
#include <random>
#include <fstream>
#include <iostream>

using namespace std;


sudoku::sudoku(int rows, int columns, string difficulty) {
    r = rows;
    c = columns;
    matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }
    int numbers1[] = { 3, 4, 5, 9, 2, 6, 7, 8, 1, 8, 9, 1, 4, 7, 3, 5, 2,
                      6, 7, 2, 6, 8, 5, 1, 4, 3, 9, 2, 5, 4, 1, 9, 7, 8,
                      6, 3, 9, 1, 3, 5, 6, 8, 2, 4, 7, 6, 8, 7, 3, 4, 2,
                      1, 9, 5, 4, 7, 9, 6, 8, 5, 3, 1, 2, 1, 6, 2, 7, 3,
                      4, 9, 5, 8, 5, 3, 8, 2, 1, 9, 6, 7, 4 };
    int count = 0;
    int numbers2[] = { 6, 1, 3, 8, 2, 7, 5, 4, 9, 2, 5, 7, 6, 4, 9, 8, 3,
                      1, 9, 8, 4, 5, 3, 1, 6, 7, 2, 1, 9, 6, 7, 5, 3, 2,
                      8, 4, 8, 3, 2, 4, 9, 6, 1, 5, 7, 7, 4, 5, 2, 1, 8,
                      3, 9, 6, 3, 7, 8, 9, 6, 2, 4, 1, 5, 4, 2, 9, 1, 8,
                      5, 7, 6, 3, 5, 6, 1, 3, 7, 4, 9, 2, 8 };
    int numbers3[] = { 7, 9, 5, 2, 6, 1, 4, 8, 3, 4, 2, 6, 8, 7, 3, 5, 1,
                      9, 8, 1, 3, 4, 5, 9, 2, 6, 7, 5, 7, 2, 1, 9, 8, 6,
                      3, 4, 9, 3, 8, 6, 4, 5, 7, 2, 1, 6, 4, 1, 3, 2, 7,
                      9, 5, 8, 3, 5, 9, 7, 1, 6, 8, 4, 2, 1, 6, 4, 9, 8,
                      2, 3, 7, 5, 2, 8, 7, 5, 3, 4, 1, 9, 6 };

    int randSeed = randomGenerator(3);
    if (randSeed == 1) {
        count = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                matrix[i][j] = numbers1[count];
                count++;
            }
        }
    }
    else if (randSeed == 2) {
        count = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                matrix[i][j] = numbers2[count];
                count++;
            }
        }
    }
    else {
        count = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                matrix[i][j] = numbers3[count];
                count++;
            }
        }
    }
    fill(difficulty);
}

int sudoku::randomGenerator(int num) {
    random_device rd;

    mt19937 gen(rd());

    uniform_int_distribution<int> dis(1, num);

    int random_number = dis(gen);

    return random_number;
}

bool sudoku::getBoard() {
    ofstream outfile("outfile.csv");
    if (!outfile.is_open()) {
        cerr << "Failed to open file for writing.\n";
        return false;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            outfile << matrix[i][j] << endl;
        }
    }
    outfile.close();
    return true;
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
        swapSubMatCols(i, (ranNum - 1));
    }
}
void sudoku::swapSubMatCols(int c1, int c2) {
    for (int i = 0; i < 3; i++) {
        swapCols(c1 * 3 + i, c2 * 3 + i);
    }
}

void sudoku::removeElement(string Difficulty) {
    int randX;
    int randY;
    int amtToRemove;
    if (Difficulty == "easy") {
        amtToRemove = randomGenerator(21);
    }
    else if (Difficulty == "medium") {
        amtToRemove = randomGenerator(42);
    }
    else {
        amtToRemove = randomGenerator(61);
    }
    for (int i = 0; i < amtToRemove; i++) {
        randX = randomGenerator(9 - 1);
        randY = randomGenerator(9 - 1);
        matrix[randX][randY] = 0;
    }
}

void sudoku::fill(string difficulty) {
    shuffleCols();
    shuffleRows();
    shuffleSubMatRows();
    shuffleSubMatCols();
    removeElement(difficulty);
    getBoard();
}

void sudoku::printSudoku() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}