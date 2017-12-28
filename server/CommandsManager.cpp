/*
 * CommandsManager.cpp
 *
 *  Created on: 20 בדצמ׳ 2017
 *      Author: noam
 */

#include "CommandsManager.h"
#include "ListCommand.h"
#include "StartCommand.h"
#include "JoinCommand.h"
#include "CloseCommand.h"
#include "PlayCommand.h"

CommandsManager::CommandsManager () {
    commandsMap["close"] = new CloseCommand();
    commandsMap["play"] = new PlayCommand();
}

CommandsManager::CommandsManager(Server &s) {
	commandsMap["list_games"] = new ListCommand(s);
	commandsMap["start"] = new StartCommand(s);
    commandsMap["join"] = new JoinCommand(s);
}
void CommandsManager::executeCommand(string command,vector<string> args) {
	Command *commandObj = commandsMap[command];
    cout<<"command: "<<command<<endl;
	 commandObj->execute(args);
}
CommandsManager::~CommandsManager() {
	map<string, Command *>::iterator it;
	for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
		delete it->second;
	}
}