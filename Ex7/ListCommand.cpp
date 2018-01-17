//
//       Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
//



#include "ListCommand.h"

ListCommand::ListCommand(Server &server) : s(server) {}

bool ListCommand::execute(vector<string> args) {
    //the client to print the list is the last argument in the vector
    int clientsocket = atoi(args[args.size() - 1].c_str());
    args.pop_back();

    string names = "This is the list of games: \n";
    vector<Game> * g = s.getGames();
    //connect all the name of the games into a string
    for (vector<Game>::iterator it = g->begin(); it != g->end(); it++){
        if(it->getIsWait()) {
            names = names + it->getName() + "\n";
        }
    }
    //if there is no game write that
    if(!(g->size()>0)) {
        names = names+"there is no games";
    }
    const char * answer = names.c_str();
    int l = strlen(answer);
    write(clientsocket, &l, sizeof(l));
    write(clientsocket, answer, l);
    return true;
}
