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
	static bool _isDuplicate;
	static char buffer[255];

	static void storeTask(Task task);
	static bool isTaskDuplicate(Task task);
	static void showDirectory();
	static bool isExistingFile();
	static void openFile();
	static void setFileName(string name);
	static void writeToFile();
	static void readFile();
};


#endif