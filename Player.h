/*
 *  Noam shimshoviz 203565429 Sarit Zevin 313242588
 */
#include "GameLogic.h"
#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
protected:
	char player;
	char other;
public:
     /**
     * constructor of a player 
     * @ parm p, the player tag for the game
     */
	Player(char p);
    /**
     * @ return the tag of the other player
     */
	char getOther() const;
    /**
     * @ return the tag of the player
     */
	char getPlayer() const;
    /**
     * virtual function that play the turn of the player
     */
	virtual bool playTurn(GameLogic logic) const = 0;
    /**
     * virtual d'tor of player
     */
	virtual ~Player() {}
};

#endif /* PLAYER_H_ */
