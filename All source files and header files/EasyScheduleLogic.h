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
public:
	static CommandParser cp;
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

public:
	static void main(string userInput);

	static void parsingCommand(string userInput);
	static void creatingTask();
	static void storingTask();
	static void deletingTask();
	static void searchingTask();
	static void displayingTask();
	static void sortingTask();
	static string tellUI();
	static bool isDuplicate();
	EasyScheduleLogic(void);
	~EasyScheduleLogic(void);
};

#endif

