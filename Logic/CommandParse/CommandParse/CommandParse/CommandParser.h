#pragma once
#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H
#include <string>
#include <iostream>
#include "Task.h"

using namespace std;

class CommandParser
{
public:
	CommandParser(void);
	Task createTask(string);
	~CommandParser(void);
};

#endif
