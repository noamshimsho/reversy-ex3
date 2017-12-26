/*
 * JoinCommand.h
 *
 *  Created on: 25 בדצמ׳ 2017
 *      Author: noam
 */

#ifndef JOINCOMMAND_H_
#define JOINCOMMAND_H_

#include "Command.h"

class JoinCommand: public Command {
public:
	JoinCommand(Server &server);
	void execute(vector <string> args);
private:
	Server &s;
};

#endif /* JOINCOMMAND_H_ */
