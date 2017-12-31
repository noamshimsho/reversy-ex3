/*
 * JoinCommand.cpp
 *
 *  Created on: 25 בדצמ׳ 2017
 *      Author: noam
 */

#include "JoinCommand.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>




JoinCommand::JoinCommand(Server &server) :s(server) {}

void JoinCommand::execute(vector<string> args) {


	bool flag = true;
  cout<<"in join"<<endl;
	int clientsocket = atoi(args[args.size() - 1].c_str());
	args.pop_back();
	string name = args[0];
	pthread_mutex_lock(&m1);
	vector<Game> * g = s.getGames();
	for (vector<Game>::iterator it = g->begin(); it != g->end(); it++){
		if(it->getName()  == name && it->getWait()){
			flag = false;
			it->setSecondClient(clientsocket);
			it->setIsWait(false);
			pthread_mutex_unlock(&m1);
      const char * answer = "Welcome to the game";
      int l = strlen(answer);
      write(clientsocket, &l, sizeof(l));
      write(clientsocket, answer, l);
			it->startGame();
		}
	}
	pthread_mutex_unlock(&m1);
	if (flag) {
			const char * answer = "-1";
			int l = strlen(answer);
			write(clientsocket, &l, sizeof(l));
		  write(clientsocket, answer, l);

	}
	    cout << "why im here........." << endl;
}
