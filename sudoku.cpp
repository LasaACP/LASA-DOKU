#include "sudoku.h"
#include <iostream>
#include <random>
#include <fstream>
#include <iostream>

using namespace std;


// Method allows the user to see the solution to the sudoku board
void sudoku::getSolution() {

    // Copy the original board into the solution matrix to print
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            solutionMatrix[i][j] = matrix[i][j];
        }
    }
    ofstream outfile("solution.csv");
    
    // Make sure the file is open, show error if it isn't
    if (!outfile.is_open()) {
        cerr << "Failed to open file for writing.\n";
    }

    // Print the solution to user
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            outfile << solutionMatrix[i][j] << endl;
        }
    }
    outfile.close();
}


// Constructor for the sudoku board
sudoku::sudoku(int rows, int columns, string difficulty) {
    r = rows;
    c = columns;

    // Initialize the solution matrix so that it is the correct size for later
    solutionMatrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        solutionMatrix[i] = new int[columns];
    }
    matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }

    // numbers1, numbers2, and numbers3 are pre-set, solved sudoku boards
    // These will be randomly shuffled to create unique boards for the user
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

    // Pick the solved game to be used
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

    // Fill the board, includes shuffles 
    fill(difficulty);
}


// Randomly generates a number from 1-num
int sudoku::randomGenerator(int num) {
    random_device rd;

    mt19937 gen(rd());

    // Ensures that there is an even amount of each number, and not pre-set values/order
    uniform_int_distribution<int> dis(1, num);

    int random_number = dis(gen);

    return random_number;
}


// Prints the board for the user, similar to solution method but with the parts removed from the sudoku board
bool sudoku::getBoard() {
    ofstream outfile("outfile.csv");

    // Ensure no errors have occurred
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

    // Returns true if the board was successfully displayed
    return true;
}


// Overall method that shuffles the rows of the solved board
void sudoku::shuffleRows() {

    // Represents one of the 3x3 squares that make up the larger board
    int blockNumber;

    for (int i = 0; i < 9; i++) {
        int ranNum = randomGenerator(3);
        blockNumber = i / 3;

        // Calls helper function to swap the random rows
        swapRows(i, blockNumber * 3 + (ranNum - 1));
    }
}


// Helper function for suffleRows()
// Swaps the rows provided in the parameter in matrix 
void sudoku::swapRows(int r1, int r2) {
    int rowVal;
    for (int i = 0; i < 9; i++) {
        rowVal = matrix[r1][i];
        matrix[r1][i] = matrix[r2][i];
        matrix[r2][i] = rowVal;
    }
}


// Same as the shuffleRows() method, but for the columns
void sudoku::shuffleCols() {
    int blockNumber;

    for (int i = 0; i < 9; i++) {
        int ranNum = randomGenerator(3);
        blockNumber = i / 3;
        swapCols(i, blockNumber * 3 + (ranNum - 1));
    }
}


// Same helper method
void sudoku::swapCols(int c1, int c2) {
    int colVal;
    for (int i = 0; i < 9; i++) {
        colVal = matrix[i][c1];
        matrix[i][c1] = matrix[i][c2];
        matrix[i][c2] = colVal;
    }
}


// Shuffles one of the 3x3 square rows
void sudoku::shuffleSubMatRows() {

    for (int i = 0; i < 3; i++) {
        int ranNum = randomGenerator(3);

        // Calls helper function to swap rows
        swapSubMatRows(i, (ranNum - 1));
    }
}


// Helper method that calls another helper method to swap the rows specified
void sudoku::swapSubMatRows(int r1, int r2) {
    for (int i = 0; i < 3; i++) {

        // Actually swaps the rows
        swapRows(r1 * 3 + i, r2 * 3 + i);
    }
}


// Same as shuffleSubMatRows()
void sudoku::shuffleSubMatCols() {

    for (int i = 0; i < 3; i++) {
        int ranNum = randomGenerator(3);
        swapSubMatCols(i, (ranNum - 1));
    }
}

// Same as swapSubMatRows()
void sudoku::swapSubMatCols(int c1, int c2) {
    for (int i = 0; i < 3; i++) {
        swapCols(c1 * 3 + i, c2 * 3 + i);
    }
}


// Uses the difficulty provided when the object was created and removes some elements from the board
// "easy" removes the fewest elements, "medium" a middle amount, and anything else removes the most
void sudoku::removeElement(string Difficulty) {
    int randX;
    int randY;
    int amtToRemove;

    //Determines the exact amount of elements to remove
    if (Difficulty == "easy") {
        amtToRemove = randomGenerator(21);
    }
    else if (Difficulty == "medium") {
        amtToRemove = randomGenerator(42);
    }
    else {
        amtToRemove = randomGenerator(61);
    }

    // Picks the elements of the board to be removed and replaces them with 0's
    for (int i = 0; i < amtToRemove; i++) {
        randX = randomGenerator(9)-1;
        randY = randomGenerator(9)-1;
        matrix[randX][randY] = 0;
    }
}


// Fills the sudoku board, calls many helper functions
void sudoku::fill(string difficulty) {
    shuffleCols();
    shuffleRows();
    shuffleSubMatRows();
    shuffleSubMatCols();

    // Important to include getSolution() before removeElement() to retain solved matrix
    getSolution();
    removeElement(difficulty);
    getBoard();
}


// Print the sudoku board to the user if the code is run without html to display
void sudoku::printSudoku() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}