/*
 * Task.h
 *
 *  Created on: 16 בינו׳ 2018
 *      Authors: noam shimshoviz, ID: 203565429 and sarit zevin, ID: 313242588
 */

#ifndef TASK_H_
#define TASK_H_
/**
 * this class represent Task
 */
class Task {
public:
	/**
	 * construct a Task
	 * @param func the function that does task
	 * @param arg the arguments for the task
	 */
	Task(void * (*func)(void *arg), void* arg):
		func(func), arg(arg) {}
	/**
	 * execute the function of the task
	 */
	void execute() {
		func(arg);
	}
	/**
	 * default destructor
	 */
	virtual ~Task(){}
private:
	void * (*func)(void *arg);
	void *arg;
};


#endif /* TASK_H_ */
