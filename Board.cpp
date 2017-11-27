/*
 * Board.cpp
  *
 *  Created on: 2 בנוב׳ 2017
 *      Author: Noam shimshoviz 203565429 and sarit zevin, ID: 313242588
 */
#include <iostream>
using namespace std;
#include "Board.h"

Board::Board(int r, int c): row(r),column(c) {  // build the board as a array of pointers that each one of them point to another array

	board = new discSymbol* [row];
	for(int i = 0; i < row; i++) {
		board[i] = new discSymbol[column];
	}
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			board[i][j] =S;
		}
	}
	// build the opening board
	board [(row / 2) -1][(row / 2) -1] = O;
	board [(row / 2)][(row / 2)] = O;
	board [(row / 2) -1][(row / 2)] = X;
	board [(row / 2)][(row / 2) -1] = X;


}
Board::~Board(){
	for (int i = 0; i < row; i++){
		delete [] board[i];
	}
	delete [] board;
}

void Board::print() const {
	for (int i = 1; i <= row; i++) {
	        cout << (char)S << "| " << i  ;
	    }
	    cout << '|' << endl;
	    cout << string(34, '-') << endl;

	    int num = 1;
	    for (int i = 0; i < row; ++i) {
	        cout << num <<'|';
	        for (int j = 0; j < column; ++j) {
	            cout << (char)board [i][j] << " | ";
	        }
	        num++;
	        cout << endl << string(34, '-')<< endl;
	    }

}

void Board::update(int row, int column, discSymbol player) {
	board[row][column] = player;
}

int Board::getColumn() const {
	return column;
}

int Board::getRow() const {
	return row;
}

discSymbol** Board::getBoard()  {
	return board;
}

Board::Board( Board& oldboard) {
	row = oldboard.getRow();
	column = oldboard.getColumn();
	discSymbol** old = oldboard.getBoard();

	board = new discSymbol* [row];
	for(int i = 0; i < row; i++) {
		board[i] = new discSymbol[column];
	}

	for (int i = 0; i < row; i++){
			for (int j = 0; j < column; j++){
				board[i][j] = old[i][j];

			}
			}
}

int Board::score(discSymbol player)  {
				int total = 0;
				for (int i = 0; i < this->getRow(); i++) {
						for (int j = 0; j < this->getColumn(); j++){
								if (this->getBoard()[i][j] == player) {
									total ++;
								}
							}
					}
	return total;
}

