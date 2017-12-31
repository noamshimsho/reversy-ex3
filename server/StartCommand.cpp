/*
 * StartCommand.cpp
 *
 *  Created on: 25 בדצמ׳ 2017
 *      Author: noam
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

void StartCommand::execute(vector<string> args) {

	cout <<endl << "Start command !!!!!!!!!!!" << endl;

	int clientsocket = atoi(args[args.size() - 1].c_str());
	args.pop_back();
	string name = args[0];
	pthread_mutex_lock(&m1);
	for (vector<string>::const_iterator it = s.gamesName.begin(); it != s.gamesName.end(); it++){
		if(name == *it){
			const char * answer  = "-1";
			int l = strlen(answer);
			write(clientsocket, &l, sizeof(l));
			write(clientsocket, answer, l);
		}
	}
	pthread_mutex_unlock(&m1);
  Game g(name, clientsocket);
  s.getGames()->push_back(g);
  const char * answer = "waiting for another player...";
  int l = strlen(answer);
  write(clientsocket, &l, sizeof(l));
  write(clientsocket, answer, l);

  int status;
  pthread_exit(&status);
}
