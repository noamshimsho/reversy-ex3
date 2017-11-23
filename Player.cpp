/*
 * Noam shimshoviz 203565429 Sarit Zevin 313242588
 */

#include "Player.h"


Player::Player(char p) {
	player = p;
	if(player == 'x') {
		other = '0';
	}
	else {
		other = 'x';
	}
}

char Player::getOther() const {
	return other;
}

char Player::getPlayer() const {
	return player;
}

