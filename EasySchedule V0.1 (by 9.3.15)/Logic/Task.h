#pragma once
#ifndef TASK_H
#define TASK_H
#include<string>

using namespace std;

class Task {
private:
	string _commandType;
	string _taskType;
	string  _name;
	string _taskType;
	int _year;
	int _month;
	int _day;
	double _startTimeHour;
	double _startTimeMin;
	double _endTimeHour;
	double _endTimeMin;
	bool _isDone;

public:
	Task();
	Task(string commandType, string name, int year, int month, int day, double startTimeHour, double startTimeMin, double endTimehour, double endTimeMin);
	Task(string commandType, string name, int year, int month, int day, double endTimeHour, double endTimeMin);
	Task(string commandType, string name);

	void markDone();

	void setName(string newName); //in later versions V0.2 onwards: set for all date and time parameters too.
	string getCommandType();
	string getTaskType();
	string getName();
	int getYear();
	int getMonth();
	int getDay();
	string getDate();
	double getStartTimeHour();
	double getStartTimeMin();
	double getEndTimeHour();
	double getEndTimeMin();
	bool isDone();
};

#endif