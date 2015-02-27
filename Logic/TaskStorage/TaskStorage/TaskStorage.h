#pragma once
#ifndef TASKSTORAGE_H
#define TASKSTORAGE_H

#include <iostream>
#include <string>
#include <sstream>
#include "Task.h"
using namespace std;

class TaskStorage
{
private:
	Task taskItem;

public:
	TaskStorage(void);
	~TaskStorage(void);
};

#endif
