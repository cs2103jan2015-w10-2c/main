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
	double _startTimeHour;
	double _startTimeMin;
	double _endTimeHour;
	double _endTimeMin;
	bool _isDone;

public:
	Task();
	Task(string commandType, string taskType, string name, int year, int month, int day, double startTimeHour, double startTimeMin, double endTimeHour, double endTimeMin, bool isDone);
	Task(string commandType, string name, int year, int month, int day, double startTimeHour, double startTimeMin, double endTimeHour, double endTimeMin);
	Task(string commandType, string name, int year, int month, int day, double endTimeHour, double endTimeMin);
	Task(string commandType, string name);

	void markDone();
	void setName(string newName);
	void setYear(int newYear);
	void setMonth(int newMonth);
	void setDay(int newDay);
	void setStartTimeHour(int newStartTimeHour);
	void setStartTimeMin(int newStartTimeMin);
	void setEndTimeHour(int newEndTimeHour);
	void setEndTimeMin(int newEndTimeMin);

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