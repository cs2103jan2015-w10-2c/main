#pragma once
#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H
#include <string>
#include "Task.h"

using namespace std;

class CommandParser
{
public:
	CommandParser(void);
	Task getUserInput(string);
	~CommandParser(void);
};

#endif
