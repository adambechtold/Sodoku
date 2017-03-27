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

    string getItem(int row, int col);

    int Length();

private:
    matrix<int> mat;
};


#endif //SODOKU_BOARD_H
