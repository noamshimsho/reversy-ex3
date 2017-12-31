/*
 * Game.h
 *
 *  Created on: 25 בדצמ׳ 2017
 *       Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
 */
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
#ifndef GAME_H_
#define GAME_H_
/**
 * this class represent a game
 */
class Game {
public:
    /**
     * construct a game from given string and integer
     * @param gameName the name of the game
     * @param first the first client who connect the game
     */
	Game(string gameName, int first);
    /**
     * @return the first client
     */
	int getFirstClient() const;
    /**
     * @return the name of the game
     */
	const string& getName() const;
    /**
     * @return the second client to connect
     */
	int getSecondClient() const;
    /**
     * set the second client to connect
     * @param secondClient the integer to set
     */
	void setSecondClient(int secondClient);
    /**
     * this method start the game
     */
	void startGame ();
    /**
     * @return true if the game is waiting (only one client connect)
     * false otherwise
     */
    bool getIsWait();
    /**
     * @return true if the game is finish, false otherwise
     */
    bool getIsFinish();
    /**
     * set wait (according to the amount of player to connect)
     * @param wait the boolean to set
     */
    void setIsWait(bool wait);
    /**
     * set finish when the game is finisj
     * @param finish the boolean to set
     */
    void setIsFinish(bool finish);

private:
	int firstClient;
	int secondClient;
	string name;
    int isWait;
    int isFinish;
};

#endif /* GAME_H_ */
