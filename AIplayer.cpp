/*
 * AIplayer.cpp
 *
 *  Created on: 16 בנוב׳ 2017
 *      Author: noam
 */

#include "AIplayer.h"
#include "Player.h"

AIplayer::AIplayer(char name): Player(name) {}

bool AIplayer::playTurn(GameLogic logic) const {
    int o, p;
    int minScore;
    int maxScore = -(logic.getBoard().getColumn()*logic.getBoard().getRow()) - 1;
    bool flag;
    Position point(0,0);
	const vector<Position>& moves1 = logic.calculateMoves(player);
	if (moves1.size() != 0) {
		for (vector<Position>::const_iterator it1 = moves1.begin(); it1 != moves1.end(); it1++ ) {
			Board temp1 (logic.getBoard());    //create copy of the main board
			logic.updateBoard(*it1, player,temp1);  // play a move on the copy board
			const vector<Position>& moves2 = logic.calculateMoves(other, temp1);
            minScore = (logic.getBoard().getColumn()*logic.getBoard().getRow()) + 1;
            if(moves2.size() == 0) {
                p = temp1.score(this->getPlayer());
                o = temp1.score(this->getOther());
                if(minScore > (p-o)) {
                    minScore = p-o;
                }
            } else {
                for (vector<Position>::const_iterator it2 = moves2.begin(); it2 != moves2.end(); it2++) {
                    Board temp2(temp1);    //create copy of the main board
                    logic.updateBoard(*it2, other, temp2);  // play a move on the copy board
                    p = temp2.score(this->getPlayer());
                    o = temp2.score(this->getOther());
                    if (minScore > (p-o)) {
                        minScore = p-o;
                    }
                }
            }
            if(maxScore < minScore) {
                maxScore = minScore;
                point = *it1;
            }
		}
        logic.updateBoard(point, this->getPlayer());
		return true;
	}
	else {
        cout << this->getPlayer()<<" no possible moves for you, the turn pass to your opponent" << endl;
		return false;
	}
}
