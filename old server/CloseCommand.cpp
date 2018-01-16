//
// Created by sarit on 28/12/17.
// Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588


#include <cstdlib>
#include <unistd.h>
#include "CloseCommand.h"

CloseCommand::CloseCommand(){}

void CloseCommand::execute (vector<string> args) {


	// the first two aguments in the vector is the clients IDs
	int firstClient = atoi(args[0].c_str());
	int secondClient = atoi(args[1].c_str());

	//inform the cleint that he is going to be closed
	int arg = -1;

	write(secondClient, &arg, sizeof(arg));
	write(secondClient, &arg, sizeof(arg));
	//close the sockets
	close(firstClient);
	close(secondClient);

	//close the thread
	pthread_exit(NULL);
}
