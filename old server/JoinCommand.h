/*
 * JoinCommand.h
 *
 *  Created on: 25 בדצמ׳ 2017
 *       Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
 */

#ifndef JOINCOMMAND_H_
#define JOINCOMMAND_H_

#include "Command.h"
/**
 * this class represent a join command
 * this class inherit from Command class
 */
class JoinCommand: public Command {
public:
	/**
	 * construct a join command from a given server
	 * @param server the given server
	 */
	JoinCommand(Server &server);
	/**
     * this method execute the join command
     * @param args the arguments to join with
     */
	void execute(vector <string> args);
private:
	Server &s;
};

#endif /* JOINCOMMAND_H_ */
