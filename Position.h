/*
 * Position.h
 *
 *  Created on: 31 באוק׳ 2017
 *      Author: Noam shimshoviz 203565429
 */

#ifndef POSITION_H_
#define POSITION_H_

#include <iostream>
using namespace std;
class Position {
private:
    int row;
    int column;
public:
    /**
     * constructor of Position
     * @ parm x, is the roe number, and y is the column number
     */
    Position( int x, int y);
    /**
     * operator overloadig of == between tow position
     * @ parm other, the other position to be compare
     *  @ return true if its the same position else false
     */
    bool operator==(const Position& other);
    /**
     * @ return the number of column of the position
     */
    const int& getColumn() const;
    /**
     * @ return the number of row of the position
     */
    const int& getRow() const;
    friend ostream& operator <<(ostream &out, const Position &point);
};

#endif /* POSITION_H_ */
