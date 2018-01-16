/*
 * AIplayer.h
 *
 *  Created on: 16 בנוב׳ 2017
 *      Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
 */

#ifndef AIPLAYER_H_
#define AIPLAYER_H_
#include "Player.h"

class AIplayer: public Player {
public:
	/**
	 * construct Player from given char
	 * @ param name- the char to construct 
	 */
	AIplayer(discSymbol name);
	/**
	 * make the player's turn
	 * @ param logic- the logic for the turn
	 * @param moves- vector of possible moves
	 */
	Position playTurn(GameLogic logic, vector<Position> &moves) const;
};

#endif /* AIPLAYER_H_ */
