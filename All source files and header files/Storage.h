#pragma once
#ifndef STORAGE_H_
#define STORAGE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <iterator>
#include <list>

#include "Task.h"
#include "Record.h"
#include "Tracker.h"

using namespace std;

class Storage {

private:

	static const string LINE_BUFFER;
	static const string COMMANDLIST;
	static const string FLOATING_TASK;
	static const string DEADLINE_TASK;
	static const string TIMED_TASK;

	static const int MIN_MONTHS_IN_A_YEAR;
	static const int MAX_MONTHS_IN_A_YEAR;
	static const int MIN_DAY_IN_A_MONTH;
	static const int MAX_DAYS_IN_A_MONTH[12];
	static const int MIN_HOURS_IN_A_DAY;
	static const int MAX_HOURS_IN_A_DAY;
	static const int MIN_MINUTES_IN_AN_HOUR;
	static const int MAX_MINUTES_IN_AN_HOUR;
	static const int SHIFT_BY_ONE;

public:

	Storage();
	~Storage();

	static string _fileName;
	static string _pathName;
	static list<Task>_taskList;
	static list<Task>_searchResultList;
	static ofstream _fWrite;
	static ifstream _fRead;
	static char buffer[1000];
	static int _index;
	static bool isSuccess;
	static bool isSearched;
	static bool isDateValid;
	static bool isTimeValid;
	static list<Task>_previousTaskList;
	static list<Task>::iterator _taskIt;
	static Tracker _tracker;
	static Record _record;

	//File functions
	static void openFile();
	static void readFile();
	static void setFileName(string name);
	static void setPathName(string name);
	static void writeToFile();

	//Task functions
	static void storeTask(Task task);
	static string editTaskName(int i, string s);
	static string editTaskTime(int i, int sth, int stm, int eth, int etm);
	static string editTaskDate(int i, int year, int month, int day);
	static string editTaskDateTime(int i, int year, int month, int day, int sth, int stm, int eth, int etm);
	static void executeTaskCommand(string commandType);
	static void executeEditName(string commandType, string name);
	static void executeEditTime(string commandType, int sth, int stm, int eth, int etm);
	static void executeEditDate(string commandType, int year, int month, int day);
	static void executeEditDateTime(string commandType, int year, int month, int day, int sth, int stm, int eth, int etm);
	static void setTime(int sth, int stm, int eth, int etm);
	static void setDate(int year, int month, int day);
	static string searchByName(string searchKeyWord);
	static string markDone(int i);
	static string markNotDone(int i);
	static string executeIndexCommand(int i, string commandType);
	static string deleteByNumber(int i);	
	static string toStringTaskDetail(list <Task> &listToFormat);
	static string toStringTaskDetail();
	static list<Task> getPreviousTaskList();
	static list<Task> autoInitialDisplay();
	static list<Task> allDeadline();
	static list<Task> allFloating();
	static list<Task> allTimed();
	static list<Task> allToday();
	static list<Task> allTomorrow();
	static list<Task> allYesterday();
	

	//Supporting functions
	static void getTask(Task task);
	static void searchTodayTask(int day, int month, int year);
	static void searchUpcomingDeadline(int day, int month, int year);
	static void getTaskItFromIndex(int i, list<Task> &taskList);
	static void getTaskItFromIndex(int i);
	static void getTaskIt(Task task);
	static void findTaskInList(string searchKeyWord);
	static void sortList();
	static int getIndex();
	static int getDeviderNum(string input);
	static string toLower(string text);
	static string getCommandList();
	static bool compareTask(Task task);
	static bool isExistingTask(Task &task);
	static bool isValidDate(Task task);
	static bool isValidTime(Task task);
	static bool isValidDate(int month, int day);
	static bool isValidTime(int sth, int stm, int eth, int etm);
	static bool isValidDirectory();
	static bool isValidIndex(int i, list<Task> &taskList);
	static bool isValidTaskInput(Task task);

	//Undo functions
	static void creatRecordAdd(Task task);
	static void addToTracker();
	static void undoingReverseAdd(list<Task> listToUndo);
	static void undoingReverseDelete(list<Task> listToUndo);
	static void undoingReverseNotDone(list<Task> listToUndo);
	static void undoingReverseDone(list<Task> listToUndo);
	static void undoingReverseEdit(list<Task> listToUndo);
	static void storePreviousTask(string commandType);
	static Tracker getTracker();
	static void deleteLastTrackerEntry();

};


#endif	