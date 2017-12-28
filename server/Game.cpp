/*
 * Game.cpp
 *
 *  Created on: 25 בדצמ׳ 2017
 *      Author: noam
 */

#include <unistd.h>
#include "Game.h"

Game::Game(string gameName, int first) {
	name = gameName;
	firstClient = first;
    secondClient = 0;
	wait = true;
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

bool Game::isWait() const {
	return wait;
}

void Game::setWait(bool wait) {
	this->wait = wait;
}

void Game::startGame () {
	 //const char * answer = "you are the ";
	 //int l = strlen(answer);
	 //write(clientsocket, &l, sizeof(l));
	 //write(clientsocket, answer, l);
    cout<<"in start game"<<endl;
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
    cout<<"board's size: "<<size<<endl;
	n = write(secondClient, &size, sizeof(size));
}
