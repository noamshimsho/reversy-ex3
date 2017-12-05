/*
 * Server.h
 *
 *  Created on: 27 בנוב׳ 2017
 *      Author: noam
 */

#ifndef SERVER_H_
#define SERVER_H_


class Server {

public:
	Server(int port);
	void start();
	void stop();

private:
	int port;
	int serverSocket;

	void handleClient(int clinetSocket, int client2Socket);




};




#endif /* SERVER_H_ */
