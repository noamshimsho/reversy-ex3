/*
 * RemotePlayer.h
 *
 *  Created on: 28 בדצמ׳ 2017
 *      Author:  Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
 */

#ifndef REMOTEPLAYER_H_
#define REMOTEPLAYER_H_

#include "Player.h"

class RemotePlayer: public Player {
public:
	 /**
	     * constructor HumanPlayer calling to the base c'tor of player.
	     * @param name, the player tag for the game
	     */
	RemotePlayer(discSymbol name);
	     /**
	     * the HumanPlayer play his turn
	     * @param logic, the rules of the game
	     * @param moves- vector of possible moves
	     */
		Position playTurn(GameLogic logic, vector<Position> &moves) const;
	};

#endif /* REMOTEPLAYER_H_ */
