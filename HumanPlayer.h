/*
 * Noam shimshoviz 203565429 Sarit Zevin 313242588
 */
#include "GameLogic.h"
#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

#include "Player.h"

class HumanPlayer: public Player {
public:
     /**
     * constructor HumanPlayer calling to the base c'tor of player. 
     * @ parm name, the player tag for the game
     */
	HumanPlayer(char name);
     /**
     * the HumanPlayer play his turn
     * @ parm logic, the rules of the game
     */
	bool playTurn(GameLogic logic) const;
};

#endif /* HUMANPLAYER_H_ */
