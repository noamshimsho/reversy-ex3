/*
 * Server.h
 *
 *  Created on: 27 בנוב׳ 2017
 *       Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <vector>
#include <string>
#include "Game.h"
using namespace std;
class Server {


public:
    /*
     * construct the server from a given integer
     * @param port the port of the server
     */
	Server(int port);
    /*
     * start the connection
     */
	void start();
    /*
   * close the connection
     */
	void stop();

	void deleteName (string &name);
	vector <string> gamesName;
	vector <Game> *getGames();
	int getServerSocket() const;

private:
	int port;
	int serverSocket;
	vector <Game> games;


    /*
     * this method read the first player move and write it to the second player and vice versa
     */
	void handleClient(int clinetSocket, int otherSocket);
};

#endif /* SERVER_H_ */
