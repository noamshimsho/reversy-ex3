/*
 * Command.h
 *
 *  Created on: 20 בדצמ׳ 2017
 *      Author: noam
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include <vector>
#include <string>
#include "Server.h"
using namespace std;

class Command {
public:
	virtual void execute(vector<string> args) = 0;
	virtual ~Command() {}
	pthread_mutex_t m1;
};



#endif /* COMMAND_H_ */
