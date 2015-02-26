#ifndef DEADLINETASK_H_
#define DEADLINETASK_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class DeadlineTask{
private:
	int _year;
	int _month;
	int _day;
	double _deadline;
	string _taskDescription;
	string _taskStatus;

public:
	DeadlineTask();
	DeadlineTask(int, int, int, double, string);

	string toStringTaskDetail();

	int getTaskSerialID();

	int getYear();

	~DeadlineTask();
};

#endif