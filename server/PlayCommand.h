//
//       Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
//

#ifndef SERVER_PLAYCOMMAND_H
#define SERVER_PLAYCOMMAND_H
#include "Command.h"
/**
 * this class represent play command
 * this class inherit from Command class
 */
class PlayCommand  : public Command{

public:
    /**
     * default constructor
     */
    PlayCommand();
    /**
     * this method execute the play command
     * @param args the arguments to make a turn in the game-
     * the row and column
     */
    void execute(vector <string> args);
};


#endif //SERVER_PLAYCOMMAND_H
