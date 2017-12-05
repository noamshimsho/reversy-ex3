/*
 * AIplayer.cpp
 *
 *  Created on: 16 בנוב׳ 2017
 *       Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
 */

#include "AIplayer.h"
#include "Player.h"
#include "Board.h"

AIplayer::AIplayer(discSymbol name): Player(name) {}

Position AIplayer::playTurn(GameLogic logic) const {
	Position winner(0,0);
    int o, p;
	  const vector<Position>& moves = logic.calculateMoves(player);
	//if (moves.size() != 0) { // check if there is possible moves for the player
		int max_score = -(logic.getBoard().getRow() * logic.getBoard().getColumn()) - 1;
		for (vector<Position>::const_iterator it = moves.begin(); it != moves.end(); it++ ) {
			Board temp (logic.getBoard());                 //create copy of the main board
			logic.updateBoard(*it, player,temp);          // play a move on the copy board

			int min_score = temp.getColumn() * temp.getRow() + 1;
			const vector<Position>& moves1 = logic.calculateMoves(other,temp); 
			//check if there is possible moves for the other player
			if(moves1.size() == 0) {
				//even if there isn't possible moves still need to check the score, maybe this is the best move
				p = temp.score(this->getPlayer());
				o = temp.score(this->getOther());
				if(min_score > (p-o)) {
				    min_score = p-o;
				}
			} else {
				//check the score for each move of the other player
				for (vector<Position>::const_iterator it2 = moves1.begin(); it2 != moves1.end(); it2++) {
				    Board temp2(temp);    //create copy of the main board
				    logic.updateBoard(*it2, other, temp2);  // play a move on the copy board
				    p = temp2.score(this->getPlayer());
				    o = temp2.score(this->getOther());
				    if (min_score > (p-o)) {
				        min_score = p-o;
				    }
				}
			    }
			//update the best move with the lower score
			if (min_score > max_score) {
				max_score = min_score;
				 winner = *it;
			}
		}
		//update the board according to the best choosen move
		//logic.updateBoard(winner, player);
		//logic.getBoard().print();
		//print the move the AI player did
		//cout << endl << " player " << (char)this->getPlayer() << " play: " << winner << endl;
		return winner;
	//}

}
