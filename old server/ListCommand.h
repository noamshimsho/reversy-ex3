/*
 * ListCommand.h
 *
 *  Created on: 20 בדצמ׳ 2017
 *       Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
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
/**
 * this class represent list command
 * this class inherit from Command class
 */
class ListCommand: public Command {
public:
	/**
	 * construct a list command from a given server
	 * @param server the given server
	 */
	ListCommand(Server &server);
	/**
     * this method execute the list command
     * @param args the arguments to list the games
     */
    void execute(vector <string> args);
private:
	Server &s;
};

#endif /* LISTCOMMAND_H_ */