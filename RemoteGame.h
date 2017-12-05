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
};

#endif /* REMOTEGAME_H_ */
