/*
 * ListCommand.h
 *
 *  Created on: 20 בדצמ׳ 2017
 *      Author: noam
 */

#ifndef LISTCOMMAND_H_
#define LISTCOMMAND_H_
#include "Command.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

class ListCommand: public Command {

public:
	ListCommand(Server &server);
	virtual void execute(vector <string> args) {
		cout <<endl << "list commmmmand!!!!!!!!!!!" << endl;

		int clientsocket = atoi(args[args.size() - 1].c_str());
		args.pop_back();

		string names = "This is the list of games: \n";
		for (vector<string>::const_iterator it = s.gamesName.begin(); it != s.gamesName.end(); it++){
			names = names + *it +", ";
		}
		 const char * answer = names.c_str();
		 int l = strlen(answer);
		 write(clientsocket, &l, sizeof(l));
		 write(clientsocket, answer, l);

	}
private:
	Server &s;
};
ListCommand::ListCommand(Server &server): s(server){}

#endif /* LISTCOMMAND_H_ */



