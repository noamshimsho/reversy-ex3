/*
 * Command.h
 *
 *  Created on: 20 בדצמ׳ 2017
 *  Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include <vector>
#include <string>
#include "Server.h"
using namespace std;
/**
 * this class represent a command
 */
class Command {
public:
	/**
	 * this method execute the command
	 * @param args the argument to be used when executing the command
	 */
	virtual bool execute(vector<string> args) = 0;
	/**
	 * defualt destructor
	 */
	virtual ~Command() {}
};



#endif /* COMMAND_H_ */
