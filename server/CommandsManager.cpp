/*
 * CommandsManager.cpp
 *
 *  Created on: 20 בדצמ׳ 2017
 *       Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
 */
#include "CommandsManager.h"
#include "ListCommand.h"
#include "StartCommand.h"
#include "JoinCommand.h"
#include "CloseCommand.h"
#include "PlayCommand.h"
#include "EndCommand.h"

CommandsManager::CommandsManager () {
  commandsMap["close"] = new CloseCommand();
  commandsMap["play"] = new PlayCommand();
  commandsMap["end"] = new EndCommand();

}

CommandsManager::CommandsManager(Server &s) {
	commandsMap["list_games"] = new ListCommand(s);
	commandsMap["start"] = new StartCommand(s);
  commandsMap["join"] = new JoinCommand(s);
}
void CommandsManager::executeCommand(string command,vector<string> args) {
	Command *commandObj = commandsMap[command];
    commandObj->execute(args);
}
CommandsManager::~CommandsManager() {
	map<string, Command *>::iterator it;
    //delete the map
	for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
		delete it->second;
	}
}
