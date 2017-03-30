//
// Created by Adam Bechtold on 3/28/17.
//


#include "Cell.h"

const int Blank = -1;  // Indicates that a cell is blank
const int SquareSize = 3;  //  The number of cells in a small square
const int BoardSize = SquareSize * SquareSize;


using namespace std;

Cell::Cell(int value) {
    this->value = value;
    this->rowConflicts = vector<bool>(BoardSize);
    this->colConflicts = vector<bool>(BoardSize);
    this->sqaureConflicts = vector<bool>(BoardSize);
}

Cell::Cell() : Cell(Blank) { }

int Cell::getValue() const {
    return this->value;
}

ostream &operator<<(ostream &ostr, const Cell &c) {
    ostr << c.getValue();
    return ostr;
}

vector<bool> Cell::getRowConflicts() const {
    return this->sqaureConflicts;
}

vector<bool> Cell::getColConflicts() const {
    return this->colConflicts;
}

vector<bool> Cell::getSquareConflict() const {
    return this->sqaureConflicts;
}

void Cell::setValue(int value) {
    this->value = value;
}

void Cell::setRowConflict(vector<bool> conflict) {
    this->rowConflicts = conflict;
}

void Cell::setColConflict(vector<bool> conflict) {
    this->colConflicts = conflict;
}

void Cell::setSquareConflict(vector<bool> conflict) {
    this->sqaureConflicts = conflict;
}

void Cell::modRowConflict(int index, bool val) {
    this->rowConflicts[index] = val;
    this->addConflictValue(index+1);
}

void Cell::modColConflict(int index, bool val) {
    this->colConflicts[index] = val;
    this->addConflictValue(index+1);
}

void Cell::modSquareConflict(int index, bool val) {
    this->sqaureConflicts[index] = val;
    this->addConflictValue(index+1);
}


void Cell::addConflictValue(int val) {

    for (int i = 0; i < this->conflictValues.size(); i++) {
        if (this->conflictValues[i] == val) {
            return;
        }
    }

    this->conflictValues.push_back(val);
}





