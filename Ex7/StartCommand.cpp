/*
 * StartCommand.cpp
 *
 *  Created on: 25 בדצמ׳ 2017
 *       Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
 */

#include "StartCommand.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
StartCommand::StartCommand(Server &server) :s(server) {}

bool StartCommand::execute(vector<string> args) {
	bool flag = true;
	//the client who strat is the last argument in the vector
	int clientsocket = atoi(args[args.size() - 1].c_str());
	args.pop_back();
	//the name of the requested game to start
	string name = args[0];
	//checking if the asked name to start the game is valid (not exist already)
	for (vector<Game>::iterator it = s.getGames()->begin(); it != s.getGames()->end(); it++){
		//if the name isn't valid

		if(name == it->getName() && it->getIsWait()){
			//send to the client -1 which means wrong name
			const char * answer  = "-1";
			int l = strlen(answer);
			write(clientsocket, &l, sizeof(l));
			write(clientsocket, answer, l);
			flag = false;
			return true;
		}
	}
	if (flag){
	//if the name is valid create a game with that name
    Game g(name, clientsocket);
    s.getGames()->push_back(g);
	//send message that the player should wait for another player to connect
    const char * answer = "waiting for another player...";
    int l = strlen(answer);
    write(clientsocket, &l, sizeof(l));
    write(clientsocket, answer, l);
    int status;
	//close the thread
    return false;
    //pthread_exit(&status);
	}
}
