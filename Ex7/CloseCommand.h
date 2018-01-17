/**
 * Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
 */
#ifndef SERVER_CLOSECOMMAND_H
#define SERVER_CLOSECOMMAND_H


#include "Command.h"
/**
 * this class represents close command
 * this class inherit from Command class
 */
class CloseCommand : public Command{

public:
    /**
     * defualt constructor
     */
    CloseCommand();
    /**
     * this method execute the close command
     * @param args the arguments to close with
     */
    bool execute(vector <string> args);
};


#endif //SERVER_CLOSECOMMAND_H
