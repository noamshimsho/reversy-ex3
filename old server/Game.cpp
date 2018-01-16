/*
 * Game.cpp
 *
 *  Created on: 25 בדצמ׳ 2017
 *       Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
 */

#include <unistd.h>
#include <sstream>
#include "Game.h"
#include "CommandsManager.h"
/**
 * this method make a turn for each player at a time
 * @param readPlayer the player to read from
 * @param writePlayer the player to write to
 * @param manager send to execute the command the write player write
 * @param game this game
 */
void playTurn(int readPlayer, int writePlayer, CommandsManager &manager, Game *game);

Game::Game(string gameName, int first) {
	  name = gameName;
	  firstClient = first;
    secondClient = 0;
    this->isWait = true;
    this->isFinish = false;
}
void Game::setIsFinish (bool finish) {
    this->isFinish = finish;
}
void Game::setIsWait (bool wait) {
    this->isWait = wait;
}
bool Game::getIsFinish () {
    return this->isFinish;
}
bool Game::getIsWait () {
    return this->isWait;
}
int Game::getFirstClient() const {
	return firstClient;
}

const string& Game::getName() const {
	return name;
}

int Game::getSecondClient() const {
	return secondClient;
}

void Game::setSecondClient(int secondClient) {
	this->secondClient = secondClient;
}

void Game::startGame () {
  CommandsManager manager = CommandsManager();
	int arg1, arg2, n, size;
	arg1 = 1;
	arg2 = 2;
	//send for each player his number- 1 or 2
	n = write(firstClient, &arg1, sizeof(arg1));
	if (n == -1) {
		cout << "error write arg1" << endl;
	}
	n = write(secondClient, &arg2, sizeof(arg2));
	if (n == -1) {
		cout << "error write arg2" << endl;
	}
	//read from the first player the board's size and write it to the second player
	n = read(firstClient, &size, sizeof(size));
	n = write(secondClient, &size, sizeof(size));
    //make the players turns
   while(true) {
       playTurn(this->getFirstClient(), this->getSecondClient(), manager, this);
       playTurn(this->getSecondClient(), this->getFirstClient(), manager, this);
      }

}
void playTurn(int readPlayer, int writePlayer, CommandsManager &manager, Game *game){
    int l;
    read(readPlayer, &l, sizeof(l)); //read the player's command(play or close)
    char *answer = new char[l + 1];
    read(readPlayer, answer, l);
    answer[l] = '\0';
    string please(answer);
    delete answer;
    string first_word;                    // string to vector (split)
    istringstream stm(please);
    vector<string> argv;
    string word;
    int flag = 1;
    while (stm >> word) {
        if (flag == 1) { //the first word is the command
            first_word = word;
            flag++;
        } else { //the other words is the arguments for the command
            argv.push_back(word);
        }
    }
    stringstream ss;          // convert  clientSocket to string and add it to argv
    ss << readPlayer;
    string client = ss.str();
    argv.push_back(client);
    stringstream ss1;
    ss1<< writePlayer;
    client = ss1.str();
    argv.push_back(client);
    if(first_word == "close"){
        game->setIsFinish(true);
    }
    //execute the writen command
    manager.executeCommand(first_word, argv);
}
