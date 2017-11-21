/*
 * AIplayer.cpp
 *
 *  Created on: 16 בנוב׳ 2017
 *      Author: noam
 */

#include "AIplayer.h"
#include "Player.h"

AIplayer::AIplayer(char name): Player(name) {}

bool AIplayer::playTurn(GameLogic logic) const {

	const vector<Position>& moves = logic.calculateMoves(player);
	if (moves.size() != 0) {

		for (vector<Position>::const_iterator it = moves.begin(); it != moves.end(); it++ ) {
			Board t (logic.getBoard());    //create copy of the main board
			logic.updateBoard(*it, player,t);  // play a move on the copy board

			const vector<Position>& moves = logic.calculateMoves(other);

			for (vector<Position>::const_iterator it = moves.begin(); it != moves.end(); it++ ){

			}










		}





		return true;
	}
	else {
		return false;
	}

}
