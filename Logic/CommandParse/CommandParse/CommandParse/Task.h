#pragma once
#ifndef TASK_H
#define TASK_H
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
	Task(string commandType, string name, Date date, double startTime, double endTime);
	Task(string commandType, string name, Date date, double endTime);
	Task(string commandType, string name);

	void markDone();
	string getCommandType();
	string getTaskType();
	string getName();
	Date getDate();
	double getStartTime();
	double getEndTime();
};

#endif