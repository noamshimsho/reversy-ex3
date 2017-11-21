/*
 * HumanPlayer.cpp
 *
 *  Created on: 16 בנוב׳ 2017
 *      Author: noam
 */

#include "HumanPlayer.h"
#include "Player.h"
#include "Position.h"
#include "GameFlow.h"
#include "Board.h"
#include "GameLogic.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;


HumanPlayer::HumanPlayer(char name): Player(name) {}

bool HumanPlayer::playTurn(GameLogic logic) const {

	const vector<Position>& moves = logic.calculateMoves(player);  // find the moves of the player
			if (moves.size() != 0) {  // check the player has moves
				cout << endl<< "player: " << player<<" your possible moves are: ";
				for (unsigned int i = 0; i < moves.size(); i++) {
						cout << " ( " << moves[i].getRow() << ", " << moves[i].getColumn() << ") ";
				}
				cout << endl;
				// checking the input and convert it to integers
				int row, column;
				bool flag = true;     //
				do {
					string r ,c;
					cout << "please enter row number: " << endl ;
					getline(cin, r);
					cout  << "please enter column number: " << endl ;
					getline(cin, c);


					row = atoi(r.c_str());
					column = atoi(c.c_str());

					Position p(row,column); // the position the player enter
					for (unsigned int i = 0; i < moves.size(); i++) {  // check that this position is equal to one of his options
						if (p == moves[i]) {
							flag =false;
							break;
						}
					}
					if (flag){
						cout << "wrong input try again!! " << endl;
					}
				} while (flag);

				Position p(row,column);
				logic.updateBoard(p,player);     // end of turn the main board is update
				return true;
			}
			else {
				return false;
			}


}
