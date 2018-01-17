//
//       Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
//

#include <cstdlib>
#include <unistd.h>
#include "PlayCommand.h"

PlayCommand::PlayCommand () {}

bool PlayCommand::execute (vector<string> args) {
    //write the column and row to the client
    int row = atoi(args[0].c_str());
    int col = atoi(args[1].c_str());
    int client = atoi(args[args.size()-1].c_str());
    write(client, &row, sizeof(row));
    write(client, &col, sizeof(col));
    return true;
}
