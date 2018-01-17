/*
 * ThreadPool.h
 *
 *  Created on: 16 בינו׳ 2018
 *      Author: noam
 */

#ifndef THREADPOOL_H_
#define THREADPOOL_H_
#include "Task.h"
#include <queue>
#include <pthread.h>
#include <iostream>
using namespace std;
class ThreadPool {
public:
	ThreadPool(int threasNum);
	void addTask(Task *task);
	void terminate();
	virtual ~ThreadPool();
private:
	queue <Task *> tasksQueue;
	pthread_t* threads;
	void executeTasks();
	bool stopped;
	pthread_mutex_t lock;

	static void *execute(void *arg);
};

#endif /* THREADPOOL_H_ */
