/*
 * Server.cpp
 *
 *  Created on: 27 בנוב׳ 2017
 *      Author: noam
 */

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;
#define MAX 10
#define SIZE 6

Server::Server(int port): port(port), serverSocket(0) {
	cout << "server "<< endl;
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


	listen(serverSocket, MAX);
  //while (true) {
	  struct sockaddr_in clientAddress;
	  socklen_t clientAddressLen;
		cout << "wait............."<<endl;
		int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);

		if (clientSocket == -1) {
			throw "error on accept first player";
		}
			cout << "connected to server" << endl;
			cout << "Waiting for other player to join..." << endl;

			struct sockaddr_in client2Address;
			socklen_t client2AddressLen;
			int client2Socket = accept(serverSocket, (struct sockaddr *)&client2Address, &client2AddressLen);
			if (client2Socket == -1) {
				throw "error on accept second player";
			}
			cout << "client 2222222222 connect" << endl;
			cout << "start play" << endl;
			this->handleClient(clientSocket, client2Socket);

			close(clientSocket);
			close(client2Socket);

			cout << "close client socket!" << endl;
			//this->stop();

	//}
}

void Server::stop() {
	cout << "close server socket" << endl;
	close(serverSocket);
}

void Server::handleClient(int clinetSocket, int client2Socket) {

	cout << "i'm in handleclients!!!!!!";
	int arg1, arg2, n;
	char buffer [SIZE];

		arg1 = 1;
		arg2 = 2;
		n = write(clinetSocket, &arg1, sizeof(arg1));

		if (n == -1) {
			cout << "error write arg1" << endl;
		}

		n = write(client2Socket, &arg2, sizeof(arg2));

		if (n == -1) {
			cout << "error write arg2" << endl;
		}
		// wait for move of client1

		n = read(clinetSocket,&buffer, sizeof(buffer));
		for (int i = 0; i < SIZE; i++){
			cout << buffer[i];
		} cout << endl;

		/*
		n = read(clinetSocket, &arg1, sizeof(arg1));
		if (n == -1) {
			cout << "error read arg1" << endl;
			return;
		}
		if (n == 0) {
			cout << "finish" << endl;
				return;
		}
		n = read(clinetSocket, &op, sizeof(op));
		if ( n == -1) {
			cout << "error read op" << endl;
						return;
		}
		n = read(clinetSocket, &arg2, sizeof(arg2));
		if ( n == -1) {
			cout << "error read arg2" << endl;
						return;
		}
		cout << "good exercise " << arg1 << op << arg2<< endl;

		// write to the client!!!!!
		int result = 789;
*/



}







