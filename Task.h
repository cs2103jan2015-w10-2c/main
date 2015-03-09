#pragma once
#ifndef TASK_H
#define TASK_H
#include<string>

using namespace std;

class Task{
private:
	string _commandType;
	string _taskType;
	string _name;
	int _year;
	int _month;
	int _day;
	double _startTime;
	double _endTime;
	bool _isDone;
	bool _isFloat;
	bool _isDeadline;

public:
	Task();
	Task(string commandType, string name, int year, int month, int day, double startTime, double endTime);
	Task(string commandType, string name, int year, int month, int day, double endTime);
	Task(string commandType, string name);

	void markDone();
	string getCommandType();
	string getName();
	int getYear();
	int getMonth();
	int getDay();
	string getDate();
	double getStartTime();
	double getEndTime();
	bool getDone();
	bool getFloat();
	bool getDeadline();
};

#endif