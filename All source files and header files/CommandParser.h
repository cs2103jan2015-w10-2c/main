#pragma once
#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H
#include <string>
#include <iostream>
#include "EasyScheduleLogic.h"
//#include "Task.h"

using namespace std;

class CommandParser {
public:
	EasyScheduleLogic esLogic;

public:
	//static string userInput;
	static string taskType;
	static string commandType;
	static string description;
	static int year;
	static int month;
	static int day;
	static int startTimeMin;
	static int endTimeMin;
	static int startTimeHr;
	static int endTimeHr;

public:
	CommandParser(void);
	void identifyTask(string userInput);
	~CommandParser(void);
};

#endif