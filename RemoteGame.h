/*
 * RemoteGame.h
 *
 *  Created on: 5 בדצמ׳ 2017
 *      Author: noam
 */

#ifndef REMOTEGAME_H_
#define REMOTEGAME_H_

class RemoteGame {
public:
	RemoteGame(const char *serverIP, int serverPort);
	void connectToServer();
	void play(int row, int column);
private:
	const char*serverIP;
	int serverPort;
	int clientSocket;
	void writeToServer(int x, int y);
	Position readFromServer();
	void myTurn(int & counter, int &fullBoard, GameLogic &logic, Player* p1);
	void otherTurn(int & counter, int &fullBoard, GameLogic &logic, Player* p1);
	void endGame(Board &board);

};

#endif /* REMOTEGAME_H_ */
