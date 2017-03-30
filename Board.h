//
// Created by Adam Bechtold on 3/27/17.
//

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

//int numSolutions = 0;

using namespace std;

#ifndef SODOKU_BOARD_H
#define SODOKU_BOARD_H


class Board {
public:
    Board(string fileName);

    //overloaded << operator
    friend ostream& operator<< (ostream& ostr, const Board& b);

    Cell seeCell(int i, int j) const;

    int seeCellValue(int i, int j) const;

    Cell getCell(int i, int j);

    void updateConflict(int i, int j);

    void updateAllConflicts();

    void setCell(int i, int j, int value);

    void clearCell(int i, int j, int value);

    void print();

    void printConflicts();

    bool isBlank(int i, int j);

    int squareNumber(int i, int j);
private:
    matrix<Cell> mat;
};


#endif //SODOKU_BOARD_H
