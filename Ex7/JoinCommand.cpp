/*
 * JoinCommand.cpp
 *
 *  Created on: 25 בדצמ׳ 2017
 *       Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
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

bool JoinCommand::execute(vector<string> args) {
  //the client to join is the last argument in the vector
	int clientsocket = atoi(args[args.size() - 1].c_str());
	args.pop_back();
	string name = args[0];
  bool flag = true;
	vector<Game> * g = s.getGames();
    //checking if the asked to join game is valid
	for (vector<Game>::iterator it = g->begin(); it != g->end(); it++){
        //if the name is valid it send the client to start the game
		if(it->getName()  == name && it->getIsWait()) {
            flag = false;
            it->setSecondClient(clientsocket); //set the second client to connect the game
            it->setIsWait(false); //set wait to false becuase there is two players in the game now
            const char *answer = "Welcome to the game";
            int l = strlen(answer);
            //write to the client welcome
            write(clientsocket, &l, sizeof(l));
            write(clientsocket, answer, l);
            it->startGame();
            cout << " join command after start game!!!!!!\n";
            return false;
        }
	}
    //if the name isn't valid
    if (flag){
        const char * answer = "-1";
        int l = strlen(answer);
        //send to the client -1 which means wrong name
        write(clientsocket, &l, sizeof(l));
        write(clientsocket, answer, l);
        return true;
    }
}
