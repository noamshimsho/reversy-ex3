/*
 * GameFlow.cpp
 *
 *  Created on: 7 בנוב׳ 2017
 *      Author: Noam shimshoviz 203565429 and sarit zevin, ID: 313242588
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
	//check if either the board is full or there is no possible moves twice
	while((counter!=2) && (fullBoard!=0)) {
                //check if there is possible moves for the first player
		if(playerX->playTurn(this->logic)){
		    counter = 0;
		    fullBoard--;
		//check the score of both players and print it
		    int x = this->board.score(X);
            int o = this->board.score(O);
		    cout<< " there are: " << x << " x " << endl;
	       	    cout << " there are: " << o << " 0 " << endl;
		} else {
			cout << endl << "player X: "<<" no possible moves for you, the turn pass to your opponent" << endl;
		    counter++;
		}
		if(fullBoard!=0){
		//check if there is possible moves for the second player
			if(player0->playTurn(this->logic)){
			    counter = 0;
			    fullBoard--;
		//check the score of both players and print it
			    int x = this->board.score(X);
			    int o = this->board.score(O);
				cout<< " there are: " << x << " x " << endl;
				cout << " there are: " << o << " 0 " << endl;
			} else {
			    cout <<endl << "player 0: "<<" no possible moves for you, the turn pass to your opponent" << endl;
			    counter++;
			}
		}
	}
    endGame();
}

void GameFlow:: endGame()  {
    this->board.print();
    int x = this->board.score(X);
    int o = this->board.score(O);

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
