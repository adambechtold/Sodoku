//
// This is the implementation file for the Board Class
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
#include <iomanip>

using namespace std;

Board::Board(string fileName)
// constructor of the board
{

    ifstream fin;
    fin.open(fileName);

    if (!fin)
        cout << "File access failure.\n";

    this->mat = matrix<Cell>(9,9);

    // read characters from the file and input them into the board's matrix
    char input;
    int number;

    for (int i = 0; i < BoardSize; i++)
    {
        for (int j = 0; j < BoardSize; j++)
        {
            fin >> noskipws >> input;

            if (input == '.')
                number = Blank;

            else
                number = input - '0';

            this->mat[i][j] = Cell(number);
        }
    }

    fin.close();

    // initialize conflicts for the entire board
    updateAllConflicts();

    //set the solved field
    this->solved = isSolved();
    this->countRecursions = 0;
    this->countSolutions = 0;
}

Board::Board(char* buffer)
// create a board from a vector of characters
{
    char input;
    int number;
    this->mat = matrix<Cell>(9,9);

    for (int i = 0; i < BoardSize; i++)
    {
        for (int j = 0; j < BoardSize; j++)
        {
            input = buffer[i*BoardSize + j];

            if (input == '.')
                number = Blank;

            else
                number = input - '0';

            this->mat[i][j] = Cell(number);
        }
    }

    // initialize conflicts for the entire board
    updateAllConflicts();

    //set the solved field
    this->solved = isSolved();
    this->countRecursions = 0;
    this->countSolutions = 0;
}

Cell Board::getCell(int i, int j) const
// return the cell object at the given coordinates
{
    return this->mat[i][j];
}

int Board::getCellValue(int i, int j) const
// return the value of the cell at the given coordinates
{
    return this->getCell(i, j).getValue();
}

int Board::getRecursiveCalls() const
// return the number of recursive calls used to solve this board
{
    return this->countRecursions;
}

void Board::updateConflict(int i, int j)
// updates the conflicts at a given index in all directions and the same square
{
    int startRow = (i/SquareSize) * SquareSize;
    int startCol = (j/SquareSize) * SquareSize;

    int spotVal = Blank;

    for (int a = 0; a < BoardSize; a++)
    {
        //Moving through the row
        spotVal = this->getCellValue(i, a);

        if (spotVal != Blank)
            this->mat[i][j].modRowConflict(spotVal - 1, true);


        //moving through the column
        spotVal = this->getCellValue(a, j);

        if (spotVal != Blank)
            this->mat[i][j].modColConflict(spotVal - 1, true);

        //move through the given square
        int row = a / SquareSize + startRow;
        int col = a % SquareSize + startCol;
        spotVal = this->getCellValue(row, col);

        if (spotVal != Blank)
            this->mat[i][j].modSquareConflict(spotVal - 1, true);
    } //end of for loop
}

void Board::updateAllConflicts()
// updates conflicts for the entire board
{
    for (int i = 0; i < BoardSize; i++)
    {
        for (int j = 0; j < BoardSize; j++)
            this->updateConflict(i,j);
    }
}

void Board::modCell(int i, int j, int value)
// Modifies a cell with either a new value or blank, and updates all the
// relevant conflicts
{
    bool add;
    int modIndex;
    int startRow = (i/SquareSize) * SquareSize;
    int startCol = (j/SquareSize) * SquareSize;

    // if the cell is to be set to blank, use it's current value to find the
    //   indices to be modified and set it's value to blank
    if(value == Blank)
    {
       add = false;
       modIndex = this->mat[i][j].getValue() - 1;
       this->mat[i][j].setValue(Blank);
    }

    // if the cells is to be set to a legal value, set it's value to the given
    //   value parameter and use that parameter to find the indices to be
    //   modified
    else if(value > 0 && value < 10)
    {
        add = true;
        this->mat[i][j].setValue(value);
        modIndex = value - 1;
    }

    //update the conflict vectors for the cell at index i, j
    this->mat[i][j].modRowConflict(modIndex, add);
    this->mat[i][j].modColConflict(modIndex, add);
    this->mat[i][j].modSquareConflict(modIndex, add);

    //update conflicts in the same row, columns, and square as cell i,j
    for(int a = 0; a < BoardSize; a++)
    {
        this->mat[i][a].modRowConflict(modIndex, add);
        this->mat[a][j].modColConflict(modIndex, add);
        int row = a / SquareSize + startRow;
        int col = a % SquareSize + startCol;
        this->mat[row][col].modSquareConflict(modIndex, add);
    }
}

bool Board::isBlank(int i, int j)
// Returns true if cell i,j is blank, and false otherwise.
{
    if (i < 0 || i >= BoardSize || j < 0 || j >= BoardSize)
        throw rangeError("bad value in setCell");

    return (getCellValue(i, j) == Blank);
}

bool Board::isLegal(int i, int j, int s)
// can the given digit, s, be assigned to the cell at row, i, and col, j
{
    return this->mat[i][j].checkValue(s) && (s > 0) && (s <= BoardSize);
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

void Board::mostConstrained(int &row, int &column)
// Finds the cell in the board with the fewest possible value
// modifies passed row and column values
{
    int numconflicts = 0;

    for (int i = 0; i < BoardSize; i++)
    {
        for (int j = 0; j < BoardSize; j++)
        {
            if (this->mat[i][j].numConstraints() >= numconflicts
                && this->mat[i][j].getValue() == Blank)
            {
                numconflicts = this->mat[i][j].numConstraints();
                row = i;
                column = j;
            }
        }
    }
    return;
}

void Board::solve()
// solve the board using a recursive backtracking algorithm
{
    if (isSolved())
    {
        this->solved = true;
        this->countSolutions++;
    }

    else
    {
        int row, col;
        mostConstrained(row, col);

        for (int i = 1; i <= BoardSize; i++)
        {
            if (isLegal(row, col, i))
            {
                modCell(row, col, i);
                this->countRecursions++;
                solve();
                if(!this->solved)
                    modCell(row, col, Blank);
            }
        }
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
                cout << " " << getCellValue(i, j) << " ";

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
// Prints out a formatted table of each cell's location, value, and conflict
//  values
{
    cout << setw(7) << "Cell";
    cout << setw(11) << "Value";
    cout << setw(20) << "Conflict Values\n";

    for (int i = 0; i < BoardSize; i++)
    {
        for (int j = 0; j < BoardSize; j++)
        {
            cout << "   " << "(" << i << "," << j << ")   ";
            this->mat[i][j].printCell();
            cout << endl;
        }
    }
}

ostream &operator<<(ostream &ostr, const Board &b)
// overloads the << operator to print the contents of the board
{
    for (int i = 0; i < BoardSize; i++)
    {
        for (int j = 0; j < BoardSize; j++)
            ostr << b.getCellValue(i, j) << " ";

        ostr << endl;
    }
    return ostr;
}

