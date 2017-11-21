/*
 * Board.h
 *
 *  Created on: 2 בנוב׳ 2017
 *      Author: Noam shimshoviz 203565429
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <iostream>
using namespace std;

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
	void update(int row, int column, char player);
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
	char** getBoard();

	Board ( Board & oldboard);

private:
	int row;
	int column;
	char** board;
};

#endif /* BOARD_H_ */
