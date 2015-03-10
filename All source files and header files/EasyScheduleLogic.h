//This class takes in userinput from GUI,
//call Command Parser to pass command,
//call Task and create the task
//and call Storage to storethe created task


#pragma once
#ifndef EASYSCHEDULELOGIC_H
#define EASYSCHEDULELOGIC_H

#include "CommandParser.h"
#include "Task.h"
#include "Storage.h"
#include <sstream>
#include <string>

using namespace std;

class EasyScheduleLogic {
private:
	static CommandParser _cp;
	static Storage _storage;
	static Task _task;
	static string _commandType;
	static string _taskType;
	static string  _name;
	static int _year;
	static int _month;
	static int _day;
	static int _startTimeHour;
	static int _startTimeMin;
	static int _endTimeHour;
	static int _endTimeMin;

public:
	static void main(string userInput);

	static void parsingCommand(string userInput);
	static void creatingTask();
	static void storingTask();
	static string tellUI();
	static bool isDuplicate();
	EasyScheduleLogic(void);
	~EasyScheduleLogic(void);
};

#endif

