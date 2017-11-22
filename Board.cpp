/*
 * Board.cpp
  *
 *  Created on: 2 בנוב׳ 2017
 *      Author: Noam shimshoviz 203565429
 */
#include <iostream>
using namespace std;
#include "Board.h"

Board::Board(int r, int c): row(r),column(c) {  // build the board as a array of pointers that each one of them point to another array

	board = new char* [row];
	for(int i = 0; i < row; i++) {
		board[i] = new char[column];
	}
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			board[i][j] =' ';
		}
	}
	// build the opening board
	board [(row / 2) -1][(row / 2) -1] = '0';
	board [(row / 2)][(row / 2)] = '0';
	board [(row / 2) -1][(row / 2)] = 'x';
	board [(row / 2)][(row / 2) -1] = 'x';


}
Board::~Board(){
	for (int i = 0; i < row; i++){
		delete [] board[i];
	}
	delete [] board;
//	cout << "delete board";
}

void Board::print() const {
	for (int i = 1; i <= row; i++) {
	        cout << " " << "| " << i  ;
	    }
	    cout << '|' << endl;
	    cout << string(34, '-') << endl;

	    int num = 1;
	    for (int i = 0; i < row; ++i) {
	        cout << num <<'|';
	        for (int j = 0; j < column; ++j) {
	            cout << board [i][j] << " | ";
	        }
	        num++;
	        cout << endl << string(34, '-')<< endl;
	    }

}

void Board::update(int row, int column, char player) {
	board[row][column] = player;
}

int Board::getColumn() const {
	return column;
}

int Board::getRow() const {
	return row;
}

char** Board::getBoard()  {
	return board;
}

Board::Board( Board& oldboard) {
	row = oldboard.getRow();
	column = oldboard.getColumn();
	char** old = oldboard.getBoard();

	board = new char* [row];
	for(int i = 0; i < row; i++) {
		board[i] = new char[column];
	}

	for (int i = 0; i < row; i++){
			for (int j = 0; j < column; j++){
				board[i][j] = old[i][j];

			}
    }
}
int Board:: score(char player) {
    int i,j, counter=0;
    for(i=0; i<this->getRow(); i++) {
        for (j=0;j<this->getColumn();j++) {
            if (this->getBoard()[i][j] == player) {
                counter++;
            }
        }
    }
    return counter;
}
