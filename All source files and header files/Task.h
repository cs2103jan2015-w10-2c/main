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
	int _year;
	int _month;
	int _day;
	int _startTimeHour;
	int _startTimeMin;
	int _endTimeHour;
	int _endTimeMin;
	bool _isDone;

public:
	Task();
	Task(string commandType, string name, int year, int month, int day, int startTimeHour, int startTimeMin, int endTimehour, int endTimeMin);
	Task(string commandType, string name, int year, int month, int day, int endTimeHour, int endTimeMin);
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
	int getStartTimeHour();
	int getStartTimeMin();
	int getEndTimeHour();
	int getEndTimeMin();
	bool isDone();
};

#endif