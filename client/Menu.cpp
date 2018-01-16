//
// Author: Noam shimshoviz 203565429 Sarit Zevin 313242588
//

#include "Menu.h"
#include "GameFlow.h"
#include "HumanPlayer.h"
#include "AIplayer.h"
#include "RemoteGame.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

Menu::Menu() {}

void Menu::chooseFromMenu() {
    // get the size of board from the user.
    int size;
    bool flag = true;
    string s, a = "1", b = "2", c = "3";
    string choise;
    // the user choose which game he want to play.
    while (flag) {
        cout << "Press 1 if you want to play against AI player, " << endl;
        cout << "press 2 if you want to play against human player: " << endl;
        cout << "press 3 if you want to play remote game: " << endl;
        getline(cin, choise);
        if (choise == a || choise == b || choise == c) {
            flag = false;
        } else{
            cout << "wrong input try again" << endl;
        }
    }
    if (choise == a || choise == b) {
        //make sure that the size of the board is even
        do {
            cout << "Please enter even size of board: " << endl;
            getline(cin, s);
            size = atoi(s.c_str());
            if (size > 0 && size % 2 == 0) {
                flag = false;
            } else {
                cout << "wrong input try again" << endl;
                flag = true;
            }
        } while (flag);
    }
    this->startGame(atoi(choise.c_str()), size);
}
void Menu::startGame(int choise, int size) {
    //creating game against AI player
    if (choise == 1) {
        GameFlow game(size, size);
        Player *p1 = new HumanPlayer(X) ;
        Player *p2 = new AIplayer(O);
        game.play(p1, p2);
        delete p2;
        delete p1;
        //creating game against human player
    } else if (choise == 2) {
        GameFlow game(size, size);
        Player *p1 = new HumanPlayer(X) ;
        Player *p2 = new HumanPlayer(O);
        game.play(p1, p2);
        delete p2;
        delete p1;
        //creating remote game
    } else if (choise == 3) {
    	int port;
    	string IP;
    	const char* ip;
    	ifstream inFile;
    	inFile.open("clientProtocol.txt");
    	inFile >> IP;
    	inFile >> port;
    	inFile.close();
    	ip = IP.c_str();
    	RemoteGame remote (ip, port);
    	try {
    	   remote.connectToServer();
        } catch (const char *msg) {
    	    cout << "failed connect to server. Reason: " << msg << endl;
        }
    	  //remote.play();
    }
}
