/*
 * main.cpp
 *
 *  Created on: 27 בנוב׳ 2017
 *      Author: noam
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

using namespace std;

int main() {
	int port;
	ifstream inFile;
	inFile.open("protocol.txt");
	if (inFile.is_open() == false){
		exit(1);
	}
	inFile >> port;
	cout << port  << endl;
	Server server(port);
	inFile.close();


	//server.start();

	try {
		server.start();
	} catch (const char *msg) {
		cout << "cannot start server. Reason: " << msg << endl;
	}
	server.stop();

	/*
	int sockfd, newsockfd, portno;
	socklen_t clilen;
	char buffer[256];
	struct sockaddr_in serv_addr,cli_addr;
	int n;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0) {
		cout << "error opening socket";
		exit(1);
	}

	bzero((char *)&serv_addr, sizeof(serv_addr));
	portno = 8002;
	serv_addr.sin_family =AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		cout << "error on binding";
		exit(1);
	}

	listen(sockfd, 10);
	clilen = sizeof(cli_addr);

	newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr, &clilen);


	if (newsockfd < 0) {
		cout << "error on accept";
		exit(1);
	}



bzero(buffer, 256);
n = read(newsockfd,buffer,255);

if ( n<0) {
	cout << "error on read";
exit(1);
}
cout << buffer;

n = write(newsockfd,"gv05", 4);
if ( n<0) {
	cout << "error on write";
exit(1);
}

close(sockfd);
*/




return 0;
}


