#include <iostream>
#include "Board.h"

using namespace std;

int main()
{

    //Instructions for main.cpp 4a:
    // Read each Sudoku board form the file one by one
    // print the board and conflicts to the screen
    // check to see if the board has been solved

    Board b1 = Board("Sudoku1.txt");
    b1.print();
    int row, column;
    b1.mostConstrained(row, column);
    cout << "(" << row << ", " << column << ")";
    //===========TEST ZONE==========
    /*
     * Board b1 = Board("Sudoku1.txt");
    Board b2 = Board("Sudoku2.txt");
    Board b3 = Board("Sudoku3.txt");

    cout << "\n\n";
    cout << "=====================WELCOME WELCOME WELCOME=====================";
    cout << endl << "Check out these lit Sudoku boards we got goin' on!!!\n\n";


    cout << "\n ===========BOARD 1============\n\n";
    b1.print();
    cout << "Press ENTER to see the conflicts";
    cin.ignore();
    cout << "Conflicts: \n\n";
    b1.printConflicts();

    cout << "\n\nLet's try adding a value to this board.\n";
    cout << "Press ENTER to add value \"9\" to cell (7,7).\n";
    cin.ignore();

    b1.modCell(7,7,9);

    cout << "here is the new board: \n";
    b1.print();
    cout << "press ENTER to see the conflicts";
    cin.ignore();
    cout << "Conflicts: \n\n";
    b1.printConflicts();

    cout << "\n\nLet's try removing a value to this board.\n";
    cout << "Press ENTER get rid of the \"9\".\n";
    cin.ignore();

    b1.modCell(7,7, Blank);

    cout << "Here is the new board: \n";
    b1.print();
    cout << "\npress ENTER to see the conflicts";
    cin.ignore();
    cout << "\nConflicts: \n\n";
    b1.printConflicts();

    cout << "\n\nThat was FUN!!!\n";
    cout << "press ENTER to see the rest of the boards with their conflicts.";
    cin.ignore();

    cout << "\n ===========BOARD 2============\n\n";
    b2.print();
    b2.printConflicts();
    cout << "\n ===========BOARD 3============\n\n";
    b3.print();
    b3.printConflicts();
*/
    return 0;
}