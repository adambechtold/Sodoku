//
// This is the header file for the Cell Class
// This file contains the declarations of the cell class, including:
//
// Default and overloaded constructors to initialize the cell
// A getValue function
// A setValue function
// Functions to update the different boolean conflict vectors
// Functions to add and remove values from the list of conflict values
// Functions to support printing of the cell's value
//

#include <vector>

using namespace std;

#ifndef SODOKU_CELL_H
#define SODOKU_CELL_H


class Cell {
private:
    int value;

    vector<bool> rowConflicts;
    vector<bool> colConflicts;
    vector<bool> squareConflicts;
    vector<bool> conflictValues;

public:
    Cell();
    Cell(int value);

    int getValue() const;

    void setValue(int value);

    void modRowConflict(int index, bool val);
    void modColConflict(int index, bool addBool);
    void modSquareConflict(int index, bool addBool);

    void printCell();

    friend ostream& operator<< (ostream& ostr, const Cell& c);
};


#endif //SODOKU_CELL_H
