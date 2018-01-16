/*
 * RemoteGame.h
 *
 *  Created on: 5 בדצמ׳ 2017
 *      Author: Noam shimshoviz 203565429 Sarit Zevin 313242588
 */

#ifndef REMOTEGAME_H_
#define REMOTEGAME_H_

class RemoteGame {
public:
	/*
	 * construct a remote game according to a given const char* and int
	 * which represents the server's IP and port
	 */
	RemoteGame(const char *serverIP, int serverPort);
	/*
	 * connecting to the server
	 */
	void connectToServer();
    /*
     * this method play the remote game
     */
	void play();
	string sendCommands(string command);
private:
	const char*serverIP;
	int serverPort;
	int clientSocket;
    /*
     * this method write to the server two integers
     * @param x- the first integer to write
     * @param y- the second integer to write
     */
	void writeToServer(int x, int y);
    /*
     * this method read from the server twice
     * @return Position of two cordinate that made from the two reading
     */
	Position readFromServer();
    /*
     * make the first player turns and write his moves to the other player
     * @param counter, check if both of the players can't do any move
     * @param fullBoard, chech if the board is full
     * @param logic the rules of the game
     * @param p1 the player that make the turn
     */
	void myTurn(int & counter, int &fullBoard, GameLogic &logic, Player* p1);
    /*
     * update the board according to moves the first player write
     * @param counter, check if both of the players can't do any move
     * @param fullBoard, chech if the board is full
     * @param logic the rules of the game
     * @param p1 the player that make the turn
     */
	void otherTurn(int & counter, int &fullBoard, GameLogic &logic, Player* p1);
    /*
     * this method finish the game of the given board
     * @param board- the board to finish the game from
     * @param tag- the player's number to announce the winning
     */
	void endGame(Board &board, int tag);
	/**
	 * close the socket if the server quit
	 * @param n the integer that announce if the server quti
	 */
	void quitServer(int n);

};

#endif /* REMOTEGAME_H_ */
