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
#include <sstream>
#include "Game.h"


#define MAX 10
#define SIZE 6

Server::Server(int port): port(port), serverSocket(0){
	gamesName.push_back("Noam");
	gamesName.push_back("Sarit");
	gamesName.push_back("Beer");
	cout << "server "<< endl;
}

struct ThreadArgs {
	int client;
	CommandsManager manager;
};

static void * clientHandle (void * tArgs){

 struct ThreadArgs *args = (struct ThreadArgs *) tArgs;
 long clientSocket = args-> client;
 sleep(5);
 //CommandsManager man = args->manager;
 cout << "." << endl;
 int l;
 read(clientSocket,&l,sizeof(l));
 char* answer = new char[l + 1];
 read(clientSocket, answer, l);
 string please (answer);
 delete answer;
 cout << ".." << endl;
 string first_word;                    // string to vector (split)
 istringstream stm(please);
 vector <string> argv;
 string word;
 int flag = 1;
 while (stm >> word) {
		if (flag == 1) {
			first_word = word;
			flag++;
		} else {
		argv.push_back(word);
		}
	}
 cout << "..." << endl;
	 stringstream ss;          // convert  clientSocket to string and add it to argv
	 ss << clientSocket;
	 string client = ss.str();
	 argv.push_back(client);
	 cout << "...." <<first_word<<" "<< argv[0]<< endl;
	 args->manager.executeCommand(first_word,argv);
   close(clientSocket);
}

static void * acceptHandle (void * tArgs){
		Server *s = (Server *)tArgs;
	  //vector <pthread_t> v1;
	  //vector <ThreadArgs> v2;
		pthread_t a1[2];
		ThreadArgs a2[2];
		int i = 0;
		ThreadArgs *args = new ThreadArgs;
		CommandsManager m (*s);
	   while (true) {
		    struct sockaddr_in clientAddress;
		    socklen_t clientAddressLen;
				cout << "wait............."<<endl;
				int clientSocket = accept(s->getServerSocket(), (struct sockaddr *)&clientAddress, &clientAddressLen);
				if (clientSocket == -1) {
					throw "error on accept player";
				}

			//pthread_t thread;
			//args->clientSocket = clientSocket;
			//args->manager = m;
				a2[i].client = clientSocket;
	a2[i].manager = m;
			int rc;
			//rc = pthread_create(&thread, NULL,clientHandle,(void*)args);
			rc = pthread_create(&a1[i], NULL,clientHandle,&a2[i]);
			if (rc) {
				cout << "bad!!!!";
			}
			//void* status;
			//pthread_join(thread, &status);
			i++;
			cout << "finish while"<< endl;

			//close(clientSocket);
			//sleep(10);
		}
	    delete args;

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
	listen(serverSocket, MAX);
/*
  //vector <pthread_t> v1;
  //vector <ThreadArgs> v2;
	pthread_t a1[2];
	ThreadArgs a2[2];
	int i = 0;
	ThreadArgs *args = new ThreadArgs;
	CommandsManager m (*this);
	   while (true) {
			    struct sockaddr_in clientAddress;
			    socklen_t clientAddressLen;
					cout << "wait............."<<endl;
					int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
					if (clientSocket == -1) {
						throw "error on accept player";
					}

				//pthread_t thread;
				//args->clientSocket = clientSocket;
				//args->manager = m;
					a2[i].client = clientSocket;
					a2[i].manager = m;
				int rc;
				//rc = pthread_create(&thread, NULL,clientHandle,(void*)args);
				rc = pthread_create(&a1[i], NULL,clientHandle,&a2[i]);
				if (rc) {
					cout << "bad!!!!";
				}
				//void* status;
				//pthread_join(thread, &status);
				i++;
				cout << "finish while"<< endl;

				//close(clientSocket);
				//sleep(10);
			}
delete args;
*/


	pthread_t thread;
	int rc;
	rc = pthread_create(&thread, NULL,acceptHandle,this);
	if (rc) {
		cout << "bad!!!!";
	 }
	bool flag = true;
	string exit;
	while (flag){
		cout << "for exit write exit " << endl;
		getline(cin, exit);
		if (exit == "exit") {
			 flag = false;
			 this->stop();
		}
	}

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

int Server::getServerSocket() const {
	return serverSocket;
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

vector<Game> *Server::getGames() {
	return &this->games;
}
