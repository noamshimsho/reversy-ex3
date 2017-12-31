/*
 * ListCommand.cpp
 *
 *  Created on: 29 בדצמ׳ 2017
 *      Author: noam
 */

#include "ListCommand.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
ListCommand::ListCommand(Server &server): s(server){}

void  ListCommand:: execute(vector <string> args) {

	int clientsocket = atoi(args[args.size() - 1].c_str());
	args.pop_back();

	string names = "This is the list of games: \n";
  int length = names.length()+4;
  pthread_mutex_lock(&m1);
	vector<Game> * g = s.getGames();
	for (vector<Game>::iterator it = g->begin(); it != g->end(); it++){
		if(it->getWait()){
			names = names + it->getName() +"\n";
		}
		if (it->getfinish()) {
			g->erase(it);
		}
	}
	pthread_mutex_unlock(&m1);
    if(names.length() < length){
        names = names+"there is no games";
    }
	 const char * answer = names.c_str();
	 int l = strlen(answer);
	 write(clientsocket, &l, sizeof(l));
	 write(clientsocket, answer, l);

}
