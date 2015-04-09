#pragma once
#ifndef TASK_H
#define TASK_H
#include <string>

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

	static const string NAME_OF_MONTH[12];


public:
	Task();
	Task(string commandType, string taskType, string name, int year, int month, int day, double startTimeHour, double startTimeMin, double endTimeHour, double endTimeMin, bool isDone);
	Task(string commandType, string name, int year, int month, int day, double startTimeHour, double startTimeMin, double endTimeHour, double endTimeMin);
	Task(string commandType, string name, int year, int month, int day, double endTimeHour, double endTimeMin);
	Task(string commandType, string name);

	void markDone();
	void markNotDone();
	void setName(string newName);
	void setYear(int newYear);
	void setMonth(int newMonth);
	void setDay(int newDay);
	void setStartTimeHour(double newStartTimeHour);
	void setStartTimeMin(double newStartTimeMin);
	void setEndTimeHour(double newEndTimeHour);
	void setEndTimeMin(double newEndTimeMin);
	void setCommandType(string commandType);
	void setTaskType(string taskType);

	string getCommandType();
	string getTaskType();
	string getName();
	int getYear();
	int getMonth();
	string getAlphaMonth(int month);
	int getDay();
	string getDate();
	string getAlphabetDate();
	double getStartTimeHour();
	double getStartTimeMin();
	double getEndTimeHour();
	double getEndTimeMin();
	bool isDone();
};

#endif