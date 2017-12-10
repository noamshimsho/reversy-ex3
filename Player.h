/*
 *  Noam shimshoviz 203565429 Sarit Zevin 313242588
 */
#include "GameLogic.h"
#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
protected:
	discSymbol player;
	discSymbol other;
public:
     /**
     * constructor of a player 
     * @ parm p, the player tag for the game
     */
	Player(discSymbol p);
    /**
     * @ return the tag of the other player
     */
	discSymbol getOther() const;
    /**
     * @ return the tag of the player
     */
	discSymbol getPlayer() const;

	vector<Position> hasMove(GameLogic logic) const;
    /**
     * virtual function that play the turn of the player
     * @param logic, the rules of the game
     * @param moves- vector of possible moves
     */
	virtual Position playTurn(GameLogic logic,vector<Position> &moves) const = 0;
    /**
     * virtual d'tor of player
     */
	virtual ~Player() {}
};

#endif /* PLAYER_H_ */
