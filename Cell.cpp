//
// Created by Adam Bechtold on 3/28/17.
//


#include "Cell.h"

const int Blank = -1;  // Indicates that a cell is blank

using namespace std;

Cell::Cell() {
    this->value = Blank;
}

Cell::Cell(int value) {
    this->value = value;
}

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
}

void Cell::modColConflict(int index, bool val) {
    this->colConflicts[index] = val;
}

void Cell::modSquareConflict(int index, bool val) {
    this->sqaureConflicts[index] = val;
}





