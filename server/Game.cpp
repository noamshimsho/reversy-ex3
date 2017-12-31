/*
 * Game.cpp
 *
 *  Created on: 25 בדצמ׳ 2017
 *      Author: noam
 */

#include <unistd.h>
#include <sstream>
#include "Game.h"
#include "CommandsManager.h"
void playTurn(int readPlayer, int writePlayer, CommandsManager &manager, Game *g);

Game::Game(string gameName, int first) {
	name = gameName;
	firstClient = first;
  secondClient = 0;
  isWait = true;
  isFinish = false;
}

int Game::getFirstClient() const {
	return firstClient;
}

void Game::setFirstClient(int firstClient) {
	this->firstClient = firstClient;
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
	//read and write the second player the board's size
	n = read(firstClient, &size, sizeof(size));
	n = write(secondClient, &size, sizeof(size));
    while(true) {
        playTurn(this->getFirstClient(), this->getSecondClient(), manager, this);
        playTurn(this->getSecondClient(), this->getFirstClient(), manager, this);
    }


}
void playTurn(int readPlayer, int writePlayer, CommandsManager &manager, Game *g){
    int l;
    cout<<"in play turn"<<endl;
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
        if (flag == 1) {
            first_word = word;
            flag++;
        } else {
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
    if (first_word == "close" ) {
    	  g->setIsfinish(true);
    }
    manager.executeCommand(first_word, argv);

}

bool Game::getfinish() const {
	return isFinish;
}

void Game::setIsfinish(bool isfinish) {
	this->isFinish = isfinish;
}

bool Game::getWait() const {
	return isWait;
}

void Game::setIsWait(bool isWait) {
	this->isWait = isWait;
}
