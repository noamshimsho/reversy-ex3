/*
 * Noam shimshoviz 203565429 Sarit Zevin 313242588
 */

#include "GameLogic.h"
#include "Board.h"
#include <iostream>
#include "Position.h"
#include <vector>

using namespace std;
Board& GameLogic::getBoard() const {
	return board;
}
GameLogic::GameLogic(Board& board): board(board) {}


vector<Position> GameLogic::calculateMoves(discSymbol player, Board& m) const {

	  discSymbol ** b = m.getBoard();
		const int& row = m.getRow();
		const int& column = m.getColumn();
		vector<Position> moves;

		for (int i = 0; i < row; i++){
			for (int j = 0; j < column; j++){

				if ( b[i][j] == S){  // check that it's an empty cell

					if (j - 1 > 0 and b[i][j-1] != S and b[i][j-1] != player) {   // left
							for (int t = 2; j-t >= 0; t++){
								if (b[i][j-t] == player) {
									bool flag = true;
									Position candidate(i + 1, j + 1);
									for (unsigned int a = 0; a < moves.size(); a++) {
										if (candidate == moves[a]){
											flag = false;
										}
									}
									if (flag){
									moves.push_back(Position(i+1,j+1));
									}
										break;
									}
								else if  (b[i][j-t] == S){
									break;
								}
							}
					}

					 if (j - 1 > 0 and i-1 > 0 and b[i-1][j-1] != S and b[i-1][j-1] != player) { // left oblique line
						for (int t = 2; j-t >= 0 and i - t >= 0; t++) {
							if (b[i-t][j-t] == player) {
								bool flag = true;
								Position candidate(i + 1, j + 1);
								for (unsigned int a = 0; a < moves.size(); a++) {
									if (candidate == moves[a]){
										flag = false;
										}
									}
								if (flag){
									moves.push_back(Position(i+1,j+1));
								}
							}
							else if (b[i-t][j-t] == S){
									break;
							}
						}
					}

					 if (i - 1 > 0  and b[i-1][j] != S and b[i-1][j] != player) { // up
						for (int t = 2; i-t >= 0; t++) {
							if (b[i-t][j] == player) {
								bool flag = true;
								Position candidate(i + 1, j + 1);
								for (unsigned int a = 0; a < moves.size(); a++) {
									if (candidate == moves[a]){
										flag = false;
										}
									}
								if (flag){
									moves.push_back(Position(i+1,j+1));
									break;
								}
							}
							else if (b[i-t][j] == S){
									break;
							}
						}
					}

					 if(j + 1 < column  and i-1 > 0 and b[i-1][j+1] != S and b[i-1][j+1] != player) {
										for (int t = 2; j+t < column and i-t >= 0 ; t++) {
											if (b[i-t][j+t] == player) {
												bool flag = true;
												Position candidate(i + 1, j + 1);
												for (unsigned int a = 0; a < moves.size(); a++) {
													if (candidate == moves[a]){
														flag = false;
														}
													}
												if (flag){
													moves.push_back(Position(i+1,j+1));
													break;
												}
											}
											else if (b[i-t][j+t] == S){
													break;
											}
										}
									}

					 if (j + 1 < column  and b[i][j+1] != S and b[i][j+1] != player) { // right
						for (int t = 2; j+t < column; t++) {
							if (b[i][j+t] == player) {
								bool flag = true;
								Position candidate(i + 1, j + 1);
								for (unsigned int a = 0; a < moves.size(); a++) {
									if (candidate == moves[a]){
										flag = false;
										}
									}
								if (flag){
									moves.push_back(Position(i+1,j+1));
									break;
								}
							}
							else if (b[i][j+t] == S){
									break;
							}
						}
					}

					 if (j + 1 < column and i+1 < row and b[i+1][j+1] != S and b[i+1][j+1] != player) {
						for (int t = 2; j + t < column and i + t < row; t++) {
							if (b[i+t][j+t] == player) {
								bool flag = true;
								Position candidate(i + 1, j + 1);
								for (unsigned int a = 0; a < moves.size(); a++) {
									if (candidate == moves[a]){
										flag = false;
										}
									}
								if (flag){
									moves.push_back(Position(i+1,j+1));
									break;
								}
							}
							else if (b[i+t][j+t] == S){
									break;
							}
						}
					}

					 if ( i+1 < row and b[i+1][j] != S and b[i+1][j] != player) { // down
						for (int t = 2; i+t < row; t++) {
							if (b[i+t][j] == player) {
								bool flag = true;
								Position candidate(i + 1, j + 1);
								for (unsigned int a = 0; a < moves.size(); a++) {
									if (candidate == moves[a]){
										flag = false;
										}
									}
								if (flag){
									moves.push_back(Position(i+1,j+1));
									break;
								}
							}
							else if (b[i+t][j] == S){
									break;
							}
						}
					}

					 if (j - 1 > 0 and i+1 < row and b[i+1][j-1] != S and b[i+1][j-1] != player){
						for (int t = 2; j-t >= 0 and i + t < row; t++) {
							if (b[i+t][j-t] == player) {
								bool flag = true;
								Position candidate(i + 1, j + 1);
								for (unsigned int a = 0; a < moves.size(); a++) {
									if (candidate == moves[a]){
										flag = false;
										}
									}
								if (flag){
									moves.push_back(Position(i+1,j+1));
									break;
								}
							}
							else if (b[i+t][j-t] == S){
									break;
							}
						}
					}
				}
			}
		}
		return moves;

}

