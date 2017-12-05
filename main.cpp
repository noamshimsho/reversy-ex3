// Noam shimshoviz 203565429 Sarit Zevin 313242588


#include "GameFlow.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "AIplayer.h"
#include "RemoteGame.h"
#include <stdlib.h>

int main() {
    // get the size of board from the user.
    int  size;
    bool flag;
		string s;
		do {
		cout << "Please enter even size of board: " << endl ;
		getline(cin, s);
		size = atoi(s.c_str());
		if (size > 0 && size%2 == 0){
			flag = false;
		} else {
			cout << "wrong input try again"<<endl;
			flag = true;
		}
		} while (flag);

   // the user choose against which to play. 


		string a = "1";
		string b = "2";
		string c = "3";
    string choise;
    flag = true;
    while (flag) {
        cout << "Press 1 if you want to play against AI player, " << endl;
        cout<<"press 2 if you want to play against human player: " << endl;
        cout<<"press 3 if you want to play remote game: " << endl;
        getline(cin, choise);
        flag = false;

        if((choise != a) && (choise != b) && (choise != c)) {
            flag = true;
            cout << "try again" << endl;
        }
    } 
   // build the game with the choosen board and players and start the game.


    if (choise == a) {
    		GameFlow game(size, size);
    		Player *p1 = new HumanPlayer(X) ;
        Player *p2 = new AIplayer(O);
        game.play(p1, p2);
        delete p2;
        delete p1;
    } else if (choise == b) {
    		GameFlow game(size, size);
    		Player *p1 = new HumanPlayer(X) ;
        Player *p2 = new HumanPlayer(O);
        game.play(p1, p2);
        delete p2;
        delete p1;
    }	else if (choise == c) {
    		RemoteGame remote ("127.0.0.1", 8005);
    		try {
    			remote.connectToServer();
    		} catch (const char *msg) {
    				cout << "failed connect to server. Reason: " << msg << endl;
    			}
    		remote.play(size, size);

}

    return 0;
}
