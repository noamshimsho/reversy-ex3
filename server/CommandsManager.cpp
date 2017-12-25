/*
 * CommandsManager.cpp
 *
 *  Created on: 20 בדצמ׳ 2017
 *      Author: noam
 */

#include "CommandsManager.h"
#include "ListCommand.h"
CommandsManager::CommandsManager(){}
CommandsManager::CommandsManager(Server &s) {
	commandsMap["list_games"] = new ListCommand(s);
}
void CommandsManager::executeCommand(string command,vector<string> args) {
	Command *commandObj = commandsMap[command];
	 commandObj->execute(args);
}
CommandsManager::~CommandsManager() {
	map<string, Command *>::iterator it;
	for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
		delete it->second;
	}
}

