# LASA-DOKU
This program creates an HTML webpage that allows users to easily play on randomly generated sudoku boards. The program has 3 pre-set boards. To ensure that the board is distinct each time and always solvable, the board undergoes a random amount of transformations onto the one of the three pre-set boards.

### Description of functions
Available Buttons:
- Generate Sudoku
- Solve Board
- Check Answer

The "Generate Sudoku" function creates the random sudoku board by using our C++ algothrithm that calls many helper functions to randomly shuffle a pre-solved board.
The "Solve Board" button calls another function to solve the sudoku puzzle, then displays the results to the user.
Finally, the user can check their answers with the "Check Answers" button, and the code checks if the numbers inputted are a valid solution to the given sudoku board.

Additional Features:
- “Click to Fill”
- Color Coding for Unfilled v. Filled Cells
- Player Notes
- Adjustable Notes Box

The user is able to submit their answers to the game by clicking on the cell they would like to change. A user will know which cells that still must be completed based on the color of the cell. Additionally, there is functionality for player's store notes in andustable-size text area.

### Imported Libraries

The imported libraries for the c++ code, from ```sudoku.cpp```, are shown below. The ```#include <random>``` is important for our code to be able to generate the random numbers that are used for the transformations of the board. Queues were used to create the solve method, so ```#include <queue>``` was necessary. the other 2 included libraries are for reading and writing to files. 

```
#include <iostream>
#include <random>
#include <fstream>
#include <queue>
```
The imported libraries for the python code, from ```server.py```, are shown below. Flask was the tool that was used to allow the c++ code to work with html to create the website. ```import subprocess``` allows the python code to run the required functions from the c++ files.
```
from flask import Flask, render_template, send_file
import subprocess
```

## Structure
 The files are shown below. The ```sudoku.cpp``` and ```sudoku.h``` files are where the main part of the c++ coding takes place, and ```sudokuMain.cpp``` can be used to test the code. ```server.py``` is what allows the c++ code to communicate to the html webpage once the user runs the program. ```sudokuUI.html``` is where the majority of the html code is done, and it creates the UI for the user on the website. It is important to keep the templates folder on the same directory level as the single files named above to ensure everything is within the scope.
```
├── templates
    └──sudokuUI.html
├── x64\Debug
├── outfile.csv
├── server.py
├── solution.csv
├── sudoku.cpp
├── sudoku.h
├── sudokuAlgorithm.exe
├── sudokuAlgorithm.vcxproj
├── sudokuAlgorithm.vcxproj.filters
├── sudokuAlgorithm.vcxproj.user
└── sudokuMain.cpp
```
The directory tree can be generated by the linux **tree** command. You may need to add this to the REPL NIX environment (install tree.out).


## Authors

Yang-fan Chau, William Gu, Jacob Mathew, Lalsin Nilian & Liam Teltow

## License

This project is licensed under the MIT License

