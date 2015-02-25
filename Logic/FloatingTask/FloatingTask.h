#ifndef FLOATINGTASK_H_
#define FLOATINGTASK_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class FloatingTask{
private:
	string _taskDescription;
	string _taskStatus;
	int _taskSerialID;

public:
	FloatingTask();
	FloatingTask(string);
	string toStringTaskDetail();
	int getTaskSerialID();
	~FloatingTask();
};

#endif