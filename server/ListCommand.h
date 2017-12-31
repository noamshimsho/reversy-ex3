/*
 * ListCommand.h
 *
 *  Created on: 29 בדצמ׳ 2017
 *      Author: noam
 */

#ifndef LISTCOMMAND_H_
#define LISTCOMMAND_H_

#include "Command.h"

class ListCommand: public Command {
public:
	ListCommand(Server &server);
	virtual void execute(vector <string> args);
private:
	Server &s;

};

#endif /* LISTCOMMAND_H_ */







