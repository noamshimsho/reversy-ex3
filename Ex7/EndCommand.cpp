//
// Created by sarit on 28/12/17.
// Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588


#include <cstdlib>
#include <unistd.h>
#include "EndCommand.h"

EndCommand::EndCommand(){}

bool EndCommand::execute (vector<string> args) {

    // the first two aguments in the vector is the clients IDs
    int firstClient = atoi(args[0].c_str());
    int secondClient = atoi(args[1].c_str());

    //close the sockets
    close(firstClient);
    close(secondClient);
    //cout << " end command!!!!\n";
    //close the thread
    //pthread_exit(NULL);
    return false;

}
