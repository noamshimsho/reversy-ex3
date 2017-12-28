//
// Created by sarit on 28/12/17.
//

#include <cstdlib>
#include <unistd.h>
#include "PlayCommand.h"

PlayCommand::PlayCommand () {}
void PlayCommand::execute (vector<string> args) {
    cout<<"in play command/ execute"<<endl;
    int row = atoi(args[0].c_str());
    int col = atoi(args[1].c_str());
    int client = atoi(args[args.size()-1].c_str());
    write(client, &row, sizeof(row));
    write(client, &col, sizeof(col));
}