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
	bool _isFloat;
	bool _isDeadline;
	double _serialID;

public:
	Task();
	Task(string commandType, string name, Date date, double startTime, double endTime, double serialID);
	Task(string commandType, string name, Date date, double endTime, double serialID);
	Task(string commandType, string name, double serialID);

	void markDone();
	string getCommandType();
	string getName();
	Date getDate();
	double getStartTime();
	double getEndTime();
	bool getDone();
	bool getFloat();
	bool getDeadline();
	double getSerialID();
};

#endif