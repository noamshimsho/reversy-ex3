/*
 * CommandsManager.h
 *
 *  Created on: 20 בדצמ׳ 2017
 *       Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
 */

#ifndef COMMANDSMANAGER_H_
#define COMMANDSMANAGER_H_
#include <map>
#include "Command.h"
/**
 * this class represent command manager
 */
class CommandsManager {
public:
	/**
	 * constructor for commands who don't need the server
	 */
	CommandsManager();
	/**
	 * constructor for commands who need the server
	 * @param s the server for the commands
	 */
	CommandsManager(Server &s);
	/**
	 * distruct the commnd manager
	 */
	~CommandsManager();
	/**
	 * this method send the commands to their executers
	 * @param command the command to execute
	 * @param args the aguments to execute the command
	 */
	bool executeCommand(string command, vector<string> args);
private:
	map<string, Command *> commandsMap;
};

#endif /* COMMANDSMANAGER_H_ */
