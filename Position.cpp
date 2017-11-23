//  Noam shimshoviz 203565429 Sarit Zevin 313242588
#include <iostream>
#include "Position.h"

Position::Position(int x, int y): row(x), column(y) {}

const int& Position::getColumn() const {

    return column;
}

const int& Position::getRow() const {
    return row;
}

bool Position::operator ==(const Position& other) {

    return ((row == other.getRow()) and (column == other.getColumn()));
}
ostream &operator <<(ostream &out, const Position &point) {
    out << " (" << point.getRow() << ", " << point.getColumn() << ") ";
    return out;
}

