//
// Created by sarit on 28/12/17.
//

#include <sstream>
#include <cstdlib>
#include "RemotePlayer.h"
RemotePlayer::RemotePlayer(discSymbol name): Player(name) {}

Position RemotePlayer::playTurn (GameLogic logic, vector<Position> &moves) const {
    cout << endl<< "player: " << (char)player<<" your possible moves are: ";
    for (unsigned int i = 0; i < moves.size(); i++) {
        cout << moves[i] << " ";
    }
    cout << endl;
    string command, row, col;
    int r, c;
    while(true) {
        cout << "please enter your move (play <x, y>): ";
        getline(cin, command);
        istringstream stm(command);
        vector<string> argv;
        string word;
        while (stm >> word) {
            argv.push_back(word);
        }
        if(argv[0] == "play"){
            r = atoi(argv[1].c_str());
            c = atoi(argv[2].c_str());

            Position p(r, c); // the position the player enter
            for (unsigned int i = 0; i < moves.size(); i++) {  // check that this position is equal to one of his options
                if (p == moves[i]) {
                    return p;
                }
            }
        } else if(argv[0] == "close"){
            Position p(-1, -1);
            return p;
        } else{
            cout << "wrong input try again!! " << endl;
        }

    }

}