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
    cout << b1;
    cout << "\n=======BOARD 2========\n\n";
    cout << b2;
    cout << "\n=======BOARD 3========\n\n";
    cout << b3;

    return 0;
}