#pragma once
#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <assert.h>

using namespace std;

class CommandParser {
private:
	static const string FILEPATH;
	static const string FILENAME;
	static const string FLOATING_TASK;
	static const string DEADLINE_TASK;
	static const string TIMED_TASK;

	static const string ADD;
	static const string COMMAND_DELETE;
	static const string DISPLAY;
	static const string DONE;
	static const string EDIT;
	static const string EXIT;
	static const string NOT_DONE;
	static const string SEARCH;
	static const string SORT;
	static const string UNDO;
	static const string VIEW;

	static const string DATE;
	static const string NAME;
	static const string TIME;

	static const string TODAY;
	static const string TOMORROW;
	static const string MONDAY;
	static const string MON;
	static const string TUESDAY;
	static const string TUE;
	static const string WEDNESDAY;
	static const string WED;
	static const string THURSDAY;
	static const string THU;
	static const string FRIDAY;
	static const string FRI;
	static const string SATURDAY;
	static const string SAT;
	static const string SUNDAY;
	static const string SUN;

public:
	static string taskType;
	static string commandType;
	static string name;
	static int number; //for delete, done, notdone
	static int year;
	static int month;
	static int day;
	static int startTimeMin;
	static int endTimeMin;
	static int startTimeHour;
	static int endTimeHour;
	static string dayOfWeek;
	static int dayOfWeekNo;
	static string attribute; //what to edit

public:
	CommandParser(void);
	~CommandParser(void);
	void identifyTask(string userInput);
	void extractCommandType(string userInput);

	void addingTask(string userInput);
	void easyAdd(string userInput);
	void easyAddDate(string userInput);
	void normalAdd(string userInput);
	void normalAddDate(string userInput);
	void addTimeDeadline(string userInput);
	void addTimeTimedTask(string userInput);
	void getDayOfWeekNo(string dayOfWeek);
	void getDayToAdd(int localWeekday);
	void executeByNumberOrName(string userInput);

	void editingTask(string userInput);
	void editDate(string userInput);
	void editName(string userInput);
	void editTime(string userInput);
	void editFloatDateTime(string cutInput);

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

	void setDevider(string userInput);
	void setTodayDate();
	void setTomorrowDate();
	void setDayDate();

	void viewTask(string userInput);
};

#endif