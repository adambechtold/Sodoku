//
// This is the implimentation file for the Board Class
// This file contains the definitions of the board class, including:
//
// Functions to view the contents of each matrix index
// A function which update the conflicts of the entire board
// A function to update conflicts related to a specific index
// Functions to set and clear specific index values
// Functions to support printing the matrix as well as all cell conflicts
// Functions to determine if the board is solved
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

    updateAllConflicts();
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
}

Cell Board::seeCell(int i, int j) const
// return the cell object at the given coordinates
{
    return this->mat[i][j];
}

int Board::seeCellValue(int i, int j) const
// return the value of the cell at the given coordinates
{
    return this->seeCell(i, j).getValue();
}


void Board::updateConflict(int i, int j)
{
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

void Board::updateAllConflicts()
{
    for (int i = 0; i < BoardSize; i++) {
        for (int j = 0; j < BoardSize; j++) {
            this->updateConflict(i,j);
        }
    }
}


/* //Attempt at merging setCell and clearCell
 *TODO: discuss this
 * void Board::setCell(int i, int j, int value)
{
    bool add;
    int startRow = (i/SquareSize) * SquareSize;
    int startCol = (j/SquareSize) * SquareSize;

    if(value == 0)
    {
       add = false;
       int value = this->mat[i][j].getValue();
       this->mat[i][j].setValue(Blank);
    }

    if(value > 0 || value < 10)
    {
        add = true;
        this->mat[i][j].setValue(value);
    }

    this->mat[i][j].modRowConflict(value, add);
    this->mat[i][j].modColConflict(value, add);
    this->mat[i][j].modSquareConflict(value, add);

    //update conflicts in the row, column, and square
    for(int a = 0; a < BoardSize; a++)
    {
        this->mat[i][a].modRowConflict(value - 1, add);
        this->mat[a][j].modRowConflict(value - 1, add);
        int row = a / SquareSize + startRow;
        int col = a % SquareSize + startCol;
        this->mat[row][col].modSquareConflict(value - 1, add);
    }
}

 */
// sets the value of a cell at the given coordinates and updates all affected conflict lists
// TODO: clearly, there is tons of overlap with the clearCell function
void Board::setCell(int i, int j, int value)
{
    this->mat[i][j].setValue(value);

    this->mat[i][j].modRowConflict(value, true);
    this->mat[i][j].modColConflict(value, true);
    this->mat[i][j].modSquareConflict(value, true);


    //update conflicts in the row, column, and sqaure
    int startRow = (i/SquareSize) * SquareSize;
    int startCol = (j/SquareSize) * SquareSize;
    for(int a = 0; a < BoardSize; a++) {
        this->mat[i][a].modRowConflict(value - 1, true);
        this->mat[a][j].modRowConflict(value - 1, true);
        int row = a / SquareSize + startRow;
        int col = a % SquareSize + startCol;
        this->mat[row][col].modSquareConflict(value - 1, true);
    }
}

void Board::clearCell(int i, int j)
{
    int value = this->mat[i][j].getValue();
    this->mat[i][j].setValue(Blank);

    this->mat[i][j].modRowConflict(value, false);
    this->mat[i][j].modColConflict(value, false);
    this->mat[i][j].modSquareConflict(value, false);

    //update conflicts in the row, column, and square
    int startRow = (i/SquareSize) * SquareSize;
    int startCol = (j/SquareSize) * SquareSize;
    for(int a = 0; a < BoardSize; a++) {
        this->mat[i][a].modRowConflict(value - 1, false);
        this->mat[a][j].modRowConflict(value - 1, false);
        int row = a / SquareSize + startRow;
        int col = a % SquareSize + startCol;
        this->mat[row][col].modSquareConflict(value - 1, false);
    }
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

void Board::printConflicts()
{
    cout << setw(7) << "Cell";
    cout << setw(11) << "Value";
    cout << setw(20) << "Conflict Values\n";

    for (int i = 0; i < BoardSize; i++) {
        for (int j = 0; j < BoardSize; j++) {
            cout << "   " << "(" << i << "," << j << ")   ";
            this->mat[i][j].printCell();
            cout << endl;
        }
    }
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

bool Board::isSolved()
// Returns true if entire board has values, and false otherwise
{
    for (int i = 0; i < BoardSize; i++)
    {
        for (int j = 0; j < BoardSize; j++)
        {
            if (isBlank(i,j))
                return false;
        }
    }
    return true;
}


