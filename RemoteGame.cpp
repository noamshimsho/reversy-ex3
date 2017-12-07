/*
 * RemoteGame.cpp
 *
 *  Created on: 5 בדצמ׳ 2017
 *      Author: noam
 */
#include "Player.h"
#include "Position.h"
#include "HumanPlayer.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "RemoteGame.h"
#include "Position.h"
using namespace std;

RemoteGame::RemoteGame(const char* serverIP, int serverPort): serverIP(serverIP),
serverPort(serverPort),clientSocket(0) {
cout << "client!!" << endl;
}

void RemoteGame::connectToServer() {
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket == -1) {
		throw "Error opening socket";
	}

	struct in_addr address;
	if(!inet_aton(serverIP, &address)) {
		throw "can't parse IP address";
	}
	struct hostent *server;
	server = gethostbyaddr((const void *)&address, sizeof(address), AF_INET);
	if (server == NULL) {
		throw "HOST IS UNREACHBLE";
	}

	struct sockaddr_in serverAddress;
	bzero((char *)& address, sizeof(address));
	serverAddress.sin_family = AF_INET;
	memcpy((char *)&serverAddress.sin_addr.s_addr,(char *)server->h_addr, server->h_length);
	serverAddress.sin_port = htons(serverPort);

	if (connect(clientSocket, (struct sockaddr *)& serverAddress, sizeof(serverAddress)) == -1) {
		throw "error connecting to server";
	}
	cout << "Connected to server" << endl;

	}

void RemoteGame::play(int row, int column) {
	int tag, n;
	int counter = 0;
	Board board(row, column);
	int fullBoard = ((board.getRow())*(board.getColumn()))-4;
	GameLogic logic(board);


	n = read(clientSocket,&tag, sizeof(tag));
	if (n == -1) {
		throw " error reading";
	}
	if (tag == 1) {
		Player *p1 = new HumanPlayer(X);
		board.print();
		while((counter < 2) && (fullBoard!=0)) {
			this->myTurn(counter,fullBoard,logic,p1);
			cout << "counter!!!!!!!!!!!!!!" << counter <<endl;
			if(fullBoard !=0 && counter != 2) {
				this->otherTurn(counter,fullBoard,logic,p1);
			}
		}
		delete p1;

	} else if (tag == 2) {
			Player *p1 = new HumanPlayer(O);
			cout <<endl << "waiting for other player's move..." << endl;
			while((counter < 2) && (fullBoard!=0)){
				this->otherTurn(counter,fullBoard,logic,p1);
				cout << "counter!!!!!!!!!!!!!!" << counter <<endl;
				if(fullBoard !=0 && counter != 2) {
					this->myTurn(counter,fullBoard,logic,p1);
				}
			}
			delete p1;
	}
	cout << "finish the while loop!!!!";
	this->writeToServer(-1,-1);
	this->endGame(board);
}
void RemoteGame::writeToServer(int x, int y) {
	 write(clientSocket,&x, sizeof(x));
	 write(clientSocket,&y, sizeof(y));
}
Position RemoteGame::readFromServer() {
	int r,c;
	read(clientSocket,&r,sizeof(r));
	read(clientSocket,&c,sizeof(c));
	Position p(r,c);
	return p;
}

void RemoteGame::myTurn(int& counter, int& fullBoard, GameLogic& logic, Player* p1) {
	Position p(0,0);
	vector <Position> moves = p1->hasMove(logic);
	if (!moves.empty()) {
				counter = 0;
				fullBoard--;
				p = p1->playTurn(logic,moves);
			  logic.updateBoard(p,p1->getPlayer());
			  logic.getBoard().print();

				this->writeToServer(p.getRow(),p.getColumn());
			}
			else {
				cout << endl << "you don't have moves..." << endl;
				 this->writeToServer(p.getRow(), p.getColumn());
				 counter++;
			}
	cout <<endl << "waiting for other player's move..." << endl;
}

void RemoteGame::otherTurn(int& counter, int& fullBoard, GameLogic& logic, Player* p1) {

			Position move = this->readFromServer();
			if (move == Position (0,0)) {
				cout << "The other player's has no move" << endl;
				counter++;
			} else {
				  logic.updateBoard(move,p1->getOther());
				  logic.getBoard().print();
				  counter = 0;
				  fullBoard--;
			}
}

void RemoteGame:: endGame(Board & board)  {
    board.print();
    int x = board.score(X);
    int o = board.score(O);

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

