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
#include "ThreadPool.h"
using namespace std;
/**
 * this class repersent a server
 */
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

	/**
	 * @return vector with the list of games
	 */
	vector <Game> *getGames();
	/**
	 * @return the number of the server socket
	 */
	int getServerSocket() const;
	 vector<pthread_t*>& getV1();

private:
	int port;
	int serverSocket;
	vector <Game> games;
	ThreadPool * pool;


};

#endif /* SERVER_H_ */
