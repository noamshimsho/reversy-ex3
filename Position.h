/*
 *      Author: Noam shimshoviz 203565429 Sarit Zevin 313242588
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
	Position(int x, int y);
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
	/*
	 * set the first cordinate of the position according to a given integer
	 */
	void setRow(int row);
	/*
	 * set the second cordinate of the position according to a given integer
	 */
	void setColumn(int column);
	/**
	 * @ return the number of row of the position
	 */
	const int& getRow() const;
	/**
	 * operator overloadig of <<
	 * this function print the position to an ostream object
	 * @ parm an ostrem object to write on him and point to be written
	 * @ return the ostream object with the point print on him
	 */
	friend ostream& operator <<(ostream &out, const Position &point);
};

#endif /* POSITION_H_ */
