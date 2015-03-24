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

using namespace std;

class Storage {

private:
	static string _fileName;
	static list<Task>_taskList;
	static list<Task>::iterator _taskIt;

	static const string LINE_BUFFER;
	static const string COMMANDLIST;

public:

	Storage();

	static ofstream _fWrite;
	static ifstream _fRead;
	static char buffer[1000];

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

	static void sortList();
	static string searchByName(string searchKeyWord);
	static string markDone(string name);
	static string markNotDone(string name);
	static string deleteByName(string searchKeyWord);
	static string toStringTaskDetail();
	static string toStringTaskDetail(list <Task> listToFormat);
};


#endif