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
	Position winner(0,0);
	const vector<Position>& moves = logic.calculateMoves(player);
	if (moves.size() != 0) {
		int max_score = -(logic.getBoard().getRow() * logic.getBoard().getColumn()) - 1;
		for (vector<Position>::const_iterator it = moves.begin(); it != moves.end(); it++ ) {
			Board temp (logic.getBoard());                 //create copy of the main board
			logic.updateBoard(*it, player,temp);          // play a move on the copy board


			int min_score = temp.getColumn() * temp.getRow() + 1;
			const vector<Position>& moves1 = logic.calculateMoves(other,temp);

			for (vector<Position>::const_iterator it1 = moves1.begin(); it1 != moves1.end(); it1++ ){

				if (moves1.size() != 0) {
				Board temp2 = temp;
				logic.updateBoard(*it1, other,temp2);

				int o = temp2.score(other);
				int p = temp2.score(player);

				if ( p - o < min_score) {
					min_score = p - o;
				}
				else {
						int o = temp2.score(other);
						int p = temp2.score(player);
						if ( p - o < min_score) {
									min_score = p - o;
							}
					}
				}
			}

			if (min_score > max_score) {
				max_score = min_score;

				 winner = *it;
			}
		}

		logic.updateBoard(winner, player);
		logic.getBoard().print();
		cout << endl << " player " << this->getPlayer() << " play: " << winner << endl;
		return true;
	}
	else {
		return false;
	}

}
