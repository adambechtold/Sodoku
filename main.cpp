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
    b1.printConflicts();

    int input;
    string inputStr;
    cout << "\"s\" for set. \"c\" for clear: ";
    cin >> inputStr;

    cout << "Row: ";
    cin >> input;
    int row = input;
    cout << "Col: ";
    cin >> input;
    int col = input;

    if(inputStr == "s"){
        cout << "Value: ";
        cin >> input;
        int value = input;
        b1.setCell(row, col,value);
    }

    else
        b1.clearCell(row,col);

    b1.print();
    b1.printConflicts();

    cout << "Press enter to see the rest of the board.";
    cin >> inputStr;

    cout << "\n=======BOARD 2========\n\n";
    b2.print();
    cout << "\n=======BOARD 3========\n\n";
    b3.print();

    return 0;
}