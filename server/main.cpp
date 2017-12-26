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

void * print(void * arg) {
	long i;
	i = (long)arg;

	while (i < 1000) {
	cout << "thread!!!!" << " ,"<< i << endl;
	i++;

	}
	pthread_exit(NULL);
}


void m() {
    //read the port from the file
	int port;
	ifstream inFile;
	inFile.open("serverProtocol.txt");
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
	server.stop();
}

struct ThreadArgs {
	int clientSocket;

};
int main() {
	m();
	/*
	vector<Game> v;
	int x;
	for (x = 0; x < 1; x++) {
		Game y("yes", 3);
		v.push_back(y);
		cout << y.getName() << endl;
	}
	cout << v.size();
	*/
/*

	vector <ThreadArgs> v;
	int x =1;
	while (x < 4) {
		ThreadArgs a;
		a.clientSocket = x;
		v.push_back(a);
		x++;
	}
for (vector<ThreadArgs>::const_iterator it = v.begin(); it != v.end(); it++){
	cout << it->clientSocket <<endl;
}

	string s = "this is_a string";    // string to vector (split)
	string first;
	istringstream stm(s);
	vector <string> array;
	string word;
	int flag = 1;
	while (stm >> word) {
		if (flag == 1) {
			first = word;
			flag++;
		} else {
		array.push_back(word);
		}
	}
	for (vector<string>::const_iterator it = array.begin(); it != array.end(); it++){
		cout << *it <<endl;
	}
	cout << first;



*/
return 0;
}

/*
	string n = "123";
	int x = atoi(n.c_str());  // string to int

	long lon = 99999999;
	cout << x <<endl;
	stringstream ss;         // int/long to string
	ss << n;
	string star = ss.str();
	cout << star;
	ss << lon;
	star = ss.str();
	cout << endl << star << endl;
	const char * p = n.c_str();
	cout << strlen(p);
	cout << p[0] ;
	cout << p[1];
	cout << p[2];

	*/
	/*
	pthread_t thread;
	int rc;
	int i =0;
	rc = pthread_create(&thread,NULL,print,(void*)i);
	if (rc) {
		cout << "mistake";
		exit(-1);
	}

	while (i < 1000) {
	cout << "main!!!!" << " ,"<< i << endl;
	i++;
	}
	pthread_exit(NULL);



*/

