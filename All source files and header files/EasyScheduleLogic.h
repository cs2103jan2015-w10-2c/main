//This class takes in userinput from GUI,
//call Command Parser to pass command,
//call Task and create the task
//and call Storage to storethe created task


#pragma once
#ifndef EASYSCHEDULELOGIC_H
#define EASYSCHEDULELOGIC_H

#include "CommandParser.h"
//#include "Task.h"
#include "Storage.h"
//#include <sstream>
#include <string>

using namespace std;

class EasyScheduleLogic {

private:
	static const int MIN_MONTHS_IN_A_YEAR;
	static const int MAX_MONTHS_IN_A_YEAR;
	static const int MIN_DAY_IN_A_MONTH;
	static const int MAX_DAYS_IN_A_MONTH[12];
	static const int MIN_HOURS_IN_A_DAY;
	static const int MAX_HOURS_IN_A_DAY;
	static const int MIN_MINUTES_IN_AN_HOUR;
	static const int MAX_MINUTES_IN_AN_HOUR;

	static const int SHIFT_BY_ONE;

	static const string FLOATING_TASK;
	static const string DEADLINE_TASK;
	static const string TIMED_TASK;

	
	static const string MESSAGE_WELCOME;
	static const string MESSAGE_ADD;
	static const string MESSAGE_ADD_FAIL;
	static const string MESSAGE_DELETE;
	static const string MESSAGE_DELETE_FAIL;
	static const string MESSAGE_CLEAR;
	//static const string MESSAGE_SEARCH_FAIL;
	static const string MESSAGE_SORT;
	static const string MESSAGE_EMPTY;
	static const string MESSAGE_INVALID_INPUT_COMMAND;
	static const string MESSAGE_INVALID_INPUT_NAME;
	static const string MESSAGE_INVALID_DATE;

private:
	static char buffer[1000];
	static bool isInvalidCommandType;
	static bool isInvalidTaskType;
private:
	static CommandParser parser;
	static Storage storage;
	static Task task;
	static string commandType;
	static string taskType;
	static string name;
	static int year;
	static int month;
	static int day;
	static int startTimeHour;
	static int startTimeMin;
	static int endTimeHour;
	static int endTimeMin;

	static int localYear;
	static int localMonth;
	static int localDay;
	static int localHour;
	static int localMin;

public:
	
	static void main();
	static void executeLogic(string userInput);

	static void parsingCommand(string userInput);
	static void creatingTask();
	static void storingTask();
	static string deletingTask();
	static string searchingTask();
	static string displayingTask();
	static string markDone();
	static string markNotDone();
	static void sortingTask();
	static string tellUI();
	static bool isDuplicate();
	static bool isValidDate();
	static void getLocalDateTime();
	EasyScheduleLogic(void);
	~EasyScheduleLogic(void);
};

#endif

