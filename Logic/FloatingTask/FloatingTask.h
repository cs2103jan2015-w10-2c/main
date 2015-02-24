#ifndef FLOATINGTASK_H_
#define FLOATINGTASK_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class FloatingTask{
private:
	int _year;
	int _month;
	int _day;
	string _taskDescription;
	string _taskStatus;
	int _taskSerialID;

public:
	FloatingTask();
	FloatingTask(int, int, int, string);
	string toStringTaskDetail();
	int getTaskSerialID();
	~FloatingTask();
};

#endif