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
  while (true) {
	  struct sockaddr_in clientAddress;
	  socklen_t clientAddressLen;

		cout << "wait............."<<endl;

		int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);

		if (clientSocket == -1) {
			throw "error on accept first player";
		}

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
			//this->stop();

	}
}

void Server::stop() {
	cout << "close server socket" << endl;
	close(serverSocket);
}

void Server::handleClient(int clientSocket, int otherSocket) {


	int arg1, arg2, n;


		arg1 = 1;
		arg2 = 2;
		n = write(clientSocket, &arg1, sizeof(arg1));

		if (n == -1) {
			cout << "error write arg1" << endl;
		}

		n = write(otherSocket, &arg2, sizeof(arg2));

		if (n == -1) {
			cout << "error write arg2" << endl;
		}

bool flag = true;
int row, column;
		while(flag) {
			n = read(clientSocket, &row, sizeof(row));
			n = read(clientSocket, &column, sizeof(column));
			if (row == -1) {
				close(clientSocket);
				//close(otherSocket);
				flag = false;
			} else {
				n = write(otherSocket, &row, sizeof(row));
				n = write(otherSocket, &column, sizeof(column));
			}

			n = read(otherSocket, &row, sizeof(row));
			n = read(otherSocket, &column, sizeof(column));
			if (row == -1) {
				close(otherSocket);
							//close(otherSocket);
				flag = false;
			} else {
				n = write(clientSocket, &row, sizeof(row));
				n = write(clientSocket, &column, sizeof(column));
			}
		}
}







