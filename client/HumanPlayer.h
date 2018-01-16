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
     * @param name, the player tag for the game
     */
	HumanPlayer(discSymbol name);
     /**
     * the HumanPlayer play his turn
     * @param logic, the rules of the game
     * @param moves- vector of possible moves
     */
	Position playTurn(GameLogic logic, vector<Position> &moves) const;
};

#endif /* HUMANPLAYER_H_ */
