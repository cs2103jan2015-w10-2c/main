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
	static Storage* storage;
	static Task* task;

public:
	static void main(string userInput);

	static void parsingCommand(string userInput); //haven't done
	static void createTask(); //haven't done
	static void storeTask();
	static string tellUI();
	static bool isDuplicate();
	EasyScheduleLogic(void);
	~EasyScheduleLogic(void);
};

#endif

