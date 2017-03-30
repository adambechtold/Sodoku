//
// Created by Adam Bechtold on 3/27/17.
//
#include <fstream>
#include <vector>
#include "Board.h"
#include "Cell.h"
#include <iomanip>

using namespace std;

Board::Board(string fileName)
// constructor of the board
{

    ifstream fin;
    fin.open(fileName);

    if (!fin) {
        cout << "File access failure.\n";
    }

    this->mat = matrix<Cell>(9,9);

    char input;
    int number;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            fin >> noskipws >> input;
            if (input == '.') {
                number = Blank;
            }
            else {
                number = input - '0';
            }
            this->mat[i][j] = Cell(number);
        }
    }

    fin.close();

    //TODO update conflicts
}

ostream &operator<<(ostream &ostr, const Board &b)
// overloads the << operator to print the contents of the board
{
    for (int i = 0; i < BoardSize; i++) {
        for (int j = 0; j < BoardSize; j++) {
            ostr << b.seeCellValue(i, j) << " ";
        }
        ostr << endl;
    }
    return ostr;

    //TODO print conflicts
}

Cell Board::seeCell(int i, int j) const
// return the cell object at the given coordinates
{
    return this->mat[i][j];
    //TODO update conflicts
}

int Board::seeCellValue(int i, int j) const
// return the value of the cell at the given coordinates
{
    return this->seeCell(i, j).getValue();
}

Cell Board::getCell(int i, int j)
// return the cell object at the given coordinates
{
    return this->mat[i][j];
    //TODO update conflicts
}


void Board::updateConflict(int i, int j) {
    int startRow = (i/SquareSize) * SquareSize;
    int startCol = (j/SquareSize) * SquareSize;

    int spotVal = Blank;
    for (int a = 0; a < BoardSize; a++) {

        //Moving through the row
        spotVal = this->seeCellValue(i,a);
        if (spotVal != Blank)
            this->mat[i][j].modRowConflict(spotVal - 1, true);


        //moving through the column
        spotVal = this->seeCellValue(a,j);
        if (spotVal != Blank)
            this->mat[i][j].modColConflict(spotVal - 1, true);

        //move through the given square
        int row = a / SquareSize + startRow;
        int col = a % SquareSize + startCol;
        spotVal = this->seeCellValue(row,col);
        if (spotVal != Blank)
            this->mat[i][j].modSquareConflict(spotVal - 1, true);
    }
}

void Board::updateAllConflicts() {
    for (int i = 0; i < BoardSize; i++) {
        for (int j = 0; j < BoardSize; j++) {
            this->updateConflict(i,j);
        }
    }
}


void Board::setCell(int i, int j, int value) {
    this->mat[i][j] = value;
    //TODO update conflicts
}

void Board::clearCell(int i, int j, int value) {
    this->mat[i][j] = 0;
    //TODO update conflicts
}

void Board::print()
// Prints the current board.
{
    for (int i = 0; i < BoardSize; i++)
    {
        if (i % SquareSize == 0)
        {
            cout << " -";
            for (int j = 0; j < BoardSize; j++)
                cout << "---";
            cout << "-";
            cout << endl;
        }
        for (int j = 0; j < BoardSize; j++)
        {
            if ((j) % SquareSize == 0)
                cout << "|";
            if (!isBlank(i,j))
                cout << " " << seeCellValue(i, j) << " ";
            else
                cout << "   ";
        }
        cout << "|";
        cout << endl;
    }

    cout << " -";
    for (int j = 1; j <= BoardSize; j++)
        cout << "---";
    cout << "-";
    cout << endl;
}

void Board::printConflicts() {
    cout <<
}



bool Board::isBlank(int i, int j)
// Returns true if cell i,j is blank, and false otherwise.
{
    if (i < 0 || i >= BoardSize || j < 0 || j >= BoardSize)
        throw rangeError("bad value in setCell");

    return (seeCellValue(i, j) == Blank);
}


int Board::squareNumber(int i, int j)
// Return the square number of cell i,j (counting from left to right,
// top to bottom.  Note that i and j each go from 1 to BoardSize
{
    // Note that (int) i/SquareSize and (int) j/SquareSize are the x-y
    // coordinates of the square that i,j is in.

    return SquareSize * ((i/SquareSize) + (j/SquareSize + 1));
}


