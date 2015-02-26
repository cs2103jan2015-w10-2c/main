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

#include "FloatTask.h"

using namespace std;

class Storage {

private:
	static string _fileName;
	static list<FloatTask>_FloatList;
	static list<FloatTask>::iterator _FloatIt;
	static bool _isDuplicate;

public:

	Storage();

	static bool storeFloat(string name);
	static bool isFloatDuplicate(string name);

};


#endif