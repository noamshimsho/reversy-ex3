/*
 * main.cpp
 *
 *  Created on: 27 בנוב׳ 2017
 *       Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
 */

#include "Server.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <pthread.h>
#include <sstream>
#include <iterator>
using namespace std;
/**
 * this class represent the main class
 */
/**
 * this is the main method
 * it read from the protocol file and start the connection
 * @return zero to end
 */
int main() {
	//read the port from the file
	int port;
	ifstream inFile;
	inFile.open("protocol.txt");
	if (inFile.is_open() == false){
		exit(1);
	}
	inFile >> port;
	Server server(port);
	inFile.close();

	//start the connection
	try {
		server.start();
	} catch (const char *msg) {
		cout << "cannot start server. Reason: " << msg << endl;
	}
	//server.stop();
	return 0;
}
