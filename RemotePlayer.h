//
// Created by sarit on 28/12/17.
//

#ifndef UNTITLED_REMOTEPLAYER_H
#define UNTITLED_REMOTEPLAYER_H


#include "Player.h"

class RemotePlayer: public Player {

public:
    /**
    * constructor HumanPlayer calling to the base c'tor of player.
    * @param name, the player tag for the game
    */
    RemotePlayer(discSymbol name);
    /**
    * the HumanPlayer play his turn
    * @param logic, the rules of the game
    * @param moves- vector of possible moves
    */
    Position playTurn(GameLogic logic, vector<Position> &moves) const;
};


#endif //UNTITLED_REMOTEPLAYER_H
