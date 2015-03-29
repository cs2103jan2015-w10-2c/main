#pragma once
#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <assert.h>
//#include "EasyScheduleLogic.h"
//#include "Task.h"

using namespace std;

class CommandParser {
public:
	static string taskType;
	static string commandType;
	static string name;
	static int number; //for delete
	static int year;
	static int month;
	static int day;
	static int startTimeMin;
	static int endTimeMin;
	static int startTimeHour;
	static int endTimeHour;

public:
	CommandParser(void);
	~CommandParser(void);
	void identifyTask(string userInput);
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
};

#endif