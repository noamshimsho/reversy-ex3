//
// Created by sarit on 28/12/17.
//

#ifndef SERVER_CLOSECOMMAND_H
#define SERVER_CLOSECOMMAND_H


#include "Command.h"

class CloseCommand : public Command{

public:
    CloseCommand();
    void execute(vector <string> args);
};


#endif //SERVER_CLOSECOMMAND_H