vector<Position> GameLogic::calculateMoves(discSymbol player) const {

	return this->calculateMoves(player, board);
}


void GameLogic::updateBoard(Position p, discSymbol player) {
	this->updateBoard(p,player,board);

}


void GameLogic::updateBoard(Position p, discSymbol player, Board& m) {
	const int& i = p.getRow() - 1;
	const int& j = p.getColumn() - 1;
	const int& row = m.getRow();
	const int& column = m.getColumn();
	discSymbol ** b = m.getBoard();

		if (j - 1 > 0 and b[i][j-1] != S and b[i][j-1] != player) {   // check the left beside cell that is oposite player
				for (int t = 2; j-t >= 0; t++){   //chek the rest left side if there is the same tag
					if (b[i][j-t] == player) {
						for (int a = j-1; a > j-t; a--) {
							b[i][a] = player;
						}
							break;
						}
					else if  (b[i][j-t] == S){
						break;
					}
				}
		}

		 if (j - 1 > 0 and i - 1 > 0 and b[i-1][j-1] != S and b[i-1][j-1] != player) {
			for (int t = 2; j-t >= 0 and i-t >= 0; t++){
				if (b[i-t][j-t] == player) {
					for (int a = 1; a < t; a++) {
						b[i-a][j-a] = player;
					}
						break;
					}

				else if  (b[i-t][j-t] == S){
					break;
				}
			}
	}

		 if ( i - 1 > 0 and b[i-1][j] != S and b[i-1][j] != player) {   // up
			for (int t = 2; i-t >= 0; t++){
				if (b[i-t][j] == player) {
					for (int a = 1; a < t; a++) {
						b[i-a][j] = player;
					}
						break;
					}

				else if  (b[i-t][j] == S){
					break;
				}
			}
	}

		 if(j + 1 < column  and i-1 > 0 and b[i-1][j+1] != S and b[i-1][j+1] != player) {
					for (int t = 2; j+t < column and i-t >= 0 ; t++) {
						if (b[i-t][j+t] == player) {
							for (int a = 1; a < t; a++) {
												b[i-a][j+a] = player;
											}
							break;
						}
						else if (b[i-t][j+t] == S){
						break;
										}
									}
								}
				 if (j + 1 < column  and b[i][j+1] != S and b[i][j+1] != player) { // right
					for (int t = 2; j+t < column; t++) {
						if (b[i][j+t] == player) {
							for (int a = 1; a < t; a++) {
												b[i][j+a] = player;
											}
							break;
						}
						else if (b[i][j+t] == S){
								break;
						}
					}
				}

				 if (j + 1 < column and i+1 < row and b[i+1][j+1] != S and b[i+1][j+1] != player) {
					for (int t = 2; j + t < column and i + t < row; t++) {
						if (b[i+t][j+t] == player) {
							for (int a = 1; a < t; a++) {
												b[i+a][j+a] = player;
											}
							break;
						}
						else if (b[i+t][j+t] == S){
								break;
						}
					}
				}

				 if ( i+1 < row and b[i+1][j] != S and b[i+1][j] != player) { // down
					for (int t = 2; i+t < row; t++) {
						if (b[i+t][j] == player) {
							for (int a = 1; a < t; a++) {
												b[i+a][j] = player;
											}
							break;
						}
						else if (b[i+t][j] == S){
								break;
						}
					}
				}

				 if (j - 1 > 0 and i+1 < row and b[i+1][j-1] != S and b[i+1][j-1] != player) { //  down
					for (int t = 2; j-t >= 0 and i + t < row; t++) {
						if (b[i+t][j-t] == player) {
							for (int a = 1; a < t; a++) {
												b[i+a][j-a] = player;
											}
							break;
						}
						else if (b[i+t][j-t] == S){
								break;
						}
					}
				}
	b[i][j] = player;
	}
