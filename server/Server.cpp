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
#include <signal.h>


#define MAX 10

Server::Server(int port): port(port), serverSocket(0){
	cout << "server "<< endl;
}

struct ThreadArgs {
	int client;
	CommandsManager manager;
};

static void * clientHandle (void * tArgs){
     struct ThreadArgs *args = (struct ThreadArgs *) tArgs;
     long clientSocket = args-> client;
     while(true) {
        int l;
        read(clientSocket, &l, sizeof(l));
        char *answer = new char[l + 1];
        read(clientSocket, answer, l);
        answer[l] = '\0';
        string please(answer);
        delete answer;
        string first_word;                    // string to vector (split)
        istringstream stm(please);
        vector<string> argv;
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
        stringstream ss;          // convert  clientSocket to string and add it to argv
        ss << clientSocket;
        string client = ss.str();
        argv.push_back(client);
        args->manager.executeCommand(first_word, argv);
    }
}

static void * acceptHandle (void * tArgs){
    Server *s = (Server *)tArgs;
    //vector <pthread_t*> v1;
    vector <ThreadArgs*> v2;
    int i = 0;

    CommandsManager m (*s);
    while (true) {
        struct sockaddr_in clientAddress;
        socklen_t clientAddressLen;
        cout << "wait............."<<endl;
        int clientSocket = accept(s->getServerSocket(), (struct sockaddr *)&clientAddress, &clientAddressLen);
        if (clientSocket == -1) {
            throw "error on accept player";
        }

        s->getV1().push_back(new pthread_t);
        v2.push_back(new ThreadArgs);
        v2[i]->client = clientSocket;
        v2[i]->manager = m;
        int rc;
        rc = pthread_create(s->getV1()[i], NULL,clientHandle,v2[i]);
        if (rc) {
            cout << "bad!!!!";
        }
        i++;
    }
    //v1.clear();
    v2.clear();
}

void Server::stop() {
	cout << "close server socket" << endl;
   vector<Game> * g = this->getGames();
   for (vector<Game>::iterator it = g->begin(); it != g->end(); it++){
        if(it->getIsWait()) {
            close(it->getFirstClient());
        } else {
            close(it->getFirstClient());
            close(it->getSecondClient());
        }
    }
  this->getGames()->clear();
  this->getV1().clear();
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

int Server::getServerSocket() const {
	return serverSocket;
}

vector<Game> *Server::getGames() {
	return &this->games;
}

vector<pthread_t*>& Server::getV1()  {
	return v1;
}
