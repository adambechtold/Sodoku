//
// This is the implementation file for the Cell Class
// This file contains the definitions of the cell class, including:
//
// Default and overloaded constructors to initialize the cell
// A getValue function
// A setValue function
// Functions to update the different boolean conflict vectors
// Functions to add and remove values from the list of conflict values
// Functions to support printing of the cell's value
//

#include <iostream>
#include <iomanip>
#include "Cell.h"

const int Blank = -1;  // Indicates that a cell is blank
const int SquareSize = 3;  //  The number of cells in a small square
const int BoardSize = SquareSize * SquareSize; // Initializes the board size


using namespace std;

Cell::Cell(int value)
// overloaded constructor to specify the cell's value
{
    this->value = value;
    this->rowConflicts = vector<bool>(BoardSize);
    this->colConflicts = vector<bool>(BoardSize);
    this->conflictValues = vector<bool>(BoardSize);
    this->squareConflicts = vector<bool>(BoardSize);
}

Cell::Cell() : Cell(Blank) { }
// Default constructor for cell if no value is passed, initializes cell to be 0

int Cell::getValue() const
// Returns an cell's value, which is unable to be modified
{
    return this->value;
}

ostream &operator<<(ostream &ostr, const Cell &c)
// overloaded << operator, to print out the value of the cell
{
    ostr << c.getValue();
    return ostr;
}

void Cell::setValue(int value)
// Assigns cell's value to value passed in
{
    this->value = value;
}

void Cell::modRowConflict(int index, bool addBool)
// Modifies rowConflicts vector at specified index with either true or false
// Also adds or removes the value from the conflictValues vector
{
    this->rowConflicts[index] = addBool;
    this->conflictValues[index] = addBool;
}

void Cell::modColConflict(int index, bool addBool)
// Modifies colConflicts vector at specified index with either true or false
// Also adds or removes the value from the conflictValues vector
{
    this->colConflicts[index] = addBool;
    this->conflictValues[index] = addBool;
}

void Cell::modSquareConflict(int index, bool addBool)
// Modifies squareConflicts vector at specified index with either true or false
// Also adds or removes the value from the conflictValues vector
{
    this->squareConflicts[index] = addBool;
    this->conflictValues[index] = addBool;
}


void Cell::printCell()
// Prints out the cell's value and conflict vector
{
    if (this->value == Blank)
        cout << "|       |";

    else
        cout << "|   " << this->value << "   |";

    cout << "  ";

    for (int i = 0; i < this->conflictValues.size(); i++)
    {
        if (this->conflictValues[i])
            cout << i + 1 << "  ";
    }
}





