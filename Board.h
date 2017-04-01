//
// This is the header file for the Board Class
// This file contains the declarations of the board class, including:
//
// Functions to view the contents of each matrix index
// A function which update the conflicts of the entire board
// A function to update conflicts related to a specific index
// Functions to set and clear specific index values
// Functions to support printing the matrix as well as all cell conflicts
// Functions to determine if the board is solved


#include "d_matrix.h"
#include <cstdlib>
#include "Cell.h"


typedef int ValueType; // The type of the value in a cell
const int Blank = -1;  // Indicates that a cell is blank

const int SquareSize = 3;  //  The number of cells in a small square
//  (usually 3).  The board has
//  SquareSize^2 rows and SquareSize^2
//  columns.

const int BoardSize = SquareSize * SquareSize;

const int MinValue = 0;
const int MaxValue = 8;

using namespace std;

#ifndef SODOKU_BOARD_H
#define SODOKU_BOARD_H


class Board {
public:
    Board(string fileName);
    Board(char *buffer);

    //constant functions to look into the values of cells
    Cell seeCell(int i, int j) const;
    int seeCellValue(int i, int j) const;

    //conflict update functions
    void updateConflict(int i, int j);
    void updateAllConflicts();

    //set and clear functions
    void modCell(int i, int j, int value);

    //printing functions
    friend ostream& operator<< (ostream& ostr, const Board& b);
    void print();
    void printConflicts();

    bool isSolved();
    bool isBlank(int i, int j);
    bool isLegal(int i, int j, int s);
    int squareNumber(int i, int j);

    void mostConstrained(int& row, int& column);

    void solve();

private:
    matrix<Cell> mat;
    bool solved;
    int countRecursions;
};


#endif //SODOKU_BOARD_H
