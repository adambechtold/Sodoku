//
// This is the implimentation file for the Cell Class
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
const int BoardSize = SquareSize * SquareSize; // Tnitializes the board size


using namespace std;

Cell::Cell(int value)
// overloaded constructor to specify the cell's value
{
    this->value = value;
    this->rowConflicts = vector<bool>(BoardSize);
    this->colConflicts = vector<bool>(BoardSize);
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

void Cell::setRowConflict(vector<bool> conflict)
{
    this->rowConflicts = conflict;
}

void Cell::setColConflict(vector<bool> conflict)
{
    this->colConflicts = conflict;
}

void Cell::setSquareConflict(vector<bool> conflict)
{
    this->squareConflicts = conflict;
}

void Cell::modRowConflict(int index, bool val)
// Modifies rowConflicts vector at specified index with either true or false
// Also adds or removes the value from the conflictValues vector
{
    this->rowConflicts[index] = val;
    if(val)
        this->addConflictValue(index+1);
    else
        this->removeConflictValue(index+1);
}

void Cell::modColConflict(int index, bool val)
// Modifies colConflicts vector at specified index with either true or false
// Also adds or removes the value from the conflictValues vector

{
    this->colConflicts[index] = val;
    if(val)
        this->addConflictValue(index+1);
    else
        this->removeConflictValue(index+1);
}

void Cell::modSquareConflict(int index, bool val)
// Modifies squareConflicts vector at specified index with either true or false
// Also adds or removes the value from the conflictValues vector

{
    this->squareConflicts[index] = val;
    if(val)
        this->addConflictValue(index+1);
    else
        this->removeConflictValue(index+1);
}

void Cell::addConflictValue(int val)
// Takes in a value to be added to the conflictValues vector, and inserts it
{

    for (int i = 0; i < this->conflictValues.size(); i++)
    {
        if (this->conflictValues[i] == val)
            return;
    }

    this->conflictValues.push_back(val);
}

void Cell::removeConflictValue(int val)
// Takes in a value to be added to the conflictValues vector, and removes it
{
    for (int i = 0; i < this->conflictValues.size(); i++)
    {
        if (this->conflictValues[i] == val)
            this->conflictValues.erase(this->conflictValues.begin() + i);
    }
}

void Cell::printCell()
// Prints out the cell's value and conflict vector
{
    if(this->value == Blank) {
        cout << "|       |";
    }
    else {
        cout << "|   " << this->value << "   |";
    }
    cout << "  ";
    for(int i = 0; i < this->conflictValues.size(); i++) {
        cout << this->conflictValues[i] << ", ";
    }
}





