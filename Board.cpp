//
// Created by Adam Bechtold on 3/27/17.
//
#include <fstream>
#include <vector>
#include "Board.h"

using namespace std;

Board::Board(string fileName)
// constructor of the board
{

    ifstream fin;
    fin.open(fileName);

    if (!fin) {
        cout << "File access failure.\n";
    }

    this->mat = matrix<int>(9,9);

    char input;
    int number;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            fin >> noskipws >> input;
            if (input == '.') {
                number = 0;
            }
            else {
                number = input - '0';
            }
            this->mat[i][j] = number;
        }
    }

    fin.close();

    //TODO update conflicts
}

ostream &operator<<(ostream &ostr, const Board &b)
// overloads the << operator to print the contents of the board
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            ostr << b.mat[i][j] << " ";
        }
        ostr << endl;
    }
    return ostr;

    //TODO print conflicts
}

int Board::getCell(int row, int col) {
    return this->mat[row][col];
    //TODO update conflicts
}

void Board::setCell(int row, int col, int value) {
    this->mat[row][col] = value;
    //TODO update conflicts
}

void Board::clearCell(int row, int col, int value) {
    this->mat[row][col] = 0;
    //TODO update conflicts
}
