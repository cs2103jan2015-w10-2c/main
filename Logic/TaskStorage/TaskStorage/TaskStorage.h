#pragma once
#ifndef TASKSTORAGE_H
#define TASKSTORAGE_H

#include <iostream>
#include <string>
#include <sstream>
#include "FloatingTask.h"
using namespace std;

class TaskStorage {
private:
	FloatingTask _fTask;
	string _taskType;
	string _commandType;

public:
	TaskStorage(void);
	void parseInput(string);
	string getCommandType();
	string getTaskType();
	FloatingTask getFTask();
	~TaskStorage(void);
};

#endif
