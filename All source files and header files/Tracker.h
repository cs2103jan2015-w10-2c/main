#pragma once
#ifndef TRACKER_H
#define TRACKER_H
#include <string>
#include <stack>
#include <list>
#include "Record.h"
#include "Task.h"

using namespace std;

class Tracker{
private:
	stack <Record> _recordTracker;

public:
	Tracker();
	~Tracker();

	void addRecord(Record newRecord);
	bool isEmptyTracker();
	Record getNewestRecord();
}; 

#endif