/*
 * Player.cpp
 *
 *  Created on: 16 בנוב׳ 2017
 *      Author: noam
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

