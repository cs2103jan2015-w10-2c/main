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
<<<<<<< HEAD
	static int number;
=======
	static int number; //for delete
>>>>>>> a6fc0fec54498484374b791c20c32cf7d8cd9a63
	static int year;
	static int month;
	static int day;
	static int startTimeMin;
	static int endTimeMin;
	static int startTimeHour;
	static int endTimeHour;
	static string dayOfWeek;

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