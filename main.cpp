#include <iostream>
#include "Board.h"
#include <fstream>

using namespace std;

void solveBoard(string fileName);
// main function controls which text files to be opened to solve
// All work is done in the solveBoard function below
int main()
{
    solveBoard("Sudoku1-3.txt");
    solveBoard("Sudoku.txt");

    return 0;
}

void solveBoard(string fileName)
// Goes through the text file and generates and solves each sudoku board
{
    //opens up text file from passed name
    ifstream fin;
    fin.open(fileName);

    if (!fin)
        cout << "File access failure.\n";

    //initializes variables needed to read multiple boards from one file
    char buffer[BoardSize * BoardSize];
    char nextCheck = '\n';
    int numBoards = 0;
    int recursiveCalls = 0;

    // Continually reads from the text files in chunks of 81 characters
    // Ends if there are no more bores
    while(nextCheck == '\n')
    {
        fin.read(buffer, sizeof(buffer));
        Board b = Board(buffer);
        b.print();
        b.solve();
        b.print();
        cout << "Solving this board took " << b.getRecursiveCalls();
        cout <<" recursive calls. \n";
        recursiveCalls += b.getRecursiveCalls();
        numBoards++;
        fin >> noskipws >> nextCheck;
    }
    //determines average number of calls by adding all recursive calls made
    // for the text file, and dividing by the number of boards solved
    int averageCalls = recursiveCalls / numBoards;

    //prints out some interesting info...
    cout << "Solving " << numBoards << " boards required an average of ";
    cout << averageCalls;
    cout << " recursive calls.\n";
    cout << "Total Recursive Calls:" << recursiveCalls << ". \n\n";

}