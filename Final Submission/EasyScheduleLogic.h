//This class takes in userinput from GUI,
//call Command Parser to pass command,
//call Task and create the task
//and call Storage to store the created task


#pragma once
#ifndef EASYSCHEDULELOGIC_H
#define EASYSCHEDULELOGIC_H

#include "CommandParser.h"
#include "Storage.h"
#include <string>
#include "Tracker.h"
#include "Record.h"

using namespace std;

class EasyScheduleLogic {

private:

	static const string FLOATING_TASK;
	static const string DEADLINE_TASK;
	static const string TIMED_TASK;
	static const string NAME;
	static const string DATE;
	static const string TIME;
	
	static const string MESSAGE_WELCOME;
	static const string MESSAGE_DIRECTORY_OPENED;
	static const string MESSAGE_DIRECTORY_NOT_FOUND;
	static const string MESSAGE_PROGRAM_READY;
	static const string MESSAGE_FILE_ERROR;
	static const string MESSAGE_ADD;
	static const string MESSAGE_ADD_FAIL;
	static const string MESSAGE_DELETE;
	static const string MESSAGE_DELETE_FAIL;
	static const string MESSAGE_DELETE_CHOOSE;
	static const string MESSAGE_EDIT;
	static const string MESSAGE_EDIT_FAIL;
	static const string MESSAGE_EDIT_INPUT_ERROR;
	static const string MESSAGE_CLEAR;
	static const string MESSAGE_SEARCH_FAIL;
	static const string MESSAGE_SORT;
	static const string MESSAGE_MARK_FAIL;
	static const string MESSAGE_MARK_CHOOSE;
	static const string MESSAGE_EMPTY;
	static const string MESSAGE_INVALID_INPUT_COMMAND;
	static const string MESSAGE_INVALID_INPUT_NAME;
	static const string MESSAGE_INVALID_DATE;
	static const string MESSAGE_INVALID_TIME;
	static const string MESSAGE_INVALID_NUMBER;
	static const string MESSAGE_EXIT;
	static const string MESSAGE_UNDO_FAIL;
	static const string MESSAGE_UNDO_SUCCESS;
	static const string MESSAGE_UNDO_ERROR;
	static const string MESSAGE_EMPTY_DEADLINE;
	static const string MESSAGE_EMPTY_FLOATING;
	static const string MESSAGE_EMPTY_TIMED;
	static const string MESSAGE_EMPTY_TODAY;
	static const string MESSAGE_EMPTY_TOMORROW;
	static const string MESSAGE_EMPTY_YESTERDAY;
	static const string MESSAGE_VIEW_DEADLINE_ALL;
	static const string MESSAGE_VIEW_FLOATING_ALL;
	static const string MESSAGE_VIEW_TIMED_ALL;
	static const string MESSAGE_VIEW_TODAY_ALL;
	static const string MESSAGE_VIEW_TOMORROW_ALL;
	static const string MESSAGE_VIEW_YESTERDAY_ALL;


private:
	static string returnMessage;
	static string returnDisplay;
	static int returnIndex;
	static char buffer[1000];
	static bool isInvalidTaskType;
private:
	static CommandParser parser;
	static Storage storage;
	static Task task;
	static string commandType;
	static string taskType;
	static string name;
	static int taskNumber;
	static int year;
	static int month;
	static int day;
	static int startTimeHour;
	static int startTimeMin;
	static int endTimeHour;
	static int endTimeMin;

public:
	//@author A0111446R
	static void writeFile();
	//@author A0115131B
	static void executeLogic(string userInput);
	//@author A0111446R
	static void commandFilePath();
	static void commandFileName();
	//@author A0115131B
	static void commandView();
	static void viewDeadline();
	static void viewFloating();
	static void viewTimed();
	static void viewToday();
	static void viewTomorrow();
	static void viewYesterday();
	
	//@author A0116707H
	static void commandAdd();
	static void commandDelete();
	static void commandDisplay();
	static void commandSearch();
	static void commandSort();
	static void commandDone();
	static void commandNotDone();
	static void commandEdit();
	static void commandUndo();
	static void commandExit();
	static void commandInvalid();
	//@author A0114255N
	static void parsingCommand(string userInput);
	static void creatingTask();
	//@author A0111446R
	static void storingTask();
	//@author A0114255N
	static string addingTask();
	//@author A0111446R
	static string deletingTask();
	static string searchingTask();
	//@author A0115131B
	static string displayingTask();
	static string autoDisplay();
	static string displayAllDeadline(); 
	static string displayAllFloating();
	static string displayAllTimed();
	static string displayAllToday();
	static string displayAllTomorrow();
	static string displayAllYesterday();
	//@author A0111446R
	static string markDone();
	static string markNotDone();
	//@author A0114255N
	static string editingTask();
	//@author A0115131B
	static string undoingTask();
	static Record getLastRecord();
	static string callUndoingAdd(Record recordToUndo);
	static string callUndoingDelete(Record recordToUndo);
	static string callUndoingEdit(Record recordToUndo);
	static string callUndoingDone(Record recordToUndo);
	static string callUndoingNotDone(Record recordToUndo);
	static bool undoingAdd(Record recordToUndo);
	static bool undoingDelete(Record recordToUndo);
	static bool undoingDone(Record recordToUndo);
	static bool undoingNotDone(Record recordToUndo);
	static bool undoingEdit(Record recordToUndo);
	static string sortingTask();

	//@author A0116707H
	static string tellUIReturnMessage();
	static string tellUIDisplay();
	static int tellUIReturnIndex();
	static bool isDuplicate();

	//@author A0114255N
	static Task getTask();
	static string getCommandType();
	static string getTaskType();
	static string getName();
	static int getTaskNumber();
	static int getYear();
	static int getMonth();
	static int getDay();
	static int getStartTimeHour();
	static int getStartTimeMin();
	static int getEndTimeHour();
	static int getEndTimeMin();
	EasyScheduleLogic(void);
	~EasyScheduleLogic(void);
};

#endif

