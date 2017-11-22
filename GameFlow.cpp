/*
 * GameFlow.cpp
 *
 *  Created on: 7 בנוב׳ 2017
 *      Author: Noam shimshoviz 203565429
 */
#include "Position.h"
#include "GameFlow.h"
#include "Board.h"
#include "GameLogic.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Player.h"
using namespace std;

GameFlow::GameFlow(int& row, int& column): board(row,column), logic(board) {}

void GameFlow::play(Player *playerX, Player *player0)  {
		board.print();
    int counter = 0;
    int fullBoard = ((board.getRow())*(board.getColumn()))-4;
	while((counter!=2) && (fullBoard!=0)) {
        if(playerX->playTurn(this->logic)){
            counter = 0;
            fullBoard--;
            int x = this->board.score('x');
            int o = this->board.score('0');
						cout<< " there are: " << x << " x " << endl;
						cout << " there are: " << o << " 0 " << endl;
        } else {
        		cout << endl << "player X: "<<" no possible moves for you, the turn pass to your opponent" << endl;
            counter++;
        }
        if(player0->playTurn(this->logic)){
            counter = 0;
            fullBoard--;
            int x = this->board.score('x');
            int o = this->board.score('0');
						cout<< " there are: " << x << " x " << endl;
						cout << " there are: " << o << " 0 " << endl;
        } else {
        	  cout <<endl << "player 0: "<<" no possible moves for you, the turn pass to your opponent" << endl;
            counter++;
        }
	}
    endGame();
}

void GameFlow:: endGame()  {
    this->board.print();
    int x = this->board.score('x');
    int o = this->board.score('0');

	cout<< " the game is over!!! "<< endl;
    cout << " the x player score is: " << x << endl;
	cout << " the 0 player score is: " << o << endl;
	if (x > o) {
		cout << " the winner is.... x!!! congratulations!!! "<<endl;
	}
	else if (o > x) {
		cout << " the winner is.... 0!!! congratulations!!! "<<endl;
	}
	else {
		cout << " good game it is a draw!!!"<<endl;
	}
}
/*
void GameFlow::Play(Player x, Player 0) {
	int gameover = 0;
	char player = 'x';
	board.print();
	do {     // start the game

		const vector<Position>& moves = logic.calculateMoves(player);  // find the moves of the player
		if (moves.size() != 0) {  // check the player has moves
			gameover = 0;
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
			logic.updateBoard(p,player);
			board.print();
			//  count and print the amount of 'x' and '0'
			int totalx = 0;
			int total0 = 0;
			for (int i = 0; i < board.getRow(); i++) {
					for (int j = 0; j < board.getColumn(); j++){
							if (board.getBoard()[i][j] == 'x') {
								totalx ++;
							}
							else if (board.getBoard()[i][j] == '0') {
								total0 ++;
							}
						}
					}
				cout<< " there are: " << totalx << " x " << endl;
				cout << " there are: " << total0 << " 0 " << endl;

		}
	else {     // if the vector moves is empty the player doesn't have moves
		cout << " player " << player <<" no possible moves for you the turn pass to your opponent" << endl;
		gameover++;
		}

	if (player == 'x') { // change the player play
		player = '0';
	}
	else {
		player = 'x';
	}

	} while (gameover != 2);

	int totalx = 0;
	int total0 = 0;
	for (int i = 0; i < board.getRow(); i++) {
		for (int j = 0; j < board.getColumn(); j++){
			if (board.getBoard()[i][j] == 'x') {
				totalx ++;
			}
			else if (board.getBoard()[i][j] == '0') {
				total0 ++;
			}
		}
	}
	cout<< " the game is over!!! "<< endl << " the 'x' player score is: " << totalx << endl;
	cout << " the '0' player score is: " << total0 << endl;
	if (totalx > total0) {
		cout << " the winner is.... 'x'!!! congratulations!!! ";
	}
	else if (total0 > totalx) {
		cout << " the winner is.... '0'!!! congratulations!!! ";
	}
	else {
		cout << " good game it is a draw!!!";
	}
}
*/
