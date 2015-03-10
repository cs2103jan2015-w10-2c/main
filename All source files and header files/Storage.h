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
	static list<Task>_TaskList;
	static list<Task>::iterator _TaskIt;

	static const string LINE_BUFFER;

public:

	Storage();

	static ofstream _fWrite;
	static ifstream _fRead;
	static char buffer[500];

	static void storeTask(Task task);
	static bool isTaskDuplicate(Task task);
	static bool isFloatDuplicate(Task task);
	static bool isTimedDuplicate(Task task);
	static bool isDeadlineDuplicate(Task task);
	static void showDirectory();
	static bool isExistingFile();
	static void openFile();
	static void setFileName(string name);
	static void writeToFile();
	static void readFile();

	static void sortList();
	static string searchByName(string searchKeyWord);
	static string deleteByName(string searchKeyWord);
	static string toStringTaskDetail();
	static string toStringTaskDetail(list <Task> listToFormat);
};


#endif