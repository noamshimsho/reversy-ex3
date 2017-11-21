/*
 * PossibleMoves.h
 *
 *  Created on: 2 בנוב׳ 2017
 *      Author: Noam shimshoviz 203565429
 */

#ifndef GAMELOGIC_H_
#define GAMELOGIC_H_
#include "Board.h"
#include <vector>
#include "Position.h"
class GameLogic {
public:
	/**
	 * constructor of GameLogic
	 * @ parm board, pass by reference to the game logic for his calculations
	 */
	GameLogic(Board& board);
	/**
	 *  calculate the possible moves of the player
	 * @ parm player, which player is it's turn
	 *  @ return vector of possible position to play
	 */
	vector<Position> calculateMoves(char player) const;
	vector<Position> calculateMoves(char player, Board& m) const;
	/**
	 * repair the board after a player move
	 * @ parm p, the position of the new tag, tag is it 'x'/'0'
	 */
	void updateBoard (Position p, char player);



	void updateBoard (Position p, char player, Board& m);

	Board& getBoard() const;

private:
	 Board& board;
};

#endif /* GAMELOGIC_H_ */
