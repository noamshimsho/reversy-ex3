/*
 * ThreadPool.h
 *
 *  Created on: 16 בינו׳ 2018
 *      Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
 */

#ifndef THREADPOOL_H_
#define THREADPOOL_H_
#include "Task.h"
#include <queue>
#include <pthread.h>
#include <iostream>
using namespace std;
/**
 * this class represent ThreadPool
 */
class ThreadPool {
public:
	/**
	 * construct a ThreadPool from a given integer
	 * @param threasNum the number of threads to create in the pool
	 */
	ThreadPool(int threasNum);
	/**
	 * add given Task to the list of tasks
	 * @param task the Task to add
	 */
	void addTask(Task *task);
	/**
	 * delete the mutex
	 */
	void terminate();
	/**
	 * release all the threads in the pool
	 */
	virtual ~ThreadPool();
private:
	queue <Task *> tasksQueue;
	pthread_t* threads;
	/**
	 * execute task if there is a free thread
	 */
	void executeTasks();
	bool stopped;
	pthread_mutex_t lock;
	/**
	 * call the static method execute
	 * @param arg the arguments for the thread
	 */
	static void *execute(void *arg);
};

#endif /* THREADPOOL_H_ */
