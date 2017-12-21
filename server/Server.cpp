/*
 * Server.cpp
 *
 *  Created on: 27 בנוב׳ 2017
 *       Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
 */

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include "CommandsManager.h"


#define MAX 10
#define SIZE 6

Server::Server(int port): port(port), serverSocket(0){
	gamesName.push_back("Noam");
	gamesName.push_back("Sarit");
	gamesName.push_back("Beer");
	cout << "server "<< endl;
}

struct ThreadArgs {
	int clientSocket;
	vector <string> names;
	CommandsManager manager;
};
static void * clientHandle (void * tArgs){

 struct ThreadArgs *args = (struct ThreadArgs *) tArgs;
 long clientSocket = args-> clientSocket;
 vector <string> names = args->  names;

 //read(clientSocket.....
 args->manager.executeCommand("list_games",names);
 cout << "1234" << endl  << clientSocket << endl;
 close(clientSocket);
 pthread_exit(NULL);
}


void Server::stop() {
	cout << "close server socket" << endl;
	close(serverSocket);

}

void Server::start() {
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == -1) {
		throw "error opening socket";
	}
	struct sockaddr_in serverAddres;
	bzero((void *)& serverAddres, sizeof(serverAddres));
	serverAddres.sin_family = AF_INET;
	serverAddres.sin_addr.s_addr = INADDR_ANY;
	serverAddres.sin_port = htons(port);

	if (bind(serverSocket, (struct sockaddr*)&serverAddres, sizeof(serverAddres)) == -1){
		throw "error on binding";
	}
	ThreadArgs *args = new ThreadArgs;
	listen(serverSocket, MAX);
    while (true) {
	    struct sockaddr_in clientAddress;
	    socklen_t clientAddressLen;
	    int x = 9;
		cout << "wait............."<<endl;

		int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);

		if (clientSocket == -1) {
			throw "error on accept first player";
		}
		pthread_t thread;
		int rc;


		args->names = this->gamesName;
		args->clientSocket = clientSocket;
		CommandsManager m (*this);
		args->manager = m;
		rc = pthread_create(&thread, NULL,clientHandle,(void*)args);
		if (rc) {
			cout << "bad!!!!";
		}
		cout << clientSocket << "!!!!!!!!!!!!!!!!!!!!!!!";
		void* status;
		pthread_join(thread, &status);

		cout << "!!!!!!"<< endl;

		/*

		string s = "12";
		write(clientSocket,s.c_str(),2);
		int message = 1;
		write(clientSocket,&message, sizeof(message));



			struct sockaddr_in client2Address;
			socklen_t client2AddressLen;
			int otherSocket = accept(serverSocket, (struct sockaddr *)&client2Address, &client2AddressLen);
			if (otherSocket == -1) {
				throw "error on accept second player";
			}

			message = 2;
			write(otherSocket, &message, sizeof(message));
			this->handleClient(clientSocket, otherSocket);
			cout << "close client socket!" << endl;
			*/
	}
    delete args;
}




void Server::deleteName(string& name) {
	vector <string>::iterator it;
	for(it = gamesName.begin(); it != gamesName.end(); it++) {
		if (*it == name){
			gamesName.erase(it);
			break;
		}
	}
}



void Server::handleClient(int clientSocket, int otherSocket) {
	int arg1, arg2, n, size;
    arg1 = 1;
    arg2 = 2;
    //send for each player his number- 1 or 2
    n = write(clientSocket, &arg1, sizeof(arg1));
    if (n == -1) {
        cout << "error write arg1" << endl;
    }
    n = write(otherSocket, &arg2, sizeof(arg2));
    if (n == -1) {
        cout << "error write arg2" << endl;
    }
    //read and write the second player the board's size
    n = read(clientSocket, &size, sizeof(size));
    n = write(otherSocket, &size, sizeof(size));

    bool flag = true;
    int row, column;
    //play the game
    while(flag) {
        n = read(clientSocket, &row, sizeof(row));
	if (n == 0) {          // check if one of the player disconnect
		close(clientSocket);
		close(otherSocket);
		flag = false;
	}
        n = read(clientSocket, &column, sizeof(column));
	if (n == 0) {          // check if one of the player disconnect
		close(clientSocket);
		close(otherSocket);
		flag = false;
	}
        if (row == -1) { //means the player finish the game
            close(clientSocket);
            flag = false;
        } else {
            n = write(otherSocket, &row, sizeof(row));
	if (n == 0) {          // check if one of the player disconnect
		close(clientSocket);
		close(otherSocket);
		flag = false;
	}
            n = write(otherSocket, &column, sizeof(column));
	if (n == 0) {          // check if one of the player disconnect
		close(clientSocket);
		close(otherSocket);
		flag = false;
	}
        }
        n = read(otherSocket, &row, sizeof(row));
	if (n == 0) {          // check if one of the player disconnect
		close(clientSocket);
		close(otherSocket);
		flag = false;
	}
        n = read(otherSocket, &column, sizeof(column));
	if (n == 0) {          // check if one of the player disconnect
		close(clientSocket);
		close(otherSocket);
		flag = false;
	}
        if (row == -1) { //means the player finish the game
            close(otherSocket);
            flag = false;
        } else {
            n = write(clientSocket, &row, sizeof(row));
	if (n == 0) {          // check if one of the player disconnect
		close(clientSocket);
		close(otherSocket);
		flag = false;
	}
            n = write(clientSocket, &column, sizeof(column));
	if (n == 0) {          // check if one of the player disconnect
		close(clientSocket);
		close(otherSocket);
		flag = false;
	}
        }
    }
}
