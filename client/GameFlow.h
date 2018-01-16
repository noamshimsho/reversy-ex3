/*
 * GameFlow.h
 *
 *  Created on: 7 בנוב׳ 2017
 *      Author: Noam shimshoviz 203565429 and sarit zevin, ID: 313242588
 */

#ifndef GAMEFLOW_H_
#define GAMEFLOW_H_
#include "Board.h"
#include "GameLogic.h"
#include "Player.h"

class GameFlow {
public:
	/**
	 * constructor of GameFlow initialize board and game logic
	 * @ parm row, column the dimension of the board
	 */
	GameFlow(int& row, int& column);
	/**
	 * play start the game until it's over
	 */
	void play(Player *playerX, Player *player0);
	/*
	 * print the final score and announce the winner
	 */
	void endGame() ;
private:
	Board board;
	GameLogic logic;
};

#endif /* GAMEFLOW_H_ */
