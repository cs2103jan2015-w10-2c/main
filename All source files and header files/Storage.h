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
	static list<Task>_previousTaskList;
	static list<Task>::iterator _taskIt;
	static Tracker _tracker;
	static Record _record;

	static const string LINE_BUFFER;
	static const string COMMANDLIST;
	static const string PATH_NAME_BUFFER;

public:

	Storage();
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
	static bool compareTask(Task task);
	static void getTask(Task task);
	static void storePreviousTask(string commandType);
	static list<Task> getPreviousTaskList();
	static list<Task> autoInitialDisplay();
	static void searchTodayTask(int day, int month, int year);
	static void searchUpcomingDeadline(int day, int month, int year);
	static void getPosition(int i);

	static void findTaskInList(string searchKeyWord);
	static bool isTaskDuplicate(Task task);
	static bool isFloatDuplicate(Task task);
	static bool isTimedDuplicate(Task task);
	static bool isDeadlineDuplicate(Task task);
	static bool showDirectory();
	static void openFile();
	static void readFile();
	static void setFileName(string name);
	static void setPathName(string name);
	static void writeToFile();
	static string toLower(string text);
	static string getCommandList();


	static void creatRecordAdd(Task task);
	static void addToTracker(Record record1);

	static void sortList();
	static void undoingReverseAdd(list<Task> listToUndo);
	static void undoingReverseDelete(list<Task> listToUndo);
	static void undoingReverseNotDone(list<Task> listToUndo);
	static void undoingReverseDone(list<Task> listToUndo);

	static void storeTask(Task task);
	static string editTaskName(int i, string s);
	static string editTaskTime(int i, double sth, double stm, double eth, double etm);
	static string editTaskDate(int i, int year, int month, int day);
	static string searchByName(string searchKeyWord);
	static string markDone(int i);
	static string markNotDone(int i);
	static string deleteByNumber(int i);
	static void getIndex(Task task);


	static string toStringTaskDetail();
	static string toStringTaskDetail(list <Task> listToFormat);
	static Tracker getTracker();
	static void deleteLastTrackerEntry();

};


#endif