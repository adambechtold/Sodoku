#include <iostream>
#include "Board.h"
#include <fstream>

using namespace std;

void solveBoard(string fileName);

int main()
{

    //Instructions for main.cpp 4a:
    // Read each Sudoku board form the file one by one
    // print the board and conflicts to the screen
    // check to see if the board has been solved

    solveBoard("Sudoku1-3.txt");
    solveBoard("Sudoku.txt");

    return 0;
}

void solveBoard(string fileName)
// create boards for each one stored
{
    ifstream fin;
    fin.open(fileName);

    if (!fin)
        cout << "File access failure.\n";


    char buffer[BoardSize * BoardSize];
    char nextCheck = '\n';
    int numBoards = 0;
    int recursiveCalls = 0;

    while(nextCheck == '\n') {
        fin.read(buffer, sizeof(buffer));
        Board b = Board(buffer);
        b.solve();
        recursiveCalls += b.getRecursiveCalls();
        numBoards++;
        fin >> noskipws >> nextCheck;
    }

    int averageCalls = recursiveCalls / numBoards;

    cout << "Solving " << numBoards << " boards required  an average of ";
    cout << averageCalls;
    cout << " recursive calls.\n\n";

}