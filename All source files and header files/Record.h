#pragma once
#ifndef RECORD_H
#define RECORD_H
#include <string>
#include <list>
#include "Task.h"


using namespace std;

class Record {
private:
	string _commandType;
	list <Task> _taskRecord;
	bool _isPrevious;

public:
	Record();
<<<<<<< HEAD
	Record(string newCommand, Task newTask);
	Record(string newCommand, list<Task> newTaskList);
=======
	Record(string commandType, Task task);
>>>>>>> 73322872014d207b8ed221362092bdc40965d8cf
	~Record();
	void setCommandTypeRecord(string commandTypeRecord);
	void setlistTaskRecord(Task taskRecord);
	void setIsPrevious();
	void setIsNotPrevious();

	string getCommandType();
	list<Task> getTaskRecord();
	bool getIsPrevious();
};

#endif
