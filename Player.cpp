/*
 * Noam shimshoviz 203565429 Sarit Zevin 313242588
 */

#include "Player.h"


Player::Player(discSymbol p) {
	player = p;
	if(player == X) {
		other = O;
	}
	else {
		other = X;
	}
}

discSymbol Player::getOther() const {
	return other;
}

discSymbol Player::getPlayer() const {
	return player;
}

vector<Position> Player::hasMove(GameLogic logic) const {
	const vector<Position>& moves = logic.calculateMoves(this->getPlayer());
	return moves;

}
