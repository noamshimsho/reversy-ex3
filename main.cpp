// Noam shimshoviz 203565429


#include "GameFlow.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "AIplayer.h"

int main() {
    int choise, size;
    cout<<"Please enter size of board: ";
    cin>>size;
    GameFlow game(size, size);

    bool flag = true;
    Player *p1 = new HumanPlayer('x');
    while (flag) {
        cout << "Press 1 if you want to play against AI player, ";
        cout<<"press 2 if you want to play against human player: ";
        cin >> choise;
        flag = false;
        if((choise != 1) && (choise !=2)) {
            flag = true;
        }
    }
    if (choise == 1) {
        Player *p2 = new AIplayer('0');
        game.play(p1, p2);
        delete p2;
    } else if (choise == 2) {
        Player *p2 = new HumanPlayer('0');
        game.play(p1, p2);
        delete p2;
    }
    delete p1;

    return 0;
}