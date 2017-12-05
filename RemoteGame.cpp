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
	int tag, n, r, c;
	Board board(row, column);
	GameLogic logic(board);
	n = read(clientSocket,&tag, sizeof(tag));
	if (n == -1) {
		throw " error reading";
	}

	if (tag == 1) {
		Player *p1 = new HumanPlayer(X) ;
		board.print();
		if (p1->hasMove(logic)) {
			Position p = p1->playTurn(logic);
		  logic.updateBoard(p,p1->getPlayer());
		  logic.getBoard().print();
			r = p.getRow();
			c = p.getColumn();
			n = write(clientSocket,&r, sizeof(r));
			n = write(clientSocket,&c, sizeof(c));
		}
		else {
			int noMove = 0;
			n = write(clientSocket,&noMove, sizeof(noMove));
			n = write(clientSocket,&noMove, sizeof(noMove));
		}
		cout << "waiting for other player's move...";
		n = read(clientSocket,&r, sizeof(r));
		n = read(clientSocket,&c, sizeof(c));





	} else if (tag == 2) {
			Player *p1 = new HumanPlayer(O) ;
	}

}









