/*
 * Player.h
 *
 *  Created on: 16 בנוב׳ 2017
 *      Author: noam
 */
#include "GameLogic.h"
#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
protected:
	char player;
	char other;
public:
	Player(char p);
	char getOther() const;
	char getPlayer() const;
	virtual bool playTurn(GameLogic logic) const = 0;
	virtual ~Player() {}
};

#endif /* PLAYER_H_ */
