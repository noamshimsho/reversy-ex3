/*
 * Game.h
 *
 *  Created on: 25 בדצמ׳ 2017
 *      Author: noam
 */
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
#ifndef GAME_H_
#define GAME_H_

class Game {
public:
	Game(string gameName, int first);
	int getFirstClient() const;
	void setFirstClient(int firstClient);
	const string& getName() const;
	int getSecondClient() const;
	void setSecondClient(int secondClient);
	void startGame ();

private:
	int firstClient;
	int secondClient;
	string name;
};

#endif /* GAME_H_ */
