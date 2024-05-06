#include <bits/stdc++.h>
using namespace std;

class sudoku
{
public:
    int r;
    int c;
    int **matrix;

    sudoku(int rows, int columns)
    {
        r = rows;
        c = columns;
        matrix = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[columns];
        }
    }

    int randomGenerator(int num)
    {
        return (int)floor(
            (float)(rand() / double(RAND_MAX) * num + 1));
    }

    bool rowValidator(int x, int y, int num)
    {
        for (int i = 0; i < 9; i++)
        {
            if (i == y)
            {
                continue;
            }
            else if (matrix[x][i] == num)
            {
                return false;
            }
        }
        return true;
    }

    bool colValidator(int x, int y, int num)
    {
        for (int i = 0; i < 9; i++)
        {
            if (i == x)
            {
                continue;
            }
            else if (matrix[i][y] == num)
            {
                return false;
            }
        }
        return true;
    }

    bool matrixValidater(int x, int y, int num)
    {
        int minMatrixX = x / 3;
        int minMatrixY = y / 3;
        int startingChordX = minMatrixX * 3;
        int startingChordY = minMatrixY * 3;

        for (int i = startingChordX; i < startingChordX + 3; i++)
        {
            for (int j = startingChordY; j < startingChordY + 3; j++)
            {
                if (i == x && j == y)
                {
                    continue;
                }
                else if (matrix[i][j] == num)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void fill()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                bool defined = false;
                while (!defined)
                {
                    int rand = randomGenerator(9);
                    if (matrixValidater(i, j, rand) && rowValidator(i, j, rand) && colValidator(i, j, rand))
                    {
                        defined = true;
                        matrix[i][j] = rand;
                    }
                }
            }
        }
    }

    void printSudoku()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int rows = 9;
    int columns = 9;
    sudoku *Sudoku = new sudoku(rows, columns);
    Sudoku->fill();
    Sudoku->printSudoku();
    return 0;
}