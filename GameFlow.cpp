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
#include "Player.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

GameFlow::GameFlow(int row, int column): board(row,column), logic(board) {}
void GameFlow::play(Player *playerX, Player *player0) {
    int counter = 0;
    int fullBoard = ((board.getRow())*(board.getColumn()))-4;
	while((counter!=2) && (fullBoard!=0)) {
        if(playerX->playTurn(this->logic)){
            counter = 0;
            fullBoard--;
        } else {
            counter++;
        }
        if(player0->playTurn(this->logic)){
            counter = 0;
            fullBoard--;
        } else {
            counter++;
        }
	}
    endGame();
}

/*bool GameFlow::playTurn(Player *player) {
    Player player1 (player->getPlayer());
    int gameover = 0;
    board.print();
    const vector<Position> &moves = logic.calculateMoves(player1.getPlayer());  // find the moves of the player
    if (moves.size() != 0) {  // check the player has moves
        gameover = 0;
        cout << endl << "player: " << player1.getPlayer() << " your possible moves are: ";
        for (unsigned int i = 0; i < moves.size(); i++) {
            cout << moves[i];
        }
        cout << endl;
        // checking the input and convert it to integers
        int row, column;
        bool flag = true;     //
        do {
            string r, c;
            cout << "please enter row number: " << endl;
            getline(cin, r);
            cout << "please enter column number: " << endl;
            getline(cin, c);


            row = atoi(r.c_str());
            column = atoi(c.c_str());

            Position p(row, column); // the position the player enter
            for (unsigned int i = 0;
                 i < moves.size(); i++) {  // check that this position is equal to one of his options
                if (p == moves[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "wrong input try again!! " << endl;
            }
        } while (flag);

        Position p(row, column);
        logic.updateBoard(p, player1.getPlayer());
        board.print();
        //  count and print the amount of 'x' and '0'
        int totalP = board.score(player1.getPlayer());
        int totalO = board.score(player1.getOther());
        cout << " there are: " << totalP << " x " << endl;
        cout << " there are: " << totalO << " 0 " << endl;
        return true;
    } else {     // if the vector moves is empty the player doesn't have moves
        cout << " player " << player1.getPlayer();
        cout << " no possible moves for you, the turn pass to your opponent" << endl;
        return false;
    }
}*/

void GameFlow:: endGame() {
    this->board.print();
    int x = board.score('x');
    int o = board.score('0');

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