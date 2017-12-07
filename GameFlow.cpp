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
	while((counter < 2) && (fullBoard!=0)) {
		//check if there is possible moves for the first player
		vector <Position> moves = playerX->hasMove(logic);
		if(!moves.empty()){
		    counter = 0;
		    fullBoard--;
		    Position p = playerX->playTurn(this->logic, moves);
		    logic.updateBoard(p,playerX->getPlayer());
		    logic.getBoard().print();

		//check the score of both players and print it
		    int x = this->board.score(X);
        int o = this->board.score(O);
		    cout << " there are: " << x << "  x " << endl;
				cout << " there are: " << o << "  o " << endl;
				cout << " player " << (char)playerX->getPlayer() << " play: " << p << endl;
		} else {
			cout << endl << "player x: "<<" no possible moves for you, the turn pass to your opponent" << endl;
		    counter++;

		}
		if(fullBoard!=0 ){
		//check if there is possible moves for the second player
			vector <Position> moves = player0->hasMove(logic);
			if(!moves.empty()){
			    counter = 0;
			    fullBoard--;
			    Position p = player0->playTurn(this->logic, moves);
			    logic.updateBoard(p,player0->getPlayer());
			    logic.getBoard().print();
				//check the score of both players and print it
			    int x = this->board.score(X);
			    int o = this->board.score(O);
					cout << " there are: " << x << " x " << endl;
					cout << " there are: " << o << " o " << endl;
					cout << " player " << (char)player0->getPlayer() << " play: " << p << endl;
			} else {
			    cout <<endl << "player o: "<<" no possible moves for you, the turn pass to your opponent" << endl;
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
	cout << " the o player score is: " << o << endl;
	if (x > o) {
		cout << " the winner is.... x!!! congratulations!!! "<<endl;
	}
	else if (o > x) {
		cout << " the winner is.... o!!! congratulations!!! "<<endl;
	}
	else {
		cout << " good game it is a draw!!!"<<endl;
	}
}
