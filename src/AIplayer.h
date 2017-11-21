/*
 * AIplayer.h
 *
 *  Created on: 16 בנוב׳ 2017
 *      Author: noam
 */

#ifndef AIPLAYER_H_
#define AIPLAYER_H_
#include "Player.h"

class AIplayer: public Player {
public:
	AIplayer(char name);
	bool playTurn(GameLogic logic) const;
};

#endif /* AIPLAYER_H_ */
