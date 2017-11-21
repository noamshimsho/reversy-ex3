/*
 * HumanPlayer.h
 *
 *  Created on: 16 בנוב׳ 2017
 *      Author: noam
 */
#include "GameLogic.h"
#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

#include "Player.h"

class HumanPlayer: public Player {
public:
	HumanPlayer(char name);
	bool playTurn(GameLogic logic) const;
};

#endif /* HUMANPLAYER_H_ */
