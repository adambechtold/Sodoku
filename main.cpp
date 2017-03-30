#include <iostream>
#include "Board.h"

using namespace std;

int main() {

    //Instructions for main.cpp 4a:
    // Read each Sudoku baord form the file one by one
    // print the board and conflicts to the screen
    // check to see if the board has been solved


    //===========TEST ZONE==========
    Board b1 = Board("Soduku1.txt");
    Board b2 = Board("Soduku2.txt");
    Board b3 = Board("Soduku3.txt");

    cout << "\n=======BOARD 1========\n\n";
    b1.print();
    b1.updateAllConflicts();
    cout << "\n=======BOARD 2========\n\n";
    b2.print();
    cout << "\n=======BOARD 3========\n\n";
    b3.print();

    return 0;
}