/*
 * StartCommand.h
 *
 *  Created on: 25 בדצמ׳ 2017
 *       Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
 */

#ifndef STARTCOMMAND_H_
#define STARTCOMMAND_H_

#include "Command.h"
/**
 * this class represent a start command
 * this class inherit from Command class
 */

class StartCommand: public Command {
public:
	/**
	 * construct a start command from a given server
	 * @param server the given server
	 */
	StartCommand(Server &server);
	/**
     * this method execute the strar command
     * @param args the arguments to start the games
     * @return true of the name game is valid (not exist already)
     * @return false otherwise
     */
	bool execute(vector <string> args);
private:
	Server &s;
};

#endif /* STARTCOMMAND_H_ */
