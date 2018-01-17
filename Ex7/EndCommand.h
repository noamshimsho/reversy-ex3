/*
 * EndCommand.h
 *
 *  Created on: 1 בינו׳ 2018
 *      Author: noam
 */

#ifndef ENDCOMMAND_H_
#define ENDCOMMAND_H_

#include "Command.h"
/**
 * this class represents End game command
 * this class inherit from Command class
 */
class EndCommand: public Command {
public:
	EndCommand();
	   /**
	  * this method execute the end command
	  * @param args the arguments to close with
	     */
	 bool execute(vector <string> args);
};

#endif /* ENDCOMMAND_H_ */
