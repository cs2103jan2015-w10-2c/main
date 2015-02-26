#pragma once
#ifndef INPUT_PARAMETER_
#define INPUT_PARAMETER_
#include<string>

using namespace std;

struct Date{
	int year;
	int month;
	int day;
};

class Task{
private:
	string _commandType;
	string _taskType;
	string _name;
	Date _date;
	double _startTime;
	double _endTime;
	bool _isDone;

public:
	Task();
	Task(string commandType, string taskType, string name, Date date, double startTime, double endTime);
	void markDone();
	string getCommandType();
	string getTaskType();
	string getName();
	Date getDate();
	double getStartTime();
	double getEndTime();
};

#endif