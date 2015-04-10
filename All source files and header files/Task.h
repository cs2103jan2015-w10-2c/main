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
	int _startTimeHour;
	int _startTimeMin;
	int _endTimeHour;
	int _endTimeMin;
	bool _isDone;

	static const string NAME_OF_MONTH[12];


public:
	Task();
	Task(string commandType, string taskType, string name, int year, int month, int day, int startTimeHour, int startTimeMin, int endTimeHour, int endTimeMin, bool isDone);
	Task(string commandType, string name, int year, int month, int day, int startTimeHour, int startTimeMin, int endTimeHour, int endTimeMin);
	Task(string commandType, string name, int year, int month, int day, int endTimeHour, int endTimeMin);
	Task(string commandType, string name);

	void markDone();
	void markNotDone();
	void setName(string newName);
	void setYear(int newYear);
	void setMonth(int newMonth);
	void setDay(int newDay);
	void setStartTimeHour(int newStartTimeHour);
	void setStartTimeMin(int newStartTimeMin);
	void setEndTimeHour(int newEndTimeHour);
	void setEndTimeMin(int newEndTimeMin);
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
	int getStartTimeHour();
	int getStartTimeMin();
	int getEndTimeHour();
	int getEndTimeMin();
	bool getIsDone();
};

#endif