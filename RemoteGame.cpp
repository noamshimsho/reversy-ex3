/*
 * RemoteGame.cpp
 *
 *  Created on: 5 בדצמ׳ 2017
 * Author: Noam shimshoviz 203565429 Sarit Zevin 313242588
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
	cout << "enter command" << endl;

		 string command;
		 getline(cin, command);
		
		 cout << command << endl;
		 const char * c = command.c_str();
		 int l = strlen(c);
		 write(clientSocket, &l, sizeof(l));
		 write(clientSocket, c, l);



//int l;

int n;
n = read(clientSocket,&l,sizeof(l));


	char* answer = new char[l + 1];
	read(clientSocket, answer, l);
	//for(int i =0; i < l; i++) {
//cout<< answer[i];
//}
	string please (answer);
	cout <<please <<endl;
delete answer;

}

void RemoteGame::play() {
	int tag, n, size;
    string s;

    char* t;
    bool flag;
	//char buffer[9];
	int counter = 0;
	void * buffer;
	char array [3];

	n = read(clientSocket,array,2);
	//s1 = (string *)buffer;
	array [2] = '\0';
	string s1 = array;
	cout << array[0] << array[1];
	cout << s1 << "!!!!!!!!!!" <<   endl ;


	//find out if you are the first player or the second player to connect
	n = read(clientSocket,&tag,sizeof(tag));
	if (tag == 1) {
		cout << "Waiting for other player" << endl;
	}

	//the first player chose the board's size and send it to the second player
	n = read(clientSocket,&tag, sizeof(tag));
	if (n == -1) {
		throw " error reading";
	}
	if (tag == 1) {
        cout << "You are the first player to connect so you can chose the board's size." << endl;
        do {
            cout << "Please enter even size of board: " << endl;
            getline(cin, s);
            size = atoi(s.c_str());
            if (size > 0 && size % 2 == 0) {
                flag = false;
            } else {
                cout << "wrong input try again" << endl;
                flag = true;
            }
        } while (flag);
        write(clientSocket, &size, sizeof(size));
    }else if(tag == 2){
        cout<<"You are the second player to connect."<<endl;
        read(clientSocket,&size,sizeof(size));
        cout<<"The chosen board's size is: "<<size<<endl;
    }
    //building the board
    Board board(size, size);
    int fullBoard = ((board.getRow())*(board.getColumn()))-4;
    GameLogic logic(board);

    //the first player's game
    if(tag == 1){
        Player *p1 = new HumanPlayer(X);
		board.print();
		while((counter < 2) && (fullBoard!=0)) {
			this->myTurn(counter,fullBoard,logic,p1);

			if(fullBoard !=0 && counter != 2) {
				this->otherTurn(counter,fullBoard,logic,p1);
			}
		}
		delete p1;
        //the second player's game
	} else if (tag == 2) {
			Player *p1 = new HumanPlayer(O);
			cout <<endl << "waiting for other player's move..." << endl;
			while((counter < 2) && (fullBoard!=0)){
				this->otherTurn(counter,fullBoard,logic,p1);

				if(fullBoard !=0 && counter != 2) {
					this->myTurn(counter,fullBoard,logic,p1);
				}
			}
			delete p1;
	}
    //finish the game
	this->writeToServer(-1,-1);
	this->endGame(board, tag);
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
	if (!moves.empty()) { //means there is moves the player can do
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
			if (move == Position (0,0)) { //means the player other has no move
				cout << "The other player's has no move" << endl;
				counter++;
			} else { //update the board according to the move he read
				  logic.updateBoard(move,p1->getOther());
				  logic.getBoard().print();
				  counter = 0;
				  fullBoard--;
			}
}

void RemoteGame:: endGame(Board & board, int tag)  {
    board.print();
    //chech the score of the players
    int x = board.score(X);
    int o = board.score(O);

	cout<< " the game is over!!! "<< endl;
        cout << " the x player score is: " << x << endl;
	cout << " the o player score is: " << o << endl;
	if (x > o) {
		cout << " the winner is.... x!!!";
		if(tag==1) {
			cout << " congratulations!!! " << endl;
		} else if(tag ==2){
			cout<<" too bad..."<<endl;
		}
	}
	else if (o > x) {
		cout << " the winner is.... o!!!";
		if(tag==2) {
			cout << " congratulations!!! " << endl;
		} else if(tag ==1){
			cout<<" too bad..."<<endl;
		}
	}
	else {
		cout << " good game it is a draw!!!"<<endl;
	}
}
