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

public:
	Record();
	Record(string commandType, Task newTask);
	Record(string commandType, list<Task> newTaskList);
	~Record();

	void setCommandTypeRecord(string commandTypeRecord);
	void setlistTaskRecord(Task taskRecord);
	void clear();

	string getCommandType();
	list<Task> getTaskRecord();

};

#endif
