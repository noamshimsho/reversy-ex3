//
//      Author: Noam shimshoviz 203565429 Sarit Zevin 313242588
//

#ifndef UNTITLED_REMOTEPLAYER_H
#define UNTITLED_REMOTEPLAYER_H


#include "Player.h"

class RemotePlayer: public Player {

public:
    /**
    * constructor RemotePlayer calling to the base c'tor of player.
    * @param name, the player tag for the game
    */
    RemotePlayer(discSymbol name);
    /**
    * the RemotePlayer play his turn
    * @param logic, the rules of the game
    * @param moves- vector of possible moves
    */
    Position playTurn(GameLogic logic, vector<Position> &moves) const;
};


#endif //UNTITLED_REMOTEPLAYER_H
