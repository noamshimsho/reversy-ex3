/*
 * Game.cpp
 *
 *  Created on: 25 בדצמ׳ 2017
 *      Author: noam
 */

#include "Game.h"

Game::Game(string gameName, int first) {
	name = gameName;
	firstClient = first;
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

void Game::startGAME() {
	 //const char * answer = "you are the ";
	 //int l = strlen(answer);
	 //write(clientsocket, &l, sizeof(l));
	 //write(clientsocket, answer, l);













}
