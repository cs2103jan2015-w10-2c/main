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
	double _serialID;
	string _commandType;
	string _name;
	Date _date;
	double _startTime;
	double _endTime;
	bool _isDone;
	bool _isFloat;
	bool _isDeadline;

public:
	Task();
	Task(double serialID, string commandType, string name, Date date, double startTime, double endTime, bool isDone, bool isFloat, bool isDeadline);
	Task(string commandType, string name, Date date, double startTime, double endTime);
	Task(string commandType, string name, Date date, double endTime);
	Task(string commandType, string name);

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