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
	static string _fileName;
	static list<Task>_taskList;
	static list<Task>_searchResultList;
	static list<Task>_previousTaskList;
	static list<Task>::iterator _taskIt;
	static Tracker _tracker;
	static Record _record;

	static const string LINE_BUFFER;
	static const string COMMANDLIST;

public:

	Storage();

	static ofstream _fWrite;
	static ifstream _fRead;
	static char buffer[1000];
	static bool isTaskFound;
	static bool isSearched;

	static bool compareTask(Task task);
	static void storePreviousTask(string commandType);
	static list<Task> getPreviousTaskList();
	static void getIterator(int i);

	static void findTaskInList(string searchKeyWord);
	static string deleteByNumber(int i);
	static string markDoneByNumber(int i);
	static string markNotDoneByNumber(int i);
	static void storeTask(Task task);
	static bool isTaskDuplicate(Task task);
	static bool isFloatDuplicate(Task task);
	static bool isTimedDuplicate(Task task);
	static bool isDeadlineDuplicate(Task task);
	static void showDirectory();
	static bool isExistingFile();
	static void openFile();
	static void readFile();
	static void setFileName(string name);
	static void writeToFile();
	static string toLower(string text);
	static string getCommandList();


	static void creatRecordAdd(Task task);
	static void addToTracker(Record record1);

	static void sortList();
	static void undoingReverseAdd(Task task);
	static string searchByName(string searchKeyWord);
	static string markDone(string name);
	static string markNotDone(string name);
	static string deleteByName(string searchKeyWord);
	static string toStringTaskDetail();
	static string toStringTaskDetail(list <Task> listToFormat);

};


#endif