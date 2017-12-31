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
    string message = "closing the socket";
    const char* c = message.c_str();
    int l = strlen(c);
    write(firstClient, &l, sizeof(l));
    write(firstClient, c, l);
    write(secondClient, &l, sizeof(l));
    write(secondClient, c, l);
    //close the sockets
    close(firstClient);
    close(secondClient);
    int status;
    //close the thread
    pthread_exit(&status);

}