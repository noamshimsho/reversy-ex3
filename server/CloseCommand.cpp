//
// Created by sarit on 28/12/17.
//

#include <cstdlib>
#include <unistd.h>
#include "CloseCommand.h"

CloseCommand::CloseCommand(){}

void CloseCommand::execute (vector<string> args) {
    int firstClient = atoi(args[0].c_str());
    int secondClient = atoi(args[1].c_str());
    string message = "closing the socket";
    const char* c = message.c_str();
    int l = strlen(c);
    write(firstClient, &l, sizeof(l));
    write(firstClient, c, l);
    write(secondClient, &l, sizeof(l));
    write(secondClient, c, l);
    close(firstClient);
    close(secondClient);
    int status;
    pthread_exit(&status);

}