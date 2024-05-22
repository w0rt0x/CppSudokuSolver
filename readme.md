# Sokuko Solver in C++ with CMake
A solver for Sudoku riddles that offers a Graphical User Interface by using the Qt library in the future. Developed on and made for Linux. The main purpose of this project was to get more familiar with CMake and utilizing/incorporating external libraries like QT and GoogleTest. It uses the C++ 20 Standard.
BILD/Gif

# Setup
Clone this Repositiry and build it using CMake.
```
mkdir build
cd build
cmake ..
cmake --build .
```

# Sudoku Solver Algorithm
The Algorithm used for solving the Sudoku riddles has a recursive nature, details can be found [here](https://en.wikipedia.org/wiki/Sudoku_solving_algorithms).

# Tests
## Google Tests 
Fixed solavble and not solvable Sukdoku riddles will be used. If the Sudoku is solvable, the algorithm should tell so and vice versa. This will be checked by the external Google Test library.
Tests are put into a seperate executable, navigate to build/tests and rune the test executable.

## Using Valgrind to check for memory leaks
Install this tool with:
```
sudo apt install valgrind
```

Run it on the executable:
```
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./SudokuSolver
```

It will show 0 memory leaks:
```
==6506== HEAP SUMMARY:
==6506==     in use at exit: 0 bytes in 0 blocks
==6506==   total heap usage: 6,703 allocs, 6,703 frees, 350,224 bytes allocated
==6506== 
==6506== All heap blocks were freed -- no leaks are possible
==6506== 
==6506== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
