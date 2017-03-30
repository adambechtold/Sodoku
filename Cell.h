//
// Created by Adam Bechtold on 3/28/17.
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
    vector<bool> sqaureConflicts;

    vector<int> conflictValues;

public:
    Cell();

    Cell(int value);

    int getValue() const;

    vector<bool> getRowConflicts() const;
    vector<bool> getColConflicts() const;
    vector<bool> getSquareConflict() const;

    void setValue(int value);

    void setRowConflict(vector<bool> conflict);
    void setColConflict(vector<bool> conflict);
    void setSquareConflict(vector<bool> conflict);

    void modRowConflict(int index, bool val);
    void modColConflict(int index, bool val);
    void modSquareConflict(int index, bool val);

    void addConflictValue(int val);

    void printCell();


    friend ostream& operator<< (ostream& ostr, const Cell& c);
};


#endif //SODOKU_CELL_H
