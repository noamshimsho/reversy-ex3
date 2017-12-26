/*
 * StartCommand.h
 *
 *  Created on: 25 בדצמ׳ 2017
 *      Author: noam
 */

#ifndef STARTCOMMAND_H_
#define STARTCOMMAND_H_

#include "Command.h"

class StartCommand: public Command {
public:
	StartCommand(Server &server);
	void execute(vector <string> args);
private:
	Server &s;
};

#endif /* STARTCOMMAND_H_ */
