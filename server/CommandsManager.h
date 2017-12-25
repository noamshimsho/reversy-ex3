/*
 * CommandsManager.h
 *
 *  Created on: 20 בדצמ׳ 2017
 *      Author: noam
 */

#ifndef COMMANDSMANAGER_H_
#define COMMANDSMANAGER_H_
#include <map>
#include "Command.h"
class CommandsManager {
public:
	CommandsManager();
	CommandsManager(Server &s);
	~CommandsManager();
	void executeCommand(string command, vector<string> args);
private:
	map<string, Command *> commandsMap;
};

#endif /* COMMANDSMANAGER_H_ */
