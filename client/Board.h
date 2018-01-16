/*
 * Board.h
 *
 *  Created on: 2 בנוב׳ 2017
 *      Author: Noam shimshoviz 203565429 and sarit zevin, ID: 313242588
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <iostream>
using namespace std;

/*
 * type of disc symbol
 */
enum discSymbol{
	X = 'x',
	O = 'o',
	S = ' '
};


class Board {
public:
	/**
	 * constructor of Board initialize board according to the given dimension
	 * @ parm row, column the dimension of the board
	 */
	Board(int row, int column);
	/**
	 * distructor of the board
	 */
	~Board();
	/**
	 *  print the board to the console
	 */
	void print() const;
	/**
	 * update the board with a new tag
	 * @ parm row, column the position of the new tag, player x/0
	 */
	void update(int row, int column, discSymbol player);
	/**
	 * @ return the number of columns in the board
	 */
	int getColumn() const;
	/**
	 * @ return the number of the rows in the board
	 */
	int getRow() const;
	/**
	 * @ return the pointer of the board
	 */
	discSymbol** getBoard();
	/**
	 * copy constructor of the board
	 */
	Board ( Board & oldboard);
	/**
	 * return the score according to given char
	 * @param player- the char of the player that we to check his score
	 */
	int score (discSymbol player) ;

private:
	int row;
	int column;
	discSymbol** board;
};

#endif /* BOARD_H_ */
