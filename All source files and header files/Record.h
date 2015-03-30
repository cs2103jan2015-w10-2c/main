#pragma once
#ifndef RECORD_H
#define RECORD_H
#include<string>
#include<list>
#include "Task.h"


using namespace std;

class Record{
private:
	string _commandType;
	list <Task> _taskRecord;

public:
	Record();
	Record(string newCommand, Task newTask);
	Record(string newCommand, list<Task> newTaskList);
	~Record();
	void setCommandTypeRecord(string commandTypeRecord);
	void setlistTaskRecord(Task taskRecord);

	string getCommandType();
	list<Task> getTaskRecord();
	void clear();
};

#endif
