//
// Created by Adam Bechtold on 3/27/17.
//

#include "d_matrix.h"
#include <cstdlib>

using namespace std;

#ifndef SODOKU_BOARD_H
#define SODOKU_BOARD_H


class Board {
public:
    Board(string fileName);

    //overloaded
    friend ostream& operator<< (ostream& ostr, const Board& b);

    int getCell(int row, int col);

    void setCell(int row, int col, int value);

    void clearCell(int row, int col, int value);

private:
    matrix<int> mat;
};


#endif //SODOKU_BOARD_H
